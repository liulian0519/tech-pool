#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100


struct date		//�������� 
{
	int year;
	int month;
	int day;
};

struct other2	//������ 
{
	int day;
};

struct Other1		//�ҵ� 
{
	char GCompany[10];
	char GTel[12];
};

struct Goods		//��ͬ��� 
{
	int GNumber;		//��Ʒ�� 
	struct date GGet;		//��Ʒ�������� 
	int GPrice;		//��Ʒ�۸� 
	int GQuantity;	//��Ʒ���� 
	char GCategory[10];	//��Ʒ���
	union
	{
		struct Other1 Elec; 
		struct other2 Food;
	}Go;
};

struct Goods Good[N]; 

int Good_i=0;

int Menu();

void Get()		//¼����Ʒ��Ϣ 
{	
	printf("��������Ʒ��Ϣ��\n");
	
	printf("��������Ʒ��ţ�");
	scanf("%d", &Good[Good_i].GNumber);
	
	printf("�����빺�����ڣ�");
	scanf("%d %d %d", &Good[Good_i].GGet.year, &Good[Good_i].GGet.month, &Good[Good_i].GGet.day);
	
	printf("��������Ʒ�۸�");
	scanf("%d", &Good[Good_i].GPrice);
	
	printf("��������Ʒ������");
	scanf("%d", &Good[Good_i].GQuantity);
	
	printf("��������Ʒ���ࣺ");
	scanf("%s", Good[Good_i].GCategory);
	
	if(strcmp(Good[Good_i].GCategory, "�ҵ�")==0){
		printf("�����뵥λ��");
		scanf("%s", Good[Good_i].Go.Elec.GCompany);
		
		printf("������绰��");
		scanf("%s", Good[Good_i].Go.Elec.GTel);
	}
	
	if(strcmp(Good[Good_i].GCategory, "ʳƷ")==0){
		printf("�����뱣���ڣ�");
		scanf("%d", &Good[Good_i].Go.Food.day);
	}
	
	Good_i++;
	printf("\n"); 
	Menu();
}

void Print()		//��ӡ��Ʒ��Ϣ 
{	
	int i;
	for(i=0; i<Good_i; i++){
		printf("��Ʒ��ţ�%d\n", Good[i].GNumber);
		printf("�������ڣ�%d %d %d\n", Good[i].GGet.year, Good[i].GGet.month, Good[i].GGet.day);
		printf("��Ʒ�۸�%d Ԫ\n", Good[i].GPrice);
		printf("��Ʒ������%d ��(̨)\n", Good[i].GQuantity);
		printf("��Ʒ���ࣺ%s\n", Good[i].GCategory);
		if(strcmp(Good[i].GCategory, "�ҵ�")==0){
			printf("���޵�λ��%s\n", Good[i].Go.Elec.GCompany);
			printf("���޵绰��%s\n", Good[i].Go.Elec.GTel);
		}
		if(strcmp(Good[i].GCategory, "ʳƷ")==0){
			printf("�����ڣ�%d\n", Good[i].Go.Food.day);
		}
		printf("\n");
	}
	Menu();
}

int Menu()		//����ѡ�� 
{
	loop:printf("�����빦�ܣ�");
	int n;
	scanf("%d", &n);
	switch(n){
		case 1:Get();break;
		case 2:Print();break;
		case 3:exit(0); 
		default:goto loop;		//������������������ 
	}
}

int main()		//������ 
{	
	printf("����1�����Ʒ������2�����Ʒ,����3���˳�\n");
	Menu();
} 