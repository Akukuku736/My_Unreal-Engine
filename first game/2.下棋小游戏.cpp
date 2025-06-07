#include<graphics.h>
#include<iostream>
using namespace std;

char board_data[3][3] =
{
	{ '-', '-', '-' },
	{ '-', '-', '-' },
	{ '-', '-', '-' },
};
char current_pice = 'O';

//检测指定棋子是否获胜
bool checkWin(char c) {
	if (board_data[0][0] == c && board_data[0][1] == c && board_data[0][2] == c) 
	{
		return true;
	}
	if (board_data[1][0] == c && board_data[1][1] == c && board_data[1][2] == c)
	{
		return true;
	}
	if (board_data[2][0] == c && board_data[2][1] == c && board_data[2][2] == c)
	{
		return true;
	}
	if (board_data[0][0] == c && board_data[1][0] == c && board_data[2][0] == c)
	{
		return true;
	}
	if (board_data[0][1] == c && board_data[1][1] == c && board_data[2][1] == c)
	{
		return true;
	}
	if (board_data[0][2] == c && board_data[1][2] == c && board_data[2][2] == c)
	{
		return true;
	}
	if (board_data[0][0] == c && board_data[1][1] == c && board_data[2][2] == c)
	{
		return true;
	}
	if (board_data[0][2] == c && board_data[1][1] == c && board_data[2][0] == c)
	{
		return true;
	}
	return false;
}

//检测是否平局
bool checkDraw() {
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			if (board_data[i][j] == '-') {
				return false;
			}
		}
	}
}
//绘制棋盘
void DrawBord() {
	line(0, 200, 600, 200);
	line(0, 400, 600, 400);
	line(200, 0, 200, 600);
	line(400, 0, 400, 600);
}
//绘制棋子
void DrawPiece() {

	for (size_t i = 0; i < 3; i++) 
	{
		for (size_t j = 0; j < 3; j++) 
		{
			switch (board_data[i][j])
			{
			case'O':
				circle(200 * j + 100, 200 * i + 100,100);
				break;
			case'X':
				line(200 * j, 200 * i, 200 * (j + 1), 200 * (i + 1));
				line(200 * (j + 1), 200 * i, 200 * j, 200 * (i + 1));
				break;
			case'-':
				break;

			}
		}
	}

}
//绘制提示信息
void DrawTipText() {
	static TCHAR str[64];
	_stprintf_s(str, _T("当前棋子类型：%c"), current_pice);
	settextcolor(RGB(225, 175, 45));
	outtextxy(0, 0, str);
}


int main() {

	initgraph(600,600);
	
	bool running = true;

	BeginBatchDraw();
	ExMessage msg;
	while (running)
	{
		
		while (peekmessage(&msg))
		{
			line(0, 200, 600, 200);
			//检查鼠标左键按下信息
			if(msg.message == WM_LBUTTONDOWN)
			{
				//计算位置
				int x = msg.x;
				int y = msg.y;
				int index_x = msg.x / 200;
				int index_y = msg.y / 200;

				//尝试落子
				if (board_data[index_y][index_x] == '-') 
				{
					board_data[index_y][index_x] = current_pice;

					if (current_pice == 'O')
					{
						current_pice = 'X';
						cout << current_pice;
					}
					else
					{
						current_pice = 'O';
					}
				}
			}

		}
		if (checkWin('X')) {
			MessageBox(GetHWnd(), _T("X 玩家获胜"), _T("游戏结束"), MB_OK);
			running = false;
		}
		else if (checkWin('O')) {
			MessageBox(GetHWnd(), _T("o 玩家获胜"), _T("游戏结束"), MB_OK);
			running = false;
		}
		else if (checkDraw()) {
			MessageBox(GetHWnd(), _T("平局"), _T("游戏结束"), MB_OK);
			running = false;
		}
		cleardevice();
		DrawBord();
		DrawPiece();
		DrawTipText();

		FlushBatchDraw();
	}
	EndBatchDraw();


}