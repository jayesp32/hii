#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(2, 3); // RX, TX


#define enA 10//Enable1 L298 Pin enA 
#define in1 9 //Motor1  L298 Pin in1 
#define in2 8 //Motor1  L298 Pin in1 
#define in3 7 //Motor2  L298 Pin in1 
#define in4 6 //Motor2  L298 Pin in1 
#define enB 5 //Enable2 L298 Pin enB 

#define servo A4

#define R_S A0 //ir sensor Right
#define L_S A1 //ir sensor Left

#define echo A2    //Echo pin
#define trigger A3 //Trigger pin

int distance_L, distance_F = 30, distance_R;
long distance;
int set = 20;

int bt_ir_data = 0;  // Initialize the variable
int Speed = 130;  
int speed_low = 60;
int mode=0;


void setup(){ // put your setup code here, to run once

pinMode(R_S, INPUT); // declare if sensor as input  
pinMode(L_S, INPUT); // declare ir sensor as input

pinMode(echo, INPUT );// declare ultrasonic sensor Echo pin as input
pinMode(trigger, OUTPUT); // declare ultrasonic sensor Trigger pin as Output  

pinMode(enA, OUTPUT); // declare as output for L298 Pin enA 
pinMode(in1, OUTPUT); // declare as output for L298 Pin in1 
pinMode(in2, OUTPUT); // declare as output for L298 Pin in2 
pinMode(in3, OUTPUT); // declare as output for L298 Pin in3   
pinMode(in4, OUTPUT); // declare as output for L298 Pin in4 
pinMode(enB, OUTPUT); // declare as output for L298 Pin enB 


Serial.begin(9600); // start serial communication at 9600bps
BT_Serial.begin(9600); 

pinMode(servo, OUTPUT);

 for (int angle = 70; angle <= 140; angle += 5)  {
   servoPulse(servo, angle);  }
 for (int angle = 140; angle >= 0; angle -= 5)  {
   servoPulse(servo, angle);  }

 for (int angle = 0; angle <= 70; angle += 5)  {
   servoPulse(servo, angle);  }
delay(500);
}


void loop(){  

     // Initialize the speed variable

if (BT_Serial.available()) {
  char receivedChar = BT_Serial.read();

  if (receivedChar == 'a') {
    bt_ir_data = 1;  // Set bt_ir_data to 1 when 'a' is received
  } else if (receivedChar == 'b') {
    bt_ir_data = 2;  // Set bt_ir_data to 2 when 'b' is received
  } else if (receivedChar == 'c') {
    bt_ir_data = 3;  // Set bt_ir_data to 3 when 'c' is received
  } else if (receivedChar == 'd') {
    bt_ir_data = 4;  // Set bt_ir_data to 4 when 'd' is received
  } else if (receivedChar == 'e') {
    bt_ir_data = 5;  // Set bt_ir_data to 5 when 'e' is received
  } else if (receivedChar == 'f') {
    bt_ir_data = 6;  // Set bt_ir_data to 6 when 'f' is received
  } else if (receivedChar == 'g') {
    bt_ir_data = 7;  // Set bt_ir_data to 7 when 'g' is received
  } else if (receivedChar == 'h') {
    bt_ir_data = 8;  // Set bt_ir_data to 8 when 'h' is received
  } else if (receivedChar == 'i') {
    bt_ir_data = 9;  // Set bt_ir_data to 9 when 'i' is received
  } else if (receivedChar == 'j') {
    bt_ir_data = 10;  // Set bt_ir_data to 10 when 'j' is received
  } else if (receivedChar == 'k') {
    bt_ir_data = 11;  // Set bt_ir_data to 11 when 'k' is received
  } else if (receivedChar == 'l') {
    bt_ir_data = 12;  // Set bt_ir_data to 12 when 'l' is received
  } else if (receivedChar == 'm') {
    bt_ir_data = 13;  // Set bt_ir_data to 13 when 'm' is received
  } else if (receivedChar == 'n') {
    bt_ir_data = 14;  // Set bt_ir_data to 14 when 'n' is received
  } else if (receivedChar == '1') {
    Speed = 100;  // Set speed to 100 when '1' is received
  } else if (receivedChar == '2') {
    Speed = 120;  // Set speed to 120 when '2' is received
  } else if (receivedChar == '3') {
    Speed = 140;  // Set speed to 140 when '3' is received
  } else if (receivedChar == '4') {
    Speed = 160;  // Set speed to 160 when '4' is received
  } else if (receivedChar == '5') {
    Speed = 180;  // Set speed to 180 when '5' is received
  } else if (receivedChar == '6') {
    Speed = 200;  // Set speed to 200 when '6' is received
  } else if (receivedChar == '7') {
    Speed = 215;  // Set speed to 215 when '7' is received
  } else if (receivedChar == '8') {
    Speed = 230;  // Set speed to 230 when '8' is received
  } else if (receivedChar == '9') {
    Speed = 240;  // Set speed to 240 when '9' is received
  } else if (receivedChar == '0') {
    Speed = 255;  // Set speed to 255 when '0' is received
  } else {
    // Handle any other character received (optional)
  }
}



     if(bt_ir_data == 8){mode=0; Stop();}    //Manual Android Application and IR Remote Control Command   
else if(bt_ir_data == 9){mode=1; Speed=130;} //Auto Line Follower Command
else if(bt_ir_data == 10){mode=2; Speed=255;} //Auto Obstacle Avoiding Command

analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 

if(mode==0){     
//===============================================================================
//                          Key Control Command
//=============================================================================== 
     if(bt_ir_data == 1){forword(); }  // if the bt_data is '1' the DC motor will go forward
else if(bt_ir_data == 2){backword();}  // if the bt_data is '2' the motor will Reverse
else if(bt_ir_data == 3){turnLeft();}  // if the bt_data is '3' the motor will turn left
else if(bt_ir_data == 4){turnRight();} // if the bt_data is '4' the motor will turn right
else if(bt_ir_data == 5){Stop(); }     // if the bt_data '5' the motor will Stop
else if(bt_ir_data == 11){forwordturnRight();} // if the bt_data is '4' the motor will turn right
else if(bt_ir_data == 12){backwordturnLeft(); }     // if the bt_data '5' the motor will Stop
else if(bt_ir_data == 13){backwordturnRight();} // if the bt_data is '4' the motor will turn right
else if(bt_ir_data == 14){forwordturnLeft(); }     // if the bt_data '5' the motor will Stop

//===============================================================================
//                          Voice Control Command
//===============================================================================    
else if(bt_ir_data == 6){turnLeft();  delay(400);  bt_ir_data = 5;}
else if(bt_ir_data == 7){turnRight(); delay(400);  bt_ir_data = 5;}
}

if(mode==1){    
//===============================================================================
//                          Line Follower Control
//===============================================================================     
if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){forword();}  //if Right Sensor and Left Sensor are at White color then it will call forword function
if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){turnRight();}//if Right Sensor is Black and Left Sensor is White then it will call turn Right function  
if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){turnLeft();} //if Right Sensor is White and Left Sensor is Black then it will call turn Left function
if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){Stop();}     //if Right Sensor and Left Sensor are at Black color then it will call Stop function
} 

