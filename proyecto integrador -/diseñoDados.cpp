#include <iostream>
#include "rlutil.h"

using namespace std;

void dadoDe2 (){
rlutil::locate(posx+1,posy);
cout<< (char) 220;
rlutil::locate(posx+5,posy+2);
cout<< (char) 223;
}

void dadoDe3 (){
rlutil::locate(posx+3,posy+1);
cout<< (char) 254;
rlutil::locate(posx+1,posy);
cout<< (char) 220;
rlutil::locate(posx+5,posy+2);
cout<< (char) 223;
}
