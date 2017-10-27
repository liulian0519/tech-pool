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

//����1
/*
void SortMerge(LinkList &L1, LinkList &L2, LinkList &L)	//����ϲ�
{
	LinkList pCur;
	LinkList pCur1;
	LinkList pCur2;

	pCur = L;
	pCur1 = L1->next;
	pCur2 = L2->next;

	int temp;
	while (pCur1 && pCur2) {
		if (pCur1->data < pCur2->data) {
			pCur1 = pCur1->next;
		}
		else {
			temp = pCur1->data;
			pCur1->data = pCur2->data;
			pCur2->data = temp;
			if (pCur2->data > pCur2->next->data) {
				temp = pCur2->data;
				pCur2->data = pCur2->next->data;
				pCur2->next->data;
			}
		}
	}
}
*/


void SortMerge(LinkList &L1, LinkList &L2, LinkList &L)	//�ϲ�����ͬ������
{
	LinkList pCur;
	LinkList pCur1;
	LinkList pCur2;

	pCur = L;
	pCur1 = L1->next;
	pCur2 = L2->next;

	while (pCur1 && pCur2) {
		if (pCur1->data < pCur2->data) {
			pCur->next = pCur1;
			pCur1 = pCur1->next;
			pCur = pCur->next;
		}
		else {
			pCur->next = pCur2;
			pCur2 = pCur2->next;
			pCur = pCur->next;
		}
	}
	
	if (pCur1) {
		pCur->next = pCur1;
	}
	else {
		pCur->next = pCur2;
	}
	
	free(L1);
	free(L2);
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


	LinkList L;		// �����ϲ�֮���ͷ��㣬��������������ʹ��
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;		//ͷ���ָ����Ϊ�գ���ֹΪ�ϲ�֮��Ϊ�յ�����쳣

	SortMerge(LA, LB, L);

	//Print(LA);
	//Print(LB);

	printf("�ϲ�֮�������:\n");
	Print(L);

	system("pause");

	return 0;
}

