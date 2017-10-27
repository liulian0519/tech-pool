#include<stdio.h>
#include<stdlib.h>

//typedef int Element;

typedef struct node		// ����ڵ�
{
	int data;
	struct node *next;
}Node, *LinkList;


void CreatList(LinkList &L)	// ��������
{
	int data;
	LinkList LNew, pre;

	pre = L;

	printf("���������ִ���һ����������Ϊ0ʱ������:\n");
	while (1) {
		scanf("%d", &data);
		if (data == 0)
			break;

		LNew = (LinkList)malloc(sizeof(Node));
		LNew->data = data;

		pre->next = LNew;
		pre = LNew;
	}
	pre->next = NULL;
}

void Print(LinkList L)	// ��ӡ����
{
	LinkList pre;
	pre = L->next;

	//int i = 0;
	while (pre) {
		printf("%d ", pre->data);
		pre = pre->next;
		//	i++;
	}
	printf("\n");
	//printf("i = %d", i);
}


void Reverse(LinkList &L)	// ��������
{
	LinkList pre;
	LinkList temp;

	pre = L->next;
	L->next = NULL;

	while (pre) {
		temp = pre->next;
		pre->next = L->next;
		L->next = pre;
		pre = temp;
	}
}


int main()
{
	LinkList L;
	L = (LinkList)malloc(sizeof(Node));

	CreatList(L);	//��������

	Print(L);		//�������

	Reverse(L);		//��������

	printf("����֮�������Ϊ��\n");
	Print(L);		//�������

	system("pause");

	return 0;
}

