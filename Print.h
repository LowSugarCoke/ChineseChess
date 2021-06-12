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
	"�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��",//0
	"���� ��  ��  �p  ��  �� �� �� ��  ��  ��  ��  ��  ��  ��  ��  �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��",//1 
	"����                     �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��  ��                                   �� ��",//2
	"����                     �� ��   �U  �U  �U�@�U���U  �U  �U  ��  ��                                   �� ��",//3
	"����                     �� �� �w �q �w �q �w �q �w �q �w �q �w �q �w �q �w ��  ��                                   �� ��",//4
	"����                     �� ��   �U  �U  �U���U�@�U  �U  �U  ��  ��                                   �� ��",//5
	"����                     �� �� �w �q �w �q �w �q �w �q �w �q �w �q �w �q �w ��  ��                                   �� ��",//6
	"����                     �� ��   �U  �U  �U  �U  �U  �U  �U  ��  ��                                   �� ��",//7
	"����                     �� �� �w �q �w �q �w �q �w �q �w �q �w �q �w �q �w ��  ��                                   �� ��",//8
	"����                     �� ��   �U  �U  �U  �U  �U  �U  �U  ��  ��                                   �� ��",//9
	"����                     �� �� �w �r �w �r �w �r �w �r �w �r �w �r �w �r �w ��  ��                                   �� ��",//10
	"����                     �� ��     ���e             �~��     ��  ��                                   �� ��",//11
	"����                     �� �� �w �s �w �s �w �s �w �s �w �s �w �s �w �s �w ��  ��                                   �� ��",
	"����                     �� ��   �U  �U  �U  �U  �U  �U  �U  ��  ��                                   �� ��",
	"����                     �� �� �w �q �w �q �w �q �w �q �w �q �w �q �w �q �w ��  �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��",
	"����                     �� ��   �U  �U  �U  �U  �U  �U  �U  ��  ��        Esc ���       h ���U      �� ��",
	"����                     �� �� �w �q �w �q �w �q �w �q �w �q �w �q �w �q �w ��  ��                                   �� ��",
	"����                     �� ��   �U  �U  �U�@�U���U  �U  �U  ��  ��          Enter    ����Ѥl        �� ��",
	"����                     �� �� �w �q �w �q �w �q �w �q �w �q �w �q �w �q �w ��  ��                                   �� ��",
	"����                     �� ��   �U  �U  �U���U�@�U  �U  �U  ��  ��         ��                        �� ��",
	"����                     �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��  ��       ��  ��  ��V�䱱����      �� ��",
	"����                     �� �E  �K  �C  ��  ��  �|  �T  �G  �@ ��         ��                        �� ��",
	"���� �� �� �� �� �� �� �� �� �� �� ��                                    �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��",
	"�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��"
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
// i �C�� a~b�����C�� color ����X 
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

