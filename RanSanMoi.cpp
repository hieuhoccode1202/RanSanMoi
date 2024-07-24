#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "mylib.h"
#include "Menu.h"
#include "string"
#include "fstream"
#include "Windows.h";
#include "mmsystem.h";
using namespace std;
void kt();
void checking(int check_1);
void ve_qua();
bool check();
void tao_qua();
void ve_tuong();
int sl = 4;
int sl1 = 4;
const int N = 100;
int toa_do_x[N];
int toa_do_x1[N];
int toa_do_y1[N];
int toa_do_y[N];
void tao_ran();
void play(int speed);
void ve_ran(int k);
void xu_ly_ran(int x, int y, int stt);
void xu_ly_click();
int x_ban_dau = 25;
int y_ban_dau = 15;
int xqua = -1;
int yqua = -1;
int wid = 140;
int hei = 30;
bool check_over1();
bool check_over2();
void play_music();

void draw_image(string ffile);



void play_music()
{
    PlaySound(TEXT("D:\\App he thong\\Downloads\\sound.wav"), NULL, SND_FILENAME);

}


int main()
{
    xu_ly_click();
    return 0;
}

void xu_ly_click()
{
    ShowCur(0);
    draw();
    Create_Menu();
    int k = get_check();
    if (k == 0)
    {
        system("cls");
        draw_image("RanSanMoi.txt");
        play(420);

    }
    else if (k == 1)
    {
        system("cls");
    }
}

