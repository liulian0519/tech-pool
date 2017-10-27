#define _CRT_SECURE_NO_WARNINGS		//Ԥ���봦��
#include<stdio.h>
#include<stdlib.h>


typedef struct node		// ����ڵ�
{
	int data;
	struct node *next;
}Node, *LinkList;


void CreatList(LinkList &L)	// ��������
{
	int data;
	LinkList LNew, pCur;

	pCur = L;

	printf("���������ִ���һ����������Ϊ0ʱ������:\n");
	while (1) {
		scanf("%d", &data);
		if (data == 0)
			break;

		LNew = (LinkList)malloc(sizeof(Node));
		LNew->data = data;

		pCur->next = LNew;
		pCur = LNew;
	}
	pCur->next = NULL;
	return;
}

void Print(LinkList L)	// ��ӡ����
{
	if (L->next == NULL) {		//�жϿ�����
		printf("������Ϊ�գ�\n");
		return;
	}

	LinkList pCur;
	pCur = L->next;

	while (pCur) {
		printf("%-4d ", pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
	return;
}

void CountLength(LinkList L, int *length)	//����ĳ��ȼ���
{
	LinkList pCur;
	pCur = L->next;

	int i = 0;
	while (pCur) {
		pCur = pCur->next;
		i++;
	}

	*length = i;
	return;
}

void Reverse(LinkList &L)	// ��������
{
	LinkList pCur;
	LinkList temp;

	pCur = L->next;
	L->next = NULL;

	while (pCur) {
		temp = pCur->next;
		pCur->next = L->next;
		L->next = pCur;
		pCur = temp;
	}
	return;
}

void DirectMerge(LinkList &L1, LinkList &L2, LinkList &L)		//ֱ�Ӻϲ���������
{
	LinkList pCur;

	L->next = L1->next;
	pCur = L;

	//����ֱ�Ӻϲ�
	while (pCur->next) {
		pCur = pCur->next;
	}
	pCur->next = L2->next;

	free(L1);
	free(L2);

	return;
}

void CrossMerge(LinkList &L1, LinkList &L2, LinkList &L)	//����ϲ���������
{
	LinkList pCur;
	LinkList pCur1;
	LinkList pCur2;

	pCur = L;
	pCur1 = L1->next;
	pCur2 = L2->next;

	while (pCur2) {

		pCur->next = pCur1;
		pCur = pCur->next;		// L ָ�����
		pCur1 = pCur1->next;	// L1 �����ָ�����

		pCur->next = pCur2;
		pCur = pCur->next;		// L ָ�����
		pCur2 = pCur2->next;	// L2 ����ָ�����
	}

	pCur->next = pCur1;		//

	return;
}

int main()		//������
{
	LinkList LA, LB;	// A, B �����������ͷ���ռ�����
	LA = (LinkList)malloc(sizeof(Node));
	LB = (LinkList)malloc(sizeof(Node));

	CreatList(LA);	//��������
	CreatList(LB);

	Print(LA);		//�������
	Print(LB);

	int longA, longB;	//�����ȼ���
	CountLength(LA, &longA);
	CountLength(LB, &longB);

	//printf("%d %d\n", longA, longB);

	LinkList L;		// �����ϲ�֮���ͷ��㣬��������������ʹ��
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;		//ͷ���ָ����Ϊ�գ���ֹΪ�ϲ�֮��Ϊ�յ�����쳣

	int lengthMax;
	lengthMax = longA > longB ? longA : longB;	// ���㳤�����ֵ

	if (longA == lengthMax)		//����ϲ���ʽ�ж�
		CrossMerge(LA, LB, L);
	else
		CrossMerge(LB, LA, L);

	printf("�ϲ�֮�������:\n");
	Print(L);
	//printf("\n");


	system("pause");

	return 0;
}

