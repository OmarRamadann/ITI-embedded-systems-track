//Motor back
int motor_back1 =A2;
int motor_back2 = A3;
int motorBenb = 10;
#define motor_backrpm 50 //Any value between 0 and 255

//Motor front
int motor_front1 =A4;
int motor_front2 = A5;
int motorAenb = 9;
#define motor_frontrpm 90 //Any value between 0 and 255
//ir sensor
int L_S=2;
int R_S=13;
int v5=A0;
//Ultrasonic Sensor
const int trigPin = 11; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor

//Define Variables
long duration;
int distance;

void setup(){
  Serial.begin(9600);
  pinMode(v5,OUTPUT);
  pinMode(R_S, INPUT); // declare if sensor as input  
  pinMode(L_S, INPUT); // declare ir sensor as input
  pinMode(motor_back1, OUTPUT);
  pinMode(motor_back2, OUTPUT);
  pinMode(motorBenb, OUTPUT);
  pinMode(motor_front1, OUTPUT);
  pinMode(motor_front2, OUTPUT);
  pinMode(motorAenb, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){
  long duration,cm;
  digitalWrite(v5 , HIGH);
  forward();

 if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){
  forward();
  
 }  
 
//if Right Sensor is Black and Left Sensor is White then it will call turn Right function
else if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){turn_right();}  

//if Right Sensor is White and Left Sensor is Black then it will call turn Left function
else if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){turn_left();} 
    
delay(10);
}

  // digitalWrite(trigPin , HIGH);
  // delayMicroseconds(1000);
  // digitalWrite(trigPin , LOW);
//   pinMode(trigPin, OUTPUT);
//    digitalWrite(trigPin, LOW);
//    delayMicroseconds(2);
//    digitalWrite(trigPin, HIGH);
//    delayMicroseconds(10);
//    digitalWrite(trigPin, LOW);
//     pinMode(echoPin, INPUT);  

//   duration = pulseIn(echoPin , HIGH);
//   cm = (duration/2) / 28.5; //dist in crntimeters
//   Serial.print(cm);
//   Serial.println(); 
//   delay(100); 
//   if(cm < 10){
//     stop();
//     delay(1000);
//     //digitalWrite(motorA1, HIGH);
//     //digitalWrite(motorA2, LOW);
//     //analogWrite(motorAenb, motorArpm);
//     //digitalWrite(motorB1, LOW);
//     //digitalWrite(motorB2, HIGH);
//     //analogWrite(motorBenb, motorBrpm);
//     //delay(200);
//     // digitalWrite(motorB1, LOW);
//     // digitalWrite(motorB2, HIGH);
//     // analogWrite(motorBenb, motorBrpm);
//     turn_right();
//     delay(1500);
// forward();
// delay(200);
// stop();
// delay(1000);
// turn_left();
// delay(3000);
// forward();
// delay(200);
// stop();
// delay(1000);
// turn_right();
// delay(1000);
//   }
  // else{
  //   digitalWrite(motorA1, LOW);
  //   digitalWrite(motorA2, HIGH);
  //   analogWrite(motorAenb, motorArpm);
  //   digitalWrite(motorB1, HIGH);
  //   digitalWrite(motorB2, LOW);
  //   analogWrite(motorBenb, motorBrpm);
  // }


void stop(){
analogWrite(motorAenb, 0);
analogWrite(motorBenb, 0);
}
void forward(){
digitalWrite(motor_back1, LOW);
digitalWrite(motor_back2, HIGH);
analogWrite(motorBenb,motor_backrpm );
}
void backword(){
digitalWrite(motor_back1, HIGH);
digitalWrite(motor_back2, LOW);
analogWrite(motorBenb,motor_backrpm );
}
void turn_right(){
digitalWrite(motor_front1, HIGH);
digitalWrite(motor_front2, LOW);
analogWrite(motorAenb,motor_frontrpm ); 
forward(); 
}
void turn_left(){
digitalWrite(motor_front1, LOW);
digitalWrite(motor_front2, HIGH);
analogWrite(motorAenb,motor_frontrpm );  
forward();
}