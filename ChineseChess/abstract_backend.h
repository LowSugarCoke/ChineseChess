#pragma once

#include"database.h"
#include "log.h"
#include "coordinate.h"
#include "ary.h"

using namespace std;

class AbstractBackend
{
public:
	AbstractBackend() {};
	virtual ~AbstractBackend() {};
	virtual void saveFile(string name) = 0;
	virtual	vector<Coordinate> getMovable(int x, int y, int option) = 0;
	virtual int eatable(int a, int b) = 0;
	virtual void print() = 0;
	virtual int isChampion() = 0;
	virtual int isWin() = 0;
};
