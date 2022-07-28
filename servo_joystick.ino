// Servo library
#include <Servo.h>
// Declare variables
int joy_pin = 2;
int x;
int y;
int state;
int motorpin = 10; 
// instantiate
Servo motor;
void setup(){
  pinMode(joy_pin, OUTPUT);
  motor.attach(motorpin);
  Serial.begin(9600);
}
void loop(){
  y = analogRead(A0);
  x = analogRead(A1);
  state = digitalRead(joy_pin);
  // Serial.println(x);
  // Serial.println(y);

  // Move motor 
  int val;
  // Map analog values to angles which are writable to the servo
  
  val = map(y,0,1023,0,180);
  switch(y){
    case 512:
      motor.write(0);
      break;
    default:
      motor.write(val);

  }
}
