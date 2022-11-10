#define _CRT_SECURE_NO_WARNINGS 1 

typedef int STDatatype;

typedef struct Stack
{
	STDatatype* a;
	int capacity;
	int top;   // ��ʼΪ0����ʾջ��λ����һ��λ���±�
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
	// �ṹ��һ����Ϊ��
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

	// �������
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
	// ����Ԫ��
	// top Ϊջ������һ��Ԫ��
	// �Ȳ����� ++ 
	ps->a[ps->top++] = x;
}

void StackPop(ST* ps)
{
	assert(ps);

	// ���ջ�գ�����ɾ��
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
		// ������
		if (*s == '(' || *s == '[' || *s == '{')
		{
			// ��ջ
			StackPush(&st, *s);
			s++;
		}
		else
		{
			// ������ƥ�䣬ջΪ��
			if (StackEmpty(&st))
			{
				// ��ֹ�ڴ�й©
				StackDestroy(&st);
				return false;
			}
			// ȡջ��Ԫ�أ�����ջ
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
	// �жϱ���������ջ�Ƿ�Ϊ��
	bool ans = StackEmpty(&st);
	// ����ջ
	StackDestroy(&st);
	return ans;
}