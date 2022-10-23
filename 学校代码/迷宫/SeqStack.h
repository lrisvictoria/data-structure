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

//1.初始化
void StackInitiate(SeqStack *S){
	S->top=0;
}

//2.非空否
int StackNotEmpty(SeqStack S){
	if(S.top<=0){
		return 0;
	}
	else{
		return 1;
	}
}

//3.入栈
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

//4.出栈
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

//5.取栈顶
int StackTop(SeqStack S,DataType *d){
	if(S.top<=0){
		return 0;
	}
	else{
		*d=S.stack[S.top-1];
		return 1;
	}
}
