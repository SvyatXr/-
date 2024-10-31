#include "TXLib.h"

void drawSky(COLORREF color)
{
//TX_LIGHTBLUE
    txSetColor (TX_LIGHTBLUE);
    txSetFillColor (color);
    txRectangle (0, 0, 800, 600);
}

void drawSun(int x)
{
    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txCircle (x, 100, 70);
}

void drawCloud(int x)
{ //x = 320
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txEllipse(x+445-320, 70, x+745-320, 160);
    txEllipse(x+320-320, 70, x+570-320, 170);
    txEllipse(x+400-320, 20, x+675-320, 130);
    txCircle(410, 160, 10);

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
    //труба
    txSetFillColor (TX_BROWN);
    txRectangle (390, 170, 430, 280);
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


void drawLuna(int x)
{
    txSetColor (TX_LIGHTGRAY);
    txSetFillColor (TX_LIGHTGRAY);
    txCircle (x, 150, 50);
}

void drawSmoke(int x, int y)
{
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txEllipse(x+380-380, y+140-140, x+430-380, y+170-140);
}


int main()
{

txCreateWindow (800, 600);

    int xSun = 100;
    int xCloud = 320;
    int xLuna = -150;
    int xSmoke = 380;
    int ySmoke = 140;


    while(xSun<1000)
    {
        txBegin();
        drawSky(TX_LIGHTBLUE);
        drawSun(xSun);
        drawCloud(xCloud);
        drawTrava();
        drawhouse();

        drawSmoke(xSmoke, ySmoke);

        drawMan();
        txEnd();

        xSun += 5;
        xCloud -= 10;
        xSmoke -= 2;
        ySmoke -= 1;
        txSleep(10);

    }
    while(xLuna<1000)
    {
        txBegin();
        drawSky(TX_BLACK);
        drawLuna(xLuna);
        drawTrava();
        drawhouse();
        drawMan();
        txEnd();

        xLuna += 5;
        txSleep(10);
    }

txTextCursor (false);
return 0;
}
