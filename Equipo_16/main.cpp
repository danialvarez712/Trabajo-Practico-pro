#include <iostream>
#include "menu.h"
#include "rlutil.h"
#include "juego.h"

using namespace std;

int main(){

    srand(time(0));
    rlutil::hidecursor();
    rlutil::saveDefaultColor();

    menu();

    return 0;
}
