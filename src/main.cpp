#include <Arduino.h>
#include<avr/wdt.h>

#define BAUD_RATE 9600
#define OUT12V 7
#define OUT5V 8

String Input = "";
boolean ON = false;

void setup()
{
  pinMode(OUT12V, OUTPUT);
  pinMode(OUT5V, OUTPUT);
  digitalWrite(OUT12V, !ON); 
  digitalWrite(OUT5V, !ON); 

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, ON);

  Serial.begin(BAUD_RATE);

  wdt_enable(WDTO_4S);
}

void loop()
{
  if (Serial.available() > 1)
  {
    Input = Serial.readString();
    Input.trim(); 
    Input.toUpperCase();
    if (Input == "ON")
    {
      ON=true;
      Serial.read();
      Serial.flush();
    }
    else if (Input == "OFF")
    {
      ON=false;
      Serial.read();
      Serial.flush();
    }
    else
    {
      Serial.println("ERROR, unknown command");
      Serial.read();
      Serial.flush();
    }
    digitalWrite(OUT12V, !ON);
    digitalWrite(OUT5V, !ON);
    digitalWrite(LED_BUILTIN, ON);
    
  }
  wdt_reset(); 

}
