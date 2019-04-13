// Ping Code Adopted From: https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home#!single-pin-sketch
#include <NewPing.h>

#define TRIG_PIN  A1  // Arduino pin tied to both trigger and echo pins on the ultrasonic sensor.
#define ECHO_PIN  A2 
#define PING_MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIG_PIN,ECHO_PIN, PING_MAX_DISTANCE); // NewPing setup of pin and maximum distance.

void setup() {
  Serial.begin(9600);
  pinMode(2,HIGH);
}

void loop() { 
  delay(500);  // Wait 500ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int distanceInCms = sonar.ping() / US_ROUNDTRIP_CM; // Send ping, get ping time in microseconds (uS) and convert it to centimeters (cm)
  Serial.println("Distance: " + String(distanceInCms) + "cm");
}
