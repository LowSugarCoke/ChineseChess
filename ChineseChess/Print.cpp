#include"print.h"

static int page = 0;
static int first = 1;
static vector<string> LeftLog;
static vector<string> RegretLog;
static vector<Ary> LeftAry;
static vector<Ary> RegretAry;
static char outPut[24][180] =
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

Print::Print(AbstractBackend* backend) {
	mBackend = backend;
}

// ³]©w¿י¥X±m¦ג×÷₪ו¦r
void Print::SetColor(int color)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
// ְע¨תֱה½L¦ל¸m
void Print::gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void Print::turnToChess(int i, int k)
{
	if (k != 0)
	{
		SetColor(240);
	}
	if (chessBoard[i][k] / 8 == 0)SetColor(112);
	else SetColor(124);
	returnChess(chessBoard[i][k]);
	SetColor();
}
void Print::returnChess(int i)
{
	switch (i % 7)
	{
	case 0:
	{
		if (i / 7 == 1)	cout << "¨ע";
		else	cout << "§L";
		break;
	}
	case 1:
	{
		if (i / 7 == 0)	cout << "±N";
		else	cout << "«׃";
		break;
	}
	case 2:
	{
		if (i / 7 == 0)	cout << "₪h";
		else	cout << "¥K";
		break;
	}
	case 3:
	{
		if (i / 7 == 0)	cout << "¶H";
		else	cout << "¬Û";
		break;
	}
	case 4:
	{
		if (i / 7 == 0)	cout << "¨®";
		else	cout << "¨®";
		break;
	}
	case 5:
	{
		if (i / 7 == 0)	cout << "°¨";
		else	cout << "״X";
		break;
	}
	case 6:
	{
		if (i / 7 == 0)	cout << "¥]";
		else	cout << "¬¶";
		break;
	}
	}
}
void Print::PrintAllLine(int a, int b)
{
	for (int j = 0; j < b; j++) cout << outPut[a][j];
	cout << endl;
}
// i ¦C¼ֶ a~b¬°¦³ֳC¦ג color ¬°¦ג½X
void Print::PrintColorLine(int i, int a, int b, int color)
{
	SetColor(color);
	for (int j = a; j < b; j++) cout << outPut[i][j];
	SetColor();
}
void Print::PushLog(Log a)
{
	string t;
	t = "";
	int num = 0, tmp = 0, in = 0;
	for (int i = 0; i < 10; i++)
	{
		if (chessBoard[i][a.old.x] == a.number) num++;
	}
	tmp = num;
	if (num > 1)
	{
		if (a.number / 8 == 1)
		{
			switch (num)
			{
			case 2:
			{
				for (int i = 0; i < 10; i++)
				{
					if (chessBoard[i][a.old.x] == a.number)
					{
						if (i == a.old.y)
						{
							if (num == 2) t += "«e";
							else t += "«ב";
						}
						else num--;
					}
				}
				break;
			}
			case 3:
			{
				for (int i = 0; i < 10; i++)
				{
					if (chessBoard[i][a.old.x] == a.number)
					{
						if (i == a.old.y)
						{
							if (num == 3) t += "«e";
							else if (num == 2) t += "₪₪";
							else t += "«ב";
						}
						else num--;
					}
				}
				break;
			}
			case 4:
			{
				for (int i = 0; i < 10; i++)
				{
					if (chessBoard[i][a.old.x] == a.number)
					{
						if (i == a.old.y)
						{
							if (num == 4) t += "«e";
							else if (num == 3) t += "₪G";
							else if (num == 2) t += "₪T";
							else t += "«ב";
						}
						else num--;
					}
				}
				break;
			}
			case 5:
			{
				for (int i = 9; i >= 0; i--)
				{
					if (chessBoard[i][a.old.x] == a.number)
					{
						if (i == a.old.y)
						{
							if (num == 5) t += "«e";
							else if (num == 4) t += "₪G";
							else if (num == 3) t += "₪T";
							else if (num == 2) t += "¥|";
							else t += "«ב";
						}
						else num--;
					}
				}
				break;
			}
			}
		}
		else
		{
			switch (num)
			{
			case 2:
			{
				for (int i = 9; i >= 0; i--)
				{
					if (chessBoard[i][a.old.x] == a.number)
					{
						if (i == a.old.y)
						{
							if (num == 2) t += "«e";
							else t += "«ב";
						}
						else num--;
					}
				}
				break;
			}
			case 3:
			{
				for (int i = 9; i >= 0; i--)
				{
					if (chessBoard[i][a.old.x] == a.number)
					{
						if (i == a.old.y)
						{
							if (num == 3) t += "«e";
							else if (num == 2) t += "₪₪";
							else t += "«ב";
						}
						else num--;
					}
				}
				break;
			}
			case 4:
			{
				for (int i = 9; i >= 0; i--)
				{
					if (chessBoard[i][a.old.x] == a.number)
					{
						if (i == a.old.y)
						{
							if (num == 4) t += "«e";
							else if (num == 3) t += "₪G";
							else if (num == 2) t += "₪T";
							else t += "«ב";
						}
						else num--;
					}
				}
				break;
			}
			case 5:
			{
				for (int i = 9; i >= 0; i--)
				{
					if (chessBoard[i][a.old.x] == a.number)
					{
						if (i == a.old.y)
						{
							if (num == 5) t += "«e";
							else if (num == 4) t += "₪G";
							else if (num == 3) t += "₪T";
							else if (num == 2) t += "¥|";
							else t += "«ב";
						}
						else num--;
					}
				}
				break;
			}
			}
		}
	}
	switch (a.number % 7)
	{
	case 0:
	{
		if (a.number / 8 == 0)	t += "¨ע";
		else t += "§L";
		break;
	}
	case 1:
	{
		if (a.number / 8 == 0)	t += "±N";
		else t += "«׃";
		break;
	}
	case 2:
	{
		if (a.number / 8 == 0)	t += "₪h";
		else t += "¥K";
		break;
	}
	case 3:
	{
		if (a.number / 8 == 0)	t += "¶H";
		else t += "¬Û";
		break;
	}
	case 4:
	{
		if (a.number / 8 == 0)	t += "¨®";
		else t += "¨®";
		break;
	}
	case 5:
	{
		if (a.number / 8 == 0)	t += "°¨";
		else t += "״X";
		break;
	}
	case 6:
	{
		if (a.number / 8 == 0)	t += "¥]";
		else t += "¬¶";
		break;
	}
	}
	if (a.number / 8 == 0)
	{
		if (tmp <= 1)
		{
			switch (a.old.x + 1)
			{
			case 1: t += "¢°"; break;
			case 2: t += "¢±"; break;
			case 3: t += "¢²"; break;
			case 4: t += "¢³"; break;
			case 5: t += "¢´"; break;
			case 6: t += "¢µ"; break;
			case 7: t += "¢¶"; break;
			case 8: t += "¢·"; break;
			case 9: t += "¢¸"; break;
			}
		}
		if (a.old.x == a.new1.x)
		{
			in = 1;
			if (a.old.y > a.new1.y)
			{
				t += "°h";
			}
			else t += "¶i";
		}
		else
		{
			if (a.old.y == a.new1.y)
			{
				t += "¥­";
			}
			else
			{
				in = 1;
				if (a.old.y > a.new1.y)
				{
					t += "°h";
				}
				else t += "¶i";
			}
		}
		if (in)
		{
			if (a.old.x != a.new1.x)
			{
				switch (a.new1.x + 1)
				{
				case 1: t += "¢°"; break;
				case 2: t += "¢±"; break;
				case 3: t += "¢²"; break;
				case 4: t += "¢³"; break;
				case 5: t += "¢´"; break;
				case 6: t += "¢µ"; break;
				case 7: t += "¢¶"; break;
				case 8: t += "¢·"; break;
				case 9: t += "¢¸"; break;
				}
			}
			else
			{
				int t1 = a.old.y - a.new1.y;
				if (t1 < 0) t1 *= -1;
				switch (t1)
				{
				case 1: t += "¢°"; break;
				case 2: t += "¢±"; break;
				case 3: t += "¢²"; break;
				case 4: t += "¢³"; break;
				case 5: t += "¢´"; break;
				case 6: t += "¢µ"; break;
				case 7: t += "¢¶"; break;
				case 8: t += "¢·"; break;
				case 9: t += "¢¸"; break;
				}
			}
		}
		else switch (a.new1.x + 1)
		{
		case 1: t += "¢°"; break;
		case 2: t += "¢±"; break;
		case 3: t += "¢²"; break;
		case 4: t += "¢³"; break;
		case 5: t += "¢´"; break;
		case 6: t += "¢µ"; break;
		case 7: t += "¢¶"; break;
		case 8: t += "¢·"; break;
		case 9: t += "¢¸"; break;
		}
	}
	else
	{
		if (tmp <= 1)
		{
			switch (9 - a.old.x)
			{
			case 1: t += "₪@"; break;
			case 2: t += "₪G"; break;
			case 3: t += "₪T"; break;
			case 4: t += "¥|"; break;
			case 5: t += "₪­"; break;
			case 6: t += "₪»"; break;
			case 7: t += "₪C"; break;
			case 8: t += "₪K"; break;
			case 9: t += "₪E"; break;
			}
		}
		if (a.old.x == a.new1.x)
		{
			in = 1;
			if (a.old.y < a.new1.y)
			{
				t += "°h";
			}
			else t += "¶i";
		}
		else
		{
			if (a.old.y == a.new1.y)
			{
				t += "¥­";
			}
			else
			{
				in = 1;
				if (a.old.y < a.new1.y)
				{
					t += "°h";
				}
				else t += "¶i";
			}
		}
		if (in)
		{
			if (a.old.x != a.new1.x)
			{
				switch (9 - a.new1.x)
				{
				case 1: t += "₪@"; break;
				case 2: t += "₪G"; break;
				case 3: t += "₪T"; break;
				case 4: t += "¥|"; break;
				case 5: t += "₪­"; break;
				case 6: t += "₪»"; break;
				case 7: t += "₪C"; break;
				case 8: t += "₪K"; break;
				case 9: t += "₪E"; break;
				}
			}
			else
			{
				int t1 = a.old.y - a.new1.y;
				if (t1 < 0) t1 *= -1;
				switch (t1)
				{
				case 1: t += "₪@"; break;
				case 2: t += "₪G"; break;
				case 3: t += "₪T"; break;
				case 4: t += "¥|"; break;
				case 5: t += "₪­"; break;
				case 6: t += "₪»"; break;
				case 7: t += "₪C"; break;
				case 8: t += "₪K"; break;
				case 9: t += "₪E"; break;
				}
			}
		}
		else switch (9 - a.new1.x)
		{
		case 1: t += "₪@"; break;
		case 2: t += "₪G"; break;
		case 3: t += "₪T"; break;
		case 4: t += "¥|"; break;
		case 5: t += "₪­"; break;
		case 6: t += "₪»"; break;
		case 7: t += "₪C"; break;
		case 8: t += "₪K"; break;
		case 9: t += "₪E"; break;
		}
	}
	//gotoxy(4, 20);
	//cout << t;
	LeftLog.push_back(t);
}
void Print::PrintLog(int page, int first)
{
	for (int i = 0; i < 20; i++)
	{
		gotoxy(3, i + 2);
		for (int j = 0; j < 20; j++)	cout << " ";
	}
	for (int i = page * 20; i < LeftLog.size() && i < (page + 1) * 20; i++)
	{
		if (i < 9) gotoxy(4, (i - page * 20 + 2));
		else gotoxy(3, (i - page * 20 + 2));
		cout << i + 1;
		if (i % 2 == first)
		{
			SetColor(8);//¶ֲ©³¦ַ¦r
			cout << " ¶ֲ";
			SetColor();
			cout << " : ";
		}
		else
		{
			SetColor(12);//¶ֲ©³¬ץ¦r
			cout << " ¬ץ";
			SetColor();
			cout << " : ";
		}
		for (int j = 0; j < 3; j++)
		{
			cout << LeftLog[i][j * 2] << LeftLog[i][j * 2 + 1] << " ";
		}
		cout << LeftLog[i][6] << LeftLog[i][7];
	}
}
void Print::PrintMove(vector<Coordinate> a)
{
	int x, y;
	for (int i = 0; i < a.size(); i++)
	{
		x = a[i].x;
		y = a[i].y;
		if (x >= 0 && x < 10 && y >= 0 && y < 9)
		{
			gotoxy((25 + 4 * y), x * 2 + 2);
			SetColor(112); //¦ַ©³¶ֲ¦r
			cout << outPut[x * 2 + 2][(28 + 6 * y)] << outPut[x * 2 + 2][(28 + 6 * y) + 1] << " \b";
		}
	}
	SetColor();
}
void Print::PrintEat(vector<Coordinate> a)
{
	int x, y;
	for (int i = 0; i < a.size(); i++)
	{
		x = a[i].x;
		y = a[i].y;
		if (x >= 0 && x < 10 && y >= 0 && y < 9)
		{
			gotoxy((25 + 4 * y), x * 2 + 2);
			if (chessBoard[x][y] / 8 == 0) SetColor(16);//ֲֵ©³¶ֲ¦r
			else SetColor(20);//ֲֵ©³¬ץ¦r
			returnChess(chessBoard[x][y]);
		}
	}
	SetColor();
}
void Print::PrintTurn(int i)
{
	gotoxy(69, 4);
	SetColor(11);
	cout << "²{¦b½ü¨ל  ";
	if (i == 0)
	{
		SetColor(8);
		cout << "¶ֲ¦ג₪ט  ";
	}
	else if (i == 1)
	{
		SetColor(12);
		cout << "¬ץ¦ג₪ט  ";
	}
	SetColor(11);
	cout << "₪U´ׁ";
	SetColor();
}
void Print::PrintChoose(int i)
{
	gotoxy(73, 7);
	if (i == 0)
	{
		for (int k = 0; k < 12; k++) cout << " ";
	}
	else
	{
		SetColor(11);
		cout << "±z¿ן¾Ü₪F  ";
		if (i / 8 == 0) SetColor(8);
		else SetColor(12);
		returnChess(i);
		SetColor();
	}
}
void Print::PrintReturn()
{
	if (RegretAry.size() < 1 || RegretLog.size() < 1) return;
	int y = 38;
	SetColor(12);
	gotoxy(y, 8);
	cout << "שÝ שש שש שש שש שש שש שש שש שש שß ";
	gotoxy(y, 9);
	cout << "שר                   שר ";
	gotoxy(y, 10);
	cout << "שר                   שר ";
	gotoxy(y, 11);
	cout << "שר                   שר ";
	gotoxy(y, 12);
	cout << "שר                   שר ";
	gotoxy(y, 13);
	cout << "שר                   שר ";
	gotoxy(y, 14);
	cout << "שר                   שר ";
	gotoxy(y, 15);
	cout << "שד שש שש שש שש שש שש שש שש שש שו ";
	SetColor();
	gotoxy(y + 6, 11);
	cout << "½T©wֱÙ­ל ?";
	gotoxy(y + 4, 13);
	SetColor(112);
	cout << "¬O";
	SetColor();
	cout << "        §_";
	int yes = 1;
	gotoxy(y + 14 - 10 * yes, 13);
	while (1)
	{
		char ch;
		ch = _getch();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 75)
			{
				if (yes == 0)
				{
					gotoxy(y + 14, 13);
					cout << "§_";
					yes = 1;
					gotoxy(y + 4, 13);
					SetColor(112);
					cout << "¬O";
					SetColor();
				}
			}
			if (ch == 77)
			{
				if (yes == 1)
				{
					gotoxy(y + 4, 13);
					cout << "¬O";
					yes = 0;
					gotoxy(y + 14, 13);
					SetColor(112);
					cout << "§_";
					SetColor();
				}
			}
		}
		else if (ch == 13)
		{
			if (yes == 0)//§_
			{
				PrintChessboard();
				break;
			}
			else//¬O
			{
				LeftLog.push_back(RegretLog.at(RegretLog.size() - 1));
				RegretLog.erase(RegretLog.end() - 1);

				LeftAry.push_back(RegretAry.at(RegretAry.size() - 1));
				RegretAry.erase(RegretAry.end() - 1);
				if (turn == 0)
				{
					turn = 1;
				}
				else
				{
					turn = 0;
				}
				if (LeftAry.size() == 0)
				{
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							chessBoard[i][j] = Initial_chessboard[i][j];
						}
					}
				}
				else
				{
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							chessBoard[i][j] = LeftAry.at(LeftAry.size() - 1).ary[i][j];
						}
					}
				}
				PrintTurn(turn);
				PrintChoose(0);
				PrintChessboard();
				PrintLog(page, first);
				break;
			}
		}
		gotoxy(y + 14 - 10 * yes, 13);
	}
}
void Print::PrintRegret()
{
	if (LeftAry.size() < 1 || LeftLog.size() < 1) return;
	int y = 38;
	SetColor(12);
	gotoxy(y, 8);
	cout << "שÝ שש שש שש שש שש שש שש שש שש שß ";
	gotoxy(y, 9);
	cout << "שר                   שר ";
	gotoxy(y, 10);
	cout << "שר                   שר ";
	gotoxy(y, 11);
	cout << "שר                   שר ";
	gotoxy(y, 12);
	cout << "שר                   שר ";
	gotoxy(y, 13);
	cout << "שר                   שר ";
	gotoxy(y, 14);
	cout << "שר                   שר ";
	gotoxy(y, 15);
	cout << "שד שש שש שש שש שש שש שש שש שש שו ";
	SetColor();
	gotoxy(y + 6, 11);
	cout << "½T©w®¬´ׁ ?";
	gotoxy(y + 4, 13);
	SetColor(112);
	cout << "¬O";
	SetColor();
	cout << "        §_";
	int yes = 1;
	gotoxy(y + 14 - 10 * yes, 13);
	while (1)
	{
		char ch;
		ch = _getch();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 75)
			{
				if (yes == 0)
				{
					gotoxy(y + 14, 13);
					cout << "§_";
					yes = 1;
					gotoxy(y + 4, 13);
					SetColor(112);
					cout << "¬O";
					SetColor();
				}
			}
			if (ch == 77)
			{
				if (yes == 1)
				{
					gotoxy(y + 4, 13);
					cout << "¬O";
					yes = 0;
					gotoxy(y + 14, 13);
					SetColor(112);
					cout << "§_";
					SetColor();
				}
			}
		}
		else if (ch == 13)
		{
			if (yes == 0)//§_
			{
				PrintChessboard();
				break;
			}
			else//¬O
			{
				RegretLog.push_back(LeftLog.at(LeftLog.size() - 1));
				LeftLog.erase(LeftLog.end() - 1);
				RegretAry.push_back(LeftAry.at(LeftAry.size() - 1));
				LeftAry.erase(LeftAry.end() - 1);
				if (turn == 0)
				{
					turn = 1;
				}
				else
				{
					turn = 0;
				}
				if (LeftAry.size() == 0)
				{
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							chessBoard[i][j] = Initial_chessboard[i][j];
						}
					}
				}
				else
				{
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							chessBoard[i][j] = LeftAry.at(LeftAry.size() - 1).ary[i][j];
						}
					}
				}
				PrintTurn(turn);
				PrintChoose(0);
				PrintChessboard();
				PrintLog(page, first);
				break;
			}
		}
		gotoxy(y + 14 - 10 * yes, 13);
	}
}
int Print::PrintMenu()
{
	int y = 41;
	SetColor(9);
	gotoxy(y, 6);
	cout << "שÝ שש שש שש שש שש שש שש שß ";
	gotoxy(y, 7);
	cout << "שר               שר ";
	gotoxy(y, 8);
	cout << "שא שש שש שש שש שש שש שש שג ";
	gotoxy(y, 9);
	cout << "שר               שר ";
	gotoxy(y, 10);
	cout << "שא שש שש שש שש שש שש שש שג ";
	gotoxy(y, 11);
	cout << "שר               שר ";
	gotoxy(y, 12);
	cout << "שא שש שש שש שש שש שש שש שג ";
	gotoxy(y, 13);
	cout << "שר               שר ";
	gotoxy(y, 14);
	cout << "שד שש שש שש שש שש שש שש שו ";
	SetColor(112);
	string out[4];
	out[0] = "ִ~ִע¹Cְ¸";
	out[1] = "­«·s¶}©l";
	out[2] = "¦^¥D¿ן³ז";
	out[3] = "ֲק¶}¹Cְ¸";
	gotoxy(y + 5, 7);
	cout << out[0];
	SetColor();
	gotoxy(y + 5, 9);
	cout << out[1];
	gotoxy(y + 5, 11);
	cout << out[2];
	gotoxy(y + 5, 13);
	cout << out[3];
	int choose = 1;
	gotoxy(y + 7, 5 + choose * 2);
	char ch;
	while (1)
	{
		ch = _getch();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 72)
			{
				if (choose != 1)
				{
					gotoxy(y + 5, 5 + choose * 2);
					cout << out[choose - 1];
					choose--;
					gotoxy(y + 5, 5 + choose * 2);
					SetColor(112);
					cout << out[choose - 1];
					SetColor();
				}
			}
			if (ch == 80)
			{
				if (choose != 4)
				{
					gotoxy(y + 5, 5 + choose * 2);
					cout << out[choose - 1];
					choose++;
					gotoxy(y + 5, 5 + choose * 2);
					SetColor(112);
					cout << out[choose - 1];
					SetColor();
				}
			}
			gotoxy(y + 7, 5 + choose * 2);
		}
		else if (ch == 13)
		{
			if (choose == 1)//ִ~ִע¹Cְ¸
			{
				PrintChessboard();
				return 1;
			}
			else if (choose == 2)//­«·s¶}©l
			{
				Reset();
				return 0;
				//reset
			}
			else if (choose == 3)//¦^¥D¿ן³ז
			{
				system("cls");
				signboard();
				opening();
				PrintScreen();
				Reset();
				//reset
				return 0;
			}
			else if (choose == 4)//ֲק¶}¹Cְ¸
			{
				return 2;
			}
		}
		else if (ch == 27)
		{
			PrintChessboard();
			return 1;
		}
	}
}
void Print::PrintHelp()
{
	int y = 38;
	SetColor(14);
	gotoxy(y, 8);
	cout << "שÝ שש שש שש שש שש שש שש שש שש שß ";
	gotoxy(y, 9);
	cout << "שר                   שר ";
	gotoxy(y, 10);
	cout << "שר                   שר ";
	gotoxy(y, 11);
	cout << "שר                   שר ";
	gotoxy(y, 12);
	cout << "שר                   שר ";
	gotoxy(y, 13);
	cout << "שר                   שר ";
	gotoxy(y, 14);
	cout << "שר                   שר ";
	gotoxy(y, 15);
	cout << "שד שש שש שש שש שש שש שש שש שש שו ";
	SetColor();
	gotoxy(y + 2, 9);
	cout << "< ®¬´ׁ     > ´_­ל";
	gotoxy(y + 2, 11);
	cout << "s ¦sְֹ     r ֵ×ְֹ";
	gotoxy(y + 2, 13);
	cout << "z ₪W­¶     x ₪U­¶";
	gotoxy(25, 2);
	char ch;
	while (1)
	{
		ch = _getch();
		if (ch == 104)
		{
			PrintChessboard();
			return;
		}
	}
}
void Print::PrintChessboard()
{
	gotoxy(25, 1);
	PrintColorLine(1, 30, 64, 253);
	for (int i = 2; i < 21; i += 2)
	{
		gotoxy(25, i);
		PrintChess((i - 2) / 2);
		if (i == 20) break;
		gotoxy(25, i + 1);
		PrintColorLine(i + 1, 28, 64, 240);
	}
	gotoxy(25, 21);
	PrintColorLine(21, 28, 62, 253);
}
void Print::PrintLeft()
{
	gotoxy(1, 1);
	for (int j = 2; j < 29; j++) cout << outPut[1][j];
	for (int i = 2; i < 22; i++)
	{
		gotoxy(1, i);
		for (int j = 2; j < 28; j++) cout << outPut[i][j];
	}
	gotoxy(1, 22);
	for (int j = 2; j < 37; j++) cout << outPut[22][j];
}
void Print::PrintRight()
{
	gotoxy(60, 1);
	for (int j = 65; j < 124; j++) cout << outPut[1][j];
	for (int i = 2; i < 14; i += 2)
	{
		gotoxy(59, i);
		for (int j = 79; j < 122; j++) cout << outPut[i][j];
		gotoxy(59, i + 1);
		for (int j = 64; j < 107; j++) cout << outPut[i + 1][j];
	}
	gotoxy(60, 14);
	for (int j = 80; j < 139; j++) cout << outPut[14][j];
	for (int i = 15; i < 21; i += 2)
	{
		gotoxy(59, i);
		for (int j = 64; j < 107; j++) cout << outPut[i][j];
		gotoxy(59, i + 1);
		for (int j = 79; j < 122; j++) cout << outPut[i + 1][j];
	}
	gotoxy(59, 21);
	for (int j = 62; j < 105; j++) cout << outPut[21][j];
	gotoxy(59, 22);
	for (int j = 72; j < 132; j++) cout << outPut[22][j];
}
void Print::Reset()
{
	fstream f1;
	f1.open("Initial.txt", ios::in);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++) f1 >> chessBoard[i][j];
	}
	f1 >> turn;
	f1.close();
	first = turn;
	PrintChessboard();
	LeftLog.clear();
	for (int i = 0; i < 20; i++)
	{
		gotoxy(3, i + 2);
		for (int j = 0; j < 20; j++) cout << " ";
	}
	page = 0;
	PrintTurn(turn);
	gotoxy(25, 2);
	return;
}
void Print::SaveFile()
{
	int y = 38;
	SetColor(14);
	gotoxy(y, 8);
	cout << "שÝ שש שש שש שש שש שש שש שש שש שß ";
	gotoxy(y, 9);
	cout << "שר                   שר ";
	gotoxy(y, 10);
	cout << "שר                   שר ";
	gotoxy(y, 11);
	cout << "שר                   שר ";
	gotoxy(y, 12);
	cout << "שר                   שר ";
	gotoxy(y, 13);
	cout << "שד שש שש שש שש שש שש שש שש שש שו ";
	SetColor();
	gotoxy(y + 4, 9);
	cout << "½׀¿י₪J¦sְֹ¦W:";
	gotoxy(y + 5, 11);
	string fileName;
	cin >> fileName;
	fstream f1;
	f1.open(fileName, ios::out);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++) f1 << chessBoard[i][j] << " ";
		f1 << endl;
	}
	f1 << turn << endl;
	f1.close();
	PrintChessboard();
	return;
}
void Print::ReadFile()
{
	int y = 38;
	SetColor(14);
	gotoxy(y, 8);
	cout << "שÝ שש שש שש שש שש שש שש שש שש שß ";
	gotoxy(y, 9);
	cout << "שר                   שר ";
	gotoxy(y, 10);
	cout << "שר                   שר ";
	gotoxy(y, 11);
	cout << "שר                   שר ";
	gotoxy(y, 12);
	cout << "שר                   שר ";
	gotoxy(y, 13);
	cout << "שד שש שש שש שש שש שש שש שש שש שו ";
	SetColor();
	gotoxy(y + 4, 9);
	cout << "½׀¿י₪Jֵ×ְֹ¦W:";
	gotoxy(y + 5, 11);
	string fileName;
	fstream f1;
	while (1)
	{
		cin >> fileName;
		f1.open(fileName, ios::in);
		if (!f1)
		{
			gotoxy(y + 4, 9);
			cout << "¬dµL¦¹ְֹ½׀­«¸ױ";
			gotoxy(y + 5, 11);
			for (int i = 0; i < 14; i++) cout << " ";
			gotoxy(y + 5, 11);
		}
		else break;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++) f1 >> chessBoard[i][j];
	}
	f1 >> turn;
	f1.close();
	first = turn;
	PrintChessboard();
	LeftLog.clear();
	for (int i = 0; i < 20; i++)
	{
		gotoxy(3, i + 2);
		for (int j = 0; j < 20; j++) cout << " ";
	}
	page = 0;
	PrintTurn(turn);
	return;
}

