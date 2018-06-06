//OBSTACLE DETECTOR
#define trig 8
#define echo 11
#define motor1 5 //right
#define motor11 6 //right
#define motor2 9  // left
#define motor22 10 //left
#define high1 2
#define high2 3
#define high3 13

int duration =0, distance=0; 
void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
   pinMode(high1,INPUT);
  pinMode(high2,INPUT);
  pinMode(high3,INPUT);
  digitalWrite(high1,HIGH);
  digitalWrite(high2,HIGH);
  digitalWrite(high3,HIGH);
  pinMode(motor1, OUTPUT);
  pinMode(motor11, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor22, OUTPUT);
  analogWrite(motor1,255);  
  analogWrite(motor11,0);  
  analogWrite(motor2,255);  
  analogWrite(motor22,0);  
}

void loop() {
  // put your main code here, to run repeatedly:
   analogWrite(motor1,255);  
  analogWrite(motor11,0);  
  analogWrite(motor2,255);  
  analogWrite(motor22,0);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance = (duration*0.034)/2;
  
  if(distance<=10){
    //delay(1000);
    analogWrite(motor1,255);  
    analogWrite(motor11,0);  
    analogWrite(motor2,0);  
    analogWrite(motor22,200);
    delay(1000); // I used delay here so that bot can turn properly.
  }
  
}

