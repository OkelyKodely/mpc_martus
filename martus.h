/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.h
 * Author: dhcho
 *
 * Created on June 20, 2019, 2:30 PM
 */
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

const char g_szClassName[] = "Martus";

class Martus {
 public:
    BOOL dontplay = TRUE;
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

    void prep();
    void erasePreview();
    void showNextPiece();
    void clearLine();

    class hat {
     public:
      Martus *mm;
      hat(Martus *m) { mm = m; }
      int x0;
      int y0;
      int x1;
      int y1;
      int x2;
      int y2;
      int x3;
      int y3;
      int dir;
      void rotate();
      void goLeft();
      void goRight();
      BOOL goDown();
    };

    hat* ht = new hat(this);

    class square {
     public:
        Martus *mm;
        square(Martus *m) { mm = m; }
        int x0;
        int y0;
        int x1;
        int y1;
        int x2;
        int y2;
        int x3;
        int y3;
        void rotate();
        void goLeft();
        void goRight();
        BOOL goDown();
    };

    square* sq = new square(this);

    class line {
     public:
        Martus *mm;
        line(Martus *m) { mm = m; }
        int x0;
        int y0;
        int x1;
        int y1;
        int x2;
        int y2;
        int x3;
        int y3;
        int dir;
        void rotate();
        void goLeft();
        void goRight();
        BOOL goDown();
    };

    line* lne = new line(this);

    class lsho {
     public:
        Martus *mm;
        lsho(Martus *m) { mm = m; }
        int x0;
        int y0;
        int x1;
        int y1;
        int x2;
        int y2;
        int x3;
        int y3;
        int dir;
        void rotate();
        void goLeft();
        void goRight();
        BOOL goDown();
    };

    lsho* lsh = new lsho(this);

    class rsho {
     public:
      Martus *mm;
      rsho(Martus *m) { mm = m; }
      int x0;
      int y0;
      int x1;
      int y1;
      int x2;
      int y2;
      int x3;
      int y3;
      int dir;
      void rotate();
      void goLeft();
      void goRight();
      BOOL goDown();
    };

    rsho* rsh = new rsho(this);

    class Larm {
     public:
      Martus *mm;
      Larm(Martus *m) { mm = m; }
      int x0;
      int y0;
      int x1;
      int y1;
      int x2;
      int y2;
      int x3;
      int y3;
      int dir;
      void rotate();
      void goLeft();
      void goRight();
      BOOL goDown();
    };

    Larm* larm = new Larm(this);

    class Rarm {
     public:
      Martus *mm;
      Rarm(Martus *m) { mm = m; }
      int x0;
      int y0;
      int x1;
      int y1;
      int x2;
      int y2;
      int x3;
      int y3;
      int dir;
      void rotate();
      void goLeft();
      void goRight();
      BOOL goDown();
    };
    
    Rarm* rarm = new Rarm(this);
};