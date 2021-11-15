#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "led/diode.h"

struct args {
	int pin;
	int intervalleSecondes;
};

int main (void) {

	pthread_t thread1;

    struct args *params = (struct args *) malloc(sizeof(struct args));
	params->pin = 1;
	params->intervalleSecondes = 1;

    //ClignotementLed((void *)params);
	pthread_create(&thread1, NULL, ClignotementLed, (void *) params);

	pthread_join(thread1, NULL);

    return EXIT_SUCCESS;
}