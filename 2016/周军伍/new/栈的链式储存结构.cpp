/* ��ջ */

/*
*ջ�׾�����������һ���ڵ㣬 ջ����������ĵ�һ���ڵ�
*�����ƾ�ʹ�ó�ջ��ջ�ܷ��㣬��Լʱ��
*/

#include<stdio.h>
#include<stdlib.h>

/* ��ջ�Ķ���*/
typedef struct Stacknode
{
	int data;
	struct Stacknode *next;
}slStacktype;

/* ��ջ���� */
int PushStack(slStacktype *top, int x)
{
	/* ��Ԫ�� x ѹ����ջtop��*/
	slStacktype *p;
	if ((p = (slStacktype *)malloc(sizeof(slStacktype))) == NULL)
		return 0;
	/*����һ���ڵ�*/
	p->data = x;
	p->next = top->next;
	top->next = p;
	return 1;
}

/* ��ջ */
int PopStack(slStacktype *top)
{
	slStacktype *p;
	int x;
	if (top->next == NULL)
		return NULL; //��ջ
	p = top->next;
	top->next = p->next;
	x = p->next;
	free(p);
	return x;
}



int main()
{

	system("pausse");
	return 0;
}