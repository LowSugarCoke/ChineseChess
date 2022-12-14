#include"print.h"

// 程式進入的位置
int main()
{
	// 中國象棋
	AbstractBackend* backend = new ChineseChessBackend();
	Print ChineseChessGUI(backend);
	ChineseChessGUI.signboard(); // 初始畫面
	ChineseChessGUI.opening();  // 開場畫面
	ChineseChessGUI.PrintScreen();  //轉換成象棋的畫面
	ChineseChessGUI.play(); // 開始玩象棋
	delete backend;

	// 西洋棋
	backend = new ChessBackend();
	Print ChessGUI(backend);
	// .. to do list

	delete backend;
}