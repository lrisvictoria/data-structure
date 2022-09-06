#include <graphics.h>
#include <math.h>

int x = 200, y = 250;
int dx = 10, dy = 1;
int radius = 80;
int main()
{
	initgraph(800, 600);//设置屏幕大小为800*600
	setcolor(YELLOW);//设置线的颜色为黄色
	setbkcolor(GREEN);
	setrendermode(RENDER_MANUAL);//手动渲染
	
	for(;is_run(); delay_fps(60))//for循环，实质上是一个死循环
	{
		cleardevice();//清楚屏幕上的内容
		setlinewidth(10);//设置线宽度
		circle(x, y, radius);//画图
		circle(x + 100, y + 30, 50);
		
		x += dx;//改变x的值
		//z += 1;
		if(x > 500 - radius || x < 100 + radius)//根据x的值和左右边界的关系条件
		{
			dx = -dx;//x方向的增量会改变方向
		}
	}
	return 0;
}
