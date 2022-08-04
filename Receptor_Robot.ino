

#include <Servo.h>    //the library which helps us to control the servo motor
#include <SPI.h>      //the communication interface with the modem
#include "RF24.h"     //the library which helps us to control the radio modem (nRF24L)

//define our L298N control pins
//Motor A
const int RightMotorForward = 2;    // IN1
const int RightMotorBackward = 3;   // IN2
//Motor B
const int LeftMotorForward = 4;     // IN3
const int LeftMotorBackward = 6;    // IN4

//define the servo name
Servo my1Servo;
Servo my2Servo;
Servo my3Servo;
Servo my4Servo;
Servo my5Servo;
Servo my6Servo;
Servo my7Servo;
Servo my8Servo;



RF24 radio(5,10);     /*This object represents a modem connected to the Arduino. 
                      Arguments 5 and 10 are a digital pin numbers to which signals 
                      CE and CSN are connected.*/

const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem,that will receive data from the Arduino.

int data[1];


void setup(){
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);

  //define the servo input pins
  my1Servo.attach(14); //A0
  my2Servo.attach(15);
  my3Servo.attach(16);
  my4Servo.attach(17);
  my5Servo.attach(18);
  my6Servo.attach(19);
  my7Servo.attach(20);
  my8Servo.attach(21);
  
  radio.begin();                    //it activates the modem.
  radio.openReadingPipe(1, pipe);   //determines the address of our modem which receive data.
  radio.startListening();           //enable receiving data via modem
  }

void loop(){
  if(radio.available()){
    radio.read(data, 1);
    
    if(data[0] < 11 && data[0] > 6){
    // This is backward
    // Set a Motor A backward
    digitalWrite(RightMotorForward, LOW);
    digitalWrite(RightMotorBackward, HIGH);
    // Set a Motor B backward
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(LeftMotorBackward, HIGH);
    }
    if(data[0] > -1 && data[0] < 4){
    // This is forward
    // Set a Motor A forward
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(RightMotorBackward, LOW);
    // Set a Motor B forward
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
    }
    if (data[0] == 5){
    // Stop Motors
    digitalWrite(RightMotorForward, LOW);
    digitalWrite(RightMotorBackward, LOW);
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(LeftMotorBackward, LOW);
    }
    // This is Backward
    // Set a Motor A Backward
    if(data[0] < 21 && data[0] > 16){
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(RightMotorBackward, LOW);
    // Set a Motor B Backward
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(LeftMotorBackward, HIGH);
    }
    // Turn Right
    if(data[0] > 10 && data[0] < 14){
    digitalWrite(RightMotorForward, LOW);
    digitalWrite(RightMotorBackward, HIGH);
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
    }
    // Turn Left
    if(data[0] == 15){
    digitalWrite(RightMotorForward, LOW);
    digitalWrite(RightMotorBackward, LOW);
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(LeftMotorBackward, LOW);
    }
    // for the servo motor
    if(data[0] < 31 && data[0] > 21){
      int pot1Value = data[0];
      int pot1Pos = map(pot1Value, 21, 30, 10, 170);
      my1Servo.write(pot1Pos); 
    }
    if(data[0] < 41 && data[0] > 31){
      int pot2Value = data[0];
      int pot2Pos = map(pot2Value, 21, 30, 10, 170);
      my2Servo.write(pot2Pos); 
    }
    if(data[0] < 51 && data[0] > 41){
      int pot3Value = data[0];
      int pot3Pos = map(pot3Value, 21, 30, 10, 170);
      my3Servo.write(pot3Pos); 
    }
    if(data[0] < 61 && data[0] > 51){
      int pot4Value = data[0];
      int pot4Pos = map(pot4Value, 21, 30, 10, 170);
      my4Servo.write(pot4Pos); 
    }
    if(data[0] < 71 && data[0] > 61){
      int pot5Value = data[0];
      int pot5Pos = map(pot5Value, 21, 30, 10, 170);
      my5Servo.write(pot5Pos); 
    }
    if(data[0] < 81 && data[0] > 71){
      int pot6Value = data[0];
      int pot6Pos = map(pot6Value, 21, 30, 10, 170);
      my6Servo.write(pot6Pos); 
    }
    if(data[0] < 91 && data[0] > 81){
      int pot7Value = data[0];
      int pot7Pos = map(pot7Value, 21, 30, 10, 170);
      my7Servo.write(pot7Pos); 
    }
    if(data[0] <101 && data[0] > 91){
      int pot8Value = data[0];
      int pot8Pos = map(pot8Value, 21, 30, 10, 170);
      my8Servo.write(pot8Pos); 
    }
    
  }
}
