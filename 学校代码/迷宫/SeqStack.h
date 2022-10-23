typedef struct {
	int row;
	int col;
}Point;

#define DataType Point
#define MaxStackSize 100

typedef struct {
	DataType stack[MaxStackSize];
	int top;
}SeqStack;

//1.��ʼ��
void StackInitiate(SeqStack *S){
	S->top=0;
}

//2.�ǿշ�
int StackNotEmpty(SeqStack S){
	if(S.top<=0){
		return 0;
	}
	else{
		return 1;
	}
}

//3.��ջ
int StackPush(SeqStack *S,DataType x){
	if(S->top>=MaxStackSize){
		return 0;
	}
	else{
		S->stack[S->top]=x;
		S->top++;
		return 1;
	}
}

//4.��ջ
int StackPop(SeqStack *S,DataType *d){
	if(S->top<=0){
		return 0;
	}
	else{
		S->top--;
		*d=S->stack[S->top];
		return 1;
	}
}

//5.ȡջ��
int StackTop(SeqStack S,DataType *d){
	if(S.top<=0){
		return 0;
	}
	else{
		*d=S.stack[S.top-1];
		return 1;
	}
}
