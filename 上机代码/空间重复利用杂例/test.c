#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>

void Func1()
{
	int a = 0;
	printf("%p\n", &a);
}

void Func2()
{
	int b = 0;
	printf("%p\n", &b);
}

int main()
{
	Func1();
	Func2();

	return 0;
}

// Func1 �� a �ĵ�ַ�� Func2 �� b �ĵ�ַ��ͬ
// ���� Func1 ������Fuc1 �ռ䱻�ͷ�
// ���� Func2 ʱ�������ĺ���ջ֡���ú� Func1 ͬһ��λ��
// ��Ϊ Func1 �� Func2 һ�������ǿ�����һ���ֲ�����
// �ɴ�֤���ռ��ǿ����ظ����õģ�����
// ֤��������ۺ����ǾͿ���֪��Ϊʲô쳲��������еĿռ临�Ӷ�Ϊ O(N)