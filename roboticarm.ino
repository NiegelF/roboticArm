#include <Servo.h> 
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
Servo servo1;
int VRx = A0;
int VRy = A1;
int VRy1 = A2;
int VRx1 = A3; 
int SW = 9;
int SW1 = 8;
int pos = 0;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int xPosition = 0;
int yPosition = 0;
int xPosition1 = 0;
int yPosition1 = 0;
int SW_state = 0;
int SW1_state = 0;
int mapX = 0;
int mapY = 0;
int mapX1 = 0;
int mapY1 = 0;
int fortnite = 5;
#define SERVOMIN  201 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  555 // this is the 'maximum' pulse length count (out of 4096)
int angleToPulse(int ang){
   int pulse = map(ang,30, 150, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   return pulse;
}


// our servo # counter
uint8_t servonum = 90;
void setup() {
  Serial.begin(9600);
	servo1.attach(10);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(VRx1, INPUT);
  pinMode(VRy1, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  pinMode(SW1, INPUT_PULLUP);

}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  xPosition1 = analogRead(VRx1);
  yPosition1 = analogRead(VRy1);
  SW_state = digitalRead(SW);
  SW1_state = digitalRead(SW1);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  mapX1 = map(xPosition1, 0, 1023, -512, 512);
  mapY1 = map(yPosition1, 0, 1023, -512, 512);
  if (pos1 <= 59) {
    pos1 = 61; 
  }
  if (SW_state == LOW){
    servo1.write(0);
  }
  if (SW_state == HIGH){
    servo1.write(180);
  }
  delay(20);
  move();
  

  
}
void move(){
  if (mapX > 400) {
  delay(fortnite);
  pos += 1;
  pwm.setPWM(0,0,angleToPulse(pos) );
  loop();
  }

  else if (mapX < -400) {
  delay(fortnite);
  pos -= 1;
  pwm.setPWM(0,0,angleToPulse(pos) );
  loop();
  }

  else if (mapY > 400 && pos1 <= 175) {
  delay(fortnite);
  pos1 += 1;
  pwm.setPWM(1,0,angleToPulse(pos1) );
  loop();
  }

  else if (mapY < -400 && pos1 >= 60) {
  delay(fortnite);
  pos1 -= 1;
  pwm.setPWM(1,0,angleToPulse(pos1) );
  loop();
  }
  //Joystick 2
  else if (mapX1 > 400) {
  delay(fortnite);
  pos2 += 1;
  pwm.setPWM(2,0,angleToPulse(pos2) );
  loop();
  }

  else if (mapX1 < -400) {
  delay(fortnite);
  pos2 -= 1;
  pwm.setPWM(2,0,angleToPulse(pos2) );
  loop(); 
  }

  else if (mapY1 > 400) {
  delay(fortnite);
  pos3 += 1;
  pwm.setPWM(3,0,angleToPulse(pos3) );
    Serial.print("among us");
  loop();
  }

  else if (mapY1 < -400) {
  delay(fortnite);
  pos3 -= 1;
  pwm.setPWM(3,0,angleToPulse(pos3) );
    Serial.print("among us");

  loop();
  }
}
