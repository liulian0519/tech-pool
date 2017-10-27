///˳��ջ

#include<stdio.h>
#include<stdlib.h>

/* ˳��ջ������ */
#define MAXSIZE 10	
typedef struct
{
	int data[MAXSIZE];
	int top;
}SeqStack;

/* �ÿ�ջ�����Ƚ���ջ�ռ䣬Ȼ���ʼ��ջ��ָ�� */
SeqStack *InitSeqStack()
{
	SeqStack *s;
	s = malloc(sizeof(SeqStack));
	s->top = -1;
	return s;
}

/* �жϿ�ջ */
int EmptySeqStack(SeqStack *s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

/* ��ջ */
int PushSeqStack(SeqStack *s, int x)
{
	if (s->top == MAXSIZE - 1)	//ջ��������ջ
		return 0;
	else {
		s->top++;
		s->data[s->top] = x;
		return 1;
	}
}

/* ��ջ */
int PopSeqStack(SeqStack *s, int *x)
{
	if (EmptySeqStack(s))
		return 0;
	else {
		*x = s->data[s->top];	//ջ��Ԫ�ش�Ϊ�� *x
		s->top--;
		return 1;
	}
}

/* ȡջ��Ԫ�� */
int TopSeqStack(SeqStack *s)
{
	if (EmptySeqStack(s))
		return 0;
	else {
		return (s->data[s->top]);
	}
}
int main()
{

}