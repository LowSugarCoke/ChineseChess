#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

#include<conio.h>
#include<windows.h>


#include "abstract_backend.h"

using namespace std;

class Print {
public:
	Print(AbstractBackend* backend);
	void signboard();
	void opening();
	void play();
	void PrintScreen();

private:
	AbstractBackend* mBackend;
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
	// i 列數 a~b為有顏色 color 為色碼
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
	void Reset();
};
