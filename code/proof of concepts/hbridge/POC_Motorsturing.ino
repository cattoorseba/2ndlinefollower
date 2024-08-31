#define linkermotor1 3 
#define linkermotor2 11 
#define rechtermotor1 9 
#define rechtermotor2 10 

void setup() {
  pinMode(linkermotor1, OUTPUT);
  pinMode(linkermotor2, OUTPUT);
  pinMode(rechtermotor1, OUTPUT);
  pinMode(rechtermotor2, OUTPUT);
}

void loop() {
  //Links vooruit, rechts stil
  motorcontrol(0,255);
  delay(2000);
  //Rechts vooruit, links stil
  motorcontrol(255,0);
  delay(2000);
  // Stap 1: Rechts vooruit, links achteruit
  motorcontrol(200, -200);
  delay(2000);

  // Stap 2: Links vooruit, rechts achteruit
  motorcontrol(-200, 200);
  delay(2000);

  // Stap 3: Beide vooruit
  motorcontrol(200, 200);
  delay(2000);

  // Stap 4: Beide achteruit
  motorcontrol(-200, -200);
  delay(2000);

  // Stap 5: Rechts snel vooruit, links traag vooruit
  motorcontrol(255, 100);
  delay(2000);

  // Stap 6: Links snel vooruit, rechts traag vooruit
  motorcontrol(100, 255);
  delay(2000);

  // Stap 7: Rechts snel vooruit, links achteruit
  motorcontrol(255, -100);
  delay(2000);

  // Stap 8: Links snel vooruit, rechts achteruit
  motorcontrol(-100, 255);
  delay(2000);
}

void motorcontrol(int rechtermotorpwm, int linkermotorpwm) {
  if (rechtermotorpwm <= 0) {
    rechtermotorpwm = abs(rechtermotorpwm);
    analogWrite(rechtermotor1, 0);
    analogWrite(rechtermotor2, rechtermotorpwm);
  } else {
    analogWrite(rechtermotor1, rechtermotorpwm);
    analogWrite(rechtermotor2, 0);
  }

  if (linkermotorpwm <= 0) {
    linkermotorpwm = abs(linkermotorpwm);
    analogWrite(linkermotor1, linkermotorpwm);
    analogWrite(linkermotor2, 0);
  } else {
    analogWrite(linkermotor1, 0);
    analogWrite(linkermotor2, linkermotorpwm);
  }
}