//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <���������>\n
//! @brief      <������������>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <�����>, <���> (<���> <�����>)
//! @date       <����>
//!
//! @par        ��������������
//!           - (TODO: ������ ��������)
//!
//! @todo     - (TODO: ������ ��������� ������ �� ����� �����)
//!
//! @bug      - (TODO: ������ ��������� ������ � ���� �����)
//!
//! @par        ������� ��������� �����
//!           - ������ 0.01 Alpha
//!             - ������ ��� ��������� ����
//!
//}=======================================================================

#include "TXLib.h"
struct Button
{
    int x;
    int y;
    int w;
    int h;
    const char* text;
    bool visible;

    void draw()
    {
        if(txMouseX()>x && txMouseX()<x+w &&
                txMouseY()>y && txMouseY()<y+h)
        {
        txSetColor (TX_WHITE, 3);
        txSetFillColor (TX_ORANGE);
        Win32::RoundRect (txDC(), x, y, x+w, y+h, 30, 30);
        txSelectFont("Times New Roman", 30);
        txSetColor (TX_RED);
        txDrawText(x, y, x+w, y+h, text);
        }
        else
        {
        txSetColor (TX_WHITE, 3);
        txSetFillColor (TX_YELLOW);
        Win32::RoundRect (txDC(), x, y, x+w, y+h, 30, 30);
        txSelectFont("Times New Roman", 30);
        txSetColor (TX_RED);
        txDrawText(x, y, x+w, y+h, text);
        }
    }

    bool click()
    {
        return(txMouseX()>x && txMouseX()<x+w &&
                txMouseY()>y && txMouseY()<y+h &&
                txMouseButtons() == 1 && visible);
    }
};

struct Man
{
    int x;
    int y;
    int w_;
    int h_;
    int w;
    int h;
    HDC pic;
    int xn_kard;
    int yn_kard;



    void draw()
    {
        Win32::TransparentBlt(txDC(), x, y, w_, h_, pic, xn_kard*w,yn_kard*h, w, h, TX_WHITE);
    }

};

struct Key
{
   int x;
   int y;
   int w;
   int h;
   HDC image;
   bool visible;


    void draw()
    {
        if (visible)
        {
            Win32::TransparentBlt(txDC(), x, y, 50, 25, image, 0, 0, w, h, TX_WHITE);
        }
    }
};

struct Lock
{
   int x;
   int y;
   int w;
   int h;
   HDC image;
   bool visible;


    void draw()
    {
        if (visible)
        {
            Win32::TransparentBlt(txDC(), x, y, 35, 35, image, 0, 0, w, h, TX_WHITE);
        }
    }
};

int main()
{
txCreateWindow (1280, 820);
txTextCursor (false);
HDC karta = txLoadImage("Pictures/Map.bmp");
HDC menu = txLoadImage("Pictures/Fon.bmp");

Man man = {10, 620, 30, 30, 100, 100, txLoadImage("Pictures/man.bmp"), 0};
Lock lock ={1190,40,49,50,txLoadImage("Pictures/Lock.bmp"),true};
Key key ={158,189,50,25,txLoadImage("Pictures/Key.bmp"),true};
int x_man_old, y_man_old;



    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txClear();
        txBegin();
        txBitBlt(txDC(), 0, 0, 1280, 820, karta);
        key.draw();
        lock.draw();
        man.draw();
        txSetColor(RGB(0, 0, 0), 15);


        x_man_old = man.x;
        y_man_old = man.y;
//����������
        if(GetAsyncKeyState(VK_DOWN))
        {
            man.y += 5;
            man.yn_kard = 0;
            man.xn_kard += 1;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            man.x -= 5;
            man.xn_kard += 1;
            man.yn_kard = 1;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState(VK_RIGHT))
        {
            man.x += 5;
            man.xn_kard += 1;
            man.yn_kard = 2;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState(VK_UP))
        {
            man.y -= 5;
            man.yn_kard = 3;
            man.xn_kard += 1;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
//----------------

//������ � ����� ����� ���������
        for(int x=man.x+1; x<man.x+man.w_; x+=11)
            {
                for(int y=man.y+2; y<man.y+man.h_; y+=12)
                {
                    if(txGetPixel(x, y) == RGB(0, 0, 0))
                    {
                        man.x = x_man_old;
                        man.y = y_man_old;
                    }
                }
            }
 //----------------
         for(int x=man.x+1; x<man.x+man.w_; x+=11)
            {
                for(int y=man.y+2; y<man.y+man.h_; y+=12)
                {
                    if(txGetPixel(x, y) == RGB(245, 207, 17))
                    {
                        key.visible = false;
                        lock.visible = false;
                    }
                }
            }

        txEnd();
        txSleep(50);

    }
txDeleteDC(karta);
txDeleteDC(menu);


txDisableAutoPause();
return 0;
}