int Print::PrintWin(int who)
{
	if (who == 1) // ¬ץ₪טִ¹
	{
		system("cls");
		gotoxy(0, 0);
		cout << endl; SetColor(12);
		cout << "                                  ¢i¢i¢i¢i¢i¢iשß   ¢i¢i¢i¢i¢i¢i¢iשß  ¢i¢i¢i¢i¢i¢iשß" << endl;
		cout << "                                  ¢i¢iשÝשששששששש¢i¢iשß  ¢i¢iשÝשששששששששששששששששששו  ¢i¢iשÝשששששששששש¢i¢iשß" << endl;
		cout << "                                  ¢i¢i¢i¢i¢i¢iשÝשו  ¢i¢i¢i¢i¢iשß      ¢i¢iשר     ¢i¢iשר" << endl;
		cout << "                                  ¢i¢iשÝשששששששש¢i¢iשß  ¢i¢iשÝשששששששששששו      ¢i¢iשר     ¢i¢iשר" << endl;
		cout << "                                  ¢i¢iשר    ¢i¢iשר  ¢i¢i¢i¢i¢i¢i¢iשß  ¢i¢i¢i¢i¢i¢iשÝשששו" << endl;
		cout << "                                  שדשששששששו    שדשששששששו  שדשששששששששששששששששששששששששששו  שדשששששששששששששש שששששששו" << endl;
		cout << endl; SetColor(15);
		cout << "                                   ¢i¢iשß         ¢i¢iשß  ¢i¢iשß  ¢i¢i¢iשß      ¢i¢iשß" << endl;
		cout << "                                   ¢i¢iשר         ¢i¢iשר  ¢i¢iשר  ¢i¢i¢i¢iשß    ¢i¢iשר" << endl;
		cout << "                                   ¢i¢iשר   ¢iשß   ¢i¢iשר  ¢i¢iשר  ¢i¢iשÝשש¢i¢iשß  ¢i¢iשר" << endl;
		cout << "                                   ¢i¢iשר ¢i¢i¢iשß ¢i¢iשר  ¢i¢iשר  ¢i¢iשר שדשש¢i¢iשß¢i¢iשר" << endl;
		cout << "                                   שדשש¢i¢i¢iשÝשש¢i¢i¢iשÝשששו  ¢i¢iשר  ¢i¢iשר  שדשש¢i¢i¢i¢iשר" << endl;
		cout << "                                     שדשששששששששששו שדשששששששששששו    שדשששששששו  שדשששששששו    שדשששששששששששששששו" << endl;
		gotoxy(0, 0);
	}
	else if (who == 2) // ¶ֲ₪טִ¹
	{
		system("cls");
		gotoxy(0, 0);
		cout << endl; SetColor(8);
		cout << "                ¢i¢i¢i¢i¢i¢iשß    ¢i¢iשß              ¢i¢i¢i¢i¢iשß      ¢i¢i¢i¢i¢i¢iשß  ¢i¢iשß     ¢i¢iשß    " << endl;
		cout << "                ¢i¢iשÝשששששששששש¢i¢iשß  ¢i¢iשר            ¢i¢iשÝשששששששששש¢i¢iשß  ¢i¢iשÝשששששששששששששששששששו  ¢i¢iשר   ¢i¢iשÝשששו" << endl;
		cout << "                ¢i¢i¢i¢i¢i¢iשÝשששו  ¢i¢iשר            ¢i¢i¢i¢i¢i¢i¢iשר  ¢i¢iשר            ¢i¢i¢i¢i¢iשÝשששו" << endl;
		cout << "                ¢i¢iשÝשששששששששש¢i¢iשß  ¢i¢iשר            ¢i¢iשÝשששששששששש¢i¢iשר  ¢i¢iשר            ¢i¢iשÝשששששש¢i¢iשß" << endl;
		cout << "                ¢i¢i¢i¢i¢i¢iשÝשששו  ¢i¢i¢i¢i¢i¢i¢iשß  ¢i¢iשר     ¢i¢iשר  שדשש¢i¢i¢i¢i¢i¢iשß  ¢i¢iשר     ¢i¢iשß" << endl;
		cout << "                שדשששששששששששששששששששששששו    שדשששששששששששששששששששששששששששו  שדשששששששו     שדשששששששו    שדשששששששששששששששששששששששו  שדשששששששו     שדשששששששו" << endl;
		cout << endl; SetColor(15);
		cout << "                                   ¢i¢iשß         ¢i¢iשß  ¢i¢iשß  ¢i¢i¢iשß      ¢i¢iשß" << endl;
		cout << "                                   ¢i¢iשר         ¢i¢iשר  ¢i¢iשר  ¢i¢i¢i¢iשß    ¢i¢iשר" << endl;
		cout << "                                   ¢i¢iשר   ¢iשß   ¢i¢iשר  ¢i¢iשר  ¢i¢iשÝשש¢i¢iשß  ¢i¢iשר" << endl;
		cout << "                                   ¢i¢iשר ¢i¢i¢iשß ¢i¢iשר  ¢i¢iשר  ¢i¢iשר שדשש¢i¢iשß¢i¢iשר" << endl;
		cout << "                                   שדשש¢i¢i¢iשÝשש¢i¢i¢iשÝשששו  ¢i¢iשר  ¢i¢iשר  שדשש¢i¢i¢i¢iשר" << endl;
		cout << "                                     שדשששששששששששו שדשששששששששששו    שדשששששששו  שדשששששששו    שדשששששששששששששששו" << endl;
		gotoxy(0, 0);
	}
	int y = 48;
	int x = 17;
	int yes = 1;
	gotoxy(y + 5, x - 2);
	cout << " ­«·s¶}©l?";
	gotoxy(y + 4, x);
	SetColor(112);
	cout << "¬O";
	SetColor();
	cout << "        §_";
	gotoxy(y + 14 - 10 * yes, x);
	while (1)
	{
		char ch;
		ch = _getch();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 75)//¥×
			{
				if (yes == 0)
				{
					gotoxy(y + 14, x);
					cout << "§_";
					yes = 1;
					gotoxy(y + 4, x);
					SetColor(112);
					cout << "¬O";
					SetColor();
				}
			}
			if (ch == 77)//¥k
			{
				if (yes == 1)
				{
					gotoxy(y + 4, x);
					cout << "¬O";
					yes = 0;
					gotoxy(y + 14, x);
					SetColor(112);
					cout << "§_";
					SetColor();
				}
			}
		}
		else if (ch == 13)
		{
			if (yes == 0)
			{
				return 0;
			}
			else
			{
				return 1;
				break;
			}
		}
		gotoxy(y + 14 - 10 * yes, x);
	}
}
void Print::PrintCheck(int who)
{
	int x, y;
	x = 68;
	y = 8;
	SetColor(64);
	gotoxy(x + 6, y + 1);
	for (int i = 0; i < 15; i++) cout << " ";
	gotoxy(x + 6, y + 4);
	for (int i = 0; i < 15; i++) cout << " ";
	gotoxy(x + 6, y + 2);
	cout << "  ";
	gotoxy(x + 19, y + 2);
	cout << "  ";
	gotoxy(x + 6, y + 3);
	cout << "  ";
	gotoxy(x + 19, y + 3);
	cout << "  ";
	SetColor(12);
	gotoxy(x, y);
	cout << "  _ ";
	gotoxy(x, y + 1);
	cout << " / \\";
	gotoxy(x, y + 2);
	cout << " | |";
	gotoxy(x, y + 3);
	cout << " \\_/";
	gotoxy(x, y + 4);
	cout << " (_) ";
	gotoxy(x + 11, y + 2);
	if (who == 2) cout << "¶ֲ";
	else if (who == 1) cout << "¬ץ";
	cout << " ₪ט";
	gotoxy(x + 8, y + 3);
	cout << "₪w ³Q ±N ­x";
	SetColor();
}
void Print::blank()
{
	cout << "                                                                                                                        ";
}

