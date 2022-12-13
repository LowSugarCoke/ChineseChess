#pragma once
class Ary
{
public:
	Ary(int a[10][9]) {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				ary[i][j] = a[i][j];
			}
		}
	};
	int ary[10][9];
};
