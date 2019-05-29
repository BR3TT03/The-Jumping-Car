#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <fstream>
#include<stdlib.h>
#include<windows.h>
#define MAX_INPUT_LEN 20
using namespace std;
struct file {
    char Name[MAX_INPUT_LEN];
    int score;
} structFile[10], temp;

void savesc(char score[])
{
    char inputbuf[MAX_INPUT_LEN] = "";
    int input_pos = 0;
    int the_end = 0;
    char c;
    setcolor(RED);
    setfillstyle(11, BLACK);
    bar(0, 0, 1600, 900);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 3);
    do {
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
        outtextxy(450,100,"THE JUMPING CAR");
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
        outtextxy(450, 200, "Enter your name to save your score");
        line(450, 295, 950, 295);
        outtextxy(450, 600, "Press ESC to exit without saving");
         outtextxy(450, 265, inputbuf);
        c = getch();
        switch (c) {
        case 8: /* backspace */
            if (input_pos)
                {
                input_pos--;
            cleardevice();
                setfillstyle(11, BLACK);
                bar(0, 0, 1600, 900);
                inputbuf[input_pos]=NULL;
               }
            break;
        case 13: /* return */
            the_end = 1;
            break;
        case 27: /* Escape*/

            exit(0);

             break;
        default:
            if (input_pos < MAX_INPUT_LEN - 1 && c >= ' ' && c <= '~') {
                inputbuf[input_pos] = c;
                input_pos++;

            }
        }
    } while (!the_end);

    char playerName[20];
    strcpy(playerName, inputbuf);
    fstream scorefile;
    scorefile.open("Scores.txt",ios::app);
    scorefile << playerName << endl
              << score << endl;
    scorefile.close();
}

class MENU {
public:
    void option()
    {
        setcolor(BLACK);
        rectangle(560, 210, 820, 420);
        line(560, 280, 820, 280);
        line(560, 350, 820, 350);
        setcolor(8);
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
        outtextxy(450,100,"THE JUMPING CAR");
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
        outtextxy(620, 230, "START");
        outtextxy(570, 300, "INSTRUCTIONS");
        outtextxy(570, 370, "HIGH SCORES");
    }
    void INSTRUCTIONS();
    void HIGHSCORES();

};
void MENU::INSTRUCTIONS()
{
    cleardevice();
    POINT pos;
    while (1) {
        rectangle(100, 500, 200, 550);
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
        outtextxy(450,100,"THE JUMPING CAR");
        settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
        outtextxy(103, 515, "BACK");
        outtextxy(300, 200, "1. Press SPACE to jump");
        outtextxy(300, 300, "2. Press ESCAPE to exit the game at any time");
        outtextxy(300, 400,"Note: Your score won't be saved if you exit the game without a crash");
        if (GetAsyncKeyState(VK_LBUTTON)) {
            GetCursorPos(&pos);
            Beep(500, 200);
            if (pos.x >= 100 && pos.x <= 200 && pos.y >= 530 && pos.y <= 580) {
                break;
            }

        }
        delay(2);
    }
}
void MENU::HIGHSCORES()
{
    cleardevice();
    POINT pos;
    char abc[20], score[5];
    int k = 0;
    int i = 0;
    ifstream scoreFile("Scores.txt", ios::out | ios::in);
    while (scoreFile) {
        scoreFile.getline(abc, 20);
        strcpy(structFile[i].Name, abc);
        scoreFile.getline(score, 6);
        structFile[i].score = atoi(score);
        i++;
    }
    scoreFile.close();

    int z = i;

    for (int i = 0; i < z; ++i)
        for (int j = 0; j < z-1; ++j)
            if (structFile[j].score < structFile[j + 1].score) {
                temp.score = structFile[j].score;
                structFile[j].score = structFile[j + 1].score;
                structFile[j + 1].score = temp.score;

                strcpy(temp.Name, structFile[j].Name);
                strcpy(structFile[j].Name, structFile[j + 1].Name);
                strcpy(structFile[j + 1].Name, temp.Name);
            }
    char che[5];
    for (int Temp = 0, k = 0; k < z - 1 && k < 10; Temp = Temp + 40) {
        outtextxy(400, 100 + Temp, structFile[k].Name);
        sprintf(che, "%d", structFile[k].score);
        outtextxy(620, 100 + Temp, che);
        k++;
    }
    rectangle(100, 500, 200, 550);
    outtextxy(103, 515, "BACK");
    outtextxy(400, 50,"Player");
    outtextxy(620,50,"Score");
    while (1) {
        if (GetAsyncKeyState(VK_LBUTTON)) {
            GetCursorPos(&pos);
            Beep(500, 200);
            if (pos.x >= 100 && pos.x <= 200 && pos.y >= 530 && pos.y <= 580) {
                cleardevice();
                break;
            }
        }
        delay(2);
    }
}

