

#include <Servo.h>\
\
Servo servoM1;\
Servo servoM2;\
Servo servoM3;\
Servo servoM4;\
Servo servoM5;\
Servo servoM6;\
\
int breakTime = 500; \
\
int joyVal; //varible to read the values from the analogue pins from the left controller \
int angel; \
int joyVal2;  //varible to read the values from the analogue pins from the right controller\
int angel2;\
\
\
///joystick one (left controller)\
#define yAxis1 A14\
\
#define xAxis1  A15\
\
#define switchButton1 49 \
\
///jyostick two (right controller)\
\
#define yAxis2 A13\
\
#define xAxis2 A12\
\
#define switchButton2 52\
\
// ultrasonic sensor one (left) \
\
int trigPin =  8 ; \
\
int echoPin =  7 ;\
\
float duration ; \
float distance ; \
\
// ultrasonic sensor two (right) \
\
int trigPin2 =  6 ;\
\
int echoPin2 =  5 ; \
\
float duration2 ; \
float distance2 ;\
\
\
void setup() \{\
  // put your setup code here, to run once:\
Serial.begin(9600); \
\
 //attach servos on pins D12-13\
  servoM1.attach(13); \
  servoM2.attach(12);\
  servoM3.attach(11);\
  servoM4.attach(10);\
  servoM5.attach(9); \
  servoM6.attach(8);\
\
  pinMode( echoPin, INPUT); \
  pinMode( trigPin, OUTPUT); \
  pinMode( trigPin2, OUTPUT); \
  pinMode( echoPin2, INPUT);\
\
\}\
\
void loop() \{\
  // put your main code here, to run repeatedly:\
\
\
// ultrasonic sensor - distnance measurments \
\
digitalWrite(trigPin, LOW);\
digitalWrite(trigPin2, LOW);\
\
delayMicroseconds(2);\
\
 \
digitalWrite(trigPin, HIGH); \
digitalWrite(trigPin2, HIGH); \
\
\
delayMicroseconds(10); \
\
\
digitalWrite(trigPin, LOW); \
digitalWrite(trigPin2, LOW); \
\
\
\
duration = pulseIn(echoPin, HIGH); \
duration2 = pulseIn(echoPin2, HIGH);\
\
distance = duration * 0.034/2 ;\
distance2 = duration2 * 0.034/2;\
\
\
\
\
\
  //read the value of left joystick (between 0 - 1023)\
\
joyVal = analogRead(xAxis1);\
angel = map(joyVal, 0, 1023, 0, 180); // servo value between 0-180\
servoM1.write(angel); //set the servo position according to the joystick\
\
joyVal2 = analogRead(xAxis2);\
angel2 = map(joyVal2, 0, 1023, 0, 180); // servo value between 0-180\
servoM2.write(angel2); //set the servo position according to the joystick\
\
servoM3.write(angel); \
\
servoM4.write(angel2);\
\
servoM5.write(angel); \
\
servoM6.write(angel2); \
\
Serial.print(distance);\
Serial.print(" ");\
Serial.print(distance2); \
Serial.print(" "); \
Serial.print(joyVal); \
Serial.print(" "); \
Serial.println(joyVal2);\
\
  \
 delay(breakTime); \
  \
\}}
