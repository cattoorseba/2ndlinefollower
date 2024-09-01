#include <QTRSensors.h>
#define led_buzzer 13 // Led- en zoemerpin.
#define button 7 // Startknop.
#define irontvanger 2 // Pin van IR-ontvangermodule.
#define dip1 4 // DipSwitch 1.
#define dip2 5 // DipSwitch 2.
#define dip3 6 // DipSwitch 3.
#define linkermotor1 3 // Linkermotor PWM 1
#define linkermotor2 11 // Linkermotor PWM 2
#define rechtermotor1 9 // Rechtermotor-PWM 1
#define rechtermotor2 10 // Rechtermotor-PWM 2
int start = 0; // Initialisatievariabele
int i = 0; 
QTRSensorsAnalog qtra((unsigned char[]) {A0, A1 , A2, A3}, 4, 4); // Pinnummers waarop sensoren zijn aangesloten.
unsigned int sensorValues[4]; // Aantal sensoren.

int basissnelheid = 180; // Snelheidswaarde die moet worden toegepast bij foutwaarde 0 (max. 255 PWM).
int maxsnelheid = 255; // Motor CW/CCW maximale waarde.
float Kp = 0.17;
float Kd = 3;
int laatstefout = 0;
int fout = 0;
int rechtermotorpwm = 0; // Initiële PWM-waarde.
int linkermotorpwm = 0; // Initiële PWM-waarde.
int achtergrond = 0; // Zwarte achtergrond Witte lijn = 1, Witte achtergrond Zwarte lijn = 0.


void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(irontvanger, INPUT_PULLUP);
  pinMode(dip1, INPUT_PULLUP);
  pinMode(dip2, INPUT_PULLUP);
  pinMode(dip3, INPUT_PULLUP);
  pinMode(led_buzzer, OUTPUT);
  pinMode(linkermotor1, OUTPUT);
  pinMode(linkermotor2, OUTPUT);
  pinMode(rechtermotor1, OUTPUT);
  pinMode(rechtermotor2, OUTPUT);
  tone(led_buzzer, 500, 100);
  delay(50);
  noTone(led_buzzer);

// kalibratie van de sensoren

  for (i = 0; i < 80; i++)
  {
    if (0 <= i && i < 5)  motorcontrol(-150, 150);
    if (5 <= i && i  < 15) motorcontrol(150, -150);
    if (15 <= i && i < 25)  motorcontrol(-150, 150);
    if (25 <= i && i < 35)  motorcontrol(150, -150);
    if (35 <= i && i < 45)  motorcontrol(-150, 150);
    if (45 <= i && i  < 55) motorcontrol(150, -150);
    if (55 <= i && i < 65)  motorcontrol(-150, 150);
    if (65 <= i && i < 70)  motorcontrol(150, -150);
    if ( i >= 70  )  {
      motorcontrol(0, 0);
      delay(5);
    }
    qtra.calibrate();
    delay(3);
  }

  motorcontrol(0, 0);
  tone(led_buzzer, 3000, 100);
  delay(50);
  noTone(led_buzzer);
}


void loop() {

  if (digitalRead(button) == 0) {
    for (int a = 0; a < 5; a++) {
      tone(led_buzzer, 500, 100); delay(500); noTone(led_buzzer); delay(400); start = 1;
    }
  }

  if (start == 1) { // De lus waarin de robot in staat 1 van de startvariabele draait.
    fout = ( qtra.readLine(sensorValues, 1, achtergrond) - 1500);
    int correctiesnelheid = Kp * fout + Kd * (fout - laatstefout);
    laatstefout = fout;
    linkermotorpwm = basissnelheid + correctiesnelheid  ;
    rechtermotorpwm = basissnelheid - correctiesnelheid  ;
    linkermotorpwm = constrain(linkermotorpwm, -255, maxsnelheid); ///// Hier geldt een beperking voor de PWM-waarden die op de motoren moeten worden toegepast.
    rechtermotorpwm = constrain(rechtermotorpwm, -255, maxsnelheid);
    motorcontrol(rechtermotorpwm, linkermotorpwm);
  }
}


void motorcontrol(int rechtermotorpwm, int linkermotorpwm) {
  if (rechtermotorpwm <= 0) {
    rechtermotorpwm = abs(rechtermotorpwm);
    analogWrite(rechtermotor1, 0);
    analogWrite(rechtermotor2, rechtermotorpwm);
  }
  else {
    analogWrite(rechtermotor1, rechtermotorpwm);
    analogWrite(rechtermotor2, 0);
  }

  if (linkermotorpwm <= 0) {
    linkermotorpwm = abs(linkermotorpwm);
    analogWrite(linkermotor1, linkermotorpwm);
    analogWrite(linkermotor2, 0);
  }
  else {
    analogWrite(linkermotor1, 0);
    analogWrite(linkermotor2, linkermotorpwm);
  }

}
