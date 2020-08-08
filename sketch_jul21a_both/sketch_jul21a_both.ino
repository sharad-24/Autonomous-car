#include <AFMotor.h>

#include<NewPing.h>

//defining pins and variables
#define left A0
#define right A1
#define TRIG A2 
#define ECHO A3 
#define MAX_DISTANCE 100 
NewPing sonar(TRIG, ECHO, MAX_DISTANCE); 

//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);





void setup() {

  //declaring pin types
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  //begin serial communication
  Serial.begin(9600);
  
}

void loop(){

  delay(70);
int distance = sonar.ping_cm();
if (distance == 0) {
  distance = 30;
}
if(distance <=15) {
  Stop();
  delay(100);
rightmove();
delay(700);
forward();
delay(1000);
leftmove();  
delay(1000);
forward();
delay(500);
}
//int Right = analogRead(A0);
//    int Left = analogRead(A1);
//    
//    if(Right == 400 || Left == 400) {
//      motor1.setSpeed(255);
//      motor1.run(BACKWARD);
//      motor2.setSpeed(255);
//      motor2.run(BACKWARD);
//      motor3.setSpeed(255);
//      motor3.run(BACKWARD);
//      motor4.setSpeed(255);
//      motor4.run(BACKWARD);
//      
//    }
//      
    


  //line detected by none
   if(analogRead(left)<=400 && analogRead(right)<=400){
    //Forward
    motor1.run(FORWARD);
    motor1.setSpeed(60);
    motor2.run(FORWARD);
    motor2.setSpeed(60);
    motor3.run(FORWARD);
    motor3.setSpeed(60);
    motor4.run(FORWARD);
    motor4.setSpeed(60);
  }


  //line detected by left sensor
  else if(analogRead(left)<=400 && !analogRead(right)<=400){
    //turn left
    motor1.run(FORWARD);
    motor1.setSpeed(200);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    motor3.run(BACKWARD);
    motor3.setSpeed(200);
    motor4.run(BACKWARD);
    motor4.setSpeed(200);
    
  }
  //line detected by right sensor
  else if(!analogRead(left)<=400 && analogRead(right)<=400){
    //turn right
    motor1.run(BACKWARD);
    motor1.setSpeed(200);
    motor2.run(BACKWARD);
    motor2.setSpeed(200);
    motor3.run(FORWARD);
    motor3.setSpeed(200);
    motor4.run(FORWARD);
    motor4.setSpeed(200);
   
  }
  //line detected by both
  else if(!analogRead(left)<=400 && !analogRead(right)<=400){
    //stop
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
   
  }

  
}
void forward()
{
     motor1.run(FORWARD);
     motor1.setSpeed(150);
  motor2.run(FORWARD);
  motor2.setSpeed(150);
  motor3.run(FORWARD);
  motor3.setSpeed(150);
  motor4.run(FORWARD);
  motor4.setSpeed(150);
}

void backward()
{
     motor1.run(BACKWARD);
     motor1.setSpeed(200);
  motor2.run(BACKWARD);
  motor2.setSpeed(200);
  motor3.run(BACKWARD);
  motor3.setSpeed(200);
  motor4.run(BACKWARD);
  motor4.setSpeed(200);
}
void leftmove()
{
  motor1.run(FORWARD);
  motor1.setSpeed(200);
  motor2.run(FORWARD);
  motor2.setSpeed(200);
  motor3.run(BACKWARD);
  motor3.setSpeed(200);
  motor4.run(BACKWARD);
  motor4.setSpeed(200);
}
void rightmove()
{
  motor1.run(BACKWARD);
  motor1.setSpeed(200);
  motor2.run(BACKWARD);
  motor2.setSpeed(200);
  motor3.run(FORWARD);
  motor3.setSpeed(200);
  motor4.run(FORWARD);
  motor4.setSpeed(200);
}
void Stop()
{
  motor1.run(RELEASE);
  motor1.setSpeed(0);
  motor2.run(RELEASE);
  motor2.setSpeed(0);
  motor3.run(RELEASE);
  motor3.setSpeed(0);
  motor4.run(RELEASE);
  motor4.setSpeed(0);
}
