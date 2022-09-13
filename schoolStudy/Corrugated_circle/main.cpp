#include <graphics.h>
#include <math.h>

int x = 100, y = 200;
int r = 50;
int dr = 1;

typedef struct
{
	int x, y;
	int r;
	int dr;
}Circle;

Circle c1 = {300, 200, 50, 1};
Circle c2 = {200, 100, 50, 1};

int main()
{
	initgraph(640, 480);
	setcolor(YELLOW);
	setrendermode(RENDER_MANUAL);
	
	for ( ; is_run(); delay_fps(60) )
	{
		cleardevice();
		setlinewidth(10);
		circle(c1.x, c1.y, c1.r);
		circle(c2.x, c2.y, c2.r);
		c1.r += c1.dr;
		c2.r += c2.dr;
		if(c1.x + c1.r > 640 || c1.x - c1. r < 0 || c1.r < 0 || c1.y + c1.r > 480 || c1.y - c1.r < 0)
		{
			c1.dr = -c1.dr;
		}
		if(c2.x + c2.r > 640 || c2.x - c2. r < 0 || c2.r < 0 || c2.y + c2.r > 480 || c2.y - c2.r < 0)
		{
			c1.dr = -c1.dr;
		}
	}
	return 0;
}
