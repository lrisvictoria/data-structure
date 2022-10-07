#include <graphics.h>

#define DataType int
#define MaxStackSize 6//����ջ���ֵΪ6
typedef struct {
	DataType stack[MaxStackSize];
	int top;
} SeqStack;

//����������
SeqStack stack;
DataType result[MaxStackSize];
int current = 0;

//1��ʼ��ջ��Ϊ0
void StackInitiate(SeqStack *S) 
{
	S->top = 0;
}

//2push �������ջ����Ϊx
int StackPush(SeqStack *S, DataType x) 
{
	S->stack[S->top] = x;
	S->top++;
	return 1;
}

//3pop ��������x��ջ
int StackPop(SeqStack *S, DataType *d) 
{
	S->top--;
	*d = S->stack[S->top];
	return -1;
}
//4 �������ӵ����ݽ��о��廯����
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
	initgraph(800, 600);// �趨����Ϊ800*600
	setcolor(BLUE);// �趨������ɫΪ��ɫ
	setbkcolor(WHITE);// �趨����Ϊ��ɫ
	setbkmode(TRANSPARENT);// ͸��
	setrendermode(RENDER_MANUAL);// ��Ⱦ
	StackInitiate(&stack);// ��ʼ��
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
