#include <graphics.h>
#include <math.h>

int x = 200, y = 250;
int dx = 10, dy = 1;
int radius = 80;
int main()
{
	initgraph(800, 600);//������Ļ��СΪ800*600
	setcolor(YELLOW);//�����ߵ���ɫΪ��ɫ
	setbkcolor(GREEN);
	setrendermode(RENDER_MANUAL);//�ֶ���Ⱦ
	
	for(;is_run(); delay_fps(60))//forѭ����ʵ������һ����ѭ��
	{
		cleardevice();//�����Ļ�ϵ�����
		setlinewidth(10);//�����߿��
		circle(x, y, radius);//��ͼ
		circle(x + 100, y + 30, 50);
		
		x += dx;//�ı�x��ֵ
		//z += 1;
		if(x > 500 - radius || x < 100 + radius)//����x��ֵ�����ұ߽�Ĺ�ϵ����
		{
			dx = -dx;//x�����������ı䷽��
		}
	}
	return 0;
}
