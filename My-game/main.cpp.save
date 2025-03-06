//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <Заголовок>\n
//! @brief      <Подзаголовок>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <Автор>, <Год> (<Имя> <Почта>)
//! @date       <Дата>
//!
//! @par        Протестировано
//!           - (TODO: список платформ)
//!
//! @todo     - (TODO: список ближайших планов по этому файлу)
//!
//! @bug      - (TODO: список найденных ошибок в этом файле)
//!
//! @par        История изменений файла
//!           - Версия 0.01 Alpha
//!             - Только что созданный файл
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
HDC kartaezy = txLoadImage("Pictures/Mapezy.bmp");
HDC minikarta = txLoadImage("Pictures/miniMap.bmp");
HDC minikartaezy = txLoadImage("Pictures/miniMapezy.bmp");
HDC menu = txLoadImage("Pictures/menu.bmp");
HDC MG = txLoadImage("Pictures/LockGame.bmp");

Man man = {10, 620, 30, 30, 100, 100, txLoadImage("Pictures/man.bmp"), 0};
Lock lock ={1150,42,49,50,txLoadImage("Pictures/Lock.bmp"),true};
Key key ={153,180,50,25,txLoadImage("Pictures/Key.bmp"),true};
int x_man_old, y_man_old;
string PAGE = "menu";

