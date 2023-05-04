//Motor back
int motor_back1 =A2;
int motor_back2 = A3;
int motorBenb = 10;
#define motor_backrpm 200 //Any value between 0 and 255

//Motor front
int motor_front1 =A4;
int motor_front2 = A5;
int motorAenb = 9;
#define motor_frontrpm 170 //Any value between 0 and 255
const int trigPin = 11; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor
//Define Variables
long duration;
int distance;
int L_S=2;//ir sensors
int R_S=13;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(motor_back1, OUTPUT);
  pinMode(motor_back2, OUTPUT);
  pinMode(motorBenb, OUTPUT);
  pinMode(motor_front1, OUTPUT);
  pinMode(motor_front2, OUTPUT);
  pinMode(motorAenb, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   pinMode(R_S, INPUT); // declare if sensor as input  
  pinMode(L_S, INPUT); // declare ir sensor as input
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration,cm;
  pinMode(trigPin, OUTPUT);
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
    pinMode(echoPin, INPUT);  
  duration = pulseIn(echoPin , HIGH);
  cm = (duration/2) / 28.5; //dist in crntimeters
  Serial.print(cm);
  Serial.println(); 
  delay(100);
//forward();

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){
  forward();
  delay(400);
  stop();
  delay(500);
  //deal_obstacles();
  
 }  
 
//if Right Sensor is Black and Left Sensor is White then it will call turn Right function
else if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){turn_right();}  

//if Right Sensor is White and Left Sensor is Black then it will call turn Left function
else if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){turn_left();} 
    
delay(10);
}

//exit(0);

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
void turn_left(){
  stop();
  delay(2000);
digitalWrite(motor_front1, HIGH);
digitalWrite(motor_front2, LOW);
analogWrite(motorAenb,motor_frontrpm ); 
forward();
delay(400);
}
void center_right(){
digitalWrite(motor_front1, LOW);
digitalWrite(motor_front2, HIGH);
analogWrite(motorAenb,motor_frontrpm/2 );} 

void turn_right(){
  stop();
  delay(2000);
digitalWrite(motor_front1, LOW);
digitalWrite(motor_front2, HIGH);
analogWrite(motorAenb,motor_frontrpm );  
forward();
delay(400);
// forward();
// delay(1000);

}
void center_left(){
digitalWrite(motor_front1, HIGH);
digitalWrite(motor_front2, LOW);
analogWrite(motorAenb,motor_frontrpm/2 );}
void deal_obstacles(){
  long duration,cm;
if(cm < 10){
//forward();
//delay(1000);
stop();
delay(3000);
turn_right();
delay(1000);
 forward();
 delay(1000);
 stop();
delay (3000);
turn_left();
delay(1000);
forward();
delay(1000);
stop();
delay(1000);
turn_right();
delay(1000);

}  
}