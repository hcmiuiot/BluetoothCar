#include <SoftwareSerial.h>

#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9

const int maxSpd = 120;

SoftwareSerial BT(10, 11); //TX, RX respetively
String readdata;

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void loop() {
  while (BT.available()) {
    delay(10);
    char c = BT.read();
    readdata += c;
  }
  if (readdata.length() > 0) {
    Serial.println(readdata);

    if (readdata == "1")
    {
      analogWrite(IN1, maxSpd);
      analogWrite(IN2, 0);
      analogWrite(IN3, maxSpd);
      analogWrite(IN4, 0);
    }
    else if (readdata == "2")
    {
      analogWrite(IN1, 0);
      analogWrite(IN2, maxSpd);
      analogWrite(IN3, 0);
      analogWrite(IN4, maxSpd);
    }
    else if (readdata == "3")
    {
      analogWrite (IN1, maxSpd);
      analogWrite (IN2, 0);
      analogWrite (IN3, 0);
      analogWrite (IN4, maxSpd);
    }
    else if ( readdata == "4")
    {
      analogWrite (IN1, 0);
      analogWrite (IN2, maxSpd);
      analogWrite (IN3, maxSpd);
      analogWrite (IN4, 0);
    }
    else
    {
      analogWrite (IN1, 0);
      analogWrite (IN2, 0);
      analogWrite (IN3, 0);
      analogWrite (IN4, 0);
    }
    delay(100);
    readdata = "";
  }
} 
