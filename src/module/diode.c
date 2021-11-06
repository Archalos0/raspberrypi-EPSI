#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <wiringPi.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h> 

struct args {
	int pin;
	//int intervalMillisecond;
};

void *ClignotementLed(void *arg){

	bool isLedTurnOn = false;

	while(1){

		//if (tempsActuel - tempsDernierClignotement >= intervalMillisecond) {
			 if (isLedTurnOn == true) {
				//digitalWrite(pinLed, LOW);
				printf("pin %d Allumé\n",  ((struct args *) arg)->pin);
			} else {
				//digitalWrite(pinLed, HIGH);
				printf("pin %d Eteinte\n", ((struct args *) arg)->pin);
			}
			isLedTurnOn = !isLedTurnOn;
			sleep(0.5);
		//}
	}
	// Arrêt propre du thread
	pthread_exit(EXIT_SUCCESS);
}