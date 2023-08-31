#include "EEPROMAnything.h"

const int sensor[] = {A7, A6, A5, A4, A3, A2, A1, A0};
int Sensorwaarde[8];

struct param_t
{
  unsigned long cycleTime;///////////////////
  int black[8];
  int white[8];
  /* andere parameters die in het eeprom geheugen moeten opgeslagen worden voeg je hier toe ... */
} params;
int normalised[8];


void setup() {
  
Serial.begin(115200);

EEPROM_readAnything(0, params);
}

void loop() {
  int normalised[8];
  
  Serial.print("waarde sensoren: ");
    for (int i = 0; i < 8; i++)
    {
      Sensorwaarde[i] = analogRead(sensor[i]);
      Serial.print(Sensorwaarde[i]);
      Serial.print(" ");
    }
   Serial.println();

   Serial/*Port*/.print("normalised values: ");
    for (int i = 0; i < 8; i++)
    {
      normalised[i] = map(analogRead(sensor[i]), params.black[i], params.white[i],0 , 1000);
      Serial/*Port*/.print(normalised[i]);
      Serial/*Port*/.print(" ");
      
    }
    Serial/*Port¨*/.println();
   delay(500);
}
