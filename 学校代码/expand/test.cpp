#include <graphics.h>
#include <math.h>

int a = 150, b = 100, c = 450, d = 225;
int e1 = 10, e2 = 10;

int main()
{
	initgraph(800, 600);//�趨�����СΪ800*600
	setcolor(BLUE);//�趨��ɫΪ��ɫ
	setbkcolor(BROWN);//�趨����Ϊ��ɫ
	setrendermode(RENDER_MANUAL);//��Ⱦ
	
	for (; is_run(); delay_fps(60))
	{
		cleardevice();
		setlinewidth(10);//�趨�߿�
		rectangle(a, b, c, d);
		
		a -= e1;//�ϱ߽������ƶ�
		b -= e2;
		
		c += e1;//�±߽������ƶ�
		d += e2;
		
		Sleep(66);//����66����
		
	}
	return 0;
}
