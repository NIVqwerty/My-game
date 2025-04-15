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
        txSetColor (RGB(26,62,48));
        txDrawText(x, y, x+w, y+h, text);
        }
        else
        {
        txSetColor (TX_WHITE, 3);
        txSetFillColor (RGB(71,147,121));
        Win32::RoundRect (txDC(), x, y, x+w, y+h, 30, 30);
        txSelectFont("Times New Roman", 30);
        txSetColor (RGB(26,62,48));
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
struct Pic
{


    int x;
    int y;
    int w;
    int h;
    HDC image;
    bool visible;

    void draw()
    {
        Win32::TransparentBlt(txDC(), x, y,64,80, image,0,0,w, h,TX_GREEN);
    }

    bool click()
    {
        return(txMouseX()>x && txMouseX()<x+64 &&
                txMouseY()>y && txMouseY()<y+80 &&
                txMouseButtons() == 1 && visible);
    }
};
struct Kod
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
            Win32::TransparentBlt(txDC(), x, y, w, h, image, 0, 0,50, 50,  TX_BLUE);
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
HDC menu1 = txLoadImage("Pictures/menu1.bmp");
HDC MG = txLoadImage("Pictures/LockGame.bmp");

Pic pic1 = {1006, 607,64, 80,  txLoadImage("Pictures/7.bmp"), false};
Pic pic2 = {50, 64, 64, 80, txLoadImage("Pictures/3.bmp"), false};
Pic pic3 = {568, 657, 64, 80, txLoadImage("Pictures/9.bmp"), false};
Man man = {10, 620, 30, 30, 100, 100, txLoadImage("Pictures/man123.bmp"), 0};
Lock lock ={1150,42,49,50,txLoadImage("Pictures/Lock.bmp"),true};
Key key ={153,180,50,25,txLoadImage("Pictures/Key.bmp"),true};
Kod kod ={153,180,50,50,txLoadImage("Pictures/Kod.bmp"),true};
Kod hkod ={153,181,40,40,txLoadImage("Pictures/Hkod.bmp"),true};
Kod bkod ={300,181,500,500,txLoadImage("Pictures/739.bmp"),false};
Kod kodmas[3];
kodmas[0] ={93, 504,37,40,kod.image,true};
kodmas[1] ={888,309,37,40,kod.image,true};
kodmas[2] ={1055,721,37,40,kod.image,true};

int x_man_old, y_man_old;
string PAGE = "menu";

Button btn0 = {540, 350, 200, 40, "Играть", true};
Button btn1 = {540, 400, 200, 40, "Управление", true};
Button btn2 = {540, 500, 200, 40, "Выход", true};
Button btn3 = {5, 5, 200, 40, "Назад", true};
Button btn4 = {540, 450, 200, 40, "Об авторе", true};
Button btn5 = {560, 380, 70, 40, "ДА", false};
Button btn6 = {650, 380, 70, 40, "НЕТ", false};
Button btn7 = {150, 394, 457, 40, "Лёгкий", true};
Button btn8 = {690, 394, 457, 40, "Сложный", true};
Button btn9 = {500, 300, 250, 60, "Следующий уровень", true};
Button btn10 = {350, 300, 250, 60, "Заново", true};
Button btn11 = {650, 300, 250, 60, "В меню", true};
Button btn12 = {540, 500, 200, 40, "Сюжет", true};







    while(!btn5.click())
    {
        txClear();
        txBegin();
        btn2.visible = true;
        if(PAGE == "menu")
        {

            txBitBlt(txDC(), 0, 0, 1280, 820, menu1);
            btn0.draw();
            btn1.draw();
            btn2.draw();
            btn4.draw();
            btn5.visible = false;
            btn6.visible = false;
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
        btn5.visible = true;
        btn6.visible = true;
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
            txDrawText(120, 414, 44+600, 414+100, "E-взаимодействие");
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
        btn12.draw();
        txDrawText(550, 50, 550+300, 50+50, "Выбирете уровень:");
        // Сюжет
        if(btn12.click())
            {
                PAGE = "history";
            }
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
                kodmas[0].visible = true;
                kodmas[1].visible = true;
                kodmas[2].visible = true;

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
        txBegin();
        txBitBlt(txDC(), 0, 0, 1280, 820, karta);
        lock.draw();
        hkod.draw();
        man.draw();
        bkod.draw();
        txSetColor(RGB(0, 0, 0), 15);
        lock.x =1150;
        lock.y =42;
        man.w_ =30;
        man.h_ =30;
        kodmas[0].draw();
        kodmas[1].draw();
        kodmas[2].draw();
        x_man_old = man.x;
        y_man_old = man.y;
//Управление
        if(GetAsyncKeyState('S'))
        {
            man.y += 7;
            man.yn_kard = 0;
            man.xn_kard += 1;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState('A'))
        {
            man.x -= 7;
            man.xn_kard += 1;
            man.yn_kard = 1;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState('D'))
        {
            man.x += 7;
            man.xn_kard += 1;
            man.yn_kard = 2;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState('W'))
        {
            man.y -= 7;
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


 // Взаимодействие с частями кода
if( man.x< hkod.x+hkod.w && man.x+11>hkod.x &&
            man.y<hkod.y+hkod.h && man.y+11>hkod.y)
            {
            bkod.visible = true;
            txSetColor(TX_GREEN);
            txRectangle(6, 10, 44+400,70);
            txDrawText(6, 10, 44+400,70, "Зажмите E чтобы закрыть подсказку ");
            if(GetAsyncKeyState('E'))
                {
                 bkod.visible = false;
                }
            }
 else
 {
 bkod.visible = false;
 }
 for (int i=0; i<3; i++)
        {
    if( man.x< kodmas[i].x+kodmas[i].w && man.x+11>kodmas[i].x &&
            man.y<kodmas[i].y+kodmas[i].h && man.y+11>kodmas[i].y)
            {
                kodmas[i].visible = false;

            }
        }
 //Взаимодействие с замком
      if(lock.visible == true)
      {


            if( man.x<lock.x+lock.w && man.x+11>lock.x &&
            man.y<lock.y+lock.h && man.y+11>lock.y)
            {
                man.x = x_man_old;
                man.y = y_man_old;
            }
            if( man.x<lock.x+lock.w && man.x+11>lock.x-30 &&
            man.y-10<lock.y+lock.h+10 && man.y+11>lock.y-20)
            {
                txSetColor(TX_GREEN);
                txRectangle(6, 10, 44+400,70);
                txDrawText(6, 10, 44+400,70, "Нажмите E для подстановки кода ");
                if(GetAsyncKeyState('E'))
                {
                    PAGE = "minigame";
                    pic1.visible = false;
                    pic2.visible = false;
                    pic3.visible = false;
                }
            }
      }

       if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "startgame";
            }
            btn2.visible = false;
            txSetFillColor (TX_WHITE);
            txSetColor (TX_BLACK);
            txEnd();
        }
        if(PAGE == "minigame")
        {
        txBitBlt(txDC(), 0, 0, 1280, 820, karta);
        lock.draw();
        man.draw();
        bkod.draw();
        kodmas[0].draw();
        kodmas[1].draw();
        kodmas[2].draw();
        txBitBlt(txDC(), 400, 200, 400+392, 400+401, MG);

        if(kodmas[0].visible == false)
        {
        pic1.draw();
        pic1.visible = true;
        }
         if(kodmas[1].visible == false)
        {
        pic2.draw();
        pic2.visible = true;
        }
         if(kodmas[2].visible == false)
        {
        pic3.draw();
        pic3.visible = true;
        }
        if(!pic2.click()&!pic3.click())
        {
        if(pic1.visible == true)
        {
         if(pic1.click())
            {
                pic1.x=txMouseX()-30;
                pic1.y=txMouseY()-40;
            }
        }
        }
        if(!pic1.click()&!pic3.click())
        {
        if(pic2.visible == true)
        {
         if(pic2.click())
        {
            pic2.x=txMouseX()-30;
            pic2.y=txMouseY()-40;
        }
        }
        }
        if(!pic2.click()&!pic1.click())
        {
        if(pic3.visible == true)
        {
         if(pic3.click())
        if(pic3.click())
         {
            pic3.x=txMouseX()-30;
            pic3.y=txMouseY()-40;
         }
        }
        }
        if(pic1.x ==96+400 & pic1.y== 257+200 & pic2.x ==168+400 & pic2.y== 257+200 &pic3.x ==240+400 & pic3.y== 257+200)
        {
        lock.visible = false;
        }
        if(lock.visible == false)
        {
         PAGE = "game";
        }
        if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "game";
            }
        txSetColor(TX_GREEN);
        txRectangle(6, 10, 44+400,70);
        txDrawText(6, 10, 44+400,70, "Нажмите Esc выхода из мини-игры ");
        }
        if(PAGE == "1game")
        {
        txBegin();
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
            man.y += 9;
            man.yn_kard = 0;
            man.xn_kard += 1;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState('A'))
        {
            man.x -= 9;
            man.xn_kard += 1;
            man.yn_kard = 1;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState('D'))
        {
            man.x += 9;
            man.xn_kard += 1;
            man.yn_kard = 2;
            if(man.xn_kard>3) man.xn_kard=0;
            txSleep(50);
        }
        if(GetAsyncKeyState('W'))
        {
            man.y -= 9;
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
            txEnd();
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
        if(PAGE == "history")
        {
        int ycor=1200;
        while(ycor+100>0)
        {
        txBitBlt(txDC(), 0, 0, 1280, 820, menu);
        txSetColor(TX_BLACK);
        txDrawText(290, ycor-300, 850, ycor-200, "Джон отправился в экспидицию в джунгли,");
        txDrawText(290, ycor-250, 850, ycor-150, "где встретил таинственную грабницу.");
        txDrawText(290,ycor-200, 850, ycor-100, "Он решил изучить ее, но случайно заблудился.");
        txDrawText(290, ycor-150, 850, ycor-50, "Пока он искал выход, ");
        txDrawText(290, ycor-100, 850, ycor, "он наступил на какую-то ловушку");
        txDrawText(290, ycor-50, 850, ycor+50, " и все проходы закрылись на замки.");
        txDrawText(230, ycor, 1000, ycor+100, "Теперь ему помимо выхода нужно искать ключи и фрагменты кода! ");
        ycor-=3;
        if(ycor>0||ycor==0)
        {
        PAGE = "startgame";
        }
        txSleep(30);
        }

        }
        txEnd();
        txSleep(50);

    }
txDeleteDC(karta);
txDeleteDC(kartaezy);
txDeleteDC(minikarta);
txDeleteDC(minikartaezy);
txDeleteDC(menu);
txDeleteDC(menu1);


txDisableAutoPause();
return 0;
}

