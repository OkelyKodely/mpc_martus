#include <iostream>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <unistd.h>
#include <mmsystem.h>

using namespace std;

#define PLAY_AGAIN_BUTTON 100
#define ID_TRACKBAR 210

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#include <wingdi.h>
#include <commctrl.h>
#define GetCurrentDir getcwd
#endif

BOOL dontplay = FALSE;

const char g_szClassName[] = "Martus";

DWORD WINAPI callMe(void *data) {
  
    PlaySound(TEXT("Tetris.wav"), NULL, SND_LOOP | SND_ASYNC);
    
    return 0;
}

class Mein {
public:
    HANDLE threa, thread, thrad;

    char filename[FILENAME_MAX];
    char buff[FILENAME_MAX];
    
    string choice;
    string choicepre = "sq";
    int sleeptime = 8000;
    int points=0;
    int level = 1;
    int blocks=0;
    int lines=0;
    int linenext = 10;
    int b[740][720];

    int showNextBg = 1;

    HWND hwnd;
    HWND hwnd_title;
    HWND hwnd_new_game;
    HWND hwnd_stage;
    HWND hwnd_next;
    HWND hwnd_lines;
    HWND hwnd_points;
    HWND hwnd_blocks;
    HWND hwnd_level;

    HINSTANCE hInst;
    BITMAP bitmap;
    WNDCLASSEX wc;
    HDC hdcMem;
    HGDIOBJ oldBitmap;
    HBITMAP hBitmap, hb1,hb2,hb3,hb4,hb5;
    HFONT font;
    MSG Msg;
    BOOLEAN fist = TRUE;
    HDC hdc;
    HDC hdc2;
    PAINTSTRUCT ps;
    BITMAP bitmaps;
    HDC hdcMems;
    HGDIOBJ oldBitmaps;
    HBITMAP hbitmap, hhbbs;

    class hat {
    public:
      Mein *mm;
      hat(Mein *m) { mm = m; }
      int x0;
      int y0;
      int x1;
      int y1;
      int x2;
      int y2;
      int x3;
      int y3;
      int dir;
      
      void rotate() {
        HBRUSH brush = CreateSolidBrush(RGB(225, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);

        if(mm->choice == "ht") {

            int htx0, hty0, htx1, hty1, htx2, hty2, htx3, hty3, htdir;

            htdir = dir;
            htx0 = x0;
            hty0 = y0;
            htx1 = x1;
            hty1 = y1;
            htx2 = x2;
            hty2 = y2;
            htx3 = x3;
            hty3 = y3;

            if(dir == 0) {
                dir = 1;
                x0 += 20* 0;
                y0 += 20* 0;
                x1 += 20* 0;
                y1 -= 20* 2;
                x2 -= 20* 1;
                y2 -= 20* 1;
                x3 -= 20* 2;
                y3 -= 20* 0;
            }
            else if(dir == 1) {
                dir = 2;
                x0 -= 20* 0;
                y0 += 20* 0;
                x1 += 20* 2;
                y1 += 20* 0;
                x2 += 20* 1;
                y2 -= 20* 1;
                x3 -= 20* 0;
                y3 -= 20* 2;
            }
            else if(dir == 2) {
                dir = 3;
                x0 -= 20* 0;
                y0 -= 20* 0;
                x1 -= 20* 0;
                y1 += 20* 2;
                x2 += 20* 1;
                y2 += 20* 1;
                x3 += 20* 2;
                y3 += 20* 0;
            }
            else if(dir == 3) {
                dir = 0;
                x0 += 20* 0;
                y0 -= 20* 0;
                x1 -= 20* 2;
                y1 -= 20* 0;
                x2 -= 20* 1;
                y2 += 20* 1;
                x3 -= 20* 0;
                y3 += 20* 2;
            }

            if(x0 > 400 || x1 > 400 || x2 > 400 || x3 > 400 ||
               x0 < 220 || x1 < 220 || x2 < 220 || x3 < 220) {
                dir = htdir;
                x0 = htx0;
                y0 = hty0;
                x1 = htx1;
                y1 = hty1;
                x2 = htx2;
                y2 = hty2;
                x3 = htx3;
                y3 = hty3;
            }

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);
            DeleteObject(brush);
        }
      }
      
      BOOL goLeft() {

        HBRUSH brush = CreateSolidBrush(RGB(225, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);

        if(mm->choice == "ht" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
            if(x0 > 220 &&
               x1 > 220 &&
               x2 > 220 &&
               x3 > 220) {
                if(mm->b[x0-20][y0] == 0 &&
                   mm->b[x1-20][y1] == 0 &&
                   mm->b[x2-20][y2] == 0 &&
                   mm->b[x3-20][y3] == 0) {
                    x0 -= 20;
                    x1 -= 20;
                    x2 -= 20;
                    x3 -= 20;
                }
            }

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);

            DeleteObject(brush);

            BOOLEAN flag = FALSE;
            if(mm->b[x0][y0+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x1][y1+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x2][y2+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x3][y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }
            if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
        }
      }

      BOOL goRight() {
        HBRUSH brush = CreateSolidBrush(RGB(225, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);

        if(mm->choice == "ht" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
            if(mm->b[x0+20][y0] == 0 &&
               mm->b[x1+20][y1] == 0 &&
               mm->b[x2+20][y2] == 0 &&
               mm->b[x3+20][y3] == 0 &&

               x0 < 400 &&
               x1 < 400 &&
               x2 < 400 &&
               x3 < 400
               ) {
                x0 += 20;
                x1 += 20;
                x2 += 20;
                x3 += 20;
            }

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);
            DeleteObject(brush);

            ////thrad = CreateThread(0, 0, moveSound, 0, 0, NULL);

            BOOLEAN flag = FALSE;
            if(mm->b[x0][y0+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x1][y1+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x2][y2+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x3][y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }
            if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
        }
      }
      
      BOOL goDown() {
        BOOL canGoDown = FALSE;

        HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);
        DeleteObject(brush);
          
        if(mm->choice == "ht" && (y0 <= 630 && y1 <= 630 && y2 <= 630 && y3 <= 630)) {
            if(mm->b[x0][y0+20] == 0 &&
               mm->b[x1][y1+20] == 0 &&
               mm->b[x2][y2+20] == 0 &&
               mm->b[x3][y3+20] == 0) {
                y0 += 20;
                y1 += 20;
                y2 += 20;
                y3 += 20;
            }

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);
            DeleteObject(brush);

            ////thrad = CreateThread(0, 0, moveSound, 0, 0, NULL);

            BOOLEAN flag = FALSE;
            if(mm->b[x0][y0+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x1][y1+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x2][y2+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x3][y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                canGoDown = TRUE;
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            } else
                canGoDown = FALSE;
            
            if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
        }
        
        return canGoDown;
      }
    };

    hat* ht = new hat(this);

    class square {
    public:
        Mein *mm;
        square(Mein *m) { mm = m; }
        int x0;
        int y0;
        int x1;
        int y1;
        int x2;
        int y2;
        int x3;
        int y3;

        void rotate() {
            HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
            RECT rrect3 = {219, 20, 420, 690};
            FillRect(mm->hdc2, &rrect3, brush);
            DeleteObject(brush);

            if(mm->choice == "sq") {

                y0 += 0;
                y1 += 0;
                y2 += 0;
                y3 += 0;

                HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

                RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
                FillRect(mm->hdc2, &rrect3, brush);

                RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
                FillRect(mm->hdc2, &rrect4, brush);

                RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
                FillRect(mm->hdc2, &rrect5, brush);

                RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
                FillRect(mm->hdc2, &rrect6, brush);
                DeleteObject(brush);
            }
        }
        
        BOOL goLeft() {
            HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
            RECT rrect3 = {219, 20, 420, 690};
            FillRect(mm->hdc2, &rrect3, brush);

            if(mm->choice == "sq" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
                if(x0 > 220 &&
                   x1 > 220 &&
                   x2 > 220 &&
                   x3 > 220) {
                    if(mm->b[x0-20][y0] == 0 &&
                       mm->b[x1-20][y1] == 0 &&
                       mm->b[x2-20][y2] == 0 &&
                       mm->b[x3-20][y3] == 0) {
                        x0 -= 20;
                        x1 -= 20;
                        x2 -= 20;
                        x3 -= 20;
                    }
                }

                HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
                FillRect(mm->hdc2, &rrect3, brush);

                RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
                FillRect(mm->hdc2, &rrect4, brush);

                RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
                FillRect(mm->hdc2, &rrect5, brush);

                RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
                FillRect(mm->hdc2, &rrect6, brush);

                DeleteObject(brush);
            }
        }
        
        BOOL goRight() {
            HBRUSH brush = CreateSolidBrush(RGB(225, 122, 185));
            RECT rrect3 = {219, 20, 420, 690};
            FillRect(mm->hdc2, &rrect3, brush);

            if(mm->choice == "sq" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
                if(mm->b[x0+20][y0] == 0 &&
                   mm->b[x1+20][y1] == 0 &&
                   mm->b[x2+20][y2] == 0 &&
                   mm->b[x3+20][y3] == 0 &&

                   x0 < 400 &&
                   x1 < 400 &&
                   x2 < 400 &&
                   x3 < 400
                   ) {
                    x0 += 20;
                    x1 += 20;
                    x2 += 20;
                    x3 += 20;
                }

                HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

                RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
                FillRect(mm->hdc2, &rrect3, brush);

                RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
                FillRect(mm->hdc2, &rrect4, brush);

                RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
                FillRect(mm->hdc2, &rrect5, brush);

                RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
                FillRect(mm->hdc2, &rrect6, brush);
                DeleteObject(brush);
            }
        }

        BOOL goDown() {
            BOOL canGoDown = FALSE;

            HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
            RECT rrect3 = {219, 20, 420, 690};
            FillRect(mm->hdc2, &rrect3, brush);
            DeleteObject(brush);

            if(mm->choice == "sq" && (y0 <= 630 && y1 <= 630 && y2 <= 630 && y3 <= 630)) {
                y0 += 20;
                y1 += 20;
                y2 += 20;
                y3 += 20;

                HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

                RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
                FillRect(mm->hdc2, &rrect3, brush);

                RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
                FillRect(mm->hdc2, &rrect4, brush);

                RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
                FillRect(mm->hdc2, &rrect5, brush);

                RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
                FillRect(mm->hdc2, &rrect6, brush);
                DeleteObject(brush);

                if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                    mm->b[x0][y0] = 1;
                    mm->b[x1][y1] = 1;
                    mm->b[x2][y2] = 1;
                    mm->b[x3][y3] = 1;
                    mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,"sdf");
                    mm->prep();
                } else {
                }

