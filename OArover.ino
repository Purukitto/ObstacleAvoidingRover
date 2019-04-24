#include <AFMotor.h> 
#define trigPin 12 //Connected trig pin of Ultrasound sensor to pin 12
#define echoPin 13 //Connected echo pin of Ultrasound sensor to pin 13
AF_DCMotor motorLeft(1,MOTOR12_64KHZ); 
AF_DCMotor motorRight(2, MOTOR12_8KHZ);
 
void setup() {
  Serial.begin(9600); // Opens serial port and sets data rate to 9600 bps
  pinMode(trigPin, OUTPUT); // Set required pin mode
  pinMode(echoPin, INPUT);
  motorLeft.setSpeed(105); //Depends on motor, experiment for optimum value
  motorRight.setSpeed(105);
}
 
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 25) {
    motorLeft.run(FORWARD); 
    motorRight.run (BACKWARD);
   }
  else {
   delay (15);
   motorLeft.run(FORWARD); 
   motorRight.run(FORWARD);  
  }  
}
