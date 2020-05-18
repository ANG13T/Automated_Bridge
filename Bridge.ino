#include <Servo.h>  

Servo blocker;

int angle = 0; 
   
int trigPin = 2;
int echoPin = 3;

long duration;
int distance;

void setup() {
  Serial.begin (9600);
  // put your setup code here, to run once:
  pinMode (trigPin, OUTPUT); 
  pinMode (echoPin, INPUT);
  blocker.attach(9);
  close();
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  //Check if car is close
  if(distance > 300){
    open();
    delay(2500);
    close();
  }
}

void close(){
  for(angle = 130; angle>=30; angle-=3)     // command to move from 180 degrees to 0 degrees 
  {                                
    blocker.write(angle);              //command to rotate the servo to the specified angle
    delay(15);                       
  } 
}

void open(){
  for(angle = 30; angle < 130; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    blocker.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  }  
}
