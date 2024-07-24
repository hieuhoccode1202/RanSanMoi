// XepHinh.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifndef MENU_H
#define MENU_H




#include <iostream>
#include "../RanSanMoi/mylib.h"
using namespace std;
void draw();
void hoan_thien();
void thanh_sang(int x, int y, int color, string nd);
void Create_box(int x, int y, int w, int h, int color, int text_color, string s);
void Check_click(int check, int yp, int ycu);

int x = 70;
int y = 15;
int w = 30;
int h = 2;
int check_move = 0;
void loading()
{
    cout << "\t\t\t\t\t\t\t\tLoading";
    char a = char(177), b = char(219);
    cout << "\n\t\t\t\t\t\t\t\t";
    for (int i = 0; i < 60; ++i)
        cout << a;
    cout << "\r";
    cout << "\t\t\t\t\t\t\t\t";
    for (int i = 0; i < 60; ++i)
    {
        cout << b;
        Sleep(10);
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}
void delete_noi_dung(int x_khung, int y_khung, int w_khung, int h_khung, int diem)
{
    for (int x = x_khung + 1; x < x_khung + w_khung; ++x) 
    {
        for (int y = y_khung + 1; y < y_khung + h_khung; ++y)
        {
            gotoXY(x, y);
            cout << " ";
        }
    }
    textcolor(1);
    gotoXY(x_khung + 1, y_khung + 1);
    cout << "NguNhatVN";
    gotoXY(x_khung + 1, y_khung + 2);
    cout << "Diem: ";
    cout << diem;
}
void draw_score(int x_khung, int y_khung, int w_khung, int h_khung, int sl)
{
    SetColor(11);
    char m = char(205);
    
    for (int i = x_khung + 1; i <= x_khung + w_khung; ++i)
    {
        gotoXY(i, y_khung);
        cout << m;
        gotoXY(i, y_khung + h_khung);
        cout << m;
    }
    for (int i = y_khung + 1; i < h_khung + y_khung; ++i)
    {
        gotoXY(x_khung, i);
        cout << char(186);
        gotoXY(x_khung + w_khung, i);
        cout << char(186);

    }
    gotoXY(x_khung, y_khung);
    cout << char(201);
    gotoXY(x_khung + w_khung , y_khung);
    cout << char(187);


    gotoXY(x_khung, y_khung + h_khung );
    cout << char(200);
    gotoXY(x_khung + w_khung, y_khung + h_khung);
    cout << char(188);

    gotoXY(x_khung + 1, y_khung + 1);
    gotoXY(x_khung + 1, y_khung + 1);
    cout << "NguNhatVN";
    gotoXY(x_khung + 1, y_khung + 2);
    cout << "Diem: ";
    cout << sl;
}
int get_check()
{
    return check_move;
}
void Create_Menu()
{
    draw();
    int  ycu = y;
    int  yp = y;
    bool checkclick = false;
    while (true)
    {
        if (_kbhit())
        {
            if (!checkclick)
            {
                thanh_sang(x, y, 75, "Choi Game");
                checkclick = true;
            }
            else
            {
                ycu = yp;
                char cc = _getch();
                if (cc == 115 && yp != y + h * 3) // 's' key
                {
                    yp += 2;
                    check_move++;
                    if (check_move > 3)
                        check_move = 3;
                }
                else if (cc == 119 && yp != y) // 'w' key
                {
                    yp -= 2;
                    check_move--;
                    if (check_move < 0)
                        check_move = 0;
                }
                else if (cc == 13)
                {
                    break;
                }
                Check_click(check_move, yp, ycu);

            }
        }
    }
}
void Check_click(int check, int yp, int ycu)
{
    if (check == 0)
    {
        thanh_sang(x, yp, 75, "Choi Game");
        if (ycu == y + 2)
        {
            thanh_sang(x, ycu, 0, "Setting");
        }
    }
    else if (check == 1)
    {
        thanh_sang(x, yp, 75, "Setting");
        if (ycu == y)
        {
            thanh_sang(x, ycu, 0, "Choi Game");
        }
        else if (ycu == y + 4)
        {
            thanh_sang(x, ycu, 0, "Huong Dan");
        }
    }
    else if (check == 2)
    {
        thanh_sang(x, yp, 75, "Huong Dan");
        if (ycu == y + 2)
        {
            thanh_sang(x, ycu, 0, "Setting");
        }
        else if (ycu == y + 6)
        {
            thanh_sang(x, ycu, 0, "Thoat");
        }
    }
    else if (check == 3)
    {
        thanh_sang(x, yp, 75, "Thoat");
        if (ycu == y + 4)
        {
            thanh_sang(x, ycu, 0, "Huong Dan");
        }
    }
}
void Create_box(int x, int y, int w, int h, int color, int text_color, string s)
{
    textcolor(text_color);
    for (int i = x + 1; i <= x + w - 1; ++i)
    {
        for (int j = y + 1; j <= y + h - 1; ++j)
        {
            gotoXY(i, j);
            cout << " ";
        }
    }
    char c = char(196);
    SetColor(7);
    gotoXY(x + 1, y + 1);
    cout << s;
    textcolor(1);
    SetColor(color);
    for (int i = 0; i < w; ++i)
    {
        gotoXY(x + i, y);
        cout << c;
        gotoXY(x + i, y + h);
        cout << c;
    }
    c = char(179);
    for (int i = 0; i <= h; ++i)
    {
        gotoXY(x, y + i);
        cout << c;
        gotoXY(x + w, y + i);
        cout << c;
    }
    gotoXY(x, y);
    cout << char(218);
    gotoXY(x, y + h);
    cout << char(192);
    gotoXY(x + w, y);
    cout << char(191);
    gotoXY(x + w, y + h);
    cout << char(217);

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

}
void draw()
{

    Create_box(x, y, w, h, 11, 0, "Choi Game");
    Create_box(x, y + 2, w, h, 11, 0, "Setting");
    Create_box(x, y + 4, w, h, 11, 0, "Huong Dan");
    Create_box(x, y + 6, w, h, 11, 0, "Thoat");
    hoan_thien();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

}
void hoan_thien()
{
    for (int i = 1; i < 4; ++i)
    {
        gotoXY(x, y + (i * 2));
        cout << char(195);
        gotoXY(x + w, y + (i * 2));
        cout << char(180);
    }
}

void thanh_sang(int x, int y, int color, string nd)
{
    textcolor(color);
    for (int i = x + 1; i <= x + w - 1; ++i)
    {
        for (int j = y + 1; j <= y + h - 1; ++j)
        {
            gotoXY(i, j);
            cout << " ";
        }
    }
    SetColor(7);
    gotoXY(x + 1, y + 1);
    cout << nd;
    textcolor(1);
}
void thanh_sang2(int x, int y,int w, int h, int color, string nd)
{
    textcolor(color);
    for (int i = x + 1; i <= x + w - 1; ++i)
    {
        for (int j = y + 1; j <= y + h - 1; ++j)
        {
            gotoXY(i, j);
            cout << " ";
        }
    }
    SetColor(7);
    gotoXY(x + 1, y + 1);
    cout << nd;
    textcolor(1);
}



#endif