#include <graphics.h>
#include <math.h>

int a = 150, b = 100, c = 450, d = 225;
int dx = 50;

int main()
{
	initgraph(800, 600);//�涨ͼ�λ�����Ϊ800*600
	setcolor(BLUE);//�趨��ɫΪ��ɫ
	setbkcolor(BROWN);//�趨������ɫΪ��ɫ
	setrendermode(RENDER_MANUAL);//��Ⱦ
	
	for( ; is_run(); delay_fps(60))
	{
		cleardevice();//����
		setlinewidth(10);//�����߿�
		rectangle(a, b, c, d);
		
		a += dx;//�����ƶ�
		c += dx;
		
		if (a > 200 || a < 100 || c > 500 || c < 400)
		{
			dx = -dx;//����dx
		}
	}
	return 0;
}
