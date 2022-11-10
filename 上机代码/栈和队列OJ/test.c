#define _CRT_SECURE_NO_WARNINGS 1 

typedef int STDatatype;

typedef struct Stack
{
	STDatatype* a;
	int capacity;
	int top;   // 初始为0，表示栈顶位置下一个位置下标
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDatatype x);
void StackPop(ST* ps);
STDatatype StackTop(ST* ps);

bool StackEmpty(ST* ps);
int StackSize(ST* ps);


void StackInit(ST* ps)
{
	// 结构体一定不为空
	assert(ps);

	ps->a = (STDatatype*)malloc(sizeof(STDatatype) * 4);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ps->capacity = 4;
	ps->top = 0;
}

void StackDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDatatype x)
{
	assert(ps);

	// 检查容量
	if (ps->top == ps->capacity)
	{
		STDatatype* tmp = (STDatatype*)realloc(ps->a, sizeof(STDatatype) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	// 插入元素
	// top 为栈顶的下一个元素
	// 先插入再 ++ 
	ps->a[ps->top++] = x;
}

void StackPop(ST* ps)
{
	assert(ps);

	// 如果栈空，则不能删除
	assert(!StackEmpty(ps));
	ps->top--;
}

STDatatype StackTop(ST* ps)
{
	assert(ps);

	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

bool isValid(char* s)
{
	ST st;
	StackInit(&st);

	while (*s)
	{
		// 左括号
		if (*s == '(' || *s == '[' || *s == '{')
		{
			// 入栈
			StackPush(&st, *s);
			s++;
		}
		else
		{
			// 右括号匹配，栈为空
			if (StackEmpty(&st))
			{
				// 防止内存泄漏
				StackDestroy(&st);
				return false;
			}
			// 取栈顶元素，并出栈
			STDatatype top = StackTop(&st);
			StackPop(&st);
			if ((*s == ')' && top != '(')
				|| (*s == ']' && top != '[')
				|| (*s == '}' && top != '{'))
			{
				return false;
			}
			else
			{
				s++;
			}
		}
	}
	// 判断便利结束后，栈是否为空
	bool ans = StackEmpty(&st);
	// 销毁栈
	StackDestroy(&st);
	return ans;
}