#include "TXLib.h"

int main()
{

txCreateWindow (800, 600);

    //небо
    txSetColor (TX_LIGHTBLUE);
    txSetFillColor (TX_LIGHTBLUE);
    txRectangle (0, 0, 800, 600);


    //солнце
    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txCircle (100, 100, 50);


    //дом
    txSetColor (TX_WHITE);
    txSetFillColor (TX_BROWN);
    txRectangle (100, 360, 360, 600);

    txSetFillColor (TX_RED);
    POINT krysha[3] = {{100, 360}, {220, 220}, {360, 360}};
    txPolygon (krysha, 3);

    POINT krysha2[4] = {{220, 220}, {360, 360}, {600, 200}, {460, 110}};
    txPolygon (krysha2, 4);

    txLine (360, 600, 600, 420);
    txLine (600, 200, 600, 420);


    POINT stena[4] = {{220, 220}, {360, 360}, {600, 200}, {460, 110}};
    txPolygon (stena, 4);




txTextCursor (false);
return 0;
}