inline void car(int i)
{
    line(0, 500, 1363, 500);
    // base
    line(100, 494 + i, 109, 494 + i);
    line(121, 494 + i, 139, 494 + i);
    line(151, 494 + i, 160, 494 + i);
    // tires
    circle(115, 494 + i, 6);
    circle(145, 494 + i, 6);
    // back
    line(100, 494 + i, 100, 482 + i);
    arc(107, 484 + i, 90, 180, 7);
    line(107, 477 + i, 113, 477 + i);
    // front
    line(160, 494 + i, 160, 483 + i);
    arc(153, 484 + i, 0, 90, 7);
    line(153, 477 + i, 147, 477 + i);
    // hood
    arc(130, 477 + i, 0, 180, 18);
    // window right
    arc(132, 477 + i, 0, 90, 14);
    line(132, 477 + i, 146, 477 + i);
    line(132, 477 + i, 132, 463 + i);
    // window left
    arc(128, 477 + i, 90, 180, 13);
    line(128, 477 + i, 128, 463 + i);
    line(128, 477 + i, 115, 477 + i);
}
int main()
{
    DWORD height = GetSystemMetrics(SM_CXSCREEN);
    DWORD breadth = GetSystemMetrics(SM_CYSCREEN);

    initwindow(height, breadth);
start:
    MENU c;
    int n = 1200, i, j = 100, temp = 1210, score = 0, back = 1000, back1 = 500, x,crash = 497, n1, temp1;
    float speed = 4, o = 1, spt = 1200, sp = spt;
    char s[10];
    POINT cursorPosition;
    i = 0;

    int knox = 0;

menu:
    while (1) {
            delay(2);
            settextstyle(EUROPEAN_FONT, HORIZ_DIR, 3);
        setbkcolor(11);
        if (knox == 0) {
            setfillstyle(10, BLACK);
            bar(0, 0, 1600, 900);
            setcolor(YELLOW);
            c.option();
            outtextxy(100, 600, "Press ESCAPE to exit");
            knox = 1;
        }
        if (GetAsyncKeyState(VK_LBUTTON)) {
            Beep(500, 200);
            GetCursorPos(&cursorPosition);
            if (cursorPosition.x >= 560 && cursorPosition.x <= 800 && cursorPosition.y >= 240 && cursorPosition.y <= 310) {
                setbkcolor(WHITE);
                setcolor(RED);
                cleardevice();
                while (1) {
                    delay(2);
                    cleardevice();
                    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
                    itoa(score, s, 10);
                    outtextxy(100, 50, "Score");
                    outtextxy(100, 100, s);
                    setcolor(BLACK);

                    if (score < 10) {
                        outtextxy(100, 350, "Press SPACE to jump");
                    }
                    car(i);

                    if (GetAsyncKeyState(VK_SPACE)) {
                        if (!(i < -1)) {
                            i = -1;
                        }
                    }
                    circle(spt -= 1, 200, 20);
                    setfillstyle(1, YELLOW);
                    floodfill(sp -= 1, 200, BLACK);

                    if (spt == 5) {
                        spt = 1200;
                        sp = spt;
                    }
                    rectangle(n -= speed, 470, temp = temp - speed, 500);

                    if (n <= 500) {
                        rectangle(n1 = n + 600, 470, temp1 = temp + 600, 500);

                        if (n <= 100) {
                            score = score + 10;
                            n = n1;
                            temp = temp1;
                            n1 = 1200;
                            temp1 = 1210;
                            if ((score % 10) == 0) {
                                    if((score<320))
                                speed = speed + 0.2;
                            else
                            {
                                speed=speed-0.2;
                            }
                            }
                        }
                    }

                    if (i != 0 && i > -60 && j != 0) {
                        if (i == -59)

                            j = 0;
                        i -= 2;
                    }
                    else if (j == 0) {
                        i = i + 2;
                        if (i == -1) {
                            j = 100;
                            i = 0;
                        }
                    }

                    if ((crash + i) >= 470 && (crash + i) <= 500 && n <= 165 && n >= 100) {
                        Beep(1000, 50);
                        Beep(1500, 50);
                        Beep(2000, 50);
                        Beep(2500, 50);
                        Beep(500, 100);
                        cleardevice();
                        setcolor(BLUE);
                        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 5);
                        fflush(stdout);
                        outtextxy(500, 250, "Your Score");
                        outtextxy(600, 350, s);
                        delay(1000);
                        cleardevice();
                        savesc(s);
                        goto start;
                    }
                    else if (GetAsyncKeyState(VK_ESCAPE)) {
                        exit(0);
                    }
                }
            }
            else if (cursorPosition.x >= 560 && cursorPosition.x <= 800 && cursorPosition.y >= 310 && cursorPosition.y <= 380) {
                c.INSTRUCTIONS();
                knox = 0;
            }
            else if (cursorPosition.x >= 560 && cursorPosition.x <= 800 && cursorPosition.y >= 380 && cursorPosition.y <= 450) {
                c.HIGHSCORES();
                knox = 0;
            }
            else {
                knox = 0;
                goto menu;
            }
        }

        else if (GetAsyncKeyState(VK_ESCAPE)) {
            exit(0);
        }
    }

    return 0;
}