void Print::signboard()
{
	cout << endl;
	cout << "          _____                _____                    _____                    _____ " << endl; Sleep(80); gotoxy(0, 1); blank();
	cout << "         /\    \              |\    \                  /\    \                  /\    \ " << endl; Sleep(80); gotoxy(0, 2); blank();
	cout << "        /::\____\             |:\____\                /::\    \                /::\____\ " << endl; Sleep(80); gotoxy(0, 3); blank();
	cout << "       /::::|   |             |::|   |               /::::\    \              /:::/    /" << endl; Sleep(80); gotoxy(0, 4); blank();
	cout << "      /:::::|   |             |::|   |              /::::::\    \            /:::/    /" << endl; Sleep(80); gotoxy(0, 5); blank();
	cout << "     /::::::|   |             |::|   |             /:::/\:::\    \          /:::/    /" << endl; Sleep(80); gotoxy(0, 6); blank();
	Sleep(80); gotoxy(0, 7); blank();
	cout << "    /:::/|::|   |             |::|   |            /:::/  \:::\    \        /:::/    / " << endl; Sleep(80); gotoxy(0, 8); blank();
	cout << "   /:::/ |::|   |             |::|   |           /:::/    \:::\    \      /:::/    /" << endl; Sleep(80); gotoxy(0, 9); blank();
	cout << "  /:::/  |::|   | _____       |::|___|______    /:::/    / \:::\    \    /:::/    /" << endl; Sleep(80); gotoxy(0, 10); blank();
	cout << "      _____" << endl; Sleep(80); gotoxy(0, 11); blank();
	cout << " /:::/   |::|   |/\    \      /::::::::\    \  /:::/    /   \:::\    \  /:::/____/      /\    \ " << endl; Sleep(80); gotoxy(0, 12); blank();
	cout << "/:: /    |::|   /::\____\    /::::::::::\____\/:::/____/     \:::\____\|:::|    /      /::\____\ " << endl; Sleep(80); gotoxy(0, 13); blank();

	cout << "\::/    /|::|  /:::/    /   /:::/~~~~/~~      \:::\    \      \::/    /|:::|____\     /:::/    / " << endl; Sleep(80); gotoxy(0, 14); blank();
	cout << " \/____/ |::| /:::/    /   /:::/    /          \:::\    \      \/____/  \:::\    \   /:::/    / " << endl; Sleep(80); gotoxy(0, 15); blank();
	cout << "         |::::::/    /   /:::/    /              \:::\    \               \:::\    /:::/    / " << endl; Sleep(80); gotoxy(0, 16); blank();
	cout << "         |:::::/    /    \::/    /                \:::\    \               \:::\__/:::/    / " << endl; Sleep(80); gotoxy(0, 17); blank();
	cout << "         |::::/    /      \/____/                  \:::\    \               \::::::::/    / " << endl; Sleep(80); gotoxy(0, 18); blank();
	cout << "         /:::/    /                                 \:::\    \               \::::::/    / " << endl; Sleep(80); gotoxy(0, 19); blank();

	cout << "        /:::/    /                                   \:::\____\               \::::/    / " << endl; Sleep(80); gotoxy(0, 20); blank();
	cout << "        \::/    /                                     \::/    /                \::/____/ " << endl; Sleep(80); gotoxy(0, 21); blank();
	cout << "         \/____/                                       \/____/                  ~~  " << endl; Sleep(80); gotoxy(0, 22); blank();
	gotoxy(0, 0);
}