void draw_image(string ffile)
{
    ifstream inFile(ffile);
    if (!inFile)
    {
        cerr << "Unable to open file image.txt" << endl;
    }

    // Hide cursor
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = { 1, 0 };
    SetConsoleCursorInfo(handle, &cursor);

    loading();

    string s;
    while (getline(inFile, s))
    {
        cout << "\t\t\t\t\t\t\t";
        cout << s << endl;
        Sleep(10);
    }

    inFile.close();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

}
bool ran1_can_ran2()
{
    int x = toa_do_x[0];
    int y = toa_do_y[0];
    for (int i = 1; i < sl1; ++i)
    {
        if (x == toa_do_x1[i] && y == toa_do_y1[i])
        {
            return true;
        }
    }
    return false;
}
bool ran2_can_ran1()
{
    int x = toa_do_x1[0];
    int y = toa_do_y1[0];
    for (int i = 1; i < sl; ++i)
    {
        if (x == toa_do_x[i] && y == toa_do_y[i])
        {
            return true;
        }
    }
    return false;
}
void check_can_tuong1()
{
    int x = toa_do_x[0];
    int y = toa_do_y[0];
    if (x == x_ban_dau + wid || y == y_ban_dau + hei || x == x_ban_dau || y == y_ban_dau)
    {
        gotoXY(x, y);
        cout << "+";
    }
}
void check_can_tuong2()
{
    int x = toa_do_x1[0];
    int y = toa_do_y1[0];
    if (x == x_ban_dau + wid || y == y_ban_dau + hei || x == x_ban_dau || y == y_ban_dau)
    {
        gotoXY(x, y);
        cout << "+";
    }
}
void play(int speed)
{
    ShowCur(0);
    ve_tuong();
    tao_ran();
    int x = toa_do_x[0];
    int y = toa_do_y[0];
    int x_1 = toa_do_x1[0];
    int y_1 = toa_do_y1[0];

    int check = 3;
    int check_2 = 3;
    /*
    * 0 - là đi xuống
    * 1 - là đi lên
    * 2 - đi bên trái
    * 3 - là đi bên phải
    */
    tao_qua();
    ve_qua();
    draw_score(3, 3, 13, 3, sl);
    draw_score(150, 3, 13, 3, sl1);
    int sl_ran = 2;
    int check_die_1 = 0;
    int check_die_2 = 0;
    while (true)
    {
        if (toa_do_x[0] == toa_do_x1[0] && toa_do_y[0] == toa_do_y1[0])
        {
            break;
        }
        if (ran1_can_ran2())
        {
            for (int i = 1; i <= sl; ++i)
            {
                gotoXY(toa_do_x[i], toa_do_y[i]);
                cout << " ";
                toa_do_x[i] = -1, toa_do_y[i] = -1;
            }
            gotoXY(toa_do_x[0], toa_do_y[0]);
            cout << "o";
            sl_ran--;
            check_die_1++;
        }
        else if (!check_over1())
        {
            check_die_1++;
            if (check_die_1 > 0 && check_die_1 <= 1 ) 
            {
                for (int i = 1; i <= sl; ++i)
                {
                    gotoXY(toa_do_x[i], toa_do_y[i]);
                    cout << " ";
                }
                check_can_tuong1();
                sl_ran--;
            }
        }
        else
        {
            if (check_die_1 < 1) 
            {
                ve_ran(1);
                gotoXY(toa_do_x[sl], toa_do_y[sl]);
                cout << " ";
            }
        }
        if (ran2_can_ran1())
        {
            for (int i = 1; i <= sl1; ++i)
            {
                gotoXY(toa_do_x1[i], toa_do_y1[i]);
                cout << " ";
                toa_do_x1[i] = -1, toa_do_y1[i] = -1;
            }
            gotoXY(toa_do_x1[0], toa_do_y1[0]);
            cout << "o";
            sl_ran--;
            check_die_2++;
        }
        else if (!check_over2())
        {
            check_die_2++;
            if (check_die_2 > 0 && check_die_2 <= 1)
            {
                for (int i = 1; i <= sl1; ++i)
                {
                    gotoXY(toa_do_x1[i], toa_do_y1[i]);
                    cout << " ";
                }
                sl_ran--;
                check_can_tuong2();
            }
        }
        else
        {
            if (check_die_2 < 1)
            {
                ve_ran(2);
                gotoXY(toa_do_x1[sl1], toa_do_y1[sl1]);
                cout << " ";
            }
        }
        if (sl_ran == 0)
        {
            break;
        }
        kt();
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == 115 && check != 1) // s
            {
                check = 0;
            }
            else if (ch == 119 && check != 0) // w
            {
                check = 1;
            }
            else if (ch == 97 && check != 3) // a
            {
                check = 2;
            }
            else if (ch == 100 && check != 2) // d
            {
                check = 3;
            }
            if (ch == -32)
            {
                ch = _getch();
                if (ch == 72 && check_2 != 0)
                {
                    check_2 = 1;
                }
                else if (ch == 80 && check_2 != 1)
                {
                    check_2 = 0;
                }
                else if (ch == 75 && check_2 != 3)
                {
                    check_2 = 2;
                }
                else if (ch == 77 && check_2 != 2)
                {
                    check_2 = 3;
                }
            }

        }
        if (check == 2)
        {
            x--;
        }
        else if (check == 0)
        {
            y++;
        }
        else if (check == 1)
        {
            y--;
        }
        else if (check == 3)
        {
            x++;
        }


        if (check_2 == 2)
        {
            x_1--;
        }
        else if (check_2 == 0)
        {
            y_1++;
        }
        else if (check_2 == 1)
        {
            y_1--;
        }
        else if (check_2 == 3)
        {
            x_1++;
        }
        xu_ly_ran(x, y, 1);
        xu_ly_ran(x_1, y_1, 2);
        if (check == 1 || check == 0 || check_2 == 1 || check_2 == 0)
            Sleep(500 - speed + 85);
        else
            Sleep(500 - speed);
    }

    system("cls");

    SetColor(11);
    if (sl > sl1)
    {
        draw_image("P1.txt");
    }
    else if (sl < sl1)
    {
        draw_image("P2.txt");
    }
    else 
    {
        draw_image("Score.txt");
    }
    Create_box(80, 20, 23, 2, 75, 0, "Choi Lai");
    Create_box(80, 22, 23, 2, 75, 0, "Thoat");
    for (int i = 1; i < 2; ++i)
    {
        gotoXY(80, 20 + (i * 2));
        cout << char(195);
        gotoXY(80 + 23, 20 + (i * 2));
        cout << char(180);
    }
    int flag = false;
    int check_1 = 0;
    int yp = 20;
    while (true)
    {
        if (_kbhit())
        {
            if (!flag)
            {
                thanh_sang2(80, 20, 23, 2, 75, "Choi Lai");
                flag = true;
            }
            else
            {
                char cc = _getch();
                if (cc == 115 && yp != 22) // 's' key
                {
                    yp += 2;
                    check_1++;
                    if (check_1 > 1)
                        check_1 = 1;
                }
                else if (cc == 119 && yp != 20) // 'w' key
                {
                    yp -= 2;
                    check_1--;
                    if (check_1 < 0)
                        check_1 = 0;
                }
                else if (cc == 13)
                {
                    break;
                }
                checking(check_1);
            }

        }
    }
    if (check_1 == 0)
    {
        sl = 4;
        sl1 = 4;
        system("cls");
        draw_image("RanSanMoi.txt");
        play(speed);
    }
    else
    {
        exit(0);
    }
}

void checking(int check_1)
{
    if (check_1 == 0)
    {
        thanh_sang2(80, 20, 23, 2, 75, "Choi Lai");
        thanh_sang2(80, 22, 23, 2, 0, "Thoat");
    }
    else 
    {
        thanh_sang2(80, 20, 23, 2, 0, "Choi Lai");
        thanh_sang2(80, 22, 23, 2, 75, "Thoat");
    }
}
bool check_over1()
{
    int x = toa_do_x[0];
    int y = toa_do_y[0];
    if (x == x_ban_dau + wid || y == y_ban_dau + hei || x == x_ban_dau || y == y_ban_dau )
        return false;
    for (int i = 1; i < sl; ++i)
    {
        if (x == toa_do_x[i] && y == toa_do_y[i])
            return false;
    }
    return true;
}
bool check_over2()
{
    int x = toa_do_x1[0];
    int y = toa_do_y1[0];
    if (x == x_ban_dau + wid || y == y_ban_dau + hei || x == x_ban_dau || y == y_ban_dau )
        return false;
    for (int i = 1; i < sl1; ++i)
    {
        if (x == toa_do_x1[i] && y == toa_do_y1[i])
            return false;
    }
    return true;
}

