#pragma once
#include<iostream>
#include<windows.h>
#include<vector>
#include<conio.h>
#include<string>
#include"Backend.h"
using namespace std;
__declspec(selectany) int page = 0;
__declspec(selectany) int first = 1;
_declspec(selectany) vector<string> LeftLog;
_declspec(selectany) vector<string> RegretLog;
_declspec(selectany) vector<Ary> LeftAry;
_declspec(selectany) vector<Ary> RegretAry;
__declspec(selectany) char outPut[24][180] =
{
	"שÝ שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שß",//0
	"שרשÝ שש  ¾װ  ×p  ֵד  ¥Ü שש שß ¢°  ¢±  ¢²  ¢³  ¢´  ¢µ  ¢¶  ¢·  ¢¸ שÝ שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שß שר",//1 
	"שרשר                     שר שÝ שש שÞ שש שÞ שש שÞ שש שÞ שש שÞ שש שÞ שש שÞ שש שß  שר                                   שר שר",//2
	"שרשר                     שר שר   ¡U  ¡U  ¡U¢@¡U¡‏¡U  ¡U  ¡U  שר  שר                                   שר שר",//3
	"שרשר                     שר שר ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w שר  שר                                   שר שר",//4
	"שרשר                     שר שר   ¡U  ¡U  ¡U¡‏¡U¢@¡U  ¡U  ¡U  שר  שר                                   שר שר",//5
	"שרשר                     שר שר ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w שר  שר                                   שר שר",//6
	"שרשר                     שר שר   ¡U  ¡U  ¡U  ¡U  ¡U  ¡U  ¡U  שר  שר                                   שר שר",//7
	"שרשר                     שר שר ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w שר  שר                                   שר שר",//8
	"שרשר                     שר שר   ¡U  ¡U  ¡U  ¡U  ¡U  ¡U  ¡U  שר  שר                                   שר שר",//9
	"שרשר                     שר שר ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢r ¢w ¢r ¢w שר  שר                                   שר שר",//10
	"שרשר                     שר שר     ·¡×e             ÷~¬ֹ     שר  שר                                   שר שר",//11
	"שרשר                     שר שר ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢s ¢w ¢s ¢w שר  שר                                   שר שר",
	"שרשר                     שר שר   ¡U  ¡U  ¡U  ¡U  ¡U  ¡U  ¡U  שר  שר                                   שר שר",
	"שרשר                     שר שר ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w שר  שא שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שג שר",
	"שרשר                     שר שר   ¡U  ¡U  ¡U  ¡U  ¡U  ¡U  ¡U  שר  שר        Esc ¿ן³ז       h ְ°§U      שר שר",
	"שרשר                     שר שר ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w שר  שר                                   שר שר",
	"שרשר                     שר שר   ¡U  ¡U  ¡U¢@¡U¡‏¡U  ¡U  ¡U  שר  שר          Enter    ¿ן¨ת´ׁ₪l        שר שר",
	"שרשר                     שר שר ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w ¢q ¢w שר  שר                                   שר שר",
	"שרשר                     שר שר   ¡U  ¡U  ¡U¡‏¡U¢@¡U  ¡U  ¡U  שר  שר         ¡פ                        שר שר",
	"שרשר                     שר שד שש שה שש שה שש שה שש שה שש שה שש שה שש שה שש שו  שר       ¡צ  ¡ק  ₪ט¦Vֱה±±¨מ´ו¼׀      שר שר",
	"שרשר                     שר ₪E  ₪K  ₪C  ₪»  ₪­  ¥|  ₪T  ₪G  ₪@ שר         ¡ץ                        שר שר",
	"שרשד שש שש שש שש שש שש שש שש שש שש שו                                    שד שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שו שר",
	"שד שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שש שו"
};
void SetColor(int color = 7);
void gotoxy(int xpos, int ypos);
void turnToChess(int i, int k);
void returnChess(int i);
void PushLog(Log a);
void PrintLog(int page, int first);
void PrintMove(vector<Coordinate> a);
void PrintEat(vector<Coordinate> a);
void PrintTurn(int i);
void PrintChoose(int i);
void PrintAllLine(int a, int b);
// i ¦C¼ֶ a~b¬°¦³ֳC¦ג color ¬°¦ג½X 
void PrintColorLine(int i, int a, int b, int color);
void PrintChess(int i);
void PrintChessboard();
void PrintLeft();
void PrintRight();
void PrintReturn();
void PrintRegret();
int PrintMenu();
void PrintHelp();
void SaveFile();
void ReadFile();
int PrintWin(int who);
void PrintCheck(int who);
void blank();
void signboard();
void opening();
void play();
void PrintScreen();
void Reset();

