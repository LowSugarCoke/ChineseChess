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
//�C��Play�ˬd�O�_���N�x�����A�o��
//�L�ӭt �Ǧ^ 0
//����� �Ǧ^ 1
//�¤�� �Ǧ^ 2
int ChessBackend::isChampion()
{
	return 0;
}
//�L�ӭt �Ǧ^ 0
//����� �Ǧ^ 1
//�¤�� �Ǧ^ 2
int ChessBackend::isWin()
{
	return 0;
}