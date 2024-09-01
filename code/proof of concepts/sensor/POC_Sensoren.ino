#include <QTRSensors.h>

QTRSensorsAnalog qtra((unsigned char[]) {A0, A1, A2, A3}, 4, 4); // Sensornummers
unsigned int sensorValues[4]; // Opslag voor de sensoren

void setup() {
  Serial.begin(9600); // Seriële communicatie starten

  // Kalibratie van de sensoren
  for (int i = 0; i < 80; i++) {
    qtra.calibrate();
    delay(20);
  }

}

void loop() {
  // Lees de waarden van de sensoren
  qtra.read(sensorValues);
  
  // Print de waarden van alle sensoren naar de seriële monitor
  Serial.print("Sensorwaardes: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(sensorValues[i]);
    Serial.print("\t"); // Tab voor overzichtelijkheid
  }
  Serial.println(); // Nieuwe regel

  // Controleer of de waarden binnen het gewenste bereik liggen en toon feedback
  int minWaarde = 75;  // Stel deze in op de minimale verwachte waarde voor wit
  int maxWaarde = 918;  // Stel deze in op de maximale verwachte waarde voor zwart
  if ((sensorValues[0] >= minWaarde && sensorValues[0] <= maxWaarde) &&
      (sensorValues[1] >= minWaarde && sensorValues[1] <= maxWaarde) &&
      (sensorValues[2] >= minWaarde && sensorValues[2] <= maxWaarde) &&
      (sensorValues[3] >= minWaarde && sensorValues[3] <= maxWaarde)) {
    Serial.println("Waarden binnen het juiste bereik.");
  } else {
    Serial.println("Waarden buiten bereik.");
  }

  delay(500); // Kleine vertraging om de uitlezing leesbaar te maken
}