void ve_tuong()
{
    for (int x = x_ban_dau; x <= x_ban_dau + wid; ++x)
    {
        gotoXY(x, y_ban_dau);
        cout << "+";
        gotoXY(x, y_ban_dau + hei);
        cout << "+";
    }
    for (int y = y_ban_dau; y <= y_ban_dau + hei; ++y)
    {
        gotoXY(x_ban_dau, y);
        cout << "+";
        gotoXY(x_ban_dau + wid, y);
        cout << "+";
    }
}
bool check_randon_ran()
{
    int c1 = toa_do_x1[0];
    int c2 = toa_do_y1[0];

    for (int i = 0; i < sl; ++i)
    {
        if (c1 == toa_do_x[i] && c2 == toa_do_y[i])
        {
            return true;
        }
    }
    c1 = toa_do_x[0];
    c2 = toa_do_y[0];
    for (int i = 0; i < sl1; ++i)
    {
        if (c1 == toa_do_x1[i] && c2 == toa_do_y1[i])
        {
            return true;
        }
    }
    return false;
}
void tao_ran()
{
    srand(static_cast<unsigned int>(time(NULL))); // Sử dụng static_cast để đảm bảo không có mất mát dữ liệu

    // Tạo con rắn thứ nhất ở nửa bên trái
    int x = rand() % (wid / 2 - sl) + x_ban_dau; // random trong khoảng từ x_ban_dau đến x_ban_dau + wid/2
    int y = rand() % hei + y_ban_dau; // random trong khoảng từ y_ban_dau đến y_ban_dau + hei
    for (int i = 0; i < sl; ++i)
    {
        toa_do_x[i] = x--;
        toa_do_y[i] = y;
    }

    // Tạo con rắn thứ hai ở nửa bên phải
    int x11 = rand() % (wid / 2 - sl1) + x_ban_dau + wid / 2; // random trong khoảng từ x_ban_dau + wid/2 đến x_ban_dau + wid
    int y11 = rand() % hei + y_ban_dau; // random trong khoảng từ y_ban_dau đến y_ban_dau + hei
    for (int i = 0; i < sl1; ++i)
    {
        toa_do_x1[i] = x11--;
        toa_do_y1[i] = y11;
    }
}


void ve_ran(int k)
{
    if (k == 1)
    {
        textcolor(6);
        for (int i = 0; i < sl; ++i)
        {
            if (i == 0)
            {
                gotoXY(toa_do_x[i], toa_do_y[i]);
                cout << "0";
            }
            else
            {
                gotoXY(toa_do_x[i], toa_do_y[i]);
                cout << "o";
            }
        }
        textcolor(0);

    }
    else if (k == 2)
    {
        textcolor(10);
        for (int i = 0; i < sl1; ++i)
        {
            if (i == 0)
            {
                gotoXY(toa_do_x1[i], toa_do_y1[i]);
                cout << "0";
            }
            else
            {
                gotoXY(toa_do_x1[i], toa_do_y1[i]);
                cout << "o";
            }
        }
        textcolor(0);
    }
}

void xu_ly_ran(int x, int y, int stt)
{
    if (stt == 1)
    {
        for (int i = sl; i > 0; --i)
        {
            toa_do_x[i] = toa_do_x[i - 1];
            toa_do_y[i] = toa_do_y[i - 1];
        }
        toa_do_x[0] = x;
        toa_do_y[0] = y;
    }
    else
    {
        for (int i = sl1; i > 0; --i)
        {
            toa_do_x1[i] = toa_do_x1[i - 1];
            toa_do_y1[i] = toa_do_y1[i - 1];
        }
        toa_do_x1[0] = x;
        toa_do_y1[0] = y;
    }
}

void tao_qua()
{
    static bool first_call = true;
    if (first_call)
    {
        srand(static_cast<unsigned int>(time(NULL)));
        first_call = false;
    }

    do
    {
        xqua = rand() % (wid) + x_ban_dau; // random trong khoảng từ x_ban_dau đến x_ban_dau + w
        yqua = rand() % (hei) + y_ban_dau; // random trong khoảng từ y_ban_dau đến y_ban_dau + h
    } while (check());
}

bool check()
{
    if (xqua == x_ban_dau || yqua == y_ban_dau || xqua == x_ban_dau + wid || yqua == y_ban_dau + hei)
        return true;
    for (int i = 0; i < sl; ++i)
    {
        if (xqua == toa_do_x[i] && yqua == toa_do_y[i])
            return true;
    }
    return false;
}

void kt()
{
    int x = toa_do_x[0];
    int y = toa_do_y[0];
    if (x == xqua && y == yqua)
    {
        sl++;
        delete_noi_dung(3, 3, 13, 3, sl);
        tao_qua();
        ve_qua();
    }
    x = toa_do_x1[0];
    y = toa_do_y1[0];
    if (x == xqua && y == yqua)
    {
        sl1++;
        delete_noi_dung(150, 3, 13, 3, sl1);
        tao_qua();
        ve_qua();
    }
}

void ve_qua()
{
    gotoXY(xqua, yqua);
    cout << "*";
}
