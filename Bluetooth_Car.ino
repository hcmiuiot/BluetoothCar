/* 
 * Control car using bluetooth
 */
#include <SoftwareSerial.h>

#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9
#define MAX_SPEED 100 
#define MIN_SPEED 0

void forward();
void backward();
void left();
void right();
void stop();

void motor_1_stop() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
}
 
void motor_2_stop() {
  analogWrite(IN3, LOW);
  analogWrite(IN4, LOW);
}
 
void motor_1_for(int speed) {
  analogWrite(IN1, speed);
  analogWrite(IN2, 0);
}
 
void motor_1_back(int speed) {
  analogWrite(IN1, 0);
  analogWrite(IN2, speed);
}
 
void motor_2_for(int speed) {
  analogWrite(IN3, speed);
  analogWrite(IN4, 0);
}
 
void motor_2_back(int speed) {
  analogWrite(IN3, 0);
  analogWrite(IN4, speed);
}

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  
  while (!Serial) {
     // wait for serial port to connect. Needed for native USB port only
  }

  mySerial.begin(9600);
  mySerial.println("Bluetooth Hi");
  Serial.write("Hello\n");
}
char state = 0;
void loop() {
  
  if (mySerial.available()) {
    state = mySerial.read();
    Serial.write(state + '\n');
  }

  int delayTime = 500;
  switch (state){
    case '1':
      Serial.write("UP\n");
      forward();
      break;
    case '2':
      Serial.write("DOWN\n");
      backward();
      break;
    case '4':
      Serial.write("LEFT\n");
      left();
      break;
    case '3pioj':
      Serial.write("RIGHT\n");
      right();
      break;
    default:
      Serial.write("STOP\n");
      stop();
      break;
  }
  delay(50);
}

//*******************************************************


void forward()
{
  motor_1_for(MAX_SPEED);
  motor_2_for(MAX_SPEED);
}

void backward()
{
  motor_1_back(MAX_SPEED);
  motor_2_back(MAX_SPEED);
}

void left()
{
  motor_1_for(MAX_SPEED);
  motor_2_back(MAX_SPEED);
}

void right()
{
  motor_2_for(MAX_SPEED);
  motor_1_back(MAX_SPEED);
}
void stop()
{
  motor_1_stop();
  motor_2_stop();
}


