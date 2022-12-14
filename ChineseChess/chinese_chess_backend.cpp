#include "chinese_chess_backend.h"

ChineseChessBackend::ChineseChessBackend() :
	AbstractBackend()
{
	int a[10][9] =
	{
		{4,5,3,2,1,2,3,5,4},
		{0,0,0,0,0,0,0,0,0},
		{0,6,0,0,0,0,0,6,0},
		{7,0,7,0,7,0,7,0,7},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{14,0,14,0,14,0,14,0,14},
		{0,13,0,0,0,0,0,13,0},
		{0,0,0,0,0,0,0,0,0},
		{11,12,10,9,8,9,10,12,11}
	};
	Ary ary(a);
	chessLog.push_back(ary);
}

ChineseChessBackend::ChineseChessBackend(string name)
	:AbstractBackend()
{
}

void ChineseChessBackend::saveFile(string name)
{
}

vector<Coordinate> ChineseChessBackend::getMovable(int x, int y, int option)
{
	if (option == 0 || option == 1)
	{
		y = (y - 25) / 4;
		x = (x - 2) / 2;
	}
	vector<Coordinate> v;
	vector<Coordinate> h;
	int type;
	type = chessBoard[x][y];
	Coordinate t;
	int flag = 0;
	switch (type)
	{
	case 4:
	case 11:
	case 6:
	case 13:
		for (int i = x + 1; i < 10; i++)
		{
			if (chessBoard[i][y] == 0 && flag == 0)
			{
				t.x = i;
				t.y = y;
				v.push_back(t);
			}
			else if (chessBoard[i][y] != 0)
			{
				if ((type == 13 || type == 6) && flag == 1 && eatable(chessBoard[x][y], chessBoard[i][y]))
				{
					t.x = i;
					t.y = y;
					h.push_back(t);
					break;
				}
				else if ((type == 4 || type == 11) && eatable(chessBoard[x][y], chessBoard[i][y]) && flag == 0)
				{
					t.x = i;
					t.y = y;
					h.push_back(t);
					break;
				}
				flag++;
			}
		}
		flag = 0;
		for (int i = x - 1; i > -1; i--)
		{
			if (chessBoard[i][y] == 0 && flag == 0)
			{
				t.x = i;
				t.y = y;
				v.push_back(t);
			}
			else if (chessBoard[i][y] != 0)
			{
				if ((type == 13 || type == 6) && flag == 1 && eatable(chessBoard[x][y], chessBoard[i][y]))
				{
					t.x = i;
					t.y = y;
					h.push_back(t);
					break;
				}
				else if ((type == 4 || type == 11) && eatable(chessBoard[x][y], chessBoard[i][y]) && flag == 0)
				{
					t.x = i;
					t.y = y;
					h.push_back(t);
					break;
				}
				flag++;
			}
		}
		flag = 0;
		for (int i = y + 1; i < 9; i++)
		{
			if (chessBoard[x][i] == 0 && flag == 0)
			{
				t.x = x;
				t.y = i;
				v.push_back(t);
			}
			else if (chessBoard[x][i] != 0)
			{
				if ((type == 13 || type == 6) && flag == 1 && eatable(chessBoard[x][y], chessBoard[x][i]))
				{
					t.x = x;
					t.y = i;
					h.push_back(t);
					break;
				}
				else if ((type == 4 || type == 11) && eatable(chessBoard[x][y], chessBoard[x][i]) && flag == 0)
				{
					t.x = x;
					t.y = i;
					h.push_back(t);
					break;
				}
				flag++;
			}
		}
		flag = 0;
		for (int i = y - 1; i > -1; i--)
		{
			if (chessBoard[x][i] == 0 && flag == 0)
			{
				t.x = x;
				t.y = i;
				v.push_back(t);
			}
			else if (chessBoard[x][i] != 0)
			{
				if ((type == 13 || type == 6) && flag == 1 && eatable(chessBoard[x][y], chessBoard[x][i]))
				{
					t.x = x;
					t.y = i;
					h.push_back(t);
					break;
				}
				else if ((type == 4 || type == 11) && eatable(chessBoard[x][y], chessBoard[x][i]) && flag == 0)
				{
					t.x = x;
					t.y = i;
					h.push_back(t);
					break;
				}
				flag++;
			}
		}
		break;

	case 7:
		if (chessBoard[x + 1][y] == 0 && x < 9)
		{
			t.x = x + 1;
			t.y = y;
			v.push_back(t);
		}
		else if (eatable(chessBoard[x][y], chessBoard[x + 1][y]))
		{
			t.x = x + 1;
			t.y = y;
			h.push_back(t);
		}
		if (x > 4)
		{
			if (chessBoard[x][y + 1] == 0 && y < 8)
			{
				t.x = x;
				t.y = y + 1;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[x][y + 1]))
			{
				t.x = x;
				t.y = y + 1;
				h.push_back(t);
			}
			if (chessBoard[x][y - 1] == 0 && y > 0)
			{
				t.x = x;
				t.y = y - 1;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[x][y - 1]))
			{
				t.x = x;
				t.y = y - 1;
				h.push_back(t);
			}
		}
		break;

	case 14:
		if (chessBoard[x - 1][y] == 0 && x > 0)
		{
			t.x = x - 1;
			t.y = y;
			v.push_back(t);
		}
		else if (eatable(chessBoard[x][y], chessBoard[x - 1][y]))
		{
			t.x = x - 1;
			t.y = y;
			h.push_back(t);
		}
		if (x < 5)
		{
			if (chessBoard[x][y + 1] == 0 && y < 8)
			{
				t.x = x;
				t.y = y + 1;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[x][y + 1]))
			{
				t.x = x;
				t.y = y + 1;
				h.push_back(t);
			}
			if (chessBoard[x][y - 1] == 0 && y > 0)
			{
				t.x = x;
				t.y = y - 1;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[x][y - 1]))
			{
				t.x = x;
				t.y = y - 1;
				h.push_back(t);
			}
		}
		break;

	case 1:
		if (chessBoard[x][y + 1] == 0 && y < 5)
		{
			t.x = x;
			t.y = y + 1;
			v.push_back(t);
		}
		else if (chessBoard[x][y + 1] != 0 && y < 5 && eatable(chessBoard[x][y], chessBoard[x][y + 1]))
		{
			t.x = x;
			t.y = y + 1;
			h.push_back(t);
		}
		if (chessBoard[x][y - 1] == 0 && y > 3)
		{
			t.x = x;
			t.y = y - 1;
			v.push_back(t);
		}
		else if (chessBoard[x][y - 1] != 0 && y > 3 && eatable(chessBoard[x][y], chessBoard[x][y - 1]))
		{
			t.x = x;
			t.y = y - 1;
			h.push_back(t);
		}
		if (chessBoard[x + 1][y] == 0 && x < 2)
		{
			t.x = x + 1;
			t.y = y;
			v.push_back(t);
		}
		else if (chessBoard[x + 1][y] != 0 && x < 2 && eatable(chessBoard[x][y], chessBoard[x + 1][y]))
		{
			t.x = x + 1;
			t.y = y;
			h.push_back(t);
		}
		if (chessBoard[x - 1][y] == 0 && x > 0)
		{
			t.x = x - 1;
			t.y = y;
			v.push_back(t);
		}
		else if (chessBoard[x - 1][y] != 0 && x > 0 && eatable(chessBoard[x][y], chessBoard[x - 1][y]))
		{
			t.x = x - 1;
			t.y = y;
			h.push_back(t);
		}
		for (int i = 1; i < 10; i++)
		{
			if (chessBoard[x + i][y] != 0 && chessBoard[x + i][y] != 8)
				break;
			else if (chessBoard[x + i][y] == 0)continue;
			else if (chessBoard[x + i][y] == 8)
			{
				t.x = x + i;
				t.y = y;
				h.push_back(t);
				break;
			}
		}
		break;

	case 8:
		if (chessBoard[x][y + 1] == 0 && y < 5)
		{
			t.x = x;
			t.y = y + 1;
			v.push_back(t);
		}
		else if (chessBoard[x][y + 1] != 0 && y < 5 && eatable(chessBoard[x][y], chessBoard[x][y + 1]))
		{
			t.x = x;
			t.y = y + 1;
			h.push_back(t);
		}
		if (chessBoard[x][y - 1] == 0 && y > 3)
		{
			t.x = x;
			t.y = y - 1;
			v.push_back(t);
		}
		else if (chessBoard[x][y - 1] != 0 && y > 3 && eatable(chessBoard[x][y], chessBoard[x][y - 1]))
		{
			t.x = x;
			t.y = y - 1;
			h.push_back(t);
		}
		if (chessBoard[x + 1][y] == 0 && x < 9)
		{
			t.x = x + 1;
			t.y = y;
			v.push_back(t);
		}
		else if (chessBoard[x + 1][y] != 0 && x < 9 && eatable(chessBoard[x][y], chessBoard[x + 1][y]))
		{
			t.x = x + 1;
			t.y = y;
			h.push_back(t);
		}
		if (chessBoard[x - 1][y] == 0 && x > 7)
		{
			t.x = x - 1;
			t.y = y;
			v.push_back(t);
		}
		else if (chessBoard[x - 1][y] != 0 && x > 7 && eatable(chessBoard[x][y], chessBoard[x - 1][y]))
		{
			t.x = x - 1;
			t.y = y;
			h.push_back(t);
		}
		for (int i = 8; i > -1; i--)
		{
			if (chessBoard[i][y] != 0 && chessBoard[i][y] != 1)
				break;
			else if (chessBoard[i][y] == 0)continue;
			else if (chessBoard[i][y] == 1)
			{
				t.x = i;
				t.y = y;
				h.push_back(t);
				break;
			}
		}
		break;
	case 2:
		if (x == 0 && y == 3)
		{
			if (chessBoard[x + 1][y + 1] == 0)
			{
				t.x = x + 1;
				t.y = y + 1;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[x + 1][y + 1]))
			{
				t.x = x + 1;
				t.y = y + 1;
				h.push_back(t);
			}
		}

		if (x == 0 && y == 5)
		{
			if (chessBoard[x + 1][y - 1] == 0)
			{
				t.x = x + 1;
				t.y = y - 1;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[x + 1][y - 1]))
			{
				t.x = x + 1;
				t.y = y - 1;
				h.push_back(t);
			}
		}
		if (x == 1 && y == 4)
		{
			if (chessBoard[0][3] == 0)
			{
				t.x = 0;
				t.y = 3;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[0][3]))
			{
				t.x = 0;
				t.y = 3;
				h.push_back(t);
			}
			if (chessBoard[0][5] == 0)
			{
				t.x = 0;
				t.y = 5;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[0][5]))
			{
				t.x = 0;
				t.y = 5;
				h.push_back(t);
			}
			if (chessBoard[2][5] == 0)
			{
				t.x = 2;
				t.y = 5;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[2][5]))
			{
				t.x = 2;
				t.y = 5;
				h.push_back(t);
			}
			if (chessBoard[2][3] == 0)
			{
				t.x = 2;
				t.y = 3;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[2][3]))
			{
				t.x = 2;
				t.y = 3;
				h.push_back(t);
			}
		}
		if ((x == 2 && y == 3) || (x == 2 && y == 5))
		{
			if (chessBoard[1][4] == 0)
			{
				t.x = 1;
				t.y = 4;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[1][4]))
			{
				t.x = 1;
				t.y = 4;
				h.push_back(t);
			}
		}
		break;

	case 9:
		if (x == 9 && y == 3)
		{
			if (chessBoard[x - 1][y + 1] == 0)
			{
				t.x = x - 1;
				t.y = y + 1;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[x - 1][y + 1]))
			{
				t.x = x - 1;
				t.y = y + 1;
				h.push_back(t);
			}
		}
		if (x == 9 && y == 5)
		{
			if (chessBoard[x - 1][y - 1] == 0)
			{
				t.x = x - 1;
				t.y = y - 1;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[x - 1][y - 1]))
			{
				t.x = x - 1;
				t.y = y - 1;
				h.push_back(t);
			}
		}
		if (x == 8 && y == 4)
		{
			if (chessBoard[9][3] == 0)
			{
				t.x = 9;
				t.y = 3;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[9][3]))
			{
				t.x = 9;
				t.y = 3;
				h.push_back(t);
			}
			if (chessBoard[9][5] == 0)
			{
				t.x = 9;
				t.y = 5;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[9][5]))
			{
				t.x = 9;
				t.y = 5;
				h.push_back(t);
			}
			if (chessBoard[7][5] == 0)
			{
				t.x = 7;
				t.y = 5;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[7][5]))
			{
				t.x = 7;
				t.y = 5;
				h.push_back(t);
			}
			if (chessBoard[7][3] == 0)
			{
				t.x = 7;
				t.y = 3;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[7][3]))
			{
				t.x = 7;
				t.y = 3;
				h.push_back(t);
			}
		}
		if ((x == 7 && y == 3) || (x == 7 && y == 5))
		{
			if (chessBoard[8][4] == 0)
			{
				t.x = 8;
				t.y = 4;
				v.push_back(t);
			}
			else if (eatable(chessBoard[x][y], chessBoard[8][4]))
			{
				t.x = 8;
				t.y = 4;
				h.push_back(t);
			}
		}
		break;

	case 5:
	case 12:
		if (chessBoard[x + 1][y] == 0)
		{
			if (x + 2 < 10 && y + 1 < 9)
			{
				if (chessBoard[x + 2][y + 1] == 0)
				{
					t.x = x + 2;
					t.y = y + 1;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x + 2][y + 1]))
				{
					t.x = x + 2;
					t.y = y + 1;
					h.push_back(t);
				}
			}
			if (x + 2 < 10 && y - 1 > -1)
			{
				if (chessBoard[x + 2][y - 1] == 0)
				{
					t.x = x + 2;
					t.y = y - 1;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x + 2][y - 1]))
				{
					t.x = x + 2;
					t.y = y - 1;
					h.push_back(t);
				}
			}
		}
		if (chessBoard[x - 1][y] == 0)
		{
			if (x - 2 > -1 && y + 1 < 9)
			{
				if (chessBoard[x - 2][y + 1] == 0)
				{
					t.x = x - 2;
					t.y = y + 1;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x - 2][y + 1]))
				{
					t.x = x - 2;
					t.y = y + 1;
					h.push_back(t);
				}
			}
			if (x - 2 > -1 && y - 1 > -1)
			{
				if (chessBoard[x - 2][y - 1] == 0)
				{
					t.x = x - 2;
					t.y = y - 1;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x - 2][y - 1]))
				{
					t.x = x - 2;
					t.y = y - 1;
					h.push_back(t);
				}
			}
		}
		if (chessBoard[x][y + 1] == 0)
		{
			if (x + 1 < 10 && y + 2 < 9)
			{
				if (chessBoard[x + 1][y + 2] == 0)
				{
					t.x = x + 1;
					t.y = y + 2;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x + 1][y + 2]))
				{
					t.x = x + 1;
					t.y = y + 2;
					h.push_back(t);
				}
			}
			if (x - 1 > -1 && y + 2 < 9)
			{
				if (chessBoard[x - 1][y + 2] == 0)
				{
					t.x = x - 1;
					t.y = y + 2;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x - 1][y + 2]))
				{
					t.x = x - 1;
					t.y = y + 2;
					h.push_back(t);
				}
			}
		}
		if (chessBoard[x][y - 1] == 0)
		{
			if (x + 1 < 10 && y - 2 > -1)
			{
				if (chessBoard[x + 1][y - 2] == 0)
				{
					t.x = x + 1;
					t.y = y - 2;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x + 1][y - 2]))
				{
					t.x = x + 1;
					t.y = y - 2;
					h.push_back(t);
				}
			}
			if (x - 1 < 10 && y - 2 > -1)
			{
				if (chessBoard[x - 1][y - 2] == 0)
				{
					t.x = x - 1;
					t.y = y - 2;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x - 1][y - 2]))
				{
					t.x = x - 1;
					t.y = y - 2;
					h.push_back(t);
				}
			}
		}
		break;

	case 3:
		if (x + 2 < 5 && y + 2 < 9)
		{
			if (chessBoard[x + 1][y + 1] == 0)
			{
				if (chessBoard[x + 2][y + 2] == 0)
				{
					t.x = x + 2;
					t.y = y + 2;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x + 2][y + 2]))
				{
					t.x = x + 2;
					t.y = y + 2;
					h.push_back(t);
				}
			}
		}
		if (x - 2 > -1 && y + 2 < 9)
		{
			if (chessBoard[x - 1][y + 1] == 0)
			{
				if (chessBoard[x - 2][y + 2] == 0)
				{
					t.x = x - 2;
					t.y = y + 2;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x - 2][y + 2]))
				{
					t.x = x - 2;
					t.y = y + 2;
					h.push_back(t);
				}
			}
		}
		if (x + 2 < 5 && y - 2 > -1)
		{
			if (chessBoard[x + 1][y - 1] == 0)
			{
				if (chessBoard[x + 2][y - 2] == 0)
				{
					t.x = x + 2;
					t.y = y - 2;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x + 2][y - 2]))
				{
					t.x = x + 2;
					t.y = y - 2;
					h.push_back(t);
				}
			}
		}
		if (x - 2 > -1 && y - 2 > -1)
		{
			if (chessBoard[x - 1][y - 1] == 0)
			{
				if (chessBoard[x - 2][y - 2] == 0)
				{
					t.x = x - 2;
					t.y = y - 2;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x - 2][y - 2]))
				{
					t.x = x - 2;
					t.y = y - 2;
					h.push_back(t);
				}
			}
		}
		break;
	case 10:
		if (x + 2 < 10 && y + 2 < 9)
		{
			if (chessBoard[x + 1][y + 1] == 0)
			{
				if (chessBoard[x + 2][y + 2] == 0)
				{
					t.x = x + 2;
					t.y = y + 2;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x + 2][y + 2]))
				{
					t.x = x + 2;
					t.y = y + 2;
					h.push_back(t);
				}
			}
		}
		if (x - 2 > 4 && y + 2 < 9)
		{
			if (chessBoard[x - 1][y + 1] == 0)
			{
				if (chessBoard[x - 2][y + 2] == 0)
				{
					t.x = x - 2;
					t.y = y + 2;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x - 2][y + 2]))
				{
					t.x = x - 2;
					t.y = y + 2;
					h.push_back(t);
				}
			}
		}
		if (x + 2 < 10 && y - 2 > -1)
		{
			if (chessBoard[x + 1][y - 1] == 0)
			{
				if (chessBoard[x + 2][y - 2] == 0)
				{
					t.x = x + 2;
					t.y = y - 2;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x + 2][y - 2]))
				{
					t.x = x + 2;
					t.y = y - 2;
					h.push_back(t);
				}
			}
		}
		if (x - 2 > 4 && y - 2 > -1)
		{
			if (chessBoard[x - 1][y - 1] == 0)
			{
				if (chessBoard[x - 2][y - 2] == 0)
				{
					t.x = x - 2;
					t.y = y - 2;
					v.push_back(t);
				}
				else if (eatable(chessBoard[x][y], chessBoard[x - 2][y - 2]))
				{
					t.x = x - 2;
					t.y = y - 2;
					h.push_back(t);
				}
			}
		}
		break;
	}
	if (option == 0)return v;
	else return h;

	return vector<Coordinate>();
}
void ChineseChessBackend::print()
{
	int k = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << i - 1 << "\t";
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				cout << k++;
			}
			else
			{
				cout << chessBoard[i][j - 1];
			}
			cout << "\t";
		}
		cout << endl;
	}
}
int ChineseChessBackend::eatable(int a, int b)
{
	if (a == 7 && b == 7)return 0;
	if (a < 8 && b > 7)return 1;
	if (a > 7 && b < 8)return 1;
	return 0;
}
//每次Play檢查是否有將軍的狀態發生
//無勝負 傳回 0
//紅方勝 傳回 1
//黑方勝 傳回 2
int ChineseChessBackend::isChampion()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (chessBoard[i][j] != 0)
			{
				vector<Coordinate> temp = getMovable(i, j, 2);
				for (int k = 0; k < temp.size(); k++)
				{
					if (chessBoard[temp[k].x][temp[k].y] == 8)
					{
						return 1;
					}
					if (chessBoard[temp[k].x][temp[k].y] == 1)
					{
						return 2;
					}
				}
			}
		}
	}
	return 0;
}
//無勝負 傳回 0
//紅方勝 傳回 1
//黑方勝 傳回 2
int ChineseChessBackend::isWin()
{
	int flag1 = 0;
	int flag2 = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (chessBoard[i][j] == 1)
				flag1 = 1;
			else if (chessBoard[i][j] == 8)
				flag2 = 1;
		}
	}
	if (flag1 == 1 && flag2 == 0)
	{
		cout << "黑方勝";
		return 2;
	}
	if (flag1 == 0 && flag2 == 1)
	{
		cout << "紅方勝";
		return 1;
	}
	return 0;
}