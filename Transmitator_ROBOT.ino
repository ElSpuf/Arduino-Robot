

#include <SPI.h>                      //the communication interface with the modem
#include "RF24.h"                     //the library which helps us to control the radio modem

//define the input pins
int x_axis = A0;
int y_axis = A1;
int potPin1 = A2;
int potPin2 = A3;
int potPin3 = A4;
int potPin4 = A5;
int potPin5 = A6;
int potPin6 = A7;
int potPin7 = A8;
int potPin8 = A9;

//define variable values
int xValue;
int yValue;
int pot1Value;
int pot2Value;
int pot3Value;
int pot4Value;
int pot5Value;
int pot6Value;
int pot7Value;
int pot8Value;


int data[1];

RF24 radio(5,10);                     //5 and 10 are a digital pin numbers to which signals CE and CSN are connected.
                                      
const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem, that will receive data from Arduino.


void setup(void){
  Serial.begin(9600);
  radio.begin();                      //it activates the modem.
  radio.openWritingPipe(pipe);        //sets the address of the receiver to which the program will send data.
}

void loop(){
  
  //Send X-axis data
  xValue = analogRead(x_axis);
  xValue = map(xValue, 0, 1023, 0, 10);
  data[0] = xValue;
  radio.write(data, 1); 
  
  //Send Y-axis data
  yValue = analogRead(y_axis);
  yValue = map(yValue, 0, 1023, 11, 20);
  data[0] = yValue;
  radio.write(data, 1);
  
  //Send Potentiometer data
  pot1Value = analogRead(potPin1);
  pot1Value = map(pot1Value, 0, 1023, 21, 30);
  data[0] = pot1Value;
  radio.write(data, 1);

  pot2Value = analogRead(potPin2);
  pot2Value = map(pot2Value, 0, 1023, 21, 30);
  data[0] = pot2Value;
  radio.write(data, 1);
  
  pot3Value = analogRead(potPin3);
  pot3Value = map(pot3Value, 0, 1023, 21, 30);
  data[0] = pot3Value;
  radio.write(data, 1);

  pot4Value = analogRead(potPin4);
  pot4Value = map(pot4Value, 0, 1023, 21, 30);
  data[0] = pot4Value;
  radio.write(data, 1);

  pot5Value = analogRead(potPin5);
  pot5Value = map(pot5Value, 0, 1023, 21, 30);
  data[0] = pot5Value;
  radio.write(data, 1);

  pot6Value = analogRead(potPin6);
  pot6Value = map(pot6Value, 0, 1023, 21, 30);
  data[0] = pot6Value;
  radio.write(data, 1);

  pot7Value = analogRead(potPin7);
  pot7Value = map(pot7Value, 0, 1023, 21, 30);
  data[0] = pot7Value;
  radio.write(data, 1);

  pot8Value = analogRead(potPin8);
  pot8Value = map(pot8Value, 0, 1023, 21, 30);
  data[0] = pot8Value;
  radio.write(data, 1);

  
}
