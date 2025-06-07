//#include<graphics.h>
//#include<iostream>
//using namespace std;

//
//int main() {
//
//
//	initgraph(1280,720);
//	int i = 0;
//	int x = 500;
//	int y = 600;
//	BeginBatchDraw();
//	while (true)
//	{
//		ExMessage mse;
//		while (peekmessage(&mse))
//		{
//			if (mse.message == WM_MOUSEMOVE) {
//				x = mse.x;
//				y = mse.y;
//			}
//		}
//		cleardevice();
//		solidcircle(x, y, 100);
//		FlushBatchDraw();
//	}
//	EndBatchDraw();
//	solidcircle(500, 654, 100);
//	//system("pause");
//
//	return 0;
//}