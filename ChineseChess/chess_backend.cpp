#include "chess_backend.h"

ChessBackend::ChessBackend() :
	AbstractBackend()
{
}

ChessBackend::ChessBackend(string name)
	: AbstractBackend()
{
}

void ChessBackend::saveFile(string name)
{
}

vector<Coordinate> ChessBackend::getMovable(int x, int y, int option)
{
	return vector<Coordinate>();
}
void ChessBackend::print()
{
}
int ChessBackend::eatable(int a, int b)
{
	return 0;
}
//每次Play檢查是否有將軍的狀態發生
//無勝負 傳回 0
//紅方勝 傳回 1
//黑方勝 傳回 2
int ChessBackend::isChampion()
{
	return 0;
}
//無勝負 傳回 0
//紅方勝 傳回 1
//黑方勝 傳回 2
int ChessBackend::isWin()
{
	return 0;
}