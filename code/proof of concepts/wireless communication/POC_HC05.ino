#include <SoftwareSerial.h>

SoftwareSerial mySerial(0,1); //RX, TX

char inputdata          = 0;  //Variable for storing received data
void setup() {
  // put your setup code here, to run once:
    Serial1.begin(9600);  
    Serial.begin(9600);//Sets the baud rate for bluetooth pins 
    Serial1.print("Actief\n");  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())  {
   inputdata = Serial1.read();        //Read the incoming data & store into data
           
      if(inputdata == '1') 
      {
         Serial1.print("Ik stuur '10' naar gsm\n");  
         Serial.print("Ik stuur '100' naar arduino\n");  
 
      }
         
      else if(inputdata == '2')  
      {      
         Serial1.print("Ik stuur '20' naar gsm\n");
         Serial.print("Ik stuur '200' naar arduino\n");  
      }

      } 
  delay(500);
  }
