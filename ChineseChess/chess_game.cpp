#include"print.h"

// �{���i�J����m
int main()
{
	// ����H��
	AbstractBackend* backend = new ChineseChessBackend();
	Print ChineseChessGUI(backend);
	ChineseChessGUI.signboard(); // ��l�e��
	ChineseChessGUI.opening();  // �}���e��
	ChineseChessGUI.PrintScreen();  //�ഫ���H�Ѫ��e��
	ChineseChessGUI.play(); // �}�l���H��
	delete backend;

	// ��v��
	backend = new ChessBackend();
	Print ChessGUI(backend);
	// .. to do list

	delete backend;
}