//#include <ArduinoJson.h>
#include <stdio.h>

#define FLEXSENSORPIN0 A0
#define FLEXSENSORPIN1 A1
#define FLEXSENSORPIN2 A2
#define FLEXSENSORPIN3 A3
#define FLEXSENSORPIN4 A4


float finger1Reading;
float finger2Reading;
float finger3Reading;
float finger4Reading;
float finger5Reading;  

float dataArray[5];


void setup() {
  
  Serial.begin(9600);

}

void loop(void) {

  String output;
  
  finger1Reading = singleReading(FLEXSENSORPIN0);
  finger2Reading = singleReading(FLEXSENSORPIN1);
  finger3Reading = singleReading(FLEXSENSORPIN2);
  finger4Reading = singleReading(FLEXSENSORPIN3);
  finger5Reading = singleReading(FLEXSENSORPIN4);

  output += String(finger1Reading);
  output += ",";
  output += String(finger2Reading);
  output += ",";
  output += String(finger3Reading);
  output += ",";
  output += String(finger4Reading);
  output += ",";
  output += String(finger5Reading);

  Serial.println(output);

  delay(1000);
  
  
}

float singleReading(int pin){
  float reading;
  reading = analogRead(pin);
  return reading;
}

