#include <Servo.h>

Servo steering;  // create servo object to control a servo
Servo throttle;  // create servo object to control a servo

int steeringPin = 9;    # CHannel 3
int throttlePin = 10;   # CHannel 1
int motorOutPin = 11;
int steerOutPin = 12;

int steerPosition = 90;
int throttlePosition = 90;


void setup() {

  Serial.begin(115200);
  
  steering.attach(steeringPin);  // attaches the servo on GIO2 to the servo object
  throttle.attach(throttlePin);  // attaches the servo on GIO2 to the servo object

  pinMode(steeringPin, INPUT);
  pinMode(steerOutPin, OUTPUT);
  pinMode(throttlePin, INPUT);
  pinMode(motorOutPin, OUTPUT);
 
  steering.write(steerPosition);
  throttle.write(throttlePosition);
  
  delay(2000);
}

void loop() {

   steerPosition = pulseIn(steeringPin, HIGH);
   throttlePosition = pulseIn(throttlePin, HIGH);

   
   steerPosition = constrain(map(steerPosition, 1000, 2000, 0, 180), 0, 180);
   throttlePosition = constrain(map(throttlePosition, 1000, 2000, 0, 180), 0, 180);


   Serial.print(throttlePosition);
   Serial.print(" -- ");
   Serial.println(steerPosition);
   
   throttle.write(throttlePosition);
   steering.write(steerPosition);
}
