#include <graphics.h>
#include <math.h>

int a = 150, b = 100, c = 450, d = 255;
int dy = 50;

int main()
{
	initgraph(800, 600);//�涨ͼ�λ�����Ϊ800*600
	setcolor(BLUE);//��������Ϊ��ɫ
	setbkcolor(BROWN);//���ñ�����ɫΪ��ɫ
	setrendermode(RENDER_MANUAL);//��Ⱦ
	
	for( ; is_run();delay_fps(60))
	{
		cleardevice();
		setlinewidth(10);//�����߿�
		
		rectangle(a, b, c, d);//��泤����
		
		b += dy;//�����ƶ�
		d += dy;
	
		Sleep(66);
		if(b > 150 || b < 50 || d > 275 || c < 175)//�����߽�
		{
			dy = -dy;//����dy
		}
	}
	return 0;
}
