// An highlighted block
#include<cstdio>
#include<cstring>
#include <iostream>
#define maxSize 50

int getpriority(char m)//获取运算符优先级
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
int trans(char infix[], double s2[], int& top2)//中缀转后缀函数，注意返回值是int，一个小巧思
{
	double s1[maxSize];//存运算符的辅助栈 
	int top1 = -1;
	int i = 0;
	int k = 0;//用于记录后缀表达式的长度，并作为返回值返回
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

			--top1;//出栈左括号 
			++i;
		}
	}
	while (top1 != -1)
	{
		s2[++top2] = s1[top1--];//出栈辅助栈剩余表达式 
		++i; ++k;
	}
	return k;
}
double op(double a, char Op, double b)//运算函数 
{
	if (Op == '+') return a + b;
	if (Op == '-') return a - b;
	if (Op == '*') return a * b;
	if (Op == '/')//题目是非负整数
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
double cal(double exp[], int k)//后缀式计算函数 
{
	int i;
	double a, b, c;
	double stack[maxSize]; int top = -1;

	char Op;
	for (i = 0; i <= k - 1; ++i)//k是长度，所以到k-1
	{
		if (exp[i] < 0)
		{
			Op = exp[i] + 50;
			b = stack[top--];

			a = stack[top--];//后进先出
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
	printf(" 四则运算计算器\n");
	printf("*****************\n");
	printf("*****************\n");
	printf("*****************\n");
	printf("*****************\n");
	printf("请输入:\n");
	char infix[maxSize];
	gets_s(infix);
	double rinfix[maxSize] = { 0 };
	int top2 = -1;
	int k = trans(infix, rinfix, top2);
	printf("%.2f", cal(rinfix, k));
	return 0;
}
