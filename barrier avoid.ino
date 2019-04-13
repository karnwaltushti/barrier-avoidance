#include <NewPing.h>
int dir1 = 7;
int pwm1 = 6;
int pwm2 = 5;
int dir2 = 4;
//sensor pins
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
#define MAX_DISTANCE_FROM_OBSTACLE_IN_CMS 20

void setup() {
  Serial.begin(9600);
  pinMode(2,HIGH);
  // put your setup code here, to run once:
  pinMode(dir1,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(11,OUTPUT);
  analogWrite(11,50);
  pinMode(10,OUTPUT);
  analogWrite(10,50);
}
/*
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pwm2, HIGH); 
  digitalWrite(dir2, LOW); 
  
  digitalWrite(pwm1, LOW); 
  digitalWrite(dir1, HIGH);
}
*/

void loop() { 
  delay(500);  // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int distanceInCms = sonar.ping() / US_ROUNDTRIP_CM; // Send ping, get ping time in microseconds (uS) and convert it to centimeters (cm)
  Serial.println("Distance: " + String(distanceInCms) + "cm");

  if(distanceInCms != NO_ECHO && distanceInCms < MAX_DISTANCE_FROM_OBSTACLE_IN_CMS) {
    rotate_right(90);
  } else  {
    drive_forward();
  }
}

void rotate_right(int angleInDegrees) {
  for(int i=0; i< angleInDegrees; i++) {
    turn_right();
    delay(25); // Test this out and change it approriately based on your motor speed
  }
}

void drive_forward() {
  digitalWrite(dir1,LOW);
  digitalWrite(pwm1,HIGH);
  digitalWrite(dir2,LOW);
  digitalWrite(pwm2,HIGH);
}

void turn_right() {
  digitalWrite(pwm2, HIGH); 
  digitalWrite(dir2, LOW); 
  
  digitalWrite(pwm1, LOW); 
  digitalWrite(dir1, HIGH); 
}