Button btn0 = {540, 200, 200, 40, "Играть", true};
Button btn1 = {540, 250, 200, 40, "Управление", true};
Button btn2 = {540, 350, 200, 40, "Выход", true};
Button btn3 = {5, 5, 200, 40, "Назад", true};
Button btn4 = {540, 300, 200, 40, "Об авторе", true};
Button btn5 = {560, 380, 70, 40, "ДА", true};
Button btn6 = {650, 380, 70, 40, "НЕТ", true};
Button btn7 = {150, 394, 457, 40, "Лёгкий", true};
Button btn8 = {690, 394, 457, 40, "Сложный", true};
Button btn9 = {500, 300, 250, 60, "Следующий уровень", true};
Button btn10 = {350, 300, 250, 60, "Заново", true};
Button btn11 = {650, 300, 250, 60, "В меню", true};







    while(!btn5.click())
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
                PAGE = "startgame";
            }
            if(btn1.click())
            {
                PAGE = "rules";
            }
            if(btn4.click())
            {
                PAGE = "author";
            }
            if(btn2.click())
            {
                PAGE = "leave";
            }
            txSetFillColor (TX_BLACK);
        }
        if(PAGE == "leave")
        {
        btn3.draw();
        //Возврат в меню
        if(btn6.click())
        {
            PAGE = "menu";
        }
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            PAGE = "menu";
        }
        //---------------------
        btn2.visible = false;
        txBitBlt(txDC(), 0, 0, 1280, 820, menu);
        txSelectFont("Times New Roman", 30);
        txSetColor (TX_BLACK);
        txDrawText(304, 304, 44+900, 254+100, "Вы уверенны что хотите выйти?");

        btn5.draw();
        btn6.draw();

        }
        if(PAGE == "rules")
        {
            //Возврат в меню
            if(btn3.click())
            {
                PAGE = "menu";
            }
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            //------------------
            btn2.visible = false;
            txBitBlt(txDC(), 0, 0, 1280, 820, menu);
            txSelectFont("Times New Roman", 30);
            txSetColor (TX_BLACK);
            txDrawText(120, 254, 44+600, 254+100, "Esc-выход в меню");
            txDrawText(84, 294, 84+500, 294+100, "W-вверх");
            txDrawText(84, 324, 84+500, 324+100, "A-влево");
            txDrawText(80, 354, 84+500, 354+100, "S-вниз");
            txDrawText(100, 384, 84+500, 384+100, "D-вправо");
            btn3.draw();
        }
        if(PAGE == "startgame")
        {
        txBitBlt(txDC(), 0, 0, 1280, 820, menu);
        txBitBlt(txDC(), 150, 100, 457, 289, minikartaezy);
        txBitBlt(txDC(), 690, 100, 457, 289, minikarta);
        btn3.draw();
        btn7.draw();
        btn8.draw();
        txDrawText(550, 50, 550+300, 50+50, "Выбирете уровень:");
            //Возврат в меню
            if(btn3.click())
            {
                PAGE = "menu";
            }
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            //---------------------
            if(btn8.click())
            {
                PAGE = "game";
                man.x=20;
                lock.visible = true;
                key.visible = true;
            }
             if(btn7.click())
            {
                PAGE = "1game";
                man.x=20;
                lock.visible = true;
                key.visible = true;
            }
        }
        if(PAGE == "game")
        {
        txBitBlt(txDC(), 0, 0, 1280, 820, karta);
        key.draw();
        lock.draw();
        man.draw();
        txSetColor(RGB(0, 0, 0), 15);
        lock.x =1150;
        lock.y =42;
        key.x = 153;
        key.y = 180;
        man.w_ =30;
        man.h_ =30;
        x_man_old = man.x;
        y_man_old = man.y;
//Управление
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
        if( man.x>1167)
        {
         btn10.draw();
         btn11.draw();
        }
        if(btn10.click())
            {
                man.x=20;
                PAGE = "1game";
                lock.visible = true;
                key.visible = true;
            }
        if(btn11.click())
        {

            PAGE = "menu";

        }
//Взаимодействие со стенами
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
 // Взаимодействие с ключом
         if( man.x<key.x+key.w && man.x+11>key.x &&
            man.y<key.y+key.h && man.y+11>key.y)
        {
            lock.visible = false;
            key.visible = false;

        }
 //---------------------
 //Взаимодействие с замком
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
                PAGE = "startgame";
            }
            btn2.visible = false;
            txSetFillColor (TX_WHITE);
            txSetColor (TX_BLACK);
        }
        if(PAGE == "1game")
        {

        txBitBlt(txDC(), 0, 0, 1280, 820, kartaezy);
        key.draw();
        lock.draw();
        man.draw();
        txSetColor(RGB(0, 0, 0), 15);
        lock.x =965;
        lock.y =564;
        key.x = 472;
        key.y = 578;
        man.w_ =40;
        man.h_ =40;
        x_man_old = man.x;
        y_man_old = man.y;
//Управление
        if(GetAsyncKeyState('S'))
        {
            man.y += 6;
            man.yn_kard = 0;
            man.xn_kard += 1;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState('A'))
        {
            man.x -= 6;
            man.xn_kard += 1;
            man.yn_kard = 1;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState('D'))
        {
            man.x += 6;
            man.xn_kard += 1;
            man.yn_kard = 2;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState('W'))
        {
            man.y -= 6;
            man.yn_kard = 3;
            man.xn_kard += 1;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
//----------------
//Преход на следующий уровнь
        if( man.x>1000)
        {
         btn9.draw();
        }
        if(btn9.click())
            {
                man.x=20;
                PAGE = "game";
                lock.visible = true;
                key.visible = true;
            }
//-----------------------------
//Взаимодействие со стенами
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
//----------------------
// Взаимодействие с ключом
         if( man.x<key.x+key.w && man.x+11>key.x &&
            man.y<key.y+key.h && man.y+11>key.y)
        {
            lock.visible = false;
            key.visible = false;

        }
//---------------------
//Взаимодействие с замком
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
                PAGE = "startgame";
            }
            btn2.visible = false;
            txSetFillColor (TX_WHITE);
            txSetColor (TX_BLACK);
        }
        if(PAGE == "author")
        {
            btn3.draw();
            //Возврат в меню
            if(btn3.click())
            {
                PAGE = "menu";
            }
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            //---------------------
            btn2.visible = false;
            txBitBlt(txDC(), 0, 0, 1280, 820, menu);
            txSelectFont("Times New Roman", 30);
            txSetColor (TX_BLACK);
            txDrawText(0, 254, 44+1000, 254+100, "Ссылка на игру- https://github.com/NIVqwerty/My-game.git");
            txDrawText(175, 294, 84+600, 294+100, "Телеграмм автора - https://t.me/QwertyHoh");
            btn3.draw();
        }
        txEnd();
        txSleep(50);

    }
txDeleteDC(karta);
txDeleteDC(kartaezy);
txDeleteDC(minikarta);
txDeleteDC(minikartaezy);
txDeleteDC(menu);


txDisableAutoPause();
return 0;
}

