#include <graphics.h>
#include <math.h>

int a = 150, b = 100, c = 450, d = 255;
int dy = 50;

int main()
{
	initgraph(800, 600);//规定图形化界面为800*600
	setcolor(BLUE);//设置线条为蓝色
	setbkcolor(BROWN);//设置背景颜色为棕色
	setrendermode(RENDER_MANUAL);//渲染
	
	for( ; is_run();delay_fps(60))
	{
		cleardevice();
		setlinewidth(10);//设置线宽
		
		rectangle(a, b, c, d);//描绘长方形
		
		b += dy;//向下移动
		d += dy;
	
		Sleep(66);
		if(b > 150 || b < 50 || d > 275 || c < 175)//给定边界
		{
			dy = -dy;//调整dy
		}
	}
	return 0;
}
