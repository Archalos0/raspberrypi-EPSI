#include <wiringPi.h>
#include <stdio.h>

void RougeClignote(int red)
{
    digitalWrite(red, HIGH);
    delay(30);
	digitalWrite(red, LOW);
}

int main()
{

    wiringPiSetup();

	int green = 0;
	int red = 3;

	pinMode(red, OUTPUT);
	pinMode(green, OUTPUT);

    SDL_Init(SDL_INIT_TIMER);
    
    SDL_TimerID timer; /* Variable pour stocker le numéro du timer */
    while(1)
    {

        timer = SDL_AddTimer(30, RougeClignote, red); /* Démarrage du timer */
    }

	return 0;

}