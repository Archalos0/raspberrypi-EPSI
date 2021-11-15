#include <wiringPi.h>
#include <stdio.h>

SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
RFID_UID = []

int main(){

wiringPiSetup();

	int green = 0;
	int red = 3;

	pinMode(red, OUTPUT);
	pinMode(green, OUTPUT);

    while(1){

        if(RFID_UID == []){
            print('Badge est autorisé !');
            digitalWrite(green,HIGH);
        }
        else{
            print('Badge non autorisé !');
            digitalWrite(red, HIGH);
        }
    }

    return 0;
}