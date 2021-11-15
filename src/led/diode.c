#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <wiringPi.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h> 

struct args {
	int pin;
	int intervalleSecondes;
};

void *ClignotementLed(void *arg){

	bool estLaPremiereEntree = true;
	bool isLedTurnOn = false;

	struct timespec tempsActuel;
	struct timespec tempsDernierClignotement;

	while(1){
		

		timespec_get(&tempsActuel, TIME_UTC );
		if (estLaPremiereEntree || tempsActuel.tv_sec - tempsDernierClignotement.tv_sec >= ((struct args *) arg)->intervalleSecondes) {
			
			estLaPremiereEntree = false;
			
			if (isLedTurnOn == true) {
				//digitalWrite(pinLed, LOW);
				printf("pin %d Allumé\n",  ((struct args *) arg)->pin);
			} else {
				//digitalWrite(pinLed, HIGH);
				printf("pin %d Eteinte\n", ((struct args *) arg)->pin);
			}
			isLedTurnOn = !isLedTurnOn;
			timespec_get(&tempsDernierClignotement, TIME_UTC );
		}
	}
	// Arrêt propre du thread
	pthread_exit(EXIT_SUCCESS);
}