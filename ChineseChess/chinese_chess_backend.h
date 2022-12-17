#pragma once

#include<vector>
#include<fstream>
#include<string>
#include<iostream>

#include "abstract_backend.h"

using namespace std;

class ChineseChessBackend :public AbstractBackend
{
public:
	ChineseChessBackend();
	ChineseChessBackend(string name);
	virtual void saveFile(string name) override;
	virtual vector<Coordinate> getMovable(int x, int y, int option) override;
	virtual int eatable(int a, int b) override;
	virtual void print() override;
	virtual int isChampion() override;
	virtual int isWin() override;


private:
	vector<Ary> chessLog;
};
