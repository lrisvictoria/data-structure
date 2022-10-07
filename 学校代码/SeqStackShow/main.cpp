#include <graphics.h>

#define DataType int
#define MaxStackSize 6//定义栈最大值为6
typedef struct {
	DataType stack[MaxStackSize];
	int top;
} SeqStack;

//定义数据项
SeqStack stack;
DataType result[MaxStackSize];
int current = 0;

//1初始化栈顶为0
void StackInitiate(SeqStack *S) 
{
	S->top = 0;
}

//2push 定义插入栈数据为x
int StackPush(SeqStack *S, DataType x) 
{
	S->stack[S->top] = x;
	S->top++;
	return 1;
}

//3pop 定义数据x出栈
int StackPop(SeqStack *S, DataType *d) 
{
	S->top--;
	*d = S->stack[S->top];
	return -1;
}
//4 对所监视的内容进行具体化表现
void show() 
{
	cleardevice();
	for(int i=0; i<MaxStackSize; i++) 
	{
		circle(100+80*i,100,30);
		xyprintf(100+80*i,100,"%d",stack.stack[i]);
	}
	xyprintf(100,30,"top=%d",stack.top);
	for(int i=0; i<current; i++) 
	{
		xyprintf(100+i*80,200,"%d",result [i]);
	}
}

int main() 
{
	initgraph(800, 600);// 设定背景为800*600
	setcolor(BLUE);// 设定线条颜色为蓝色
	setbkcolor(WHITE);// 设定背景为白色
	setbkmode(TRANSPARENT);// 透明
	setrendermode(RENDER_MANUAL);// 渲染
	StackInitiate(&stack);// 初始化
	show();
	getch();
	StackPush(&stack, 11);
	show();
	getch();
	StackPush(&stack, 13);
	show();
	getch();
	StackPush(&stack, 7);
	show();
	getch();
	DataType d;
	StackPop(&stack, &d);
	result[current++] = d;
	show();
	getch();
	StackPop(&stack, &d);
	result[current++] = d;
	show();
	getch();
	StackPop(&stack, &d);
	result[current++] = d;
	show();
	getch();
	
	return 0;
}
