#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <wiringPi.h>
#include <time.h>
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
				digitalWrite(((struct args *) arg)->pin, LOW);
			} else {
			    digitalWrite(((struct args *) arg)->pin, HIGH);
			}
			isLedTurnOn = !isLedTurnOn;
			timespec_get(&tempsDernierClignotement, TIME_UTC );
		}
	}
	
	// Arrêt propre du thread
	pthread_exit(EXIT_SUCCESS);
}