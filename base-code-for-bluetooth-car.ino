#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(2, 3); // RX, TX

#include <IRremote.h>
const int RECV_PIN = A5;
IRrecv irrecv(RECV_PIN);
decode_results results;

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

int bt_ir_data; // variable to receive data from the serial port and IRremote
int Speed = 130;
int speed_low = 60;  
int mode=0;
int IR_data;

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

irrecv.enableIRIn(); // Start the receiver
irrecv.blink13(true);

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

if(BT_Serial.available() > 0){  //if some date is sent, reads it and saves in state     
bt_ir_data = BT_Serial.read(); 
 
} 

  if (Serial.available() > 0) {
    String serial_command = Serial.readString(); // Read the entire string from the serial port
    
    // Process the serial command
    
    
    if (serial_command == "command1") {
      forword();
    } else if (serial_command == "command2") {
      backword();
    } else if (serial_command == "command3") {
      turnLeft();
    } else if (serial_command == "command4") {
      turnRight();
    } else if (serial_command == "command5") {
      Stop();
    } else if (serial_command == "command6") {
      turnLeft();
      delay(400);
      bt_ir_data = 5;
    } else if (serial_command == "command7") {
      turnRight();
      delay(400);
      bt_ir_data = 5;
    } else if (serial_command == "command8") {
      mode = 0;
      Stop();
    } else if (serial_command == "command9") {
      mode = 1;
    } else if (serial_command == "command10") {
      mode = 2;
    } else if (serial_command == "command11") {
      Speed = 100;
    } else if (serial_command == "command12") {
      Speed = 120;
    } else if (serial_command == "command13") {
      Speed = 140;
    } else if (serial_command == "command14") {
      Speed = 160;
    } else if (serial_command == "command15") {
      Speed = 180;
    } else if (serial_command == "command16") {
      Speed = 200;
    } else if (serial_command == "command17") {
      Speed = 215;
    } else if (serial_command == "command18") {
      Speed = 230;
    } else if (serial_command == "command19") {
      Speed = 240;
    } else if (serial_command == "command20") {
      Speed = 255;
    } else if (serial_command == "command21") {
      forwordturnLeft();
    } else if (serial_command == "command22") {
      forwordturnRight();
    } else if (serial_command == "command23") {
      backwordturnLeft();
    } else if (serial_command == "command24") {
      backwordturnRight();
    }
    
    // Add more conditions for other commands as needed
  }

  

if (irrecv.decode(&results)) {
bt_ir_data = IRremote_data();
irrecv.resume(); // Receive the next value
delay(100);
}

     if(bt_ir_data == 8){mode=0; Stop();}    //Manual Android Application and IR Remote Control Command   
else if(bt_ir_data == 9){mode=1; } //Auto Line Follower Command
else if(bt_ir_data ==10){mode=2; } //Auto Obstacle Avoiding Command
else if (bt_ir_data == 11) {
    Speed = 100;
  } else if (bt_ir_data == 12) {
    Speed = 120;
  } else if (bt_ir_data == 13) {
    Speed = 140;
  } else if (bt_ir_data == 14) {
    Speed = 160;
  } else if (bt_ir_data == 15) {
    Speed = 180;
  } else if (bt_ir_data == 16) {
    Speed = 200;
  } else if (bt_ir_data == 17) {
    Speed = 215;
  } else if (bt_ir_data == 18) {
    Speed = 230;
  } else if (bt_ir_data == 19) {
    Speed = 240;
  } else if (bt_ir_data == 20) {
    Speed = 255;
  }




if(mode==0){     
//===============================================================================
//                          Key Control Command
//=============================================================================== 
     if(bt_ir_data == 1){forword(); }  // if the bt_data is '1' the DC motor will go forward
else if(bt_ir_data == 21){forwordturnLeft(); }  // if the bt_data is '1' the DC motor will go forward     if(bt_ir_data == 1){forword(); }  // if the bt_data is '1' the DC motor will go forward
else if(bt_ir_data == 22){forwordturnRight(); }  // if the bt_data is '1' the DC motor will go forward
else if(bt_ir_data == 2){backword();}  // if the bt_data is '2' the motor will Reverse
else if(bt_ir_data == 23){backwordturnLeft();}  // if the bt_data is '2' the motor will Reverse
else if(bt_ir_data == 24){backwordturnRight();}  // if the bt_data is '2' the motor will Reverse
else if(bt_ir_data == 3){turnLeft();}  // if the bt_data is '3' the motor will turn left
else if(bt_ir_data == 4){turnRight();} // if the bt_data is '4' the motor will turn right
else if(bt_ir_data == 5){Stop(); }     // if the bt_data '5' the motor will Stop

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

long IRremote_data(){
     if(results.value==0xFF02FD){IR_data=1;}  
else if(results.value==0xFF9867){IR_data=2;} 
else if(results.value==0xFFE01F){IR_data=3;} 
else if(results.value==0xFF906F){IR_data=4;} 
else if(results.value==0xFF629D || results.value==0xFFA857){IR_data=5;} 
else if(results.value==0xFF30CF){IR_data=8;} 
else if(results.value==0xFF18E7){IR_data=9;} 
else if(results.value==0xFF7A85){IR_data=10;} 
return IR_data;
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

void forwordturnRight(){  //forword
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
analogWrite(enA, Speed-speed_low); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
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