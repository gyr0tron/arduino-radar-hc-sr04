#include<Servo.h>
const int soundEchoPin = 12; //red
const int motorSignalPin = 6; //ylw
const int startingAngle = 1;
const int minimumAngle = 1;
const int maximumAngle = 179;
const int rotationSpeed = 1;

Servo motor;
void setup(void) 
{
    //pinMode(soundTriggerPin, OUTPUT);
    
    motor.attach(motorSignalPin);
    Serial.begin(9600);
}
void loop(void)
{
    static int motorAngle = startingAngle;
    static int motorRotateAmount = rotationSpeed;

    motor.write(motorAngle);
    delay(30);
     SerialOutput(motorAngle, CalculateDistance());
    
motorAngle += motorRotateAmount;
    if(motorAngle <= minimumAngle || motorAngle >= maximumAngle) {
        motorRotateAmount = -motorRotateAmount;
    }}
int CalculateDistance(void)
{
    pinMode(soundEchoPin, OUTPUT);
   
    //digitalWrite(soundTriggerPin, LOW);
    //delayMicroseconds(2);
    digitalWrite(soundEchoPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(soundEchoPin, LOW);
    pinMode(soundEchoPin, INPUT);
      long duration = pulseIn(soundEchoPin, HIGH);
    float distance = duration * 0.017F;
    return int(distance);
}
void SerialOutput(const int angle, const int distance)
{
    String angleString = String(angle);
    String distanceString = String(distance);
        Serial.println(angleString + "," + distanceString);
}