void Print::opening()
{
	cout << endl;
	cout << "          _____                _____                    _____                    _____ " << endl; Sleep(80);
	cout << "         /\\    \\              |\    \\                   /\\    \\                  /\\    \\ " << endl; Sleep(80);
	cout << "        /::\\____\\             |:\____\\                 /::\\    \\                /::\\____\\ " << endl; Sleep(80);
	cout << "       /::::|   |             |::|   |               /::::\\    \\              /:::/    /" << endl; Sleep(80);
	cout << "      /:::::|   |             |::|   |              /::::::\\    \\            /:::/    /" << endl; Sleep(80);
	cout << "     /::::::|   |             |::|   |             /:::/\\:::\\    \\          /:::/    /" << endl; Sleep(80);
	cout << "    /:::/|::|   |             |::|   |            /:::/  \\:::\\    \\        /:::/    / " << endl; Sleep(80);
	cout << "   /:::/ |::|   |             |::|   |           /:::/    \\:::\\    \\      /:::/    /" << endl; Sleep(80);
	cout << "  /:::/  |::|   | _____       |::|___|______    /:::/    / \\:::\\    \\    /:::/    /  _____" << endl; Sleep(80);
	cout << " /:::/   |::|   |/\\    \\      /::::::::\\    \\  /:::/    /   \\:::\\    \\  /:::/____/  /\\    \\ " << endl; Sleep(80);
	cout << "/:: /    |::|   /::\\____\\    /::::::::::\\____\\/:::/____/     \\:::\\____\\|:::|    /  /::\\____\\ " << endl; Sleep(80);
	cout << "\\::/    /|::|  /:::/    /   /:::/~~~~/~~      \\:::\\    \\      \::/    /|:::|____\\  /:::/    / " << endl; Sleep(80);
	cout << " \\/____/ |::| /:::/    /   /:::/    /          \\:::\\    \\      \/____/ \\:::\\     \\/:::/    / " << endl; Sleep(80);
	cout << "         |:::::::/    /   /:::/    /            \\:::\\    \\             \\:::\\    /:::/    / " << endl; Sleep(80);
	cout << "         |::::::/    /    \\::/    /              \\:::\\    \\             \\:::\\__/:::/    / " << endl; Sleep(80);
	cout << "         |:::::/    /      \\/____/                \\:::\\    \\             \\::::::::/    / " << endl; Sleep(80);
	cout << "         /::::/    /                               \\:::\\    \\             \\::::::/    / " << endl; Sleep(80);
	cout << "        /::::/    /                                 \\:::\\____\\             \\::::/    / " << endl; Sleep(80);
	cout << "        \\:::/    /                                   \\::/    /              \\::/____/ " << endl; Sleep(80);
	cout << "         \\/_____/                                     \\/____/                ~~  " << endl; Sleep(80);
	SetColor(12);
	gotoxy(0, 25);
	cout << "                                   --press s to start--                                    " << endl;
	SetColor();
	char ch;
	while (1)
	{
		ch = _getch();
		if (ch == 's') break;
	}
	system("cls");
}
void Print::play()
{
	int maxPage = 0;
	bool flag = false;
	char ch;
	int chess = 0;
	int x = 25, y = 2;
	int check = 0;
	Coordinate _old;
	vector<Coordinate> move;
	vector<Coordinate> eat;
	gotoxy(x, y); //³]©wֱה½L×÷¦ל¸m

	// §Q¥־whileֵ‎µ{¦¡₪£·|°h¥X¡A¨ֳ¥B¥i¥H₪@×½₪U«ü¥O
	while (1)
	{
		// ְֻ¬d¬O§_ֵ¥µP,
		if (mBackend->isChampion() > 0)
		{
			check = 1;
			PrintCheck(mBackend->isChampion());  // ¦L¥Xֵ¥µP°T¸¹
			gotoxy(x, y);
		}
		else
		{
			if (check == 1)
			{
				check = 0;
				PrintRight();
				PrintTurn(turn);
				gotoxy(x, y);
			}
		}
		ch = _getch(); // ְע¨תֱה½L¿י₪J×÷­^₪ו¦r¡Aֲא´«¦¨·L³n©w¸q×÷¼ֶ¦r
		if (ch == -32) // §Pֲ_¬O§_¬°₪W₪U¥×¥k
		{
			ch = _getch();
			switch (ch) // ₪W₪U¥×¥k
			{
			case 72:
			{
				if (y != 2)y -= 2;
				gotoxy(x, y);
				break;
			}
			case 80:
			{
				if (y != 20)y += 2;
				gotoxy(x, y);
				break;
			}
			case 75:
			{
				if (x != 25) x -= 4;
				gotoxy(x, y);
				break;
			}
			case 77:
			{
				if (x != 57)x += 4;
				gotoxy(x, y);
				break;
			}
			}
		}
		else if (ch == 13)//Enter
		{
			if (flag)
			{
				for (int i = 0; i < move.size(); i++)
				{
					if (move.at(i).x == (y - 2) / 2 && move.at(i).y == (x - 25) / 4)
					{
						Log p;
						p.number = chess;
						p.old.x = (_old.x - 25) / 4;
						p.old.y = (_old.y - 2) / 2;
						p.new1.x = (x - 25) / 4;
						p.new1.y = (y - 2) / 2;
						PushLog(p);
						chessBoard[(_old.y - 2) / 2][(_old.x - 25) / 4] = 0;
						chessBoard[(y - 2) / 2][(x - 25) / 4] = chess;
						//°O´ׁ½L
						Ary temp(chessBoard);
						LeftAry.push_back(temp);
						if (!RegretAry.empty())
						{
							RegretAry.clear();
						}
						if (turn == 0)
						{
							turn = 1;
						}
						else
						{
							turn = 0;
						}
						break;
					}
				}
				for (int i = 0; i < eat.size(); i++)
				{
					if (eat.at(i).x == (y - 2) / 2 && eat.at(i).y == (x - 25) / 4)
					{
						Log p;
						p.number = chess;
						p.old.x = (_old.x - 25) / 4;
						p.old.y = (_old.y - 2) / 2;
						p.new1.x = (x - 25) / 4;
						p.new1.y = (y - 2) / 2;
						PushLog(p);
						chessBoard[(_old.y - 2) / 2][(_old.x - 25) / 4] = 0;
						chessBoard[(y - 2) / 2][(x - 25) / 4] = chess;
						//°O´ׁ½L
						Ary temp(chessBoard);
						LeftAry.push_back(temp);
						if (!RegretAry.empty())
						{
							RegretAry.clear();
						}
						if (turn == 0)
						{
							turn = 1;
						}
						else
						{
							turn = 0;
						}
						break;
					}
				}
				//¬O§_³׃§Q
				//₪‎¨£₪‎
				int xp = 0, yp = 0;
				for (int i = 3; i < 6; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (chessBoard[j][i] == 1)
						{
							xp = j;
							yp = i;
						}
					}
				}
				int flg = 0;
				for (int i = xp + 1; i < 10; i++)
				{
					if (chessBoard[i][yp] == 8) flg = 1;
					if (chessBoard[i][yp] != 0)
					{
						break;
					}
				}
				if (mBackend->isWin() > 0 || flg == 1)
				{
					if (flg == 0)
					{
						if (PrintWin(mBackend->isWin()) == 0)//₪£×±₪F
						{
							system("cls");
							return;
							//ֲק¶}
						}
						else//¦A×±₪@¦¸
						{
							Reset();
							system("cls");
							PrintScreen();
							PrintTurn(turn);
							x = 25;
							y = 2;
							gotoxy(x, y);
							//reset
						}
					}
					else
					{
						if (PrintWin((turn - 2) * -1) == 0)//₪£×±₪F
						{
							system("cls");
							return;
							//ֲק¶}
						}
						else//¦A×±₪@¦¸
						{
							Reset();
							PrintScreen();
							PrintTurn(turn);
							x = 25;
							y = 2;
							gotoxy(x, y);
							//reset
						}
					}
				}
				maxPage = LeftLog.size() / 21;
				page = maxPage;
				PrintTurn(turn);
				PrintChoose(0);
				PrintChessboard();
				PrintLog(page, first);
				gotoxy(x, y);
				flag = false;
				continue;
			}
			else if (!flag)
			{
				_old.x = x;
				_old.y = y;
				chess = chessBoard[(y - 2) / 2][(x - 25) / 4];
				if (chess > 0)
				{
					if (turn == 0)
					{
						if (chess < 1 || chess>7)
						{
							continue;
						}
					}
					else
					{
						if (chess < 8 || chess>14)
						{
							continue;
						}
					}
					flag = true;
				}
				PrintChessboard();
				PrintChoose(chessBoard[(y - 2) / 2][(x - 25) / 4]);
				move.clear();
				move = mBackend->getMovable(y, x, 0);
				PrintMove(move);
				eat.clear();
				eat = mBackend->getMovable(y, x, 1);
				PrintEat(eat);
				gotoxy(x, y);
			}
		}
		else if (ch == 44)//<
		{
			PrintRegret();
			gotoxy(x, y);
		}
		else if (ch == 46)//>
		{
			PrintReturn();
			gotoxy(x, y);
		}
		else if (ch == 27)//esc ¿ן³ז
		{
			int q = 0;
			q = PrintMenu();
			if (q == 1)
			{
				gotoxy(x, y);
			}
			else if (q == 2)
			{
				system("cls");
				return;
			}
			else
			{
				x = 25;
				y = 2;
			}
		}
		else if (ch == 104)//h ְ°§U
		{
			PrintHelp();
			gotoxy(x, y);
		}
		else if (ch == 115)//s ¦sְֹ
		{
			SaveFile();
			gotoxy(x, y);
		}
		else if (ch == 114)//r ֵ×ְֹ
		{
			ReadFile();
			if (mBackend->isChampion() > 0)
			{
				check = 1;
				PrintCheck(mBackend->isChampion());
				gotoxy(x, y);
			}
			else
			{
				if (check == 1)
				{
					check = 0;
					PrintRight();
					PrintTurn(turn);
					gotoxy(x, y);
				}
			}
			gotoxy(x, y);
		}
		else if (ch == 122)//z ₪W­¶
		{
			if (page > 0)
			{
				page--;
				for (int i = 0; i < 20; i++)
				{
					gotoxy(3, i + 2);
					for (int j = 0; j < 20; j++) cout << " ";
				}
				PrintLog(page, first);
				gotoxy(x, y);
			}
		}
		else if (ch == 120)//x ₪U­¶
		{
			if (LeftLog.size() > (page + 1) * 20)
			{
				page++;
				for (int i = 0; i < 20; i++)
				{
					gotoxy(3, i + 2);
					for (int j = 0; j < 20; j++) cout << " ";
				}
				PrintLog(page, first);
				gotoxy(x, y);
			}
		}
	}
}
void Print::PrintChess(int i)
{
	//28¶}©l
	int s = 28;
	for (int k = 0; k < 8; k++)
	{
		if (chessBoard[i][k] == 0)
		{
			SetColor(240);
			for (int j = 0; j < 6; j++) cout << outPut[(i * 2) + 2][s + 6 * k + j];
			SetColor();
		}
		else
		{
			turnToChess(i, k);
			SetColor(240);
			cout << outPut[(i * 2) + 2][s + 6 * k + 3] << outPut[(i * 2) + 2][s + 6 * k + 4]
				<< outPut[(i * 2) + 2][s + 6 * k + 5];
			SetColor();
		}
	}
	if (chessBoard[i][8] == 0)
	{
		SetColor(240);
		cout << outPut[(i * 2) + 2][76] << outPut[(i * 2) + 2][77] << " ";
		SetColor();
	}
	else turnToChess(i, 8);
}
void Print::PrintScreen()
{
	gotoxy(0, 0);
	PrintAllLine(0, 149);
	for (int i = 1; i < 23; i++)
	{
		gotoxy(0, i);
		cout << outPut[i][0] << outPut[i][1];
	}
	gotoxy(0, 23);
	PrintAllLine(23, 149);
	PrintLeft();
	PrintChessboard();
	PrintRight();
	PrintTurn(turn);
}