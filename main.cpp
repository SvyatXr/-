#include "TXLib.h"

void drawSky()
{
    txSetColor (TX_LIGHTBLUE);
    txSetFillColor (TX_LIGHTBLUE);
    txRectangle (0, 0, 800, 600);
}

void drawSun(int x)
{
    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txCircle (x, 100, 50);
}

void drawCloud(int x)
{ //x = 320
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txEllipse(x+445-320, 70, x+745-320, 160);
    txEllipse(x+320-320, 70, x+570-320, 170);
    txEllipse(x+400-320, 20, x+675-320, 130);
}

void drawMan()
{
    txSetColor (TX_BLACK);
    txSetFillColor (TX_WHITE);
    txLine (660, 480, 680, 440);
    txLine (680, 440, 705, 480);
    txLine (680, 440, 680, 360);
    txLine (690, 360, 660, 420);
    txLine (670, 360, 700, 420);
    txCircle (680, 360, 20);
    //лицо
    txLine (688, 370, 672, 370);
    txSetFillColor (TX_LIGHTBLUE);
    txCircle (688, 358, 4);
    txCircle (672, 358, 4);
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

    int xSun = 100;
    int xCloud = 320;


    while(xSun<1000)
    {

        drawSky();
        drawSun(xSun);
        drawCloud(xCloud);
        drawTrava();
        drawhouse();
        drawMan();

        xSun += 5;
        xCloud -= 10;
        txSleep(10);

    }




txTextCursor (false);
return 0;
}
