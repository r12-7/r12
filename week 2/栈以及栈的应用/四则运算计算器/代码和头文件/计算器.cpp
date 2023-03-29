// An highlighted block
#include<cstdio>
#include<cstring>
#include <iostream>
#define maxSize 50

int getpriority(char m)//��ȡ��������ȼ�
{
	switch (m)
	{
	case'+':
	case'-':
		return 1;
		break;
	case'*':
	case'/':
		return 2;
		break;
	}
}
int trans(char infix[], double s2[], int& top2)//��׺ת��׺������ע�ⷵ��ֵ��int��һ��С��˼
{
	double s1[maxSize];//��������ĸ���ջ 
	int top1 = -1;
	int i = 0;
	int k = 0;//���ڼ�¼��׺���ʽ�ĳ��ȣ�����Ϊ����ֵ����
	while (infix[i] != '\0')
	{
		if ('0' <= infix[i] && '9' >= infix[i])
		{
			s2[++top2] = infix[i] - '0';
			++i; ++k;
			while ('0' <= infix[i] && '9' >= infix[i])
			{
				s2[top2] = infix[i] - '0' + s2[top2] * 10;
				i++;
			}
		}
		else if (infix[i] == '(')
		{
			s1[++top1] = '(' - 50;
			++i;
		}
		else if (infix[i] == '+' ||
			infix[i] == '-' ||
			infix[i] == '*' ||
			infix[i] == '/')
		{
			if (top1 == -1 ||
				s1[top1] == '(' - 50 ||
				getpriority(infix[i]) > getpriority(s1[top1] + 50))
			{
				s1[++top1] = infix[i] - 50;
				++i;
			}
			else
			{
				s2[++top2] = s1[top1--];
				++k;
			}
		}
		else if (infix[i] == ')')
		{
			while (s1[top1] != ('(' - 50))
			{
				s2[++top2] = s1[top1--];
				k++;
			}

			--top1;//��ջ������ 
			++i;
		}
	}
	while (top1 != -1)
	{
		s2[++top2] = s1[top1--];//��ջ����ջʣ����ʽ 
		++i; ++k;
	}
	return k;
}
double op(double a, char Op, double b)//���㺯�� 
{
	if (Op == '+') return a + b;
	if (Op == '-') return a - b;
	if (Op == '*') return a * b;
	if (Op == '/')//��Ŀ�ǷǸ�����
	{
		if (b == 0)
		{
			printf("error\n");
			return 0;
		}
		else
			return a / b;
	}
}
double cal(double exp[], int k)//��׺ʽ���㺯�� 
{
	int i;
	double a, b, c;
	double stack[maxSize]; int top = -1;

	char Op;
	for (i = 0; i <= k - 1; ++i)//k�ǳ��ȣ����Ե�k-1
	{
		if (exp[i] < 0)
		{
			Op = exp[i] + 50;
			b = stack[top--];

			a = stack[top--];//����ȳ�
			c = op(a, Op, b);
			stack[++top] = c;
		}
		else
			stack[++top] = exp[i];
	}
	return stack[top];
}
int main()
{	
	printf("*****************\n");
	printf("*****************\n"); 
	printf("*****************\n");
	printf("*****************\n");
	printf(" �������������\n");
	printf("*****************\n");
	printf("*****************\n");
	printf("*****************\n");
	printf("*****************\n");
	printf("������:\n");
	char infix[maxSize];
	gets_s(infix);
	double rinfix[maxSize] = { 0 };
	int top2 = -1;
	int k = trans(infix, rinfix, top2);
	printf("%.2f", cal(rinfix, k));
	return 0;
}
