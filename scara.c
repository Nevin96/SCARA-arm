#include <Wire.h> 
#include <Adafruit_PWMServoDriver.h> 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); 
const int SERVO_MIN = 150; // Minimum pulse length count (out of 4096) 
const int SERVO_MAX = 600; // Maximum pulse length count (out of 4096) 
const int GRIPPER_PIN = 9;  // Pin for the gripper 
void setup() { 
Serial.begin(9600); // Initialize serial communication 
pwm.begin(); 
pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates 
pinMode(GRIPPER_PIN, OUTPUT); // Set gripper pin as output 
digitalWrite(GRIPPER_PIN, LOW); // Initialize gripper to released state 
delay(10); 
} 
void loop() { 
if (Serial.available() > 0) { // If there is data available to read 
String input = Serial.readStringUntil('\n'); // Read the data string until newline 
int servoIndex = input.substring(0, 1).toInt(); // Get the servo index 
int servoValue = input.substring(2).toInt(); // Get the servo value 
switch (servoIndex) { 
case 1: 
// Control servo 1 (standard servo) 
int pulseLength1 = map(servoValue, 0, 270, SERVO_MIN, SERVO_MAX); 
pwm.setPWM(0, 0, pulseLength1); // Control servo 1 
break; 
case 2: 
// Control servo 2 (standard servo) 
int pulseLength2 = map(servoValue, 0, 270, SERVO_MIN, SERVO_MAX); 
pwm.setPWM(1, 0, pulseLength2); // Control servo 2 
break; 
case 3: 