if(mode==2){    
//===============================================================================
//                          Obstacle Avoiding Control
//===============================================================================     
 distance_F = Ultrasonic_read();
 Serial.print("S=");Serial.println(distance_F);
  if (distance_F > set){forword();}
    else{Check_side();}
}

delay(10);
}


void servoPulse (int pin, int angle){
int pwm = (angle*11) + 500;      // Convert angle to microseconds
 digitalWrite(pin, HIGH);
 delayMicroseconds(pwm);
 digitalWrite(pin, LOW);
 delay(50);                   // Refresh cycle of servo
}


//**********************Ultrasonic_read****************************
long Ultrasonic_read(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  distance = pulseIn (echo, HIGH);
  return distance / 29 / 2;
}

void compareDistance(){
       if (distance_L > distance_R){
  turnLeft();
  delay(350);
  }
  else if (distance_R > distance_L){
  turnRight();
  delay(350);
  }
  else{
  backword();
  delay(300);
  turnRight();
  delay(600);
  }
}

void Check_side(){
    Stop();
    delay(100);
 for (int angle = 70; angle <= 140; angle += 5)  {
   servoPulse(servo, angle);  }
    delay(300);
    distance_L = Ultrasonic_read();
    delay(100);
  for (int angle = 140; angle >= 0; angle -= 5)  {
   servoPulse(servo, angle);  }
    delay(500);
    distance_R = Ultrasonic_read();
    delay(100);
 for (int angle = 0; angle <= 70; angle += 5)  {
   servoPulse(servo, angle);  }
    delay(300);
    compareDistance();
}

void forword(){  //forword
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 

}
void forwordturnLeft(){  //forword
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed-speed_low); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 

}
void forwordturnRight(){  //forword
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
analogWrite(enA, Speed-speed_low); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 

}

void backword(){ //backword
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 

}
void backwordturnLeft(){ //backword
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
analogWrite(enA, Speed-speed_low); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 

}
void backwordturnRight(){ //backword
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed-speed_low); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 

}

void turnRight(){ //turnRight
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin  
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 

}

void turnLeft(){ //turnLeft
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 

}

void Stop(){ //stop
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 

}