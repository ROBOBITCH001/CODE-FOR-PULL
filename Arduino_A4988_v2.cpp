#include <Arduino.h>
#include <A4988.h>

const int sw = 13;
const int led= 12;
const int Msl = 10; 
const int Ms2 = 9; 
const int Ms3 = 8; 
const int Sleep = 7; 
const int Step = 6; 
const int Dire = 5;
const int spr = 200;
int RPM= 10;
int Microsteps = 2;
int val;
A4988 stepper(spr, Dire, Step, Msl, Ms2, Ms3);

void setup() {
    Serial.begin(9600);
    pinMode(sw, INPUT);
    pinMode(led, OUTPUT);
    pinMode(Step, OUTPUT);
    pinMode(Dire, OUTPUT) ;
    pinMode(Sleep, OUTPUT);
    digitalWrite(Step, LOW);
    digitalWrite(Dire, LOW);
    digitalWrite(led, HIGH);
    delay(1000);
    stepper.begin(RPM,Microsteps);

void loop() {
    digitalWrite(Dire, HIGH);
    digitalWrite(Sleep, HIGH);
    val = digitalRead(sw);
    if(val == LOW) {
        digitalWrite(led, LOW);
        stepper.move(80);
        digitalWrite(led, HIGH);
        delay(500);
    }
    delay(1000);
}
