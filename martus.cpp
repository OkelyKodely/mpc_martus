#include <iostream>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <unistd.h>
#include <mmsystem.h>
#include "martusdef.h"

using namespace std;

Martus* ourMartus = new Martus();

DWORD WINAPI downs(void* data) {
    BOOLEAN downIt = TRUE;
    do {
        ourMartus->hdcMem = CreateCompatibleDC(ourMartus->hdc2);

        HBRUSH brush = CreateSolidBrush(RGB(225, 122, 185));

        RECT rrect3 = {219, 20, 420, 690};
        FillRect(ourMartus->hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(ourMartus->choice == "sq" && (ourMartus->sq->y0 <= 630 && ourMartus->sq->y1 <= 630 && ourMartus->sq->y2 <= 630 && ourMartus->sq->y3 <= 630)) {

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
            
            RECT rrect3 = {ourMartus->sq->x0, ourMartus->sq->y0, ourMartus->sq->x0 + 20, ourMartus->sq->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->sq->x1, ourMartus->sq->y1, ourMartus->sq->x1 + 20, ourMartus->sq->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->sq->x2, ourMartus->sq->y2, ourMartus->sq->x2 + 20, ourMartus->sq->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->sq->x3, ourMartus->sq->y3, ourMartus->sq->x3 + 20, ourMartus->sq->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->sq->y0 > 650 || ourMartus->sq->y1 > 650 || ourMartus->sq->y2 > 650 || ourMartus->sq->y3 > 650) {
                ourMartus->b[ourMartus->sq->x0][ourMartus->sq->y0] = 1;
                ourMartus->b[ourMartus->sq->x1][ourMartus->sq->y1] = 1;
                ourMartus->b[ourMartus->sq->x2][ourMartus->sq->y2] = 1;
                ourMartus->b[ourMartus->sq->x3][ourMartus->sq->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->sq->x0][ourMartus->sq->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->sq->x1][ourMartus->sq->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->sq->x2][ourMartus->sq->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->sq->x3][ourMartus->sq->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->sq->x0][ourMartus->sq->y0] = 1;
                ourMartus->b[ourMartus->sq->x1][ourMartus->sq->y1] = 1;
                ourMartus->b[ourMartus->sq->x2][ourMartus->sq->y2] = 1;
                ourMartus->b[ourMartus->sq->x3][ourMartus->sq->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
        }
        else if(ourMartus->choice == "lne" && (ourMartus->lne->y0 <= 630 || ourMartus->lne->y1 <= 630 || ourMartus->lne->y2 <= 630 || ourMartus->lne->y3 <= 630)) {

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {ourMartus->lne->x0, ourMartus->lne->y0, ourMartus->lne->x0 + 20, ourMartus->lne->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->lne->x1, ourMartus->lne->y1, ourMartus->lne->x1 + 20, ourMartus->lne->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->lne->x2, ourMartus->lne->y2, ourMartus->lne->x2 + 20, ourMartus->lne->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->lne->x3, ourMartus->lne->y3, ourMartus->lne->x3 + 20, ourMartus->lne->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->lne->y0 > 650 || ourMartus->lne->y1 > 650 || ourMartus->lne->y2 > 650 || ourMartus->lne->y3 > 650) {
                ourMartus->b[ourMartus->lne->x0][ourMartus->lne->y0] = 1;
                ourMartus->b[ourMartus->lne->x1][ourMartus->lne->y1] = 1;
                ourMartus->b[ourMartus->lne->x2][ourMartus->lne->y2] = 1;
                ourMartus->b[ourMartus->lne->x3][ourMartus->lne->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->lne->x0][ourMartus->lne->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->lne->x1][ourMartus->lne->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->lne->x2][ourMartus->lne->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->lne->x3][ourMartus->lne->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->lne->x0][ourMartus->lne->y0] = 1;
                ourMartus->b[ourMartus->lne->x1][ourMartus->lne->y1] = 1;
                ourMartus->b[ourMartus->lne->x2][ourMartus->lne->y2] = 1;
                ourMartus->b[ourMartus->lne->x3][ourMartus->lne->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
        }
        else if(ourMartus->choice == "ht" && (ourMartus->ht->y0 <= 630 && ourMartus->ht->y1 <= 630 && ourMartus->ht->y2 <= 630 && ourMartus->ht->y3 <= 630)) {

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {ourMartus->ht->x0, ourMartus->ht->y0, ourMartus->ht->x0 + 20, ourMartus->ht->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->ht->x1, ourMartus->ht->y1, ourMartus->ht->x1 + 20, ourMartus->ht->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->ht->x2, ourMartus->ht->y2, ourMartus->ht->x2 + 20, ourMartus->ht->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->ht->x3, ourMartus->ht->y3, ourMartus->ht->x3 + 20, ourMartus->ht->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->ht->y0 > 630 || ourMartus->ht->y1 > 630 || ourMartus->ht->y2 > 630 || ourMartus->ht->y3 > 630) {
                ourMartus->b[ourMartus->ht->x0][ourMartus->ht->y0] = 1;
                ourMartus->b[ourMartus->ht->x1][ourMartus->ht->y1] = 1;
                ourMartus->b[ourMartus->ht->x2][ourMartus->ht->y2] = 1;
                ourMartus->b[ourMartus->ht->x3][ourMartus->ht->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->ht->x0][ourMartus->ht->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->ht->x1][ourMartus->ht->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->ht->x2][ourMartus->ht->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->ht->x3][ourMartus->ht->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->ht->x0][ourMartus->ht->y0] = 1;
                ourMartus->b[ourMartus->ht->x1][ourMartus->ht->y1] = 1;
                ourMartus->b[ourMartus->ht->x2][ourMartus->ht->y2] = 1;
                ourMartus->b[ourMartus->ht->x3][ourMartus->ht->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
        }
        else if(ourMartus->choice == "larm" && (ourMartus->larm->y0 <= 650 && ourMartus->larm->y1 <= 650 && ourMartus->larm->y2 <= 650 && ourMartus->larm->y3 <= 650)) {

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {ourMartus->larm->x0, ourMartus->larm->y0, ourMartus->larm->x0 + 20, ourMartus->larm->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->larm->x1, ourMartus->larm->y1, ourMartus->larm->x1 + 20, ourMartus->larm->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->larm->x2, ourMartus->larm->y2, ourMartus->larm->x2 + 20, ourMartus->larm->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->larm->x3, ourMartus->larm->y3, ourMartus->larm->x3 + 20, ourMartus->larm->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->larm->y0 > 650 || ourMartus->larm->y1 > 650 || ourMartus->larm->y2 > 650 || ourMartus->larm->y3 > 650) {
                ourMartus->b[ourMartus->larm->x0][ourMartus->larm->y0] = 1;
                ourMartus->b[ourMartus->larm->x1][ourMartus->larm->y1] = 1;
                ourMartus->b[ourMartus->larm->x2][ourMartus->larm->y2] = 1;
                ourMartus->b[ourMartus->larm->x3][ourMartus->larm->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->larm->x0][ourMartus->larm->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->larm->x1][ourMartus->larm->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->larm->x2][ourMartus->larm->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->larm->x3][ourMartus->larm->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->larm->x0][ourMartus->larm->y0] = 1;
                ourMartus->b[ourMartus->larm->x1][ourMartus->larm->y1] = 1;
                ourMartus->b[ourMartus->larm->x2][ourMartus->larm->y2] = 1;
                ourMartus->b[ourMartus->larm->x3][ourMartus->larm->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(ourMartus->choice == "rarm" && (ourMartus->rarm->y0 <= 650 && ourMartus->rarm->y1 <= 650 && ourMartus->rarm->y2 <= 650 && ourMartus->rarm->y3 <= 650)) {

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {ourMartus->rarm->x0, ourMartus->rarm->y0, ourMartus->rarm->x0 + 20, ourMartus->rarm->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->rarm->x1, ourMartus->rarm->y1, ourMartus->rarm->x1 + 20, ourMartus->rarm->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->rarm->x2, ourMartus->rarm->y2, ourMartus->rarm->x2 + 20, ourMartus->rarm->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->rarm->x3, ourMartus->rarm->y3, ourMartus->rarm->x3 + 20, ourMartus->rarm->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->rarm->y0 > 650 || ourMartus->rarm->y1 > 650 || ourMartus->rarm->y2 > 650 || ourMartus->rarm->y3 > 650) {
                ourMartus->b[ourMartus->rarm->x0][ourMartus->rarm->y0] = 1;
                ourMartus->b[ourMartus->rarm->x1][ourMartus->rarm->y1] = 1;
                ourMartus->b[ourMartus->rarm->x2][ourMartus->rarm->y2] = 1;
                ourMartus->b[ourMartus->rarm->x3][ourMartus->rarm->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->rarm->x0][ourMartus->rarm->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->rarm->x1][ourMartus->rarm->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->rarm->x2][ourMartus->rarm->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->rarm->x3][ourMartus->rarm->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->rarm->x0][ourMartus->rarm->y0] = 1;
                ourMartus->b[ourMartus->rarm->x1][ourMartus->rarm->y1] = 1;
                ourMartus->b[ourMartus->rarm->x2][ourMartus->rarm->y2] = 1;
                ourMartus->b[ourMartus->rarm->x3][ourMartus->rarm->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(ourMartus->choice == "lsh" && (ourMartus->lsh->y0 <= 650 && ourMartus->lsh->y1 <= 650 && ourMartus->lsh->y2 <= 650 && ourMartus->lsh->y3 <= 650)) {

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {ourMartus->lsh->x0, ourMartus->lsh->y0, ourMartus->lsh->x0 + 20, ourMartus->lsh->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->lsh->x1, ourMartus->lsh->y1, ourMartus->lsh->x1 + 20, ourMartus->lsh->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->lsh->x2, ourMartus->lsh->y2, ourMartus->lsh->x2 + 20, ourMartus->lsh->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->lsh->x3, ourMartus->lsh->y3, ourMartus->lsh->x3 + 20, ourMartus->lsh->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->lsh->y0 > 650 || ourMartus->lsh->y1 > 650 || ourMartus->lsh->y2 > 650 || ourMartus->lsh->y3 > 650) {
                ourMartus->b[ourMartus->lsh->x0][ourMartus->lsh->y0] = 1;
                ourMartus->b[ourMartus->lsh->x1][ourMartus->lsh->y1] = 1;
                ourMartus->b[ourMartus->lsh->x2][ourMartus->lsh->y2] = 1;
                ourMartus->b[ourMartus->lsh->x3][ourMartus->lsh->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->lsh->x0][ourMartus->lsh->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->lsh->x1][ourMartus->lsh->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->lsh->x2][ourMartus->lsh->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->lsh->x3][ourMartus->lsh->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->lsh->x0][ourMartus->lsh->y0] = 1;
                ourMartus->b[ourMartus->lsh->x1][ourMartus->lsh->y1] = 1;
                ourMartus->b[ourMartus->lsh->x2][ourMartus->lsh->y2] = 1;
                ourMartus->b[ourMartus->lsh->x3][ourMartus->lsh->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(ourMartus->choice == "rsh" && (ourMartus->rsh->y0 <= 650 && ourMartus->rsh->y1 <= 650 && ourMartus->rsh->y2 <= 650 && ourMartus->rsh->y3 <= 650)) {

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {ourMartus->rsh->x0, ourMartus->rsh->y0, ourMartus->rsh->x0 + 20, ourMartus->rsh->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->rsh->x1, ourMartus->rsh->y1, ourMartus->rsh->x1 + 20, ourMartus->rsh->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->rsh->x2, ourMartus->rsh->y2, ourMartus->rsh->x2 + 20, ourMartus->rsh->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->rsh->x3, ourMartus->rsh->y3, ourMartus->rsh->x3 + 20, ourMartus->rsh->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->rsh->y0 > 650 || ourMartus->rsh->y1 > 650 || ourMartus->rsh->y2 > 650 || ourMartus->rsh->y3 > 650) {
                ourMartus->b[ourMartus->rsh->x0][ourMartus->rsh->y0] = 1;
                ourMartus->b[ourMartus->rsh->x1][ourMartus->rsh->y1] = 1;
                ourMartus->b[ourMartus->rsh->x2][ourMartus->rsh->y2] = 1;
                ourMartus->b[ourMartus->rsh->x3][ourMartus->rsh->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->rsh->x0][ourMartus->rsh->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->rsh->x1][ourMartus->rsh->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->rsh->x2][ourMartus->rsh->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->rsh->x3][ourMartus->rsh->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->rsh->x0][ourMartus->rsh->y0] = 1;
                ourMartus->b[ourMartus->rsh->x1][ourMartus->rsh->y1] = 1;
                ourMartus->b[ourMartus->rsh->x2][ourMartus->rsh->y2] = 1;
                ourMartus->b[ourMartus->rsh->x3][ourMartus->rsh->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }
        }

        if(ourMartus->fist) {
            ourMartus->prep();
        }

        for(int i=0; i<700; i++) {
            for(int j=0; j<720; j++) {
                if(ourMartus->b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(ourMartus->hdc2, &rrect6, brush);
                    DeleteObject(brush);
                }
            }
        }

        ourMartus->erasePreview();
        ourMartus->showNextPiece();

        for(int x=0; x<4; x++) {
            ourMartus->clearLine();
        }

        usleep(1103000);

        if(ourMartus->choice == "sq") {

            ourMartus->sq->y0 += 20;
            ourMartus->sq->y1 += 20;
            ourMartus->sq->y2 += 20;
            ourMartus->sq->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {ourMartus->sq->x0, ourMartus->sq->y0, ourMartus->sq->x0 + 20, ourMartus->sq->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->sq->x1, ourMartus->sq->y1, ourMartus->sq->x1 + 20, ourMartus->sq->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->sq->x2, ourMartus->sq->y2, ourMartus->sq->x2 + 20, ourMartus->sq->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->sq->x3, ourMartus->sq->y3, ourMartus->sq->x3 + 20, ourMartus->sq->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->sq->y0 > 650 || ourMartus->sq->y1 > 650 || ourMartus->sq->y2 > 650 || ourMartus->sq->y3 > 650) {
                ourMartus->b[ourMartus->sq->x0][ourMartus->sq->y0] = 1;
                ourMartus->b[ourMartus->sq->x1][ourMartus->sq->y1] = 1;
                ourMartus->b[ourMartus->sq->x2][ourMartus->sq->y2] = 1;
                ourMartus->b[ourMartus->sq->x3][ourMartus->sq->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->sq->x0][ourMartus->sq->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->sq->x1][ourMartus->sq->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->sq->x2][ourMartus->sq->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->sq->x3][ourMartus->sq->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->sq->x0][ourMartus->sq->y0] = 1;
                ourMartus->b[ourMartus->sq->x1][ourMartus->sq->y1] = 1;
                ourMartus->b[ourMartus->sq->x2][ourMartus->sq->y2] = 1;
                ourMartus->b[ourMartus->sq->x3][ourMartus->sq->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(ourMartus->choice == "lne") {

            ourMartus->lne->y0 += 20;
            ourMartus->lne->y1 += 20;
            ourMartus->lne->y2 += 20;
            ourMartus->lne->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {ourMartus->lne->x0, ourMartus->lne->y0, ourMartus->lne->x0 + 20, ourMartus->lne->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->lne->x1, ourMartus->lne->y1, ourMartus->lne->x1 + 20, ourMartus->lne->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->lne->x2, ourMartus->lne->y2, ourMartus->lne->x2 + 20, ourMartus->lne->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->lne->x3, ourMartus->lne->y3, ourMartus->lne->x3 + 20, ourMartus->lne->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->lne->y0 > 650 || ourMartus->lne->y1 > 650 || ourMartus->lne->y2 > 650 || ourMartus->lne->y3 > 650) {
                ourMartus->b[ourMartus->lne->x0][ourMartus->lne->y0] = 1;
                ourMartus->b[ourMartus->lne->x1][ourMartus->lne->y1] = 1;
                ourMartus->b[ourMartus->lne->x2][ourMartus->lne->y2] = 1;
                ourMartus->b[ourMartus->lne->x3][ourMartus->lne->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->lne->x0][ourMartus->lne->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->lne->x1][ourMartus->lne->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->lne->x2][ourMartus->lne->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->lne->x3][ourMartus->lne->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->lne->x0][ourMartus->lne->y0] = 1;
                ourMartus->b[ourMartus->lne->x1][ourMartus->lne->y1] = 1;
                ourMartus->b[ourMartus->lne->x2][ourMartus->lne->y2] = 1;
                ourMartus->b[ourMartus->lne->x3][ourMartus->lne->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(ourMartus->choice == "ht") {

            ourMartus->ht->y0 += 20;
            ourMartus->ht->y1 += 20;
            ourMartus->ht->y2 += 20;
            ourMartus->ht->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {ourMartus->ht->x0, ourMartus->ht->y0, ourMartus->ht->x0 + 20, ourMartus->ht->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->ht->x1, ourMartus->ht->y1, ourMartus->ht->x1 + 20, ourMartus->ht->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->ht->x2, ourMartus->ht->y2, ourMartus->ht->x2 + 20, ourMartus->ht->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->ht->x3, ourMartus->ht->y3, ourMartus->ht->x3 + 20, ourMartus->ht->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->ht->y0 > 650 || ourMartus->ht->y1 > 650 || ourMartus->ht->y2 > 650 || ourMartus->ht->y3 > 650) {
                ourMartus->b[ourMartus->ht->x0][ourMartus->ht->y0] = 1;
                ourMartus->b[ourMartus->ht->x1][ourMartus->ht->y1] = 1;
                ourMartus->b[ourMartus->ht->x2][ourMartus->ht->y2] = 1;
                ourMartus->b[ourMartus->ht->x3][ourMartus->ht->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->ht->x0][ourMartus->ht->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->ht->x1][ourMartus->ht->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->ht->x2][ourMartus->ht->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->ht->x3][ourMartus->ht->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->ht->x0][ourMartus->ht->y0] = 1;
                ourMartus->b[ourMartus->ht->x1][ourMartus->ht->y1] = 1;
                ourMartus->b[ourMartus->ht->x2][ourMartus->ht->y2] = 1;
                ourMartus->b[ourMartus->ht->x3][ourMartus->ht->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(ourMartus->choice == "larm") {

            ourMartus->larm->y0 += 20;
            ourMartus->larm->y1 += 20;
            ourMartus->larm->y2 += 20;
            ourMartus->larm->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {ourMartus->larm->x0, ourMartus->larm->y0, ourMartus->larm->x0 + 20, ourMartus->larm->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->larm->x1, ourMartus->larm->y1, ourMartus->larm->x1 + 20, ourMartus->larm->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->larm->x2, ourMartus->larm->y2, ourMartus->larm->x2 + 20, ourMartus->larm->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->larm->x3, ourMartus->larm->y3, ourMartus->larm->x3 + 20, ourMartus->larm->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->larm->y0 > 650 || ourMartus->larm->y1 > 650 || ourMartus->larm->y2 > 650 || ourMartus->larm->y3 > 650) {
                ourMartus->b[ourMartus->larm->x0][ourMartus->larm->y0] = 1;
                ourMartus->b[ourMartus->larm->x1][ourMartus->larm->y1] = 1;
                ourMartus->b[ourMartus->larm->x2][ourMartus->larm->y2] = 1;
                ourMartus->b[ourMartus->larm->x3][ourMartus->larm->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->larm->x0][ourMartus->larm->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->larm->x1][ourMartus->larm->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->larm->x2][ourMartus->larm->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->larm->x3][ourMartus->larm->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->larm->x0][ourMartus->larm->y0] = 1;
                ourMartus->b[ourMartus->larm->x1][ourMartus->larm->y1] = 1;
                ourMartus->b[ourMartus->larm->x2][ourMartus->larm->y2] = 1;
                ourMartus->b[ourMartus->larm->x3][ourMartus->larm->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(ourMartus->choice == "rarm") {

            ourMartus->rarm->y0 += 20;
            ourMartus->rarm->y1 += 20;
            ourMartus->rarm->y2 += 20;
            ourMartus->rarm->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {ourMartus->rarm->x0, ourMartus->rarm->y0, ourMartus->rarm->x0 + 20, ourMartus->rarm->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->rarm->x1, ourMartus->rarm->y1, ourMartus->rarm->x1 + 20, ourMartus->rarm->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->rarm->x2, ourMartus->rarm->y2, ourMartus->rarm->x2 + 20, ourMartus->rarm->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->rarm->x3, ourMartus->rarm->y3, ourMartus->rarm->x3 + 20, ourMartus->rarm->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->rarm->y0 > 650 || ourMartus->rarm->y1 > 650 || ourMartus->rarm->y2 > 650 || ourMartus->rarm->y3 > 650) {
                ourMartus->b[ourMartus->rarm->x0][ourMartus->rarm->y0] = 1;
                ourMartus->b[ourMartus->rarm->x1][ourMartus->rarm->y1] = 1;
                ourMartus->b[ourMartus->rarm->x2][ourMartus->rarm->y2] = 1;
                ourMartus->b[ourMartus->rarm->x3][ourMartus->rarm->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->rarm->x0][ourMartus->rarm->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->rarm->x1][ourMartus->rarm->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->rarm->x2][ourMartus->rarm->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->rarm->x3][ourMartus->rarm->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->rarm->x0][ourMartus->rarm->y0] = 1;
                ourMartus->b[ourMartus->rarm->x1][ourMartus->rarm->y1] = 1;
                ourMartus->b[ourMartus->rarm->x2][ourMartus->rarm->y2] = 1;
                ourMartus->b[ourMartus->rarm->x3][ourMartus->rarm->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(ourMartus->choice == "lsh") {

            ourMartus->lsh->y0 += 20;
            ourMartus->lsh->y1 += 20;
            ourMartus->lsh->y2 += 20;
            ourMartus->lsh->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {ourMartus->lsh->x0, ourMartus->lsh->y0, ourMartus->lsh->x0 + 20, ourMartus->lsh->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->lsh->x1, ourMartus->lsh->y1, ourMartus->lsh->x1 + 20, ourMartus->lsh->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->lsh->x2, ourMartus->lsh->y2, ourMartus->lsh->x2 + 20, ourMartus->lsh->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->lsh->x3, ourMartus->lsh->y3, ourMartus->lsh->x3 + 20, ourMartus->lsh->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->lsh->y0 > 650 || ourMartus->lsh->y1 > 650 || ourMartus->lsh->y2 > 650 || ourMartus->lsh->y3 > 650) {
                ourMartus->b[ourMartus->lsh->x0][ourMartus->lsh->y0] = 1;
                ourMartus->b[ourMartus->lsh->x1][ourMartus->lsh->y1] = 1;
                ourMartus->b[ourMartus->lsh->x2][ourMartus->lsh->y2] = 1;
                ourMartus->b[ourMartus->lsh->x3][ourMartus->lsh->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->lsh->x0][ourMartus->lsh->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->lsh->x1][ourMartus->lsh->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->lsh->x2][ourMartus->lsh->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->lsh->x3][ourMartus->lsh->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->lsh->x0][ourMartus->lsh->y0] = 1;
                ourMartus->b[ourMartus->lsh->x1][ourMartus->lsh->y1] = 1;
                ourMartus->b[ourMartus->lsh->x2][ourMartus->lsh->y2] = 1;
                ourMartus->b[ourMartus->lsh->x3][ourMartus->lsh->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(ourMartus->choice == "rsh") {

            ourMartus->rsh->y0 += 20;
            ourMartus->rsh->y1 += 20;
            ourMartus->rsh->y2 += 20;
            ourMartus->rsh->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

            RECT rrect3 = {ourMartus->rsh->x0, ourMartus->rsh->y0, ourMartus->rsh->x0 + 20, ourMartus->rsh->y0 + 20};
            FillRect(ourMartus->hdc2, &rrect3, brush);

            RECT rrect4 = {ourMartus->rsh->x1, ourMartus->rsh->y1, ourMartus->rsh->x1 + 20, ourMartus->rsh->y1 + 20};
            FillRect(ourMartus->hdc2, &rrect4, brush);

            RECT rrect5 = {ourMartus->rsh->x2, ourMartus->rsh->y2, ourMartus->rsh->x2 + 20, ourMartus->rsh->y2 + 20};
            FillRect(ourMartus->hdc2, &rrect5, brush);

            RECT rrect6 = {ourMartus->rsh->x3, ourMartus->rsh->y3, ourMartus->rsh->x3 + 20, ourMartus->rsh->y3 + 20};
            FillRect(ourMartus->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ourMartus->rsh->y0 > 650 || ourMartus->rsh->y1 > 650 || ourMartus->rsh->y2 > 650 || ourMartus->rsh->y3 > 650) {
                ourMartus->b[ourMartus->rsh->x0][ourMartus->rsh->y0] = 1;
                ourMartus->b[ourMartus->rsh->x1][ourMartus->rsh->y1] = 1;
                ourMartus->b[ourMartus->rsh->x2][ourMartus->rsh->y2] = 1;
                ourMartus->b[ourMartus->rsh->x3][ourMartus->rsh->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }

            BOOLEAN flag = FALSE;
            if(ourMartus->b[ourMartus->rsh->x0][ourMartus->rsh->y0+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->rsh->x1][ourMartus->rsh->y1+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->rsh->x2][ourMartus->rsh->y2+20] == 1) {
                flag = TRUE;
            }
            else if(ourMartus->b[ourMartus->rsh->x3][ourMartus->rsh->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                ourMartus->b[ourMartus->rsh->x0][ourMartus->rsh->y0] = 1;
                ourMartus->b[ourMartus->rsh->x1][ourMartus->rsh->y1] = 1;
                ourMartus->b[ourMartus->rsh->x2][ourMartus->rsh->y2] = 1;
                ourMartus->b[ourMartus->rsh->x3][ourMartus->rsh->y3] = 1;
                ourMartus->blocks++;
                ourMartus->prep();
            }
            if(ourMartus->level < 40 && ourMartus->lines >= ourMartus->linenext) {ourMartus->level++;ourMartus->linenext+=10;ourMartus->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }
        }
    }
    while(downIt);

    return 0;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    DeleteObject(ourMartus->hdc2);
    ourMartus->hdc2 = GetDC(hwnd);

    switch(msg) {
        
        case WM_KEYDOWN: 
            switch (wParam) 
            { 

        case VK_LEFT: 
            if(ourMartus->choice == "ht")
                ourMartus->ht->goLeft();
            else if(ourMartus->choice == "lne")
                ourMartus->lne->goLeft();
            else if(ourMartus->choice == "sq")
                ourMartus->sq->goLeft();
            else if(ourMartus->choice == "lsh")
                ourMartus->lsh->goLeft();
            else if(ourMartus->choice == "rsh")
                ourMartus->rsh->goLeft();
            else if(ourMartus->choice == "larm")
                ourMartus->larm->goLeft();
            else if(ourMartus->choice == "rarm")
                ourMartus->rarm->goLeft();
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }

            break;

        case VK_RIGHT:
            if(ourMartus->choice == "ht")
                ourMartus->ht->goRight();
            else if(ourMartus->choice == "lne")
                ourMartus->lne->goRight();
            else if(ourMartus->choice == "sq")
                ourMartus->sq->goRight();
            else if(ourMartus->choice == "lsh")
                ourMartus->lsh->goRight();
            else if(ourMartus->choice == "rsh")
                ourMartus->rsh->goRight();
            else if(ourMartus->choice == "larm")
                ourMartus->larm->goRight();
            else if(ourMartus->choice == "rarm")
                ourMartus->rarm->goRight();
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }

            break; 

        case VK_UP:
            if(ourMartus->choice == "sq")
                ourMartus->sq->rotate();
            else if(ourMartus->choice == "lne")
                ourMartus->lne->rotate();
            else if(ourMartus->choice == "ht")
                ourMartus->ht->rotate();
            else if(ourMartus->choice == "lsh")
                ourMartus->lsh->rotate();
            else if(ourMartus->choice == "rsh")
                ourMartus->rsh->rotate();
            else if(ourMartus->choice == "larm")
                ourMartus->larm->rotate();
            else if(ourMartus->choice == "rarm")
                ourMartus->rarm->rotate();
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }

            break;

        case VK_DOWN:
            if(ourMartus->choice == "sq")
                ourMartus->sq->goDown();
            else if(ourMartus->choice == "ht")
                ourMartus->ht->goDown();
            else if(ourMartus->choice == "lne")
                ourMartus->lne->goDown();
            else if(ourMartus->choice == "lsh")
                ourMartus->lsh->goDown();
            else if(ourMartus->choice == "rsh")
                ourMartus->rsh->goDown();
            else if(ourMartus->choice == "larm")
                ourMartus->larm->goDown();
            else if(ourMartus->choice == "rarm")
                ourMartus->rarm->goDown();
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(ourMartus->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(ourMartus->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                        Rectangle(ourMartus->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(ourMartus->hdc2, hOldPen));
                        SelectObject(ourMartus->hdc2, hOldBsh);
                    }
                }
            }

            HPEN hPenOld;
            HPEN hLinePen;
            COLORREF qLineColor;
            qLineColor = RGB(0, 77, 0);
            hLinePen = CreatePen(PS_SOLID, 3, qLineColor);
            hPenOld = (HPEN)SelectObject(ourMartus->hdc2, hLinePen);
            if(ourMartus->choice == "sq") {
                if (ourMartus->sq->y0 >= ourMartus->sq->y1 &&
                        ourMartus->sq->y0 >= ourMartus->sq->y2 &&
                        ourMartus->sq->y0 >= ourMartus->sq->y3) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->sq->y0+20, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->sq->y0+20);
                }
                else if (ourMartus->sq->y1 >= ourMartus->sq->y0 &&
                        ourMartus->sq->y1 >= ourMartus->sq->y1 &&
                        ourMartus->sq->y1 >= ourMartus->sq->y2) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->sq->y1+20, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->sq->y1+20);
                }
                else if (ourMartus->sq->y2 >= ourMartus->sq->y0 &&
                        ourMartus->sq->y2 >= ourMartus->sq->y1 &&
                        ourMartus->sq->y2 >= ourMartus->sq->y3) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->sq->y2+20, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->sq->y2+20);
                }
                else if (ourMartus->sq->y3 >= ourMartus->sq->y0 &&
                        ourMartus->sq->y3 >= ourMartus->sq->y1 &&
                        ourMartus->sq->y3 >= ourMartus->sq->y2) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->sq->y3+20, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->sq->y3+20);
                }

                if (ourMartus->sq->y0 <= ourMartus->sq->y1 &&
                        ourMartus->sq->y0 <= ourMartus->sq->y2 &&
                        ourMartus->sq->y0 <= ourMartus->sq->y3) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->sq->y0, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->sq->y0);
                }
                else if (ourMartus->sq->y1 <= ourMartus->sq->y0 &&
                        ourMartus->sq->y1 <= ourMartus->sq->y1 &&
                        ourMartus->sq->y1 <= ourMartus->sq->y2) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->sq->y1, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->sq->y1);
                }
                else if (ourMartus->sq->y2 <= ourMartus->sq->y0 &&
                        ourMartus->sq->y2 <= ourMartus->sq->y1 &&
                        ourMartus->sq->y2 <= ourMartus->sq->y3) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->sq->y2, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->sq->y2);
                }
                else if (ourMartus->sq->y3 <= ourMartus->sq->y0 &&
                        ourMartus->sq->y3 <= ourMartus->sq->y1 &&
                        ourMartus->sq->y3 <= ourMartus->sq->y2) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->sq->y3, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->sq->y3);
                }
            }

            if(ourMartus->choice == "lne") {
                if (ourMartus->lne->y0 >= ourMartus->lne->y1 &&
                        ourMartus->lne->y0 >= ourMartus->lne->y2 &&
                        ourMartus->lne->y0 >= ourMartus->lne->y3) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->lne->y0+20, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->lne->y0+20);
                }
                else if (ourMartus->lne->y1 >= ourMartus->lne->y0 &&
                        ourMartus->lne->y1 >= ourMartus->lne->y1 &&
                        ourMartus->lne->y1 >= ourMartus->lne->y2) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->lne->y1+20, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->lne->y1+20);
                }
                else if (ourMartus->lne->y2 >= ourMartus->lne->y0 &&
                        ourMartus->lne->y2 >= ourMartus->lne->y1 &&
                        ourMartus->lne->y2 >= ourMartus->lne->y3) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->lne->y2+20, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->lne->y2+20);
                }
                else if (ourMartus->lne->y3 >= ourMartus->lne->y0 &&
                        ourMartus->lne->y3 >= ourMartus->lne->y1 &&
                        ourMartus->lne->y3 >= ourMartus->lne->y2) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->lne->y3+20, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->lne->y3+20);
                }

                if (ourMartus->lne->y0 <= ourMartus->lne->y1 &&
                        ourMartus->lne->y0 <= ourMartus->lne->y2 &&
                        ourMartus->lne->y0 <= ourMartus->lne->y3) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->lne->y0, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->lne->y0);
                }
                else if (ourMartus->lne->y1 <= ourMartus->lne->y0 &&
                        ourMartus->lne->y1 <= ourMartus->lne->y1 &&
                        ourMartus->lne->y1 <= ourMartus->lne->y2) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->lne->y1, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->lne->y1);
                }
                else if (ourMartus->lne->y2 <= ourMartus->lne->y0 &&
                        ourMartus->lne->y2 <= ourMartus->lne->y1 &&
                        ourMartus->lne->y2 <= ourMartus->lne->y3) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->lne->y2, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->lne->y2);
                }
                else if (ourMartus->lne->y3 <= ourMartus->lne->y0 &&
                        ourMartus->lne->y3 <= ourMartus->lne->y1 &&
                        ourMartus->lne->y3 <= ourMartus->lne->y2) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->lne->y3, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->lne->y3);
                }
            }

            if(ourMartus->choice == "rarm") {
                if(ourMartus->rarm->dir == 1) {
                    if (ourMartus->rarm->y0 >= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y0 >= ourMartus->rarm->y2 &&
                            ourMartus->rarm->y0 >= ourMartus->rarm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y0+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y0+40);
                    }
                    else if (ourMartus->rarm->y1 >= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y1 >= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y1 >= ourMartus->rarm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y1+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y1+40);
                    }
                    else if (ourMartus->rarm->y2 >= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y2 >= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y2 >= ourMartus->rarm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y2+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y2+40);
                    }
                    else if (ourMartus->rarm->y3 >= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y3 >= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y3 >= ourMartus->rarm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y3+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y3+40);
                    }
                } else {
                    if (ourMartus->rarm->y0 >= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y0 >= ourMartus->rarm->y2 &&
                            ourMartus->rarm->y0 >= ourMartus->rarm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y0+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y0+20);
                    }
                    else if (ourMartus->rarm->y1 >= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y1 >= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y1 >= ourMartus->rarm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y1+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y1+20);
                    }
                    else if (ourMartus->rarm->y2 >= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y2 >= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y2 >= ourMartus->rarm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y2+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y2+20);
                    }
                    else if (ourMartus->rarm->y3 >= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y3 >= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y3 >= ourMartus->rarm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y3+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y3+20);
                    }
                }

                if(ourMartus->rarm->dir == 0) {
                    if (ourMartus->rarm->y0 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y0 <= ourMartus->rarm->y2 &&
                            ourMartus->rarm->y0 <= ourMartus->rarm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y0);
                    }
                    else if (ourMartus->rarm->y1 <= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y1 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y1 <= ourMartus->rarm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y1-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y1-0);
                    }
                    else if (ourMartus->rarm->y2 <= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y2 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y2 <= ourMartus->rarm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y2, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y2);
                    }
                    else if (ourMartus->rarm->y3 <= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y3 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y3 <= ourMartus->rarm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y3, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y3);
                    }
                } else if(ourMartus->rarm->dir == 1) {
                    if (ourMartus->rarm->y0 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y0 <= ourMartus->rarm->y2 &&
                            ourMartus->rarm->y0 <= ourMartus->rarm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y0+0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y0+0);
                    }
                    else if (ourMartus->rarm->y1 <= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y1 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y1 <= ourMartus->rarm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y1, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y1);
                    }
                    else if (ourMartus->rarm->y2 <= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y2 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y2 <= ourMartus->rarm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y2+0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y2+0);
                    }
                    else if (ourMartus->rarm->y3 <= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y3 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y3 <= ourMartus->rarm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y3, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y3);
                    }
                } else if(ourMartus->rarm->dir == 2) {
                    if (ourMartus->rarm->y0 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y0 <= ourMartus->rarm->y2 &&
                            ourMartus->rarm->y0 <= ourMartus->rarm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y0-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y0-0);
                    }
                    else if (ourMartus->rarm->y1 <= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y1 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y1 <= ourMartus->rarm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y1-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y1-0);
                    }
                    else if (ourMartus->rarm->y2 <= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y2 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y2 <= ourMartus->rarm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y2-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y2-0);
                    }
                    else if (ourMartus->rarm->y3 <= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y3 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y3 <= ourMartus->rarm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y3-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y3-0);
                    }
                } else {
                    if (ourMartus->rarm->y0 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y0 <= ourMartus->rarm->y2 &&
                            ourMartus->rarm->y0 <= ourMartus->rarm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y0-20+0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y0-20+0);
                    }
                    else if (ourMartus->rarm->y1 <= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y1 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y1 <= ourMartus->rarm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y1-20+0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y1-20+0);
                    }
                    else if (ourMartus->rarm->y2 <= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y2 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y2 <= ourMartus->rarm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y2+0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y2+0);
                    }
                    else if (ourMartus->rarm->y3 <= ourMartus->rarm->y0 &&
                            ourMartus->rarm->y3 <= ourMartus->rarm->y1 &&
                            ourMartus->rarm->y3 <= ourMartus->rarm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rarm->y3+0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rarm->y3+0);
                    }
                }
            }

            if(ourMartus->choice == "larm") {
                if(ourMartus->larm->dir == 3) {
                    if (ourMartus->larm->y0 >= ourMartus->larm->y1 &&
                            ourMartus->larm->y0 >= ourMartus->larm->y2 &&
                            ourMartus->larm->y0 >= ourMartus->larm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y0+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y0+40);
                    }
                    else if (ourMartus->larm->y1 >= ourMartus->larm->y0 &&
                            ourMartus->larm->y1 >= ourMartus->larm->y1 &&
                            ourMartus->larm->y1 >= ourMartus->larm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y1+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y1+40);
                    }
                    else if (ourMartus->larm->y2 >= ourMartus->larm->y0 &&
                            ourMartus->larm->y2 >= ourMartus->larm->y1 &&
                            ourMartus->larm->y2 >= ourMartus->larm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y2+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y2+40);
                    }
                    else if (ourMartus->larm->y3 >= ourMartus->larm->y0 &&
                            ourMartus->larm->y3 >= ourMartus->larm->y1 &&
                            ourMartus->larm->y3 >= ourMartus->larm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y3+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y3+40);
                    }
                } else {
                    if (ourMartus->larm->y0 >= ourMartus->larm->y1 &&
                            ourMartus->larm->y0 >= ourMartus->larm->y2 &&
                            ourMartus->larm->y0 >= ourMartus->larm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y0+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y0+20);
                    }
                    else if (ourMartus->larm->y1 >= ourMartus->larm->y0 &&
                            ourMartus->larm->y1 >= ourMartus->larm->y1 &&
                            ourMartus->larm->y1 >= ourMartus->larm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y1+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y1+20);
                    }
                    else if (ourMartus->larm->y2 >= ourMartus->larm->y0 &&
                            ourMartus->larm->y2 >= ourMartus->larm->y1 &&
                            ourMartus->larm->y2 >= ourMartus->larm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y2+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y2+20);
                    }
                    else if (ourMartus->larm->y3 >= ourMartus->larm->y0 &&
                            ourMartus->larm->y3 >= ourMartus->larm->y1 &&
                            ourMartus->larm->y3 >= ourMartus->larm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y3+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y3+20);
                    }
                }

                if(ourMartus->larm->dir == 0) {
                    if (ourMartus->larm->y0 <= ourMartus->larm->y1 &&
                            ourMartus->larm->y0 <= ourMartus->larm->y2 &&
                            ourMartus->larm->y0 <= ourMartus->larm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y0);
                    }
                    else if (ourMartus->larm->y1 <= ourMartus->larm->y0 &&
                            ourMartus->larm->y1 <= ourMartus->larm->y1 &&
                            ourMartus->larm->y1 <= ourMartus->larm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y1-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y1-0);
                    }
                    else if (ourMartus->larm->y2 <= ourMartus->larm->y0 &&
                            ourMartus->larm->y2 <= ourMartus->larm->y1 &&
                            ourMartus->larm->y2 <= ourMartus->larm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y2, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y2);
                    }
                    else if (ourMartus->larm->y3 <= ourMartus->larm->y0 &&
                            ourMartus->larm->y3 <= ourMartus->larm->y1 &&
                            ourMartus->larm->y3 <= ourMartus->larm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y3, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y3);
                    }
                } else if(ourMartus->larm->dir == 3) {
                    if (ourMartus->larm->y0 <= ourMartus->larm->y1 &&
                            ourMartus->larm->y0 <= ourMartus->larm->y2 &&
                            ourMartus->larm->y0 <= ourMartus->larm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y0);
                    }
                    else if (ourMartus->larm->y1 <= ourMartus->larm->y0 &&
                            ourMartus->larm->y1 <= ourMartus->larm->y1 &&
                            ourMartus->larm->y1 <= ourMartus->larm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y1, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y1);
                    }
                    else if (ourMartus->larm->y2 <= ourMartus->larm->y0 &&
                            ourMartus->larm->y2 <= ourMartus->larm->y1 &&
                            ourMartus->larm->y2 <= ourMartus->larm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y2, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y2);
                    }
                    else if (ourMartus->larm->y3 <= ourMartus->larm->y0 &&
                            ourMartus->larm->y3 <= ourMartus->larm->y1 &&
                            ourMartus->larm->y3 <= ourMartus->larm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y3, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y3);
                    }
                } else {
                    if (ourMartus->larm->y0 <= ourMartus->larm->y1 &&
                            ourMartus->larm->y0 <= ourMartus->larm->y2 &&
                            ourMartus->larm->y0 <= ourMartus->larm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y0-20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y0-20);
                    }
                    else if (ourMartus->larm->y1 <= ourMartus->larm->y0 &&
                            ourMartus->larm->y1 <= ourMartus->larm->y1 &&
                            ourMartus->larm->y1 <= ourMartus->larm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y1-20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y1-20);
                    }
                    else if (ourMartus->larm->y2 <= ourMartus->larm->y0 &&
                            ourMartus->larm->y2 <= ourMartus->larm->y1 &&
                            ourMartus->larm->y2 <= ourMartus->larm->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y2, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y2);
                    }
                    else if (ourMartus->larm->y3 <= ourMartus->larm->y0 &&
                            ourMartus->larm->y3 <= ourMartus->larm->y1 &&
                            ourMartus->larm->y3 <= ourMartus->larm->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->larm->y3, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->larm->y3);
                    }
                }
            }

            if(ourMartus->choice == "ht") {
                if (ourMartus->ht->y0 >= ourMartus->ht->y1 &&
                        ourMartus->ht->y0 >= ourMartus->ht->y2 &&
                        ourMartus->ht->y0 >= ourMartus->ht->y3) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->ht->y0+20, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->ht->y0+20);
                }
                else if (ourMartus->ht->y1 >= ourMartus->ht->y0 &&
                        ourMartus->ht->y1 >= ourMartus->ht->y1 &&
                        ourMartus->ht->y1 >= ourMartus->ht->y2) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->ht->y1+20, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->ht->y1+20);
                }
                else if (ourMartus->ht->y2 >= ourMartus->ht->y0 &&
                        ourMartus->ht->y2 >= ourMartus->ht->y1 &&
                        ourMartus->ht->y2 >= ourMartus->ht->y3) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->ht->y2+20, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->ht->y2+20);
                }
                else if (ourMartus->ht->y3 >= ourMartus->ht->y0 &&
                        ourMartus->ht->y3 >= ourMartus->ht->y1 &&
                        ourMartus->ht->y3 >= ourMartus->ht->y2) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->ht->y3+20, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->ht->y3+20);
                }

                if (ourMartus->ht->y0 <= ourMartus->ht->y1 &&
                        ourMartus->ht->y0 <= ourMartus->ht->y2 &&
                        ourMartus->ht->y0 <= ourMartus->ht->y3) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->ht->y0, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->ht->y0);
                }
                else if (ourMartus->ht->y1 <= ourMartus->ht->y0 &&
                        ourMartus->ht->y1 <= ourMartus->ht->y1 &&
                        ourMartus->ht->y1 <= ourMartus->ht->y2) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->ht->y1, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->ht->y1);
                }
                else if (ourMartus->ht->y2 <= ourMartus->ht->y0 &&
                        ourMartus->ht->y2 <= ourMartus->ht->y1 &&
                        ourMartus->ht->y2 <= ourMartus->ht->y3) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->ht->y2, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->ht->y2);
                }
                else if (ourMartus->ht->y3 <= ourMartus->ht->y0 &&
                        ourMartus->ht->y3 <= ourMartus->ht->y1 &&
                        ourMartus->ht->y3 <= ourMartus->ht->y2) {
                    MoveToEx(ourMartus->hdc2, 224, ourMartus->ht->y3, NULL);
                    LineTo(ourMartus->hdc2, 415, ourMartus->ht->y3);
                }
            }

            if(ourMartus->choice == "lsh") {
                if(ourMartus->lsh->dir == 0) {
                    if (ourMartus->lsh->y0 >= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y0 >= ourMartus->lsh->y2 &&
                            ourMartus->lsh->y0 >= ourMartus->lsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y0+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y0+40);
                    }
                    else if (ourMartus->lsh->y1 >= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y1 >= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y1 >= ourMartus->lsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y1+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y1+40);
                    }
                    else if (ourMartus->lsh->y2 >= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y2 >= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y2 >= ourMartus->lsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y2+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y2+40);
                    }
                    else if (ourMartus->lsh->y3 >= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y3 >= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y3 >= ourMartus->lsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y3+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y3+40);
                    }
                } else {
                    if (ourMartus->lsh->y0 >= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y0 >= ourMartus->lsh->y2 &&
                            ourMartus->lsh->y0 >= ourMartus->lsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y0+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y0+20);
                    }
                    else if (ourMartus->lsh->y1 >= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y1 >= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y1 >= ourMartus->lsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y1+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y1+20);
                    }
                    else if (ourMartus->lsh->y2 >= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y2 >= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y2 >= ourMartus->lsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y2+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y2+20);
                    }
                    else if (ourMartus->lsh->y3 >= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y3 >= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y3 >= ourMartus->lsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y3+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y3+20);
                    }
                }

                if(ourMartus->lsh->dir == 3) {
                    if (ourMartus->lsh->y0 <= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y0 <= ourMartus->lsh->y2 &&
                            ourMartus->lsh->y0 <= ourMartus->lsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y0-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y0-0);
                    }
                    else if (ourMartus->lsh->y1 <= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y1 <= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y1 <= ourMartus->lsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y1-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y1-0);
                    }
                    else if (ourMartus->lsh->y2 <= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y2 <= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y2 <= ourMartus->lsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y2-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y2-0);
                    }
                    else if (ourMartus->lsh->y3 <= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y3 <= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y3 <= ourMartus->lsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y3-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y3-0);
                    }
                } else if(ourMartus->lsh->dir == 2) {
                    if (ourMartus->lsh->y0 <= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y0 <= ourMartus->lsh->y2 &&
                            ourMartus->lsh->y0 <= ourMartus->lsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y0-20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y0-20);
                    }
                    else if (ourMartus->lsh->y1 <= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y1 <= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y1 <= ourMartus->lsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y1-20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y1-20);
                    }
                    else if (ourMartus->lsh->y2 <= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y2 <= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y2 <= ourMartus->lsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y2-20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y2-20);
                    }
                    else if (ourMartus->lsh->y3 <= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y3 <= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y3 <= ourMartus->lsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y3-20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y3-20);
                    }
                } else {
                    if (ourMartus->lsh->y0 <= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y0 <= ourMartus->lsh->y2 &&
                            ourMartus->lsh->y0 <= ourMartus->lsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y0);
                    }
                    else if (ourMartus->lsh->y1 <= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y1 <= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y1 <= ourMartus->lsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y1, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y1);
                    }
                    else if (ourMartus->lsh->y2 <= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y2 <= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y2 <= ourMartus->lsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y2, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y2);
                    }
                    else if (ourMartus->lsh->y3 <= ourMartus->lsh->y0 &&
                            ourMartus->lsh->y3 <= ourMartus->lsh->y1 &&
                            ourMartus->lsh->y3 <= ourMartus->lsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->lsh->y3, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->lsh->y3);
                    }
                }
            }

            if(ourMartus->choice == "rsh") {
                if(ourMartus->rsh->dir == 0) {
                    if (ourMartus->rsh->y0 >= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y0 >= ourMartus->rsh->y2 &&
                            ourMartus->rsh->y0 >= ourMartus->rsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y0+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y0+40);
                    }
                    else if (ourMartus->rsh->y1 >= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y1 >= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y1 >= ourMartus->rsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y1+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y1+40);
                    }
                    else if (ourMartus->rsh->y2 >= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y2 >= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y2 >= ourMartus->rsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y2+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y2+40);
                    }
                    else if (ourMartus->rsh->y3 >= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y3 >= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y3 >= ourMartus->rsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y3+40, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y3+40);
                    }
                } else if(ourMartus->rsh->dir == 2) {
                    if (ourMartus->rsh->y0 >= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y0 >= ourMartus->rsh->y2 &&
                            ourMartus->rsh->y0 >= ourMartus->rsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y0+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y0+20);
                    }
                    else if (ourMartus->rsh->y1 >= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y1 >= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y1 >= ourMartus->rsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y1+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y1+20);
                    }
                    else if (ourMartus->rsh->y2 >= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y2 >= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y2 >= ourMartus->rsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y2+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y2+20);
                    }
                    else if (ourMartus->rsh->y3 >= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y3 >= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y3 >= ourMartus->rsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y3+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y3+20);
                    }
                } else {
                    if (ourMartus->rsh->y0 >= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y0 >= ourMartus->rsh->y2 &&
                            ourMartus->rsh->y0 >= ourMartus->rsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y0+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y0+20);
                    }
                    else if (ourMartus->rsh->y1 >= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y1 >= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y1 >= ourMartus->rsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y1+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y1+20);
                    }
                    else if (ourMartus->rsh->y2 >= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y2 >= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y2 >= ourMartus->rsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y2+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y2+20);
                    }
                    else if (ourMartus->rsh->y3 >= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y3 >= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y3 >= ourMartus->rsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y3+20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y3+20);
                    }
                }

                if(ourMartus->rsh->dir == 0) {
                    if (ourMartus->rsh->y0 <= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y0 <= ourMartus->rsh->y2 &&
                            ourMartus->rsh->y0 <= ourMartus->rsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y0-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y0-0);
                    }
                    else if (ourMartus->rsh->y1 <= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y1 <= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y1 <= ourMartus->rsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y1-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y1-0);
                    }
                    else if (ourMartus->rsh->y2 <= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y2 <= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y2 <= ourMartus->rsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y2-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y2-0);
                    }
                    else if (ourMartus->rsh->y3 <= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y3 <= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y3 <= ourMartus->rsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y3-0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y3-0);
                    }
                } else if(ourMartus->rsh->dir == 2) {
                    if (ourMartus->rsh->y0 <= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y0 <= ourMartus->rsh->y2 &&
                            ourMartus->rsh->y0 <= ourMartus->rsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y0-20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y0-20);
                    }
                    else if (ourMartus->rsh->y1 <= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y1 <= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y1 <= ourMartus->rsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y1-20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y1-20);
                    }
                    else if (ourMartus->rsh->y2 <= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y2 <= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y2 <= ourMartus->rsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y2-20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y2-20);
                    }
                    else if (ourMartus->rsh->y3 <= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y3 <= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y3 <= ourMartus->rsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y3-20, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y3-20);
                    }
                } else {
                    if (ourMartus->rsh->y0 <= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y0 <= ourMartus->rsh->y2 &&
                            ourMartus->rsh->y0 <= ourMartus->rsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y0, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y0);
                    }
                    else if (ourMartus->rsh->y1 <= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y1 <= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y1 <= ourMartus->rsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y1, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y1);
                    }
                    else if (ourMartus->rsh->y2 <= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y2 <= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y2 <= ourMartus->rsh->y3) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y2, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y2);
                    }
                    else if (ourMartus->rsh->y3 <= ourMartus->rsh->y0 &&
                            ourMartus->rsh->y3 <= ourMartus->rsh->y1 &&
                            ourMartus->rsh->y3 <= ourMartus->rsh->y2) {
                        MoveToEx(ourMartus->hdc2, 224, ourMartus->rsh->y3, NULL);
                        LineTo(ourMartus->hdc2, 415, ourMartus->rsh->y3);
                    }
                }
            }

            SelectObject(ourMartus->hdc2, hPenOld);
            DeleteObject(hLinePen);
            break;
        }
        case WM_PAINT:
        {
            if(ourMartus->fist) {

                HBRUSH brush79 = CreateSolidBrush(RGB(136, 0, 0));
                RECT rrect79 = {0, 0, 22640, 22750};
                FillRect(ourMartus->hdc2, &rrect79, brush79);
                DeleteObject(brush79);
                HBRUSH brush = CreateSolidBrush(RGB(50, 30, 7));
                RECT rrect = {0, 0, 640, 750};
                FillRect(ourMartus->hdc2, &rrect, brush);
                DeleteObject(brush);
                HBRUSH brush0 = CreateSolidBrush(RGB(255, 180, 230));
                RECT rrect9 = {199, 0, 440, 710};
                FillRect(ourMartus->hdc2, &rrect9, brush0);
                DeleteObject(brush0);
                HBRUSH brush2 = CreateSolidBrush(RGB(255, 200, 112));
                RECT rrect3 = {209, 10, 430, 700};
                FillRect(ourMartus->hdc2, &rrect3, brush2);
                DeleteObject(brush2);

                ourMartus->threa = CreateThread(0, 0, downs, 0, 0, NULL);
                srand(time(NULL));
                ourMartus->prep();
            }

            for(int i=0; i<700; i++) {
                for(int j=0; j<720; j++) {
                    if(ourMartus->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(ourMartus->hdc2, &rrect6, brush);
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

            char aa[16];sprintf(aa,"LEVEL: %d of 40",ourMartus->level);

            SelectObject(ourMartus->hdc2, font);
            TextOut(ourMartus->hdc2, 450, 20, aa, 15);
            TextOut(ourMartus->hdc2, 0, 240, "PREVIEW", 7);
            DeleteObject(font);

            font = CreateFont(16, 0, 0, 0,
                              FW_NORMAL, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            HBRUSH brush1 = CreateSolidBrush(RGB(255, 255, 0));
            RECT rrect1 = {40, 310, 150, 420};
            FillRect(ourMartus->hdc2, &rrect1, brush1);
            DeleteObject(brush1);

            char dd[16];sprintf(dd,"Level: %d", ourMartus->level);

            SelectObject(ourMartus->hdc2, font);
            TextOut(ourMartus->hdc2, 50, 320, dd, 9);
            DeleteObject(font);

            font = CreateFont(16, 0, 0, 0,
                              FW_NORMAL, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            char cc[16];sprintf(cc,"Blocks: %d", ourMartus->blocks);

            SelectObject(ourMartus->hdc2, font);
            if(ourMartus->blocks < 10)
                TextOut(ourMartus->hdc2, 50, 340, cc, 9);
            else if(ourMartus->blocks > 9 && ourMartus->blocks < 100)
                TextOut(ourMartus->hdc2, 50, 340, cc, 10);
            else if(ourMartus->blocks > 99 && ourMartus->blocks < 1000)
                TextOut(ourMartus->hdc2, 50, 340, cc, 11);
            else if(ourMartus->blocks > 999 && ourMartus->blocks < 10000)
                TextOut(ourMartus->hdc2, 50, 340, cc, 12);
            else
                TextOut(ourMartus->hdc2, 50, 340, cc, 13);
            DeleteObject(font);

            font = CreateFont(16, 0, 0, 0,
                              FW_NORMAL, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            char bb[16];sprintf(bb,"Lines: %d", ourMartus->lines);

            SelectObject(ourMartus->hdc2, font);
            if(ourMartus->lines < 10)
                TextOut(ourMartus->hdc2, 50, 360, bb, 8);
            else if(ourMartus->lines > 9 && ourMartus->lines < 100)
                TextOut(ourMartus->hdc2, 50, 360, bb, 9);
            else if(ourMartus->lines > 99 && ourMartus->lines < 1000)
                TextOut(ourMartus->hdc2, 50, 360, bb, 10);
            else if(ourMartus->lines > 999 && ourMartus->lines < 10000)
                TextOut(ourMartus->hdc2, 50, 360, bb, 11);
            else
                TextOut(ourMartus->hdc2, 50, 360, bb, 12);
            DeleteObject(font);

            font = CreateFont(26, 0, 0, 0,
                              FW_NORMAL, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            SelectObject(ourMartus->hdc2, font);
            TextOut(ourMartus->hdc2, 450, 480, "MPC Martus", 10);
            DeleteObject(font);

            font = CreateFont(16, 0, 0, 0,
                              FW_BOLD, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Verdana");

            SelectObject(ourMartus->hdc2, font);
            TextOut(ourMartus->hdc2, 10, 640, "By OkelyKodely", 14);
            SelectObject(ourMartus->hdc2, font);
            TextOut(ourMartus->hdc2, 10, 680, "I MADE THIS!", 12);
            DeleteObject(font);
            
            EndPaint (hwnd, &ps);
        }
        break;
        case WM_CREATE:
        {
            int y = 600; int h = 48;
            int x = 443; int w = 124;
  	    ourMartus->hwnd_new_game = CreateWindowEx(0, "BUTTON", "Turn Music On", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
								x, y, w, h, hwnd, (HMENU) PLAY_AGAIN_BUTTON, GetModuleHandle(NULL), NULL);
        }
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case PLAY_AGAIN_BUTTON:
                    if (HIWORD(wParam) == BN_CLICKED) {
                        if(!ourMartus->dontplay) {
                            SetWindowText(ourMartus->hwnd_new_game, "Turn Music On");
                            PlaySound(NULL,NULL,0);
                        } else {
                            SetWindowText(ourMartus->hwnd_new_game, "Turn Music Off");
                            PlaySound(TEXT("Tetris.wav"), NULL, SND_LOOP | SND_ASYNC);
                        }
                        ourMartus->dontplay = !ourMartus->dontplay;
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
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    
    MSG Msg;

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

    if(!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        
        return 0;
    }

    hwnd = CreateWindow(g_szClassName, NULL, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), NULL, NULL, hInstance, NULL);

    if(hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        
        return 0;
    }

    SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MINIMIZEBOX);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    
    SetWindowText(hwnd, "TETRIS");

    while(GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    
    return Msg.wParam;
}