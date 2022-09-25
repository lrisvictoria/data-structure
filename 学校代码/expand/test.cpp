#include <graphics.h>
#include <math.h>

int a = 150, b = 100, c = 450, d = 225;
int e1 = 10, e2 = 10;

int main()
{
	initgraph(800, 600);//设定界面大小为800*600
	setcolor(BLUE);//设定颜色为蓝色
	setbkcolor(BROWN);//设定背景为棕色
	setrendermode(RENDER_MANUAL);//渲染
	
	for (; is_run(); delay_fps(60))
	{
		cleardevice();
		setlinewidth(10);//设定线宽
		rectangle(a, b, c, d);
		
		a -= e1;//上边界向上移动
		b -= e2;
		
		c += e1;//下边界向下移动
		d += e2;
		
		Sleep(66);//休眠66毫秒
		
	}
	return 0;
}
