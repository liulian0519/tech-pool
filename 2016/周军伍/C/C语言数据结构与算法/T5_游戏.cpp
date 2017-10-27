#define _CRT_SECURE_NO_WARNINGS		//Ԥ���봦��
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node		// ����ڵ�
{
	int num;	//���
	int pwd;	//����
	struct node *next;
}Node, *LinkList;


void CreatList(LinkList &L, int n)	// ��������
{
	int data;
	LinkList LNew, pCur;

	pCur = L;

	int i;
	srand((unsigned)time(NULL));


	for (i = 0; i < n; i++) {
		LNew = (LinkList)malloc(sizeof(Node));
		LNew->num = i + 1;
		LNew->pwd = (rand() % 5 + 1);

		pCur->next = LNew;
		pCur = LNew;
	}

	pCur->next = L->next;

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

	while (1) {
		printf("%-4d%-4d\n", pCur->num, pCur->pwd);
		pCur = pCur->next;
		if (pCur == L->next)
			break;
	}
	return;
}

void Game(LinkList &L, int n)
{
	int count_All;	//�����������ڱ�ǵ�ǰ�ĸ���
	int count_Every;	//����ѭ��������

	LinkList pPre;
	LinkList FreeTemp;

	count_All = 0;	
	count_Every = 1;

	int flagPwd;	
	srand((unsigned)time(NULL));	/* ���ó�ʼ����Ϊ���ֵ��1~n�� */
	flagPwd = rand()%n+1;
	
	pPre = L;
	
	printf("��ʼ����Ϊ��flagPwd=%d\n", flagPwd);

	while (1) {
		if (flagPwd == count_Every) {

			printf("%d ", pPre->next->num);		//��ӡ ������ �����

			printf("%d\n", pPre->next->pwd);	// ��ӡ ������ �� pwd

			flagPwd = pPre->next->pwd;		//�������� pwd Ϊ ����������

			FreeTemp = pPre->next;		// ��¼������ �������ͷſռ�

			pPre->next = pPre->next->next;		//ɾ���ڵ㣨�����ߣ�

			free(FreeTemp);		//�ͷų����� 

			count_All++;	//���� ɾ���ڵ�ĸ���

			count_Every = 0;	// ɾ���ڵ�֮�󣬼���Ϊ��Ϊ 0
		}
		else {

			pPre = pPre->next;	//�α����
		}

		count_Every++;	//��ǰ������ +1 

		if (count_All == n) {
			L->next = NULL;
			break;
		}

		fflush(stdin);	//�������
	}
}


int main()		//������
{
	LinkList L;	// 

	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;		//ͷ���ָ����Ϊ�գ���ֹΪ�ϲ�֮��Ϊ�յ�����쳣

	int n;	//��Ϸ����
	printf("��������Ϸ����:");
	scanf("%d", &n);

	CreatList(L, n);	//��ʼ����Ϸ
	printf("��Ϸ��ʼ�������\n");
	Print(L);			//��ӡ��ʼ�����

	printf("��Ϸ�����\n");	//��Ϸ����
	Game(L, n);

	//printf("�����\n");
	//Print(L);

	system("pause");

	return 0;
}

