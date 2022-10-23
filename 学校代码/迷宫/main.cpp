#include<graphics.h>
#include"SeqStack.h"

SeqStack s;
#define MazeSize 11

int maze[MazeSize][MazeSize] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 5, 1, 0, 0, 0, 0, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 7, 0, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1,
	1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

color_t colors[MazeSize] = {
	0xFAF4FF,
	0x000079,
	0xF00078,
	0xA6FFA6,
	0x007500,
	0xAE0000,
	0xFFE6EF,
	0x00FFFF,
	0xFF0000,
	0xFF9224,
	0xFFFFB8
};

bool findStart() {
	for (int j = 0; j < MazeSize; j++)
		for (int i = 0; i < MazeSize; i++) {
			if (maze[j][i] == 5) {
				Point p;
				p.row = j;
				p.col = i;
				StackPush(&s, p);
				return true;
			}
		}
	return false;
}

bool findStop() {
	Point p;
	StackTop(s, &p);
	if (maze[p.row][p.col] == 7) {
		return true;
	} else return false;
}

bool findNext() {
	Point p;
	StackTop(s, &p);
	//down
	if (maze[p.row + 1][p.col] == 0 || maze[p.row + 1][p.col] == 7) {
		p.row++;
		if (maze[p.row][p.col] != 7)
			maze[p.row][p.col] = 2;
		StackPush(&s, p);
		return true;
	}
	//right
	if (maze[p.row][p.col + 1] == 0 || maze[p.row][p.col + 1] == 7) {
		p.col++;
		if (maze[p.row][p.col] != 7)
			maze[p.row][p.col] = 2;
		StackPush(&s, p);
		return true;
	}
	//up
	if (maze[p.row - 1][p.col] == 0 || maze[p.row - 1][p.col] == 7) {
		p.row--;
		if (maze[p.row][p.col] != 7)
			maze[p.row][p.col] = 2;
		StackPush(&s, p);
		return true;
	}
	//left
	if (maze[p.row][p.col - 1] == 0 || maze[p.row][p.col - 1] == 7) {
		p.col--;
		if (maze[p.row][p.col] != 7)
			maze[p.row][p.col] = 2;
		StackPush(&s, p);
		return true;
	}
	StackPop(&s, &p);
	maze[p.row][p.col] = 3;
	return false;

}

void show() {
	for (int j = 0; j < MazeSize; j++)
		for (int i = 0; i < MazeSize; i++) {
			setfillcolor(colors[maze[j][i]]);
			bar(5 + 51 * i, 5 + 51 * j, 55 + 51 * i, 55 + 51 * j);
		}
}

int main() {
	initgraph(800, 600);
	setcolor(BLUE);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	setrendermode(RENDER_MANUAL);

	if (findStart()) {
		while (StackNotEmpty(s)) {
			if (findStop()) {
				break;
			} else {
				findNext();
				show();
				getch();
			}
		}
	}
	while (StackNotEmpty(s)) {
		Point p;
		StackPop(&s, &p);
		maze[p.row][p.col] = 4;
		show();
		getch();
	}

	show();
	getch();
}
