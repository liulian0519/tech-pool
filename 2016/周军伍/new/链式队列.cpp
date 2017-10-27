#include<stdio.h>
#include<stdlib.h>

/*
*���о��� ˮ��һ������һ�˽��룬����һ�˳�ȥ
*/

/* ���еĶ��� */
typedef struct node1		//����һ������
{
	int data;
	struct node1 *next;
}QNode;

typedef struct node2	//�����нṹ
{
	QNode *rear;	//ָ���β
	QNode *front;	//ָ���ͷ
}LQueue;

/* ����һ����ͷ����  �ն� */
LQueue *InitLQueue()
{
	QNode *p;
	LQueue *q;

	q = (LQueue *)malloc(sizeof(LQueue));	// ����ͷβָ��ڵ�
	p = (QNode *)malloc(sizeof(QNode));	// ��������ͷ���

	p->next = NULL;
	q->front = p;
	q->rear = p;
	return q;
}

/* ��� */
void InLQueue(LQueue *q, int x)
{
	QNode *p;
	p = (QNode *)malloc(sizeof(QNode));	//�����½ڵ�
	p->data = x;
	p->next = NULL;

	q->rear->next = p;	// ���¼��������� ��β
	q->rear = p;	// rear ָ���β
}

/* �ж϶ӿ� */
int EmptyLQueue(LQueue *q)
{
	if (q->front == q->rear)	//ͷβָ����ȣ�����Ϊ��
		return 0;
	else
		return 1;
}

/* ���� */
int OutLQueue(LQueue *q, int *x)
{
	QNode *p;
	if ( EmptyLQueue(q) ) {
		printf("�ӿա�\n");
		return 0;
	}
	else {
		p = q->front->next;
		q->front->next = p->next;
		*x = p->data;
		free(p);
		if (q->front->next == NULL)
			q->rear = q->front;
		return 1;
	}
}

/*���Ӳ���*/
int main()
{
	;
}