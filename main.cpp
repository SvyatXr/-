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

void drawMan(int x, int y, int xLegs)
{
//x=680 y=440
    txSetColor (TX_BLACK);
    txSetFillColor (TX_WHITE);
    txLine (x+660-680+xLegs, y+480-440, x+680-680, y+440-440);       //���� �����
    txLine (x+680-680, y+440-440, x+705-680-xLegs, y+480-440);       //���� ������
    txLine (x+680-680, y+440-440, x+680-680, y+360-440);
    txLine (x+690-680, y+360-440, x+660-680, y+420-440);
    txLine (x+670-680, y+360-440, x+700-680, y+420-440);
    txCircle (x+680-680, y+360-440, 20);
    //����
    txLine (x+688-680, y+370-440, x+672-680, y+370-440);
    txSetFillColor (TX_LIGHTBLUE);
    txCircle (x+688-680, y+358-440, 4);
    txCircle (x+672-680, y+358-440, 4);

    txSleep(20);
}
void drawhouse()
{
    txSetColor (TX_WHITE);
    txSetFillColor (TX_BROWN);
    //����������� �����
    txRectangle (100, 360, 360, 600);
    //������� �����
    POINT stena[4] = {{360, 600}, {600, 420}, {600, 200}, {360, 360}};
    txPolygon (stena, 4);
    //����������� �����
    txSetFillColor (TX_RED);
    POINT krysha[3] = {{100, 360}, {220, 220}, {360, 360}};
    txPolygon (krysha, 3);
    //���� �����
    POINT krysha2[4] = {{220, 220}, {360, 360}, {600, 200}, {460, 110}};
    txPolygon (krysha2, 4);
    //�����
    txSetFillColor (TX_BROWN);
    txRectangle (390, 170, 430, 280);
    //����
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
    txEllipse(x+400-380, y+150-140, x+450-380, y+180-140);
    txEllipse(x+390-380, y+160-140, x+440-380, y+120-140);
    txEllipse(x+310-380, y+110-140, x+190-380, y+190-140);
    txEllipse(x+410-380, y+120-140, x+400-380, y+180-140);
    txEllipse(x+370-380, y+170-140, x+250-380, y+100-140);
    txEllipse(x+460-380, y+180-140, x+299-380, y+150-140);
    txEllipse(x+310-380, y+190-140, x+410-380, y+110-140);
}

void drawTree()
{
    txSetColor (TX_BROWN);
    txSetFillColor (TX_BROWN);
    txRectangle (540, 420, 560, 550);
    txSetColor (TX_LIGHTGREEN);
    txSetFillColor (TX_LIGHTGREEN);
    txEllipse(500, 150, 600, 450);
}


void drawText(int y, int sizeFont, const char* text)
{
     txSetColor (TX_WHITE);
     txSelectFont ("Times New Roman", sizeFont, sizeFont/3, FW_BOLD, true, false, false, 0);
     txDrawText (0, y, 800, y+500, text);
}

void drawFonText()
{
     txSetColor (TX_BLACK);
     txSetFillColor (TX_BLACK);
     txRectangle (0, 0, 800, 600);
}

int main()
{

txCreateWindow (800, 600);

    int xSun = 100;
    int xCloud = 320;
    int xMan = 680;
    int yMan = 440;
    int xLegs = 0;
    int xLuna = -150;
    int xSmoke = 380;
    int ySmoke = 140;
    int yText = 650;

    txPlaySound ("star-wars-imperial-march.wav");



    while(yText > -400)
    {
       txBegin();
       drawFonText();
       drawText(yText, 25, "������������ ����������.");
       drawText(yText+100, 55, "������ � ��-----------����:)");
       drawText(yText+150, 20, "� ������� ����- �����-�� ���������� �������.");
       txEnd();
       yText -= 5;
       txSleep(10);
 }


    while(xSun<1000)
    {
        txBegin();
        drawSky(TX_LIGHTBLUE);
        drawSun(xSun);
        drawCloud(xCloud);
        drawTrava();
        drawhouse();
        drawSmoke(xSmoke, ySmoke);
        drawMan(xMan, yMan, xLegs);

        txEnd();
        if(ySmoke<-60)
        {
            xSmoke = 380;
            ySmoke = 140;
        }
        xSun += 3;
        xCloud -= 10;
        xSmoke -= 2;
        ySmoke -= 3;
        xMan += 0;
        xLegs += 10;
        txSleep(5);

        txBegin();
        drawSky(TX_LIGHTBLUE);
        drawSun(xSun);
        drawCloud(xCloud);
        drawTrava();
        drawhouse();
        drawSmoke(xSmoke, ySmoke);
        drawMan(xMan, yMan, xLegs);
        txEnd();
        if(ySmoke<-60)
        {
            xSmoke = 380;
            ySmoke = 140;
        }
        xSun += 3;
        xCloud -= 10;
        xSmoke -= 2;
        ySmoke -= 3;
        xMan += 0;
        xLegs -= 10;
        txSleep(7);

    }

    while(xLuna<1000)
    {
        txBegin();
        drawSky(TX_BLACK);
        drawLuna(xLuna);
        drawTrava();
        drawhouse();
        drawMan(xMan, yMan, xLegs);
        txEnd();

        xLuna += 5;
        xMan += 2;
        yMan += 2;
        txSleep(7);
    }



    xLuna = -150;
    xMan = -20;
    yMan = 375;
    while(xLuna<1000)
    {
        txBegin();
        drawSky(TX_BLACK);
        drawLuna(xLuna);
        drawTrava();
        drawTree();
        drawMan(xMan, yMan, xLegs);
        txEnd();

        xLuna += 5;
        xMan += 2;
        yMan += 1;
        txSleep(7);
    }

    yText = 650;
    while(yText > -560)
    {
       txBegin();
       drawFonText();
       drawText(yText, 35, "������������ ����������.");
       drawText(yText+70, 40, "������ � ��-----------����:)");
       drawText(yText+100, 40, "���������:");
       drawText(yText+150, 25, "�  ���� ����- ��� ����� �������.");
       drawText(yText+170, 25, "�  ���� ������- ������ ������� ���������.");
       drawText(yText+190, 25, "�  ���� ����- ���� ������ �������.");
       drawText(yText+210, 25, "�  ���� �����- ����� ������� ��������.");
       drawText(yText+230, 25, "�  ���� ������ - ������ ������� �����������.");
       drawText(yText+250, 25, "�  ���� ����- ��� ����� �������.");
       drawText(yText+270, 25, "�  ���� ������- ����� ������� ���������.");
       drawText(yText+290, 25, "�  ���� ������-�� ����������� ��������- �����-�� ���������� �������.");
       drawText(yText+350, 100, "�����!");


       txEnd();
       yText -= 5;
       txSleep(10);
 }



txTextCursor (false);
return 0;
}

