#include<Servo.h>

const int trig = 2;
const int echo = 3;
long duration = 0;
int vel = 255;

Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(4);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  //initial position of servos

  servo.write(0);

  ////////////sonar//////
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  long distance_cm = ((duration * 0.034) / 2);
  if (distance_cm > 0 && distance_cm <= 7) {
    servo.write(80);
    Serial.println(distance_cm);
    Serial.println("cm");
  }
  else if (distance_cm > 7) {
    servo.write(0);
    Serial.println(distance_cm);
    Serial.println("cm");
  }
  delay(500);
}
