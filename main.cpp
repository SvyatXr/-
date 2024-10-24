#include "TXLib.h"

void drawSky()
{
    txSetColor (TX_LIGHTBLUE);
    txSetFillColor (TX_LIGHTBLUE);
    txRectangle (0, 0, 800, 600);
}

void drawSun()
{
    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txCircle (100, 100, 50);
}
void drawOblako()
{
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txCircle (700, 100, 200);

}

void drawhouse()
{
    txSetColor (TX_WHITE);
    txSetFillColor (TX_BROWN);
    //фронтвльная стена
    txRectangle (100, 360, 360, 600);
    //боковая стена
    POINT stena[4] = {{360, 600}, {600, 420}, {600, 200}, {360, 360}};
    txPolygon (stena, 4);
    //фронтальная крыша
    txSetFillColor (TX_RED);
    POINT krysha[3] = {{100, 360}, {220, 220}, {360, 360}};
    txPolygon (krysha, 3);
    //скат крыши
    POINT krysha2[4] = {{220, 220}, {360, 360}, {600, 200}, {460, 110}};
    txPolygon (krysha2, 4);
    //окно
    txSetFillColor (TX_YELLOW);
    txRectangle (170, 410, 280, 520);

}

void drawTrava()
{
    txSetColor (TX_GREEN);
    txSetFillColor (TX_GREEN);
    txRectangle (0, 375, 800, 600);

}



int main()
{

txCreateWindow (800, 600);

    drawSky();

    drawSun();

    drawTrava();

    drawhouse();





txTextCursor (false);
return 0;
}

