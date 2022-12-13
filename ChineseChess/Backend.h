#pragma once

#include<vector>
#include<fstream>
#include<string>
#include<iostream>

#include"database.h"
#include "log.h"
#include "coordinate.h"
#include "ary.h"

using namespace std;

class ChessBoard
{
public:
	ChessBoard();
	ChessBoard(string name);
	void saveFile(string name);
	vector<Ary> chessLog;
	vector<Coordinate> getMovable(int x, int y, int option);
	int eatable(int a, int b);
	void print();
	int isChampion();
	int isWin();
};
