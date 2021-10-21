#include <wiringPi.h>
#include <stdio.h>


int main(void)
{

	wiringPiSetup();

	int green = 0;
	int red = 3;

	pinMode(red, OUTPUT);
	pinMode(green, OUTPUT);


	while(1){

		digitalWrite(red, HIGH);
		digitalWrite(green, LOW);
		delay(500);
		digitalWrite(red,LOW);
		digitalWrite(green,HIGH);
		delay(500);

	}

	return 0;


}



