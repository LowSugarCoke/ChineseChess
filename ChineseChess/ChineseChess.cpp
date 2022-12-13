#include"print.h"

// 程式進入的位置
int main()
{
	Print gameGUI;
	gameGUI.signboard(); // 初始畫面
	gameGUI.opening();  // 開場畫面
	gameGUI.PrintScreen();  //轉換成象棋的畫面
	gameGUI.play(); // 開始玩象棋
}