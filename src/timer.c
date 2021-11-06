#include <wiringPi.h>
#include <stdio.h>

SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

int RougeClignote(int intervalle, int *pin);

int RougeClignote(int intervalle, int *pin)
{
    digitalWrite(red, HIGH);
    delay(50);
    digitalWrite(red, LOW);
}

int main()
{

    wiringPiSetup();

	int green = 0;
	int red = 3;

	pinMode(red, OUTPUT);
	pinMode(green, OUTPUT);
    
    SDL_TimerID timer; /* Variable pour stocker le numéro du timer */
    while(1)
    {
        timer = SDL_AddTimer(30, RougeClignote, red); /* Démarrage du timer */
    }

	return 0;

}
