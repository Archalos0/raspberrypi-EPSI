#include <wiringPi.h>
#include <stdio.h>

print('En attente d\'un badge (pour quitter, Ctrl + c): ')

while (True) {
    rc522.wait_for_tag() 
    (error, tag_type) = rc522.request()

    if () {
        (error, uid) = rc522.anticoll()
    }

    if () { 
        print('Vous avez passé le badge avec l\'id : {}'.format(uid))
        time.sleep(1) 
    }
}
