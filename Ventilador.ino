/*
 Name:		Ventilador.ino
 Created:	3/17/2020 12:38:17 PM
 Author:	PTL21166W-PAN006
*/

#include <Stepper.h>


const int stepsPerRevolution = 512;
int val = 25;
int aux = 0;
int estado = 0;
int ledPin = 13;
int foto = 0;
Stepper myStepper(stepsPerRevolution, 11, 9, 10, 8);

void setup() {
	myStepper.setSpeed(10);
	Serial.begin(9600);
	pinMode(ledPin, OUTPUT);
}

void loop() {
	digitalWrite(ledPin, HIGH);
	while (aux <= 2050)
	{
		myStepper.setSpeed(50);
		myStepper.step(-900);
		delay(2500);
		myStepper.setSpeed(70);
		myStepper.step(900);
		aux++;
		Serial.println(aux);
	}
	Serial.println("*-_Fim_-*");
	delay(10000);
}