#include <Arduino.h>

#define BAUD_RATE 115200
#define OUT12V 7
#define OUT5V 8

String Input = "";

void setup()
{
  pinMode(OUT12V, OUTPUT);
  pinMode(OUT5V, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);

  Serial.begin(BAUD_RATE);
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
      digitalWrite(OUT12V, 1);
      digitalWrite(OUT5V, 1);
      digitalWrite(LED_BUILTIN, 1);
    }
    else if (Input == "OFF")
    {
      digitalWrite(OUT12V, 0);
      digitalWrite(OUT5V, 0);
      digitalWrite(LED_BUILTIN, 0);
    }
    else
      Serial.println("ERROR, unknown command");
  }


}
