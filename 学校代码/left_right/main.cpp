#include <graphics.h>
#include <math.h>

int a = 150, b = 100, c = 450, d = 225;
int dx = 50;

int main()
{
	initgraph(800, 600);//规定图形化界面为800*600
	setcolor(BLUE);//设定颜色为蓝色
	setbkcolor(BROWN);//设定背景颜色为棕色
	setrendermode(RENDER_MANUAL);//渲染
	
	for( ; is_run(); delay_fps(60))
	{
		cleardevice();//清屏
		setlinewidth(10);//设置线宽
		rectangle(a, b, c, d);
		
		a += dx;//向右移动
		c += dx;
		
		if (a > 200 || a < 100 || c > 500 || c < 400)
		{
			dx = -dx;//调整dx
		}
	}
	return 0;
}
