#include <graphics.h>
#include <math.h>

int x = 100, y = 200;
int r = 50;
int dr = 1;


int main()
{
	initgraph(640, 480);
	setcolor(YELLOW);
	setrendermode(RENDER_MANUAL);
	
	for ( ; is_run(); delay_fps(60) )
	{
		cleardevice();
		setlinewidth(10);
		circle(x, y, r);
		r += dr;
		
		if(x + r > 640 || x - r < 0 || r < 0 || y + r > 480 || y - r < 0)
		{
			dr = - dr;
		}
	}
	return 0;
}
