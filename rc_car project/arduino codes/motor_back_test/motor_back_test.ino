int motor_back1 =A2;
int motor_back2 = A3;
int motorBenb = 10;
#define motor_backrpm 250
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(motor_back1, OUTPUT);
  pinMode(motor_back2, OUTPUT);
  pinMode(motorBenb, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
forward();
}
void forward(){
digitalWrite(motor_back1, LOW);
digitalWrite(motor_back2, HIGH);
analogWrite(motorBenb,motor_backrpm );
}