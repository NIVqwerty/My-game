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
        txSetFillColor (RGB(133,205,181));
        Win32::RoundRect (txDC(), x, y, x+w, y+h, 30, 30);
        txSelectFont("Times New Roman", 30);
        txSetColor (TX_BLACK);
        txDrawText(x, y, x+w, y+h, text);
        }
        else
        {
        txSetColor (TX_WHITE, 3);
        txSetFillColor (RGB(71,147,121));
        Win32::RoundRect (txDC(), x, y, x+w, y+h, 30, 30);
        txSelectFont("Times New Roman", 30);
        txSetColor (TX_BLACK);
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
            Win32::TransparentBlt(txDC(), x, y, 40, 20, image, 0, 0, w, h, TX_WHITE);
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
HDC menu = txLoadImage("Pictures/menu.bmp");

Man man = {10, 620, 30, 30, 100, 100, txLoadImage("Pictures/man.bmp"), 0};
Lock lock ={1150,42,49,50,txLoadImage("Pictures/Lock.bmp"),true};
Key key ={153,180,50,25,txLoadImage("Pictures/Key.bmp"),true};
int x_man_old, y_man_old;
string PAGE = "menu";

Button btn0 = {540, 200, 200, 40, "������", true};
Button btn1 = {540, 250, 200, 40, "����������", true};
Button btn2 = {540, 350, 200, 40, "�����", true};
Button btn3 = {5, 5, 200, 40, "�����", true};
Button btn4 = {540, 300, 200, 40, "�� ������", true};






    while(!btn2.click())
    {
        txClear();
        txBegin();
        btn2.visible = true;
        if(PAGE == "menu")
        {
            txBitBlt(txDC(), 0, 0, 1280, 820, menu);
            btn0.draw();
            btn1.draw();
            btn2.draw();
            btn4.draw();

            if(btn0.click())
            {
                PAGE = "game";
            }
            if(btn1.click())
            {
                PAGE = "rules";
            }
            if(btn4.click())
            {
                PAGE = "author";
            }
            txSetFillColor (TX_BLACK);
        }
        if(PAGE == "rules")
        {
            btn3.draw();
            if(btn3.click())
            {
                PAGE = "menu";
            }
            btn2.visible = false;
            txBitBlt(txDC(), 0, 0, 1280, 820, menu);
            txSelectFont("Times New Roman", 30);
            txSetColor (TX_BLACK);
            txDrawText(84, 254, 44+600, 254+100, "Esc-����� � ����");
            txDrawText(84, 294, 84+600, 294+100, "W-�����");
            txDrawText(84, 324, 84+600, 324+100, "A-�����");
            txDrawText(84, 354, 84+600, 354+100, "S-����");
            txDrawText(84, 384, 84+600, 384+100, "D-������");
            btn3.draw();
        }
        if(PAGE == "game")
        {

        txBitBlt(txDC(), 0, 0, 1280, 820, karta);
        key.draw();
        lock.draw();
        man.draw();
        txSetColor(RGB(0, 0, 0), 15);


        x_man_old = man.x;
        y_man_old = man.y;
//����������
        if(GetAsyncKeyState('S'))
        {
            man.y += 5;
            man.yn_kard = 0;
            man.xn_kard += 1;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState('A'))
        {
            man.x -= 5;
            man.xn_kard += 1;
            man.yn_kard = 1;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState('D'))
        {
            man.x += 5;
            man.xn_kard += 1;
            man.yn_kard = 2;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState('W'))
        {
            man.y -= 5;
            man.yn_kard = 3;
            man.xn_kard += 1;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
//----------------

//�������������� �� �������
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
 // �������������� � ������
         if( man.x<key.x+key.w && man.x+11>key.x &&
            man.y<key.y+key.h && man.y+11>key.y)
        {
            lock.visible = false;
            key.visible = false;

        }
 //---------------------
 //�������������� � ������
      if(lock.visible == true)
      {


            if( man.x<lock.x+lock.w && man.x+11>lock.x &&
            man.y<lock.y+lock.h && man.y+11>lock.y)
            {
                man.x = x_man_old;
                man.y = y_man_old;
            }
      }
 //---------------------
       if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            btn2.visible = false;
            txSetFillColor (TX_WHITE);
            txSetColor (TX_BLACK);
        }
        if(PAGE == "author")
        {
            btn3.draw();
            if(btn3.click())
            {
                PAGE = "menu";
            }
            btn2.visible = false;
            txBitBlt(txDC(), 0, 0, 1280, 820, menu);
            txSelectFont("Times New Roman", 30);
            txSetColor (TX_BLACK);
            txDrawText(84, 254, 44+1000, 254+100, "������ �� ����- https://github.com/NIVqwerty/My-game.git");
            txDrawText(84, 294, 84+600, 294+100, "��������� ������ - https://t.me/QwertyHoh");
            btn3.draw();
        }
        txEnd();
        txSleep(50);

    }
txDeleteDC(karta);
txDeleteDC(menu);


txDisableAutoPause();
return 0;
}

