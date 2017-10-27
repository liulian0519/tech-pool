#define _CRT_SECURE_NO_WARNINGS		//Ԥ���봦��
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define N 15	//name
#define M 15	//phone
#define H 30	//category

void FunctionSelect();
void Menu();


//�ṹ������
typedef struct node //�ڵ㶨��
{
	char name[N];
	char phone[M];
	char category[H];
	struct node *next;
}Node, *LinkPerson;


LinkPerson L;	//����ͨѶ¼ͷ���

int Per_i = 0;		//����ȫ�ֱ�����ͳ������

void CreatMailList()		//ͨѶ¼��Ϣ��¼
{
	char nameTemp[N];
	char phoneTemp[M];
	char categoryTemp[H];

	LinkPerson pNew;
	LinkPerson pCur;

	pCur = L;

	while (pCur->next) {		//���α��ƶ�����
		pCur = pCur->next;
	}

	printf("��������ϵ����Ϣ��(������Ϊ exit ʱ��������)\n");
	printf("name phone category\n");
	while (1) {
		printf("---------------------\n");
		scanf("%s", nameTemp);
		if (strcmp(nameTemp, "exit") == 0)
			break;

		scanf("%s %s", phoneTemp, categoryTemp);

		pNew = (LinkPerson)malloc(sizeof(Node));

		strcpy(pNew->name, nameTemp);
		strcpy(pNew->phone, phoneTemp);
		strcpy(pNew->category, categoryTemp);

		pCur->next = pNew;
		pCur = pNew;

		Per_i++;
	}

	pCur->next = NULL;

	return;
}

void SortByName()
{
	int lenList = Per_i;

	LinkPerson pPre;
	LinkPerson pCur;
	LinkPerson pNext;
	LinkPerson pTemp;

	int i;
	int j;

	for (i = 0; i<lenList - 1; i++) {

		pPre = L;
		pCur = L->next;   //���ڵ�ָ�����У�head--p--pNext  
		pNext = pCur->next;

		for (j = 0; j<lenList - 1 - i; j++) {

			if (strcmp(pCur->name, pNext->name) > 0) {

				pPre->next = pCur->next;
				pCur->next = pNext->next;
				pNext->next = pCur;

				pTemp = pCur;
				pCur = pNext; //������Ľ�����ɺ��ʼ�ı仯Ϊhead--pNext--p  
				pNext = pTemp;//��ô���������ͻ��������Ĳ������ǰ�ָ�뻻����  
			}

			pPre = pPre->next;//ָ�������ƶ�  
			pCur = pCur->next;
			pNext = pNext->next;
		}
	}

}

void PrintMailList()	//��ӡͨѶ¼
{
	LinkPerson pCur;
	pCur = L->next;
	int i = 0;

	printf("----------------------------------------------\n");
	printf("���: ����\t\t�绰\t\t����\n");
	printf("----------------------------------------------\n");

	while (pCur) {
		printf("----------------------------------------------\n");
		printf("%4d: %-18s%-16s%s\n", ++i, pCur->name, pCur->phone, pCur->category);
		pCur = pCur->next;
	}
	printf("----------------------------------------------\n");

	return;
}

void QueryByName()
{
	char nameTemp[N];
	int i = 0;

	LinkPerson pCur;
	pCur = L->next;

	printf("��������Ҫ���ҵ���ϵ��");
	scanf("%s", nameTemp);
	while (pCur) {
		if (strcmp(nameTemp, pCur->name) == 0) {
			printf("----------------------------------------------\n");
			printf("%4d: %-18s%-16s%s\n", i + 1, pCur->name, pCur->phone, pCur->category);
			printf("----------------------------------------------\n");
			break;
		}
		pCur = pCur->next;
		i++;
	}

	return;
}

void DeleteByName()
{
	char nameTemp[N];

	LinkPerson pCur;
	LinkPerson pTemp;
	pCur = L;

	printf("������Ҫɾ������ϵ�ˣ�");
	scanf("%s", nameTemp);

	while (pCur->next) {
		if (strcmp(pCur->next->name, nameTemp) == 0) {
			break;
		}
		pCur = pCur->next;
	}

	pTemp = pCur->next;
	pCur->next = pCur->next->next;
	Per_i--;
	free(pTemp);

	return;
}

void UpdataByName()
{
	char nameTemp[N];

	LinkPerson pCur;
	pCur = L;

	printf("��������Ҫ�޸ĵ���ϵ�ˣ�");
	scanf("%s", nameTemp);

	while (pCur) {
		if (strcmp(nameTemp, pCur->name) == 0) {
			printf("������绰���룺");
			scanf("%s", pCur->phone);
			printf("���������");
			scanf("%s", pCur->category);
			break;
		}
		pCur = pCur->next;
	}

	return;

}

void FunctionSelect()
{

	printf("����������ѡ��");
	//ѡ����ʵ��

loop: int x;
	scanf("%d", &x);
	switch (x) {
	case 1:
		CreatMailList();
		FunctionSelect();
		break;

	case 2:
		SortByName();
		PrintMailList();
		FunctionSelect();
		break;

	case 3:
		QueryByName();
		FunctionSelect();
		break;

	case 4:
		CreatMailList();
		FunctionSelect();
		break;

	case 5:
		DeleteByName();
		FunctionSelect();
		break;

	case 6:
		UpdataByName();
		FunctionSelect();
		break;
	case 7:
		system("cls");
		Menu();
		break;

	case 8:
		exit(0);
		break;

	default:
		printf("���������룺");
		goto loop;
	}
}



void Menu()
{
	//����ѡ�������ʽ
	printf("                         ͨѶ¼\n");
	printf("**************************************************************\n");
	printf("*   1.�����ϵ��                                2.��ʾ��ϵ�� *\n");
	printf("*   3.��ѯ��ϵ��                                4.������ϵ�� *\n");
	printf("*   5.ɾ����ϵ��                                6.�޸���ϵ�� *\n");
	printf("*   7.����                                      8.ǧ���ѡ   *\n");
	printf("**************************************************************\n");
	FunctionSelect();
}

int main()
{

	L = (LinkPerson)malloc(sizeof(Node));
	L->next = NULL;	 //���������� 
					 //�˵�
	Menu();

	system("pause");

	return 0;
}