                BOOLEAN flag = FALSE;
                if(mm->b[x0][y0+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x1][y1+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x2][y2+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x3][y3+20] == 1) {
                    flag = TRUE;
                }
                if(flag) {
                    canGoDown = TRUE;
                    mm->b[x0][y0] = 1;
                    mm->b[x1][y1] = 1;
                    mm->b[x2][y2] = 1;
                    mm->b[x3][y3] = 1;
                    mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                    mm->prep();
                } else
                    canGoDown = FALSE;
                
                if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
            }
        }
    };

    square* sq = new square(this);

    class line {
    public:
        Mein *mm;
        line(Mein *m) { mm = m; }
        int x0;
        int y0;
        int x1;
        int y1;
        int x2;
        int y2;
        int x3;
        int y3;
        int dir;

        void rotate() {
            HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
            RECT rrect3 = {219, 20, 420, 690};
            FillRect(mm->hdc2, &rrect3, brush);
            DeleteObject(brush);

            if(mm->choice == "lne") {

                int lnex0, lney0, lnex1, lney1, lnex2, lney2, lnex3, lney3, lnedir;

                lnedir = dir;
                lnex0 = x0;
                lney0 = y0;
                lnex1 = x1;
                lney1 = y1;
                lnex2 = x2;
                lney2 = y2;
                lnex3 = x3;
                lney3 = y3;

                if(dir == 0) {
                    dir = 1;
                    x0 += 20* 3;
                    y0 += 20* 3;
                    x1 += 20* 2;
                    y1 += 20* 2;
                    x2 += 20* 1;
                    y2 += 20* 1;
                    x3 += 20* 0;
                    y3 += 20* 0;
                }
                else if(dir == 1) {
                    dir = 2;
                    x0 -= 20* 3;
                    y0 += 20* 3;
                    x1 -= 20* 2;
                    y1 += 20* 2;
                    x2 -= 20* 1;
                    y2 += 20* 1;
                    x3 -= 20* 0;
                    y3 += 20* 0;
                }
                else if(dir == 2) {
                    dir = 3;
                    x0 -= 20* 3;
                    y0 -= 20* 3;
                    x1 -= 20* 2;
                    y1 -= 20* 2;
                    x2 -= 20* 1;
                    y2 -= 20* 1;
                    x3 -= 20* 0;
                    y3 -= 20* 0;
                }
                else if(dir == 3) {
                    dir = 0;
                    x0 += 20* 3;
                    y0 -= 20* 3;
                    x1 += 20* 2;
                    y1 -= 20* 2;
                    x2 += 20* 1;
                    y2 -= 20* 1;
                    x3 += 20* 0;
                    y3 -= 20* 0;
                }

                if(x0 > 400 || x1 > 400 || x2 > 400 || x3 > 400 ||
                   x0 < 220 || x1 < 220 || x2 < 220 || x3 < 220) {
                    dir = lnedir;
                    x0 = lnex0;
                    y0 = lney0;
                    x1 = lnex1;
                    y1 = lney1;
                    x2 = lnex2;
                    y2 = lney2;
                    x3 = lnex3;
                    y3 = lney3;
                }

                HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

                RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
                FillRect(mm->hdc2, &rrect3, brush);

                RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
                FillRect(mm->hdc2, &rrect4, brush);

                RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
                FillRect(mm->hdc2, &rrect5, brush);

                RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
                FillRect(mm->hdc2, &rrect6, brush);
                DeleteObject(brush);
            }
        }
        
        BOOL goLeft() {
            HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
            RECT rrect3 = {219, 20, 420, 690};
            FillRect(mm->hdc2, &rrect3, brush);
            DeleteObject(brush);

            if(mm->choice == "lne" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
                if(x0 > 220 &&
                   x1 > 220 &&
                   x2 > 220 &&
                   x3 > 220) {
                    if(mm->b[x0-20][y0] == 0 &&
                       mm->b[x1-20][y1] == 0 &&
                       mm->b[x2-20][y2] == 0 &&
                       mm->b[x3-20][y3] == 0) {
                        x0 -= 20;
                        x1 -= 20;
                        x2 -= 20;
                        x3 -= 20;
                    }
                }

                HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

                RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
                FillRect(mm->hdc2, &rrect3, brush);

                RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
                FillRect(mm->hdc2, &rrect4, brush);

                RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
                FillRect(mm->hdc2, &rrect5, brush);

                RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
                FillRect(mm->hdc2, &rrect6, brush);

                DeleteObject(brush);
            }
        }
        
        BOOL goRight() {
            HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
            RECT rrect3 = {219, 20, 420, 690};
            FillRect(mm->hdc2, &rrect3, brush);
            DeleteObject(brush);

            if(mm->choice == "lne" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
              if(mm->b[x0+20][y0] == 0 &&
                 mm->b[x1+20][y1] == 0 &&
                 mm->b[x2+20][y2] == 0 &&
                 mm->b[x3+20][y3] == 0 &&

                 x0 < 400 &&
                 x1 < 400 &&
                 x2 < 400 &&
                 x3 < 400
                 ) {
                  x0 += 20;
                  x1 += 20;
                  x2 += 20;
                  x3 += 20;
              }

              HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

              RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
              FillRect(mm->hdc2, &rrect3, brush);

              RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
              FillRect(mm->hdc2, &rrect4, brush);

              RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
              FillRect(mm->hdc2, &rrect5, brush);

              RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
              FillRect(mm->hdc2, &rrect6, brush);
              DeleteObject(brush);
          }
        }
        
        BOOL goDown() {
            BOOL canGoDown = FALSE;

            HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
            RECT rrect3 = {219, 20, 420, 690};
            FillRect(mm->hdc2, &rrect3, brush);
            DeleteObject(brush);

            if(mm->choice == "lne" && (y0 <= 580 || y1 <= 580 || y2 <= 580 || y3 <= 580)) {
                y0 += 20;
                y1 += 20;
                y2 += 20;
                y3 += 20;

                HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

                RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
                FillRect(mm->hdc2, &rrect3, brush);

                RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
                FillRect(mm->hdc2, &rrect4, brush);

                RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
                FillRect(mm->hdc2, &rrect5, brush);

                RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
                FillRect(mm->hdc2, &rrect6, brush);
                DeleteObject(brush);

                if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                    mm->b[x0][y0] = 1;
                    mm->b[x1][y1] = 1;
                    mm->b[x2][y2] = 1;
                    mm->b[x3][y3] = 1;
                    mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                    mm->prep();
                } else {
                }

                BOOLEAN flag = FALSE;
                if(mm->b[x0][y0+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x1][y1+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x2][y2+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x3][y3+20] == 1) {
                    flag = TRUE;
                }
                if(flag) {
                    canGoDown = TRUE;
                    mm->b[x0][y0] = 1;
                    mm->b[x1][y1] = 1;
                    mm->b[x2][y2] = 1;
                    mm->b[x3][y3] = 1;
                    mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                    mm->prep();
                } else
                    canGoDown = FALSE;
                
                if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
            }
            
            return canGoDown;
        }
    };

    line* lne = new line(this);

    class lsho {
    public:
        Mein *mm;
        lsho(Mein *m) { mm = m; }
        int x0;
        int y0;
        int x1;
        int y1;
        int x2;
        int y2;
        int x3;
        int y3;
        int dir;
        
        void rotate() {
            HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
            RECT rrect3 = {219, 20, 420, 690};
            FillRect(mm->hdc2, &rrect3, brush);
            DeleteObject(brush);

            if(mm->choice == "lsh") {

                int lshx0, lshy0, lshx1, lshy1, lshx2, lshy2, lshx3, lshy3, lshdir;

                lshdir = dir;
                lshx0 = x0;
                lshy0 = y0;
                lshx1 = x1;
                lshy1 = y1;
                lshx2 = x2;
                lshy2 = y2;
                lshx3 = x3;
                lshy3 = y3;

                if(dir == 0) {
                    dir = 1;
                    x0 += 20* 1;
                    y0 += 20* 1;
                    x1 += 20* 1;
                    y1 -= 20* 1;
                    x2 += 20* 0;
                    y2 += 20* 0;
                    x3 += 20* 0;
                    y3 -= 20* 2;
                }
                else if(dir == 1) {
                    dir = 2;
                    x0 -= 20* 1;
                    y0 += 20* 1;
                    x1 += 20* 1;
                    y1 += 20* 1;
                    x2 -= 20* 0;
                    y2 += 20* 0;
                    x3 += 20* 2;
                    y3 -= 20* 0;
                }
                else if(dir == 2) {
                    dir = 3;
                    x0 -= 20* 1;
                    y0 -= 20* 1;
                    x1 -= 20* 1;
                    y1 += 20* 1;
                    x2 -= 20* 0;
                    y2 -= 20* 0;
                    x3 -= 20* 0;
                    y3 += 20* 2;
                }
                else if(dir == 3) {
                    dir = 0;
                    x0 += 20* 1;
                    y0 -= 20* 1;
                    x1 -= 20* 1;
                    y1 -= 20* 1;
                    x2 += 20* 0;
                    y2 -= 20* 0;
                    x3 -= 20* 2;
                    y3 += 20* 0;
                }

                if(x0 > 400 || x1 > 400 || x2 > 400 || x3 > 400 ||
                   x0 < 220 || x1 < 220 || x2 < 220 || x3 < 220) {
                    dir = lshdir;
                    x0 = lshx0;
                    y0 = lshy0;
                    x1 = lshx1;
                    y1 = lshy1;
                    x2 = lshx2;
                    y2 = lshy2;
                    x3 = lshx3;
                    y3 = lshy3;
                }

                HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

                RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
                FillRect(mm->hdc2, &rrect3, brush);

                RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
                FillRect(mm->hdc2, &rrect4, brush);

                RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
                FillRect(mm->hdc2, &rrect5, brush);

                RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
                FillRect(mm->hdc2, &rrect6, brush);
                DeleteObject(brush);
            }
        }
        
        BOOL goLeft() {
            HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
            RECT rrect3 = {219, 20, 420, 690};
            FillRect(mm->hdc2, &rrect3, brush);
            DeleteObject(brush);

            if(mm->choice == "lsh" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
                if(x0 > 220 &&
                   x1 > 220 &&
                   x2 > 220 &&
                   x3 > 220) {
                    if(mm->b[x0-20][y0] == 0 &&
                       mm->b[x1-20][y1] == 0 &&
                       mm->b[x2-20][y2] == 0 &&
                       mm->b[x3-20][y3] == 0) {
                        x0 -= 20;
                        x1 -= 20;
                        x2 -= 20;
                        x3 -= 20;
                    }
                }

                HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

                RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
                FillRect(mm->hdc2, &rrect3, brush);

                RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
                FillRect(mm->hdc2, &rrect4, brush);

                RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
                FillRect(mm->hdc2, &rrect5, brush);

                RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
                FillRect(mm->hdc2, &rrect6, brush);

                DeleteObject(brush);

                if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                    mm->b[x0][y0] = 1;
                    mm->b[x1][y1] = 1;
                    mm->b[x2][y2] = 1;
                    mm->b[x3][y3] = 1;
                    mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                    mm->prep();
                }

                ////thrad = CreateThread(0, 0, moveSound, 0, 0, NULL);

                BOOLEAN flag = FALSE;
                if(mm->b[x0][y0+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x1][y1+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x2][y2+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x3][y3+20] == 1) {
                    flag = TRUE;
                }
                if(flag) {
                    mm->b[x0][y0] = 1;
                    mm->b[x1][y1] = 1;
                    mm->b[x2][y2] = 1;
                    mm->b[x3][y3] = 1;
                    mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                    mm->prep();
                }
                if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
                for(int i=0; i<700; i++) {
                    for(int j=0; j<700; j++) {
                        if(mm->b[i][j] == 1) {
                            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                            RECT rrect6 = {i, j, i + 20, j + 20};
                            FillRect(mm->hdc2, &rrect6, brush);
                            DeleteObject(brush);

                            HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                            HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                            Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                            DeleteObject(SelectObject(mm->hdc2, hOldPen));
                            SelectObject(mm->hdc2, hOldBsh);
                        }
                    }
                }
            }
        }
        
        BOOL goRight() {
            HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
            RECT rrect3 = {219, 20, 420, 690};
            FillRect(mm->hdc2, &rrect3, brush);
            DeleteObject(brush);

            if(mm->choice == "lsh" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
                if(mm->b[x0+20][y0] == 0 &&
                   mm->b[x1+20][y1] == 0 &&
                   mm->b[x2+20][y2] == 0 &&
                   mm->b[x3+20][y3] == 0 &&

                   x0 < 400 &&
                   x1 < 400 &&
                   x2 < 400 &&
                   x3 < 400
                   ) {
                    x0 += 20;
                    x1 += 20;
                    x2 += 20;
                    x3 += 20;
                }

                HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

                RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
                FillRect(mm->hdc2, &rrect3, brush);

                RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
                FillRect(mm->hdc2, &rrect4, brush);

                RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
                FillRect(mm->hdc2, &rrect5, brush);

                RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
                FillRect(mm->hdc2, &rrect6, brush);
                DeleteObject(brush);

                if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                    mm->b[x0][y0] = 1;
                    mm->b[x1][y1] = 1;
                    mm->b[x2][y2] = 1;
                    mm->b[x3][y3] = 1;
                    mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                    mm->prep();
                }

                ////thrad = CreateThread(0, 0, moveSound, 0, 0, NULL);

                BOOLEAN flag = FALSE;
                if(mm->b[x0][y0+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x1][y1+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x2][y2+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x3][y3+20] == 1) {
                    flag = TRUE;
                }
                if(flag) {
                    mm->b[x0][y0] = 1;
                    mm->b[x1][y1] = 1;
                    mm->b[x2][y2] = 1;
                    mm->b[x3][y3] = 1;
                    mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                    mm->prep();
                }
                if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
                for(int i=0; i<700; i++) {
                    for(int j=0; j<700; j++) {
                        if(mm->b[i][j] == 1) {
                            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                            RECT rrect6 = {i, j, i + 20, j + 20};
                            FillRect(mm->hdc2, &rrect6, brush);
                            DeleteObject(brush);

                            HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                            HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                            Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                            DeleteObject(SelectObject(mm->hdc2, hOldPen));
                            SelectObject(mm->hdc2, hOldBsh);
                        }
                    }
                }
            }
        }

        BOOL goDown() {
            BOOL canGoDown = FALSE;

            HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
            RECT rrect3 = {219, 20, 420, 690};
            FillRect(mm->hdc2, &rrect3, brush);
            DeleteObject(brush);

            if(mm->choice == "lsh" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
                y0 += 20;
                y1 += 20;
                y2 += 20;
                y3 += 20;

                HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

                RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
                FillRect(mm->hdc2, &rrect3, brush);

                RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
                FillRect(mm->hdc2, &rrect4, brush);

                RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
                FillRect(mm->hdc2, &rrect5, brush);

                RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
                FillRect(mm->hdc2, &rrect6, brush);
                DeleteObject(brush);

                if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                    mm->b[x0][y0] = 1;
                    mm->b[x1][y1] = 1;
                    mm->b[x2][y2] = 1;
                    mm->b[x3][y3] = 1;
                    mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                    mm->prep();
                } else {
                }

                BOOLEAN flag = FALSE;
                if(mm->b[x0][y0+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x1][y1+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x2][y2+20] == 1) {
                    flag = TRUE;
                }
                else if(mm->b[x3][y3+20] == 1) {
                    flag = TRUE;
                }
                if(flag) {
                    canGoDown = TRUE;
                    mm->b[x0][y0] = 1;
                    mm->b[x1][y1] = 1;
                    mm->b[x2][y2] = 1;
                    mm->b[x3][y3] = 1;
                    mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                    mm->prep();
                } else
                    canGoDown = FALSE;
                
                if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
                for(int i=0; i<700; i++) {
                    for(int j=0; j<700; j++) {
                        if(mm->b[i][j] == 1) {
                            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                            RECT rrect6 = {i, j, i + 20, j + 20};
                            FillRect(mm->hdc2, &rrect6, brush);
                            DeleteObject(brush);

                            HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                            HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                            Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                            DeleteObject(SelectObject(mm->hdc2, hOldPen));
                            SelectObject(mm->hdc2, hOldBsh);
                        }
                    }
                }
            
                return canGoDown;
            }
        }
    };

    lsho* lsh = new lsho(this);

    class rsho {
    public:
      Mein *mm;
      rsho(Mein *m) { mm = m; }
      int x0;
      int y0;
      int x1;
      int y1;
      int x2;
      int y2;
      int x3;
      int y3;
      int dir;
      
      void rotate() {
        HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(mm->choice == "rsh") {

            int rshx0, rshy0, rshx1, rshy1, rshx2, rshy2, rshx3, rshy3, rshdir;

            rshdir = dir;
            rshx0 = x0;
            rshy0 = y0;
            rshx1 = x1;
            rshy1 = y1;
            rshx2 = x2;
            rshy2 = y2;
            rshx3 = x3;
            rshy3 = y3;

            if(dir == 0) {
                dir = 1;
                x0 += 20* 1;
                y0 += 20* 1;
                x1 += 20* 0;
                y1 += 20* 0;
                x2 -= 20* 1;
                y2 += 20* 1;
                x3 -= 20* 2;
                y3 += 20* 0;
            }
            else if(dir == 1) {
                dir = 2;
                x0 -= 20* 1;
                y0 += 20* 1;
                x1 += 20* 0;
                y1 += 20* 0;
                x2 -= 20* 1;
                y2 -= 20* 1;
                x3 -= 20* 0;
                y3 -= 20* 2;
            }
            else if(dir == 2) {
                dir = 3;
                x0 -= 20* 1;
                y0 -= 20* 1;
                x1 -= 20* 0;
                y1 -= 20* 0;
                x2 += 20* 1;
                y2 -= 20* 1;
                x3 += 20* 2;
                y3 -= 20* 0;
            }
            else if(dir == 3) {
                dir = 0;
                x0 += 20* 1;
                y0 -= 20* 1;
                x1 += 20* 0;
                y1 -= 20* 0;
                x2 += 20* 1;
                y2 += 20* 1;
                x3 += 20* 0;
                y3 += 20* 2;
            }

            if(x0 > 400 || x1 > 400 || x2 > 400 || x3 > 400 ||
               x0 < 220 || x1 < 220 || x2 < 220 || x3 < 220) {
                dir = rshdir;
                x0 = rshx0;
                y0 = rshy0;
                x1 = rshx1;
                y1 = rshy1;
                x2 = rshx2;
                y2 = rshy2;
                x3 = rshx3;
                y3 = rshy3;
            }

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);
            DeleteObject(brush);
        }
      }
      
      BOOL goLeft() {
        HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(mm->choice == "rsh" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
            if(x0 > 220 &&
               x1 > 220 &&
               x2 > 220 &&
               x3 > 220) {
                if(mm->b[x0-20][y0] == 0 &&
                   mm->b[x1-20][y1] == 0 &&
                   mm->b[x2-20][y2] == 0 &&
                   mm->b[x3-20][y3] == 0) {
                    x0 -= 20;
                    x1 -= 20;
                    x2 -= 20;
                    x3 -= 20;
                }
            }

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }

            ////thrad = CreateThread(0, 0, moveSound, 0, 0, NULL);

            BOOLEAN flag = FALSE;
            if(mm->b[x0][y0+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x1][y1+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x2][y2+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x3][y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }
            if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mm->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mm->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mm->hdc2, hOldPen));
                        SelectObject(mm->hdc2, hOldBsh);
                    }
                }
            }
        }
      }
      
      BOOL goRight() {
        HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(mm->choice == "rsh" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
            if(mm->b[x0+20][y0] == 0 &&
               mm->b[x1+20][y1] == 0 &&
               mm->b[x2+20][y2] == 0 &&
               mm->b[x3+20][y3] == 0 &&

               x0 < 400 &&
               x1 < 400 &&
               x2 < 400 &&
               x3 < 400
               ) {
                x0 += 20;
                x1 += 20;
                x2 += 20;
                x3 += 20;
            }

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }

            ////thrad = CreateThread(0, 0, moveSound, 0, 0, NULL);

            BOOLEAN flag = FALSE;
            if(mm->b[x0][y0+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x1][y1+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x2][y2+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x3][y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }
            if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mm->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mm->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mm->hdc2, hOldPen));
                        SelectObject(mm->hdc2, hOldBsh);
                    }
                }
            }
        }
      }

      BOOL goDown() {
        BOOL canGoDown = FALSE;

        HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(mm->choice == "rsh" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
            y0 += 20;
            y1 += 20;
            y2 += 20;
            y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            } else {
            }

            BOOLEAN flag = FALSE;
            if(mm->b[x0][y0+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x1][y1+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x2][y2+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x3][y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                canGoDown = TRUE;
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            } else
                canGoDown = FALSE;
            
            if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mm->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mm->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mm->hdc2, hOldPen));
                        SelectObject(mm->hdc2, hOldBsh);
                    }
                }
            }
        }
        
        return canGoDown;
      }
    };

    rsho* rsh = new rsho(this);

    class Larm {
    public:
      Mein *mm;
      Larm(Mein *m) { mm = m; }
      int x0;
      int y0;
      int x1;
      int y1;
      int x2;
      int y2;
      int x3;
      int y3;
      int dir;
      
      void rotate() {
            HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
            RECT rrect3 = {219, 20, 420, 690};
            FillRect(mm->hdc2, &rrect3, brush);
            DeleteObject(brush);

            if(mm->choice == "larm") {

                int larmx0, larmy0, larmx1, larmy1, larmx2, larmy2, larmx3, larmy3, larmdir;

                larmdir = dir;
                larmx0 = x0;
                larmy0 = y0;
                larmx1 = x1;
                larmy1 = y1;
                larmx2 = x2;
                larmy2 = y2;
                larmx3 = x3;
                larmy3 = y3;

                if(dir == 0) {
                    dir = 1;
                    x0 += 20* 2;
                    y0 += 20* 2;
                    x1 += 20* 1;
                    y1 += 20* 1;
                    x2 += 20* 0;
                    y2 += 20* 0;
                    x3 += 20* 1;
                    y3 -= 20* 1;
                }
                else if(dir == 1) {
                    dir = 2;
                    x0 -= 20* 2;
                    y0 += 20* 2;
                    x1 -= 20* 1;
                    y1 += 20* 1;
                    x2 -= 20* 0;
                    y2 += 20* 0;
                    x3 += 20* 1;
                    y3 += 20* 1;
                }
                else if(dir == 2) {
                    dir = 3;
                    x0 -= 20* 2;
                    y0 -= 20* 2;
                    x1 -= 20* 1;
                    y1 -= 20* 1;
                    x2 -= 20* 0;
                    y2 -= 20* 0;
                    x3 -= 20* 1;
                    y3 += 20* 1;
                }
                else if(dir == 3) {
                    dir = 0;
                    x0 += 20* 2;
                    y0 -= 20* 2;
                    x1 += 20* 1;
                    y1 -= 20* 1;
                    x2 += 20* 0;
                    y2 -= 20* 0;
                    x3 -= 20* 1;
                    y3 -= 20* 1;
                }

                if(x0 > 400 || x1 > 400 || x2 > 400 || x3 > 400 ||
                   x0 < 220 || x1 < 220 || x2 < 220 || x3 < 220) {
                    dir = larmdir;
                    x0 = larmx0;
                    y0 = larmy0;
                    x1 = larmx1;
                    y1 = larmy1;
                    x2 = larmx2;
                    y2 = larmy2;
                    x3 = larmx3;
                    y3 = larmy3;
                }

                HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

                RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
                FillRect(mm->hdc2, &rrect3, brush);

                RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
                FillRect(mm->hdc2, &rrect4, brush);

                RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
                FillRect(mm->hdc2, &rrect5, brush);

                RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
                FillRect(mm->hdc2, &rrect6, brush);
                DeleteObject(brush);
            }
      }
      
      BOOL goLeft() {
        HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(mm->choice == "larm" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
            if(x0 > 220 &&
               x1 > 220 &&
               x2 > 220 &&
               x3 > 220) {
                if(mm->b[x0-20][y0] == 0 &&
                   mm->b[x1-20][y1] == 0 &&
                   mm->b[x2-20][y2] == 0 &&
                   mm->b[x3-20][y3] == 0) {
                    x0 -= 20;
                    x1 -= 20;
                    x2 -= 20;
                    x3 -= 20;
                }
            }

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);

            DeleteObject(brush);

            if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }

            ////thrad = CreateThread(0, 0, moveSound, 0, 0, NULL);

            BOOLEAN flag = FALSE;
            if(mm->b[x0][y0+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x1][y1+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x2][y2+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x3][y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }
            if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mm->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mm->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mm->hdc2, hOldPen));
                        SelectObject(mm->hdc2, hOldBsh);
                    }
                }
            }
        }
      }
      
      BOOL goRight() {
        HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(mm->choice == "larm" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
            if(mm->b[x0+20][y0] == 0 &&
               mm->b[x1+20][y1] == 0 &&
               mm->b[x2+20][y2] == 0 &&
               mm->b[x3+20][y3] == 0 &&

               x0 < 400 &&
               x1 < 400 &&
               x2 < 400 &&
               x3 < 400
               ) {
                x0 += 20;
                x1 += 20;
                x2 += 20;
                x3 += 20;
            }

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }

            ////thrad = CreateThread(0, 0, moveSound, 0, 0, NULL);

            BOOLEAN flag = FALSE;
            if(mm->b[x0][y0+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x1][y1+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x2][y2+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x3][y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }
            if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mm->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mm->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mm->hdc2, hOldPen));
                        SelectObject(mm->hdc2, hOldBsh);
                    }
                }
            }
        }
          
      }

      BOOL goDown() {
        BOOL canGoDown = FALSE;

        HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(mm->choice == "larm" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
            y0 += 20;
            y1 += 20;
            y2 += 20;
            y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            } else {
            }

            BOOLEAN flag = FALSE;
            if(mm->b[x0][y0+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x1][y1+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x2][y2+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x3][y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                canGoDown = TRUE;
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            } else
                canGoDown = FALSE;
            
            if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mm->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mm->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mm->hdc2, hOldPen));
                        SelectObject(mm->hdc2, hOldBsh);
                    }
                }
            }
        }
        
        return canGoDown;
      }
    };

    Larm* larm = new Larm(this);

    class Rarm {
    public:
      Mein *mm;
      Rarm(Mein *m) { mm = m; }
      int x0;
      int y0;
      int x1;
      int y1;
      int x2;
      int y2;
      int x3;
      int y3;
      int dir;
      
      void rotate() {
        HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(mm->choice == "rarm") {

            int rarmx0, rarmy0, rarmx1, rarmy1, rarmx2, rarmy2, rarmx3, rarmy3, rarmdir;

            rarmdir = dir;
            rarmx0 = x0;
            rarmy0 = y0;
            rarmx1 = x1;
            rarmy1 = y1;
            rarmx2 = x2;
            rarmy2 = y2;
            rarmx3 = x3;
            rarmy3 = y3;

            if(dir == 0) {
                dir = 1;
                x0 += 20* 2;
                y0 += 20* 2;
                x1 += 20* 1;
                y1 += 20* 1;
                x2 += 20* 0;
                y2 += 20* 0;
                x3 -= 20* 1;
                y3 += 20* 1;
            }
            else if(dir == 1) {
                dir = 2;
                x0 -= 20* 2;
                y0 += 20* 2;
                x1 -= 20* 1;
                y1 += 20* 1;
                x2 -= 20* 0;
                y2 += 20* 0;
                x3 -= 20* 1;
                y3 -= 20* 1;
            }
            else if(dir == 2) {
                dir = 3;
                x0 -= 20* 2;
                y0 -= 20* 2;
                x1 -= 20* 1;
                y1 -= 20* 1;
                x2 -= 20* 0;
                y2 -= 20* 0;
                x3 += 20* 1;
                y3 -= 20* 1;
            }
            else if(dir == 3) {
                dir = 0;
                x0 += 20* 2;
                y0 -= 20* 2;
                x1 += 20* 1;
                y1 -= 20* 1;
                x2 += 20* 0;
                y2 -= 20* 0;
                x3 += 20* 1;
                y3 += 20* 1;
            }

            if(x0 > 400 || x1 > 400 || x2 > 400 || x3 > 400 ||
               x0 < 220 || x1 < 220 || x2 < 220 || x3 < 220) {
                dir = rarmdir;
                x0 = rarmx0;
                y0 = rarmy0;
                x1 = rarmx1;
                y1 = rarmy1;
                x2 = rarmx2;
                y2 = rarmy2;
                x3 = rarmx3;
                y3 = rarmy3;
            }

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);
            DeleteObject(brush);
        }
      }
      
      BOOL goLeft() {
        HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(mm->choice == "rarm" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
            if(x0 > 220 &&
               x1 > 220 &&
               x2 > 220 &&
               x3 > 220) {
                if(mm->b[x0-20][y0] == 0 &&
                   mm->b[x1-20][y1] == 0 &&
                   mm->b[x2-20][y2] == 0 &&
                   mm->b[x3-20][y3] == 0) {
                    x0 -= 20;
                    x1 -= 20;
                    x2 -= 20;
                    x3 -= 20;
                }
            }

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);

            DeleteObject(brush);

            if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }

            ////thrad = CreateThread(0, 0, moveSound, 0, 0, NULL);

            BOOLEAN flag = FALSE;
            if(mm->b[x0][y0+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x1][y1+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x2][y2+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x3][y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }
            if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mm->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mm->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mm->hdc2, hOldPen));
                        SelectObject(mm->hdc2, hOldBsh);
                    }
                }
            }
        }
      }
      
      BOOL goRight() {
        HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(mm->choice == "rarm" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
            if(mm->b[x0+20][y0] == 0 &&
               mm->b[x1+20][y1] == 0 &&
               mm->b[x2+20][y2] == 0 &&
               mm->b[x3+20][y3] == 0 &&

               x0 < 400 &&
               x1 < 400 &&
               x2 < 400 &&
               x3 < 400
               ) {
                x0 += 20;
                x1 += 20;
                x2 += 20;
                x3 += 20;
            }

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }

            ////thrad = CreateThread(0, 0, moveSound, 0, 0, NULL);

            BOOLEAN flag = FALSE;
            if(mm->b[x0][y0+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x1][y1+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x2][y2+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x3][y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            }
            if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mm->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mm->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mm->hdc2, hOldPen));
                        SelectObject(mm->hdc2, hOldBsh);
                    }
                }
            }
        }
      }
      
      BOOL goDown() {
        BOOL canGoDown = FALSE;

        HBRUSH brush = CreateSolidBrush(RGB(255, 122, 185));
        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mm->hdc2, &rrect3, brush);
        DeleteObject(brush);
 
        if(mm->choice == "rarm" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
            y0 += 20;
            y1 += 20;
            y2 += 20;
            y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
            FillRect(mm->hdc2, &rrect3, brush);

            RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
            FillRect(mm->hdc2, &rrect4, brush);

            RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
            FillRect(mm->hdc2, &rrect5, brush);

            RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
            FillRect(mm->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            } else {
            }

            BOOLEAN flag = FALSE;
            if(mm->b[x0][y0+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x1][y1+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x2][y2+20] == 1) {
                flag = TRUE;
            }
            else if(mm->b[x3][y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                canGoDown = TRUE;
                mm->b[x0][y0] = 1;
                mm->b[x1][y1] = 1;
                mm->b[x2][y2] = 1;
                mm->b[x3][y3] = 1;
                mm->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mm->blocks,mm->points,mm->lines);SetWindowText(mm->hwnd,aa);
                mm->prep();
            } else
                canGoDown = FALSE;
            
            if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mm->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mm->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mm->hdc2, hOldPen));
                        SelectObject(mm->hdc2, hOldBsh);
                    }
                }
            }
        }
        
        return canGoDown;
      }
    };

    Rarm* rarm = new Rarm(this);

    void prep() {
        choice = choicepre;
        if(fist) {
            int r = rand() % 7;
            if(r == 1)
              choicepre = "sq";
            else if(r == 2)
              choicepre = "lne";
            else if(r == 3)
              choicepre = "ht";
            else if(r == 4)
              choicepre = "larm";
            else if(r == 5)
              choicepre = "rarm";
            else if(r == 6)
              choicepre = "lsh";
            else
              choicepre = "rsh";
            choice = choicepre;
        }
        fist = FALSE;
        cout << choice;
        cout << "\n";
        int r = rand() % 7;
        if(r == 1)
          choicepre = "sq";
        else if(r == 2)
          choicepre = "lne";
        else if(r == 3)
          choicepre = "ht";
        else if(r == 4)
          choicepre = "larm";
        else if(r == 5)
          choicepre = "rarm";
        else if(r == 6)
          choicepre = "lsh";
        else
          choicepre = "rsh";
        lsh->x0 = 300;
        lsh->y0 = 50;
        lsh->x1 = 280;
        lsh->y1 = 70;
        lsh->x2 = 300;
        lsh->y2 = 70;
        lsh->x3 = 280;
        lsh->y3 = 90;
        lsh->dir = 0;
        rsh->x0 = 300;
        rsh->y0 = 50;
        rsh->x1 = 300;
        rsh->y1 = 70;
        rsh->x2 = 320;
        rsh->y2 = 70;
        rsh->x3 = 320;
        rsh->y3 = 90;
        rsh->dir = 0;
        larm->x0 = 300;
        larm->y0 = 50;
        larm->x1 = 300;
        larm->y1 = 70;
        larm->x2 = 300;
        larm->y2 = 90;
        larm->x3 = 280;
        larm->y3 = 90;
        larm->dir = 0;
        rarm->x0 = 300;
        rarm->y0 = 50;
        rarm->x1 = 300;
        rarm->y1 = 70;
        rarm->x2 = 300;
        rarm->y2 = 90;
        rarm->x3 = 320;
        rarm->y3 = 90;
        rarm->dir = 0;
        ht->x0 = 300;
        ht->y0 = 50;
        ht->x1 = 280;
        ht->y1 = 70;
        ht->x2 = 300;
        ht->y2 = 70;
        ht->x3 = 320;
        ht->y3 = 70;
        ht->dir = 0;
        sq->x0 = 300;
        sq->y0 = 50;
        sq->x1 = 320;
        sq->y1 = 50;
        sq->x2 = 300;
        sq->y2 = 70;
        sq->x3 = 320;
        sq->y3 = 70;
        lne->x0 = 300;
        lne->y0 = 50;
        lne->x1 = 300;
        lne->y1 = 70;
        lne->x2 = 300;
        lne->y2 = 90;
        lne->x3 = 300;
        lne->y3 = 110;
        lne->dir = 0;
    }

    void erasePreview() {
        HBRUSH brush11 = CreateSolidBrush(RGB(255, 0, 0));
        RECT rrect11 = {0, 12, 143, 233};
        FillRect(hdc2, &rrect11, brush11);
        DeleteObject(brush11);

        HBRUSH brush = CreateSolidBrush(RGB(100, 100, 100));
        RECT rrect5 = {0, 20, 129, 220};
        FillRect(hdc2, &rrect5, brush);
        DeleteObject(brush);
    }

    void showNextPiece() {
        if(choicepre == "sq") {
            HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
            RECT rrect5 = {-90+100, 100, -90+100 + 20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {-90+120, 100, -90+120 + 20, 100 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {-90+100, 120, -90+100 + 20, 120 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {-90+120, 120, -90+120 + 20, 120 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        } else if(choicepre == "lne") {
            HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
            RECT rrect5 = {-90+100, 100, -90+100 + 20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {-90+100, 120, -90+100 + 20, 120 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {-90+100, 140, -90+100 + 20, 140 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {-90+100, 160, -90+100 + 20, 160 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        } else if(choicepre == "ht") {
            HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
            RECT rrect5 = {-90+120, 100, -90+120 + 20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {-90+100, 120, -90+100 + 20, 120 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {-90+120, 120, -90+120 + 20, 120 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {-90+140, 120, -90+140 + 20, 120 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        } else if(choicepre == "larm") {
            HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
            RECT rrect5 = {-90+120, 100, -90+120 + 20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {-90+120, 120, -90+120 + 20, 120 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {-90+120, 140, -90+120 + 20, 140 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {-90+100, 140, -90+100 + 20, 140 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        } else if(choicepre == "rarm") {
            HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
            RECT rrect5 = {-90+120-20, 100, -90+120 + 20-20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {-90+120-20, 120, -90+120 + 20-20, 120 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {-90+120-20, 140, -90+120 + 20-20, 140 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {-90+140-20, 140, -90+140 + 20-20, 140 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        } else if(choicepre == "lsh") {
            HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
            RECT rrect5 = {-90+120, 100, -90+120 + 20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {-90+120, 120, -90+120 + 20, 120 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {-90+100, 120, -90+100 + 20, 120 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {-90+100, 140, -90+100 + 20, 140 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        } else if(choicepre == "rsh") {
            HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
            RECT rrect5 = {-90+100, 100, -90+100 + 20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {-90+100, 120, -90+100 + 20, 120 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {-90+120, 120, -90+120 + 20, 120 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {-90+120, 140, -90+120 + 20, 140 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        }
    }

    void clearLine() {

        int count = 0;

        int clearBlocks[700];

        int cc = 0;

        BOOLEAN keepon = TRUE;

        do {
            for(int i=0; i<700; i++) {
                clearBlocks[i] = 0;
            }

            for(int j=0; j<=700 && keepon; j++) {

                int clearThisLine = 0;

                for(int i=0; i<740; i++) {
                    if(1 == b[i][j]) {
                        clearThisLine++;
                    }
                }

                if(clearThisLine == 10) {
                    char aa[10];
                    sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowText(hwnd,aa);
                    clearBlocks[count] = j;
                    count++;
                    lines++;
                    points+=10;
                    keepon = FALSE;
                }
            }

            if(count > 0) {

                int cnt;

                cnt = 0;

                for(;cnt < count; cnt++) {
                    for(int j=0; j<700; j++) {
                        for(int i=0; i<740; i++) {
                            if(j == clearBlocks[cnt]) {
                                b[i][j] = 0;
                            }
                        }
                    }
                }

                cnt = 0;

                for(;cnt < count; cnt++) {
                    for(int j=650; j>=0; j-=20) {
                        for(int i=0; i<740; i++) {
                            if(b[i][j] == 1 && j < clearBlocks[cnt]) {
                                b[i][j] = 0;
                                b[i][j+20] = 1;
                            }
                        }
                    }
                }
            }

            cc++;

        } while(cc < 35);
    }

    void printMiscLabels(int stage) {    }
};

Mein* mein = new Mein();

DWORD WINAPI downs(void* data) {

    BOOLEAN downIt = TRUE;

    do {

        mein->hdcMems = CreateCompatibleDC(mein->hdc2);

        HBRUSH brush = CreateSolidBrush(RGB(225, 122, 185));

        RECT rrect3 = {219, 20, 420, 690};
        FillRect(mein->hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(mein->choice == "sq" && (mein->sq->y0 <= 630 && mein->sq->y1 <= 630 && mein->sq->y2 <= 630 && mein->sq->y3 <= 630)) {

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->sq->x0, mein->sq->y0, mein->sq->x0 + 20, mein->sq->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->sq->x1, mein->sq->y1, mein->sq->x1 + 20, mein->sq->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->sq->x2, mein->sq->y2, mein->sq->x2 + 20, mein->sq->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->sq->x3, mein->sq->y3, mein->sq->x3 + 20, mein->sq->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->sq->y0 > 650 || mein->sq->y1 > 650 || mein->sq->y2 > 650 || mein->sq->y3 > 650) {
                mein->b[mein->sq->x0][mein->sq->y0] = 1;
                mein->b[mein->sq->x1][mein->sq->y1] = 1;
                mein->b[mein->sq->x2][mein->sq->y2] = 1;
                mein->b[mein->sq->x3][mein->sq->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->sq->x0][mein->sq->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->sq->x1][mein->sq->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->sq->x2][mein->sq->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->sq->x3][mein->sq->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->sq->x0][mein->sq->y0] = 1;
                mein->b[mein->sq->x1][mein->sq->y1] = 1;
                mein->b[mein->sq->x2][mein->sq->y2] = 1;
                mein->b[mein->sq->x3][mein->sq->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
        }
        else if(mein->choice == "lne" && (mein->lne->y0 <= 580 || mein->lne->y1 <= 580 || mein->lne->y2 <= 580 || mein->lne->y3 <= 580)) {
    //        lne->y0 += 20;
    //        lne->y1 += 20;
    //        lne->y2 += 20;
    //        lne->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->lne->x0, mein->lne->y0, mein->lne->x0 + 20, mein->lne->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->lne->x1, mein->lne->y1, mein->lne->x1 + 20, mein->lne->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->lne->x2, mein->lne->y2, mein->lne->x2 + 20, mein->lne->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->lne->x3, mein->lne->y3, mein->lne->x3 + 20, mein->lne->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->lne->y0 > 650 || mein->lne->y1 > 650 || mein->lne->y2 > 650 || mein->lne->y3 > 650) {
                mein->b[mein->lne->x0][mein->lne->y0] = 1;
                mein->b[mein->lne->x1][mein->lne->y1] = 1;
                mein->b[mein->lne->x2][mein->lne->y2] = 1;
                mein->b[mein->lne->x3][mein->lne->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->lne->x0][mein->lne->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->lne->x1][mein->lne->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->lne->x2][mein->lne->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->lne->x3][mein->lne->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->lne->x0][mein->lne->y0] = 1;
                mein->b[mein->lne->x1][mein->lne->y1] = 1;
                mein->b[mein->lne->x2][mein->lne->y2] = 1;
                mein->b[mein->lne->x3][mein->lne->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
        }
        else if(mein->choice == "ht" && (mein->ht->y0 <= 630 && mein->ht->y1 <= 630 && mein->ht->y2 <= 630 && mein->ht->y3 <= 630)) {
    //        ht->y0 += 20;
    //        ht->y1 += 20;
    //        ht->y2 += 20;
    //        ht->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->ht->x0, mein->ht->y0, mein->ht->x0 + 20, mein->ht->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->ht->x1, mein->ht->y1, mein->ht->x1 + 20, mein->ht->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->ht->x2, mein->ht->y2, mein->ht->x2 + 20, mein->ht->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->ht->x3, mein->ht->y3, mein->ht->x3 + 20, mein->ht->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->ht->y0 > 630 || mein->ht->y1 > 630 || mein->ht->y2 > 630 || mein->ht->y3 > 630) {
                mein->b[mein->ht->x0][mein->ht->y0] = 1;
                mein->b[mein->ht->x1][mein->ht->y1] = 1;
                mein->b[mein->ht->x2][mein->ht->y2] = 1;
                mein->b[mein->ht->x3][mein->ht->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->ht->x0][mein->ht->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->ht->x1][mein->ht->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->ht->x2][mein->ht->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->ht->x3][mein->ht->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->ht->x0][mein->ht->y0] = 1;
                mein->b[mein->ht->x1][mein->ht->y1] = 1;
                mein->b[mein->ht->x2][mein->ht->y2] = 1;
                mein->b[mein->ht->x3][mein->ht->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
        }
        else if(mein->choice == "larm" && (mein->larm->y0 <= 650 && mein->larm->y1 <= 650 && mein->larm->y2 <= 650 && mein->larm->y3 <= 650)) {
    //        larm->y0 += 20;
    //        larm->y1 += 20;
    //        larm->y2 += 20;
    //        larm->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->larm->x0, mein->larm->y0, mein->larm->x0 + 20, mein->larm->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->larm->x1, mein->larm->y1, mein->larm->x1 + 20, mein->larm->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->larm->x2, mein->larm->y2, mein->larm->x2 + 20, mein->larm->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->larm->x3, mein->larm->y3, mein->larm->x3 + 20, mein->larm->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->larm->y0 > 650 || mein->larm->y1 > 650 || mein->larm->y2 > 650 || mein->larm->y3 > 650) {
                mein->b[mein->larm->x0][mein->larm->y0] = 1;
                mein->b[mein->larm->x1][mein->larm->y1] = 1;
                mein->b[mein->larm->x2][mein->larm->y2] = 1;
                mein->b[mein->larm->x3][mein->larm->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->larm->x0][mein->larm->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->larm->x1][mein->larm->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->larm->x2][mein->larm->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->larm->x3][mein->larm->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->larm->x0][mein->larm->y0] = 1;
                mein->b[mein->larm->x1][mein->larm->y1] = 1;
                mein->b[mein->larm->x2][mein->larm->y2] = 1;
                mein->b[mein->larm->x3][mein->larm->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(mein->choice == "rarm" && (mein->rarm->y0 <= 650 && mein->rarm->y1 <= 650 && mein->rarm->y2 <= 650 && mein->rarm->y3 <= 650)) {
    //        rarm->y0 += 20;
    //        rarm->y1 += 20;
    //        rarm->y2 += 20;
    //        rarm->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->rarm->x0, mein->rarm->y0, mein->rarm->x0 + 20, mein->rarm->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->rarm->x1, mein->rarm->y1, mein->rarm->x1 + 20, mein->rarm->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->rarm->x2, mein->rarm->y2, mein->rarm->x2 + 20, mein->rarm->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->rarm->x3, mein->rarm->y3, mein->rarm->x3 + 20, mein->rarm->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->rarm->y0 > 650 || mein->rarm->y1 > 650 || mein->rarm->y2 > 650 || mein->rarm->y3 > 650) {
                mein->b[mein->rarm->x0][mein->rarm->y0] = 1;
                mein->b[mein->rarm->x1][mein->rarm->y1] = 1;
                mein->b[mein->rarm->x2][mein->rarm->y2] = 1;
                mein->b[mein->rarm->x3][mein->rarm->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->rarm->x0][mein->rarm->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->rarm->x1][mein->rarm->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->rarm->x2][mein->rarm->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->rarm->x3][mein->rarm->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->rarm->x0][mein->rarm->y0] = 1;
                mein->b[mein->rarm->x1][mein->rarm->y1] = 1;
                mein->b[mein->rarm->x2][mein->rarm->y2] = 1;
                mein->b[mein->rarm->x3][mein->rarm->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(mein->choice == "lsh" && (mein->lsh->y0 <= 650 && mein->lsh->y1 <= 650 && mein->lsh->y2 <= 650 && mein->lsh->y3 <= 650)) {
    //        lsh->y0 += 20;
    //        lsh->y1 += 20;
    //        lsh->y2 += 20;
    //        lsh->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->lsh->x0, mein->lsh->y0, mein->lsh->x0 + 20, mein->lsh->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->lsh->x1, mein->lsh->y1, mein->lsh->x1 + 20, mein->lsh->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->lsh->x2, mein->lsh->y2, mein->lsh->x2 + 20, mein->lsh->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->lsh->x3, mein->lsh->y3, mein->lsh->x3 + 20, mein->lsh->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->lsh->y0 > 650 || mein->lsh->y1 > 650 || mein->lsh->y2 > 650 || mein->lsh->y3 > 650) {
                mein->b[mein->lsh->x0][mein->lsh->y0] = 1;
                mein->b[mein->lsh->x1][mein->lsh->y1] = 1;
                mein->b[mein->lsh->x2][mein->lsh->y2] = 1;
                mein->b[mein->lsh->x3][mein->lsh->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->lsh->x0][mein->lsh->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->lsh->x1][mein->lsh->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->lsh->x2][mein->lsh->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->lsh->x3][mein->lsh->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->lsh->x0][mein->lsh->y0] = 1;
                mein->b[mein->lsh->x1][mein->lsh->y1] = 1;
                mein->b[mein->lsh->x2][mein->lsh->y2] = 1;
                mein->b[mein->lsh->x3][mein->lsh->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(mein->choice == "rsh" && (mein->rsh->y0 <= 650 && mein->rsh->y1 <= 650 && mein->rsh->y2 <= 650 && mein->rsh->y3 <= 650)) {
    //        rsh->y0 += 20;
    //        rsh->y1 += 20;
    //        rsh->y2 += 20;
    //        rsh->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->rsh->x0, mein->rsh->y0, mein->rsh->x0 + 20, mein->rsh->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->rsh->x1, mein->rsh->y1, mein->rsh->x1 + 20, mein->rsh->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->rsh->x2, mein->rsh->y2, mein->rsh->x2 + 20, mein->rsh->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->rsh->x3, mein->rsh->y3, mein->rsh->x3 + 20, mein->rsh->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->rsh->y0 > 650 || mein->rsh->y1 > 650 || mein->rsh->y2 > 650 || mein->rsh->y3 > 650) {
                mein->b[mein->rsh->x0][mein->rsh->y0] = 1;
                mein->b[mein->rsh->x1][mein->rsh->y1] = 1;
                mein->b[mein->rsh->x2][mein->rsh->y2] = 1;
                mein->b[mein->rsh->x3][mein->rsh->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->rsh->x0][mein->rsh->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->rsh->x1][mein->rsh->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->rsh->x2][mein->rsh->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->rsh->x3][mein->rsh->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->rsh->x0][mein->rsh->y0] = 1;
                mein->b[mein->rsh->x1][mein->rsh->y1] = 1;
                mein->b[mein->rsh->x2][mein->rsh->y2] = 1;
                mein->b[mein->rsh->x3][mein->rsh->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }
        }

        HBRUSH brus = CreateSolidBrush(RGB(255, 255, 255));

        RECT ect3 = {219, 20, 420, 690};
        //FillRect(hdc2, &ect3, brus);
        DeleteObject(brus);

        if(mein->fist) {
            //thread = CreateThread(NULL, 0, downs, NULL, 0, NULL);
            //srand(time(NULL));
            mein->prep();
        }

        for(int i=0; i<700; i++) {
            for(int j=0; j<720; j++) {
                if(mein->b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(mein->hdc2, &rrect6, brush);
                    DeleteObject(brush);
                }
            }
        }

        mein->erasePreview();
        mein->printMiscLabels(mein->level);
        mein->showNextPiece();
        for(int x=0; x<4; x++) {
            mein->clearLine();
        }

        usleep(1103000);

        if(mein->choice == "sq") {

            mein->sq->y0 += 20;
            mein->sq->y1 += 20;
            mein->sq->y2 += 20;
            mein->sq->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->sq->x0, mein->sq->y0, mein->sq->x0 + 20, mein->sq->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->sq->x1, mein->sq->y1, mein->sq->x1 + 20, mein->sq->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->sq->x2, mein->sq->y2, mein->sq->x2 + 20, mein->sq->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->sq->x3, mein->sq->y3, mein->sq->x3 + 20, mein->sq->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->sq->y0 > 650 || mein->sq->y1 > 650 || mein->sq->y2 > 650 || mein->sq->y3 > 650) {
                mein->b[mein->sq->x0][mein->sq->y0] = 1;
                mein->b[mein->sq->x1][mein->sq->y1] = 1;
                mein->b[mein->sq->x2][mein->sq->y2] = 1;
                mein->b[mein->sq->x3][mein->sq->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->sq->x0][mein->sq->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->sq->x1][mein->sq->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->sq->x2][mein->sq->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->sq->x3][mein->sq->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->sq->x0][mein->sq->y0] = 1;
                mein->b[mein->sq->x1][mein->sq->y1] = 1;
                mein->b[mein->sq->x2][mein->sq->y2] = 1;
                mein->b[mein->sq->x3][mein->sq->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);
                SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(mein->choice == "lne") {

            mein->lne->y0 += 20;
            mein->lne->y1 += 20;
            mein->lne->y2 += 20;
            mein->lne->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->lne->x0, mein->lne->y0, mein->lne->x0 + 20, mein->lne->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->lne->x1, mein->lne->y1, mein->lne->x1 + 20, mein->lne->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->lne->x2, mein->lne->y2, mein->lne->x2 + 20, mein->lne->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->lne->x3, mein->lne->y3, mein->lne->x3 + 20, mein->lne->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->lne->y0 > 650 || mein->lne->y1 > 650 || mein->lne->y2 > 650 || mein->lne->y3 > 650) {
                mein->b[mein->lne->x0][mein->lne->y0] = 1;
                mein->b[mein->lne->x1][mein->lne->y1] = 1;
                mein->b[mein->lne->x2][mein->lne->y2] = 1;
                mein->b[mein->lne->x3][mein->lne->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->lne->x0][mein->lne->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->lne->x1][mein->lne->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->lne->x2][mein->lne->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->lne->x3][mein->lne->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->lne->x0][mein->lne->y0] = 1;
                mein->b[mein->lne->x1][mein->lne->y1] = 1;
                mein->b[mein->lne->x2][mein->lne->y2] = 1;
                mein->b[mein->lne->x3][mein->lne->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(mein->choice == "ht") {

            mein->ht->y0 += 20;
            mein->ht->y1 += 20;
            mein->ht->y2 += 20;
            mein->ht->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->ht->x0, mein->ht->y0, mein->ht->x0 + 20, mein->ht->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->ht->x1, mein->ht->y1, mein->ht->x1 + 20, mein->ht->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->ht->x2, mein->ht->y2, mein->ht->x2 + 20, mein->ht->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->ht->x3, mein->ht->y3, mein->ht->x3 + 20, mein->ht->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->ht->y0 > 650 || mein->ht->y1 > 650 || mein->ht->y2 > 650 || mein->ht->y3 > 650) {
                mein->b[mein->ht->x0][mein->ht->y0] = 1;
                mein->b[mein->ht->x1][mein->ht->y1] = 1;
                mein->b[mein->ht->x2][mein->ht->y2] = 1;
                mein->b[mein->ht->x3][mein->ht->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->ht->x0][mein->ht->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->ht->x1][mein->ht->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->ht->x2][mein->ht->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->ht->x3][mein->ht->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->ht->x0][mein->ht->y0] = 1;
                mein->b[mein->ht->x1][mein->ht->y1] = 1;
                mein->b[mein->ht->x2][mein->ht->y2] = 1;
                mein->b[mein->ht->x3][mein->ht->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(mein->choice == "larm") {

            mein->larm->y0 += 20;
            mein->larm->y1 += 20;
            mein->larm->y2 += 20;
            mein->larm->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->larm->x0, mein->larm->y0, mein->larm->x0 + 20, mein->larm->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->larm->x1, mein->larm->y1, mein->larm->x1 + 20, mein->larm->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->larm->x2, mein->larm->y2, mein->larm->x2 + 20, mein->larm->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->larm->x3, mein->larm->y3, mein->larm->x3 + 20, mein->larm->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->larm->y0 > 650 || mein->larm->y1 > 650 || mein->larm->y2 > 650 || mein->larm->y3 > 650) {
                mein->b[mein->larm->x0][mein->larm->y0] = 1;
                mein->b[mein->larm->x1][mein->larm->y1] = 1;
                mein->b[mein->larm->x2][mein->larm->y2] = 1;
                mein->b[mein->larm->x3][mein->larm->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->larm->x0][mein->larm->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->larm->x1][mein->larm->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->larm->x2][mein->larm->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->larm->x3][mein->larm->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->larm->x0][mein->larm->y0] = 1;
                mein->b[mein->larm->x1][mein->larm->y1] = 1;
                mein->b[mein->larm->x2][mein->larm->y2] = 1;
                mein->b[mein->larm->x3][mein->larm->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(mein->choice == "rarm") {

            mein->rarm->y0 += 20;
            mein->rarm->y1 += 20;
            mein->rarm->y2 += 20;
            mein->rarm->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->rarm->x0, mein->rarm->y0, mein->rarm->x0 + 20, mein->rarm->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->rarm->x1, mein->rarm->y1, mein->rarm->x1 + 20, mein->rarm->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->rarm->x2, mein->rarm->y2, mein->rarm->x2 + 20, mein->rarm->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->rarm->x3, mein->rarm->y3, mein->rarm->x3 + 20, mein->rarm->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->rarm->y0 > 650 || mein->rarm->y1 > 650 || mein->rarm->y2 > 650 || mein->rarm->y3 > 650) {
                mein->b[mein->rarm->x0][mein->rarm->y0] = 1;
                mein->b[mein->rarm->x1][mein->rarm->y1] = 1;
                mein->b[mein->rarm->x2][mein->rarm->y2] = 1;
                mein->b[mein->rarm->x3][mein->rarm->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->rarm->x0][mein->rarm->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->rarm->x1][mein->rarm->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->rarm->x2][mein->rarm->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->rarm->x3][mein->rarm->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->rarm->x0][mein->rarm->y0] = 1;
                mein->b[mein->rarm->x1][mein->rarm->y1] = 1;
                mein->b[mein->rarm->x2][mein->rarm->y2] = 1;
                mein->b[mein->rarm->x3][mein->rarm->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(mein->choice == "lsh") {

            mein->lsh->y0 += 20;
            mein->lsh->y1 += 20;
            mein->lsh->y2 += 20;
            mein->lsh->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->lsh->x0, mein->lsh->y0, mein->lsh->x0 + 20, mein->lsh->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->lsh->x1, mein->lsh->y1, mein->lsh->x1 + 20, mein->lsh->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->lsh->x2, mein->lsh->y2, mein->lsh->x2 + 20, mein->lsh->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->lsh->x3, mein->lsh->y3, mein->lsh->x3 + 20, mein->lsh->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->lsh->y0 > 650 || mein->lsh->y1 > 650 || mein->lsh->y2 > 650 || mein->lsh->y3 > 650) {
                mein->b[mein->lsh->x0][mein->lsh->y0] = 1;
                mein->b[mein->lsh->x1][mein->lsh->y1] = 1;
                mein->b[mein->lsh->x2][mein->lsh->y2] = 1;
                mein->b[mein->lsh->x3][mein->lsh->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->lsh->x0][mein->lsh->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->lsh->x1][mein->lsh->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->lsh->x2][mein->lsh->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->lsh->x3][mein->lsh->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->lsh->x0][mein->lsh->y0] = 1;
                mein->b[mein->lsh->x1][mein->lsh->y1] = 1;
                mein->b[mein->lsh->x2][mein->lsh->y2] = 1;
                mein->b[mein->lsh->x3][mein->lsh->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(mein->choice == "rsh") {

            mein->rsh->y0 += 20;
            mein->rsh->y1 += 20;
            mein->rsh->y2 += 20;
            mein->rsh->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {mein->rsh->x0, mein->rsh->y0, mein->rsh->x0 + 20, mein->rsh->y0 + 20};
            FillRect(mein->hdc2, &rrect3, brush);

            RECT rrect4 = {mein->rsh->x1, mein->rsh->y1, mein->rsh->x1 + 20, mein->rsh->y1 + 20};
            FillRect(mein->hdc2, &rrect4, brush);

            RECT rrect5 = {mein->rsh->x2, mein->rsh->y2, mein->rsh->x2 + 20, mein->rsh->y2 + 20};
            FillRect(mein->hdc2, &rrect5, brush);

            RECT rrect6 = {mein->rsh->x3, mein->rsh->y3, mein->rsh->x3 + 20, mein->rsh->y3 + 20};
            FillRect(mein->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(mein->rsh->y0 > 650 || mein->rsh->y1 > 650 || mein->rsh->y2 > 650 || mein->rsh->y3 > 650) {
                mein->b[mein->rsh->x0][mein->rsh->y0] = 1;
                mein->b[mein->rsh->x1][mein->rsh->y1] = 1;
                mein->b[mein->rsh->x2][mein->rsh->y2] = 1;
                mein->b[mein->rsh->x3][mein->rsh->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }

            BOOLEAN flag = FALSE;
            if(mein->b[mein->rsh->x0][mein->rsh->y0+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->rsh->x1][mein->rsh->y1+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->rsh->x2][mein->rsh->y2+20] == 1) {
                flag = TRUE;
            }
            else if(mein->b[mein->rsh->x3][mein->rsh->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                //thrad = CreateThread(NULL, 0, fallSound, NULL, 0, NULL);
                mein->b[mein->rsh->x0][mein->rsh->y0] = 1;
                mein->b[mein->rsh->x1][mein->rsh->y1] = 1;
                mein->b[mein->rsh->x2][mein->rsh->y2] = 1;
                mein->b[mein->rsh->x3][mein->rsh->y3] = 1;
                mein->blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",mein->blocks,mein->points,mein->lines);SetWindowText(mein->hwnd,aa);
                mein->prep();
            }
            if(mein->level < 40 && mein->lines >= mein->linenext) {mein->level++;mein->linenext+=10;mein->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }
        }
    }
    while(downIt);

    return 0;
}

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    DeleteObject(mein->hdc2);
    mein->hdc2 = GetDC(hwnd);

    switch(msg)
    {
        case WM_KEYDOWN: 
            switch (wParam) 
            { 

        case VK_LEFT: 
            if(mein->choice == "ht")
                mein->ht->goLeft();
            else if(mein->choice == "lne")
                mein->lne->goLeft();
            else if(mein->choice == "sq")
                mein->sq->goLeft();
            else if(mein->choice == "lsh")
                mein->lsh->goLeft();
            else if(mein->choice == "rsh")
                mein->rsh->goLeft();
            else if(mein->choice == "larm")
                mein->larm->goLeft();
            else if(mein->choice == "rarm")
                mein->rarm->goLeft();
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }

            break;

        case VK_RIGHT:
            if(mein->choice == "ht")
                mein->ht->goRight();
            else if(mein->choice == "lne")
                mein->lne->goRight();
            else if(mein->choice == "sq")
                mein->sq->goRight();
            else if(mein->choice == "lsh")
                mein->lsh->goRight();
            else if(mein->choice == "rsh")
                mein->rsh->goRight();
            else if(mein->choice == "larm")
                mein->larm->goRight();
            else if(mein->choice == "rarm")
                mein->rarm->goRight();
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }

            break; 

        case VK_UP:
            if(mein->choice == "sq")
                mein->sq->rotate();
            else if(mein->choice == "lne")
                mein->lne->rotate();
            else if(mein->choice == "ht")
                mein->ht->rotate();
            else if(mein->choice == "lsh")
                mein->lsh->rotate();
            else if(mein->choice == "rsh")
                mein->rsh->rotate();
            else if(mein->choice == "larm")
                mein->larm->rotate();
            else if(mein->choice == "rarm")
                mein->rarm->rotate();
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }

            break;

        case VK_DOWN:
            if(mein->choice == "sq")
                mein->sq->goDown();
            else if(mein->choice == "ht")
                mein->ht->goDown();
            else if(mein->choice == "lne")
                mein->lne->goDown();
            else if(mein->choice == "lsh")
                mein->lsh->goDown();
            else if(mein->choice == "rsh")
                mein->rsh->goDown();
            else if(mein->choice == "larm")
                mein->larm->goDown();
            else if(mein->choice == "rarm")
                mein->rarm->goDown();
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(mein->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(mein->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(mein->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(mein->hdc2, hOldPen));
                        SelectObject(mein->hdc2, hOldBsh);
                    }
                }
            }
            break;
//        case VK_SPACE:
//            if(mein->choice == "ht")
//                do {
//
//                } while (mein->ht->goDown());
//            else if(mein->choice == "sq")
//                do {
//
//                } while (mein->sq->goDown());
//            else if(mein->choice == "lne")
//                do {
//
//                } while (mein->lne->goDown());
//            else if(mein->choice == "sq")
//                do {
//
//                } while (mein->sq->goDown());
//            else if(mein->choice == "lsh")
//                do {
//
//                } while (mein->lsh->goDown());
//            else if(mein->choice == "rsh")
//                do {
//
//                } while (mein->rsh->goDown());
//            else if(mein->choice == "larm")
//                do {
//
//                } while (mein->larm->goDown());
//            else if(mein->choice == "rarm")
//                do {
//
//                } while (mein->rarm->goDown());
//            break;
        }
        case WM_PAINT:
        {
            if(mein->fist) {

                mein->thrad = CreateThread(NULL, 0, callMe, NULL, 0, NULL);

                HBRUSH brush79 = CreateSolidBrush(RGB(136, 0, 0));
                RECT rrect79 = {0, 0, 22640, 22750};
                FillRect(mein->hdc2, &rrect79, brush79);
                DeleteObject(brush79);
                HBRUSH brush = CreateSolidBrush(RGB(50, 230, 7));
                RECT rrect = {0, 0, 640, 750};
                FillRect(mein->hdc2, &rrect, brush);
                DeleteObject(brush);
                HBRUSH brush0 = CreateSolidBrush(RGB(255, 180, 230));
                RECT rrect9 = {199, 0, 440, 710};
                FillRect(mein->hdc2, &rrect9, brush0);
                DeleteObject(brush0);
                HBRUSH brush2 = CreateSolidBrush(RGB(255, 200, 112));
                RECT rrect3 = {209, 10, 430, 700};
                FillRect(mein->hdc2, &rrect3, brush2);
                DeleteObject(brush2);

                mein->threa = CreateThread(0, 0, downs, 0, 0, NULL);
                srand(time(NULL));
                mein->prep();
            }

            for(int i=0; i<700; i++) {
                for(int j=0; j<720; j++) {
                    if(mein->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(mein->hdc2, &rrect6, brush);
                        DeleteObject(brush);
                    }
                }
            }

            PAINTSTRUCT ps;
            HDC hdc = BeginPaint (hwnd, &ps);

            HFONT font;

            font = CreateFont(16, 0, 0, 0,
                              FW_BOLD, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            char aa[16];sprintf(aa,"LEVEL: %d of 40",mein->level);

            SelectObject(mein->hdc2, font);
            TextOut(mein->hdc2, 450, 20, aa, 15);
            TextOut(mein->hdc2, 0, 240, "PREVIEW", 7);
            DeleteObject(font);

            font = CreateFont(16, 0, 0, 0,
                              FW_NORMAL, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            HBRUSH brush1 = CreateSolidBrush(RGB(255, 255, 0));
            RECT rrect1 = {40, 310, 150, 420};
            FillRect(mein->hdc2, &rrect1, brush1);
            DeleteObject(brush1);

            char dd[16];sprintf(dd,"Level: %d", mein->level);

            SelectObject(mein->hdc2, font);
            TextOut(mein->hdc2, 50, 320, dd, 9);
            DeleteObject(font);

            font = CreateFont(16, 0, 0, 0,
                              FW_NORMAL, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            char cc[16];sprintf(cc,"Blocks: %d", mein->blocks);

            SelectObject(mein->hdc2, font);
            if(mein->blocks < 10)
                TextOut(mein->hdc2, 50, 340, cc, 9);
            else if(mein->blocks > 9 && mein->blocks < 100)
                TextOut(mein->hdc2, 50, 340, cc, 10);
            else if(mein->blocks > 99 && mein->blocks < 1000)
                TextOut(mein->hdc2, 50, 340, cc, 11);
            else if(mein->blocks > 999 && mein->blocks < 10000)
                TextOut(mein->hdc2, 50, 340, cc, 12);
            else
                TextOut(mein->hdc2, 50, 340, cc, 13);
            DeleteObject(font);

            font = CreateFont(16, 0, 0, 0,
                              FW_NORMAL, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            char bb[16];sprintf(bb,"Lines: %d", mein->lines);

            SelectObject(mein->hdc2, font);
            if(mein->lines < 10)
                TextOut(mein->hdc2, 50, 360, bb, 8);
            else if(mein->lines > 9 && mein->lines < 100)
                TextOut(mein->hdc2, 50, 360, bb, 9);
            else if(mein->lines > 99 && mein->lines < 1000)
                TextOut(mein->hdc2, 50, 360, bb, 10);
            else if(mein->lines > 999 && mein->lines < 10000)
                TextOut(mein->hdc2, 50, 360, bb, 11);
            else
                TextOut(mein->hdc2, 50, 360, bb, 12);
            DeleteObject(font);

            font = CreateFont(26, 0, 0, 0,
                              FW_NORMAL, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            SelectObject(mein->hdc2, font);
            TextOut(mein->hdc2, 450, 480, "MPC Martus", 10);
            DeleteObject(font);

            font = CreateFont(16, 0, 0, 0,
                              FW_BOLD, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Verdana");

            SelectObject(mein->hdc2, font);
            TextOut(mein->hdc2, 10, 640, "By OkelyKodely", 14);
            SelectObject(mein->hdc2, font);
            TextOut(mein->hdc2, 10, 680, "I MADE THIS!", 12);
            DeleteObject(font);

//            HBRUSH brush11 = CreateSolidBrush(RGB(255, 0, 0));
//            RECT rrect11 = {0, 12, 143, 233};
//            FillRect(mein->hdc2, &rrect11, brush11);
//            DeleteObject(brush11);
//
//            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 200));
//            RECT rrect5 = {0, 20, 129, 220};
//            FillRect(mein->hdc2, &rrect5, brush);
//            DeleteObject(brush);
            
            EndPaint (hwnd, &ps);
        }
        break;
        case WM_CREATE:
        {
            int y = 600; int h = 48;
            int x = 443; int w = 124;
  	    mein->hwnd_new_game = CreateWindowEx(0, "BUTTON", "Turn Music Off", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
								x, y, w, h, hwnd, (HMENU) PLAY_AGAIN_BUTTON, GetModuleHandle(NULL), NULL);
        }
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case PLAY_AGAIN_BUTTON:
                    if (HIWORD(wParam) == BN_CLICKED) {
                        if(!dontplay) {
                            SetWindowText(mein->hwnd_new_game, "Turn Music On");
                            PlaySound(NULL,NULL,0);
                        } else {
                            SetWindowText(mein->hwnd_new_game, "Turn Music Off");
                            PlaySound(TEXT("Tetris.wav"), NULL, SND_LOOP | SND_ASYNC);
                        }
                        dontplay = !dontplay;
                    }
                    SetFocus(hwnd);
                break;
            }
        break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindow(g_szClassName, NULL, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
      0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 
	  NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    SetWindowLong(hwnd, GWL_STYLE,
               GetWindowLong(hwnd, GWL_STYLE) & ~WS_MINIMIZEBOX);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    
    SetWindowText(hwnd, "TETRIS");

    // Step 3: The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}