//�ֻ�ͨѶ¼

#include<stdio.h>
#include<string.h>
#include<cstdlib>
#define N 200

int per_i=0;
void Sort();
void Get();
void Show();
void Check();
void Add();
void Add();
void Menu();
void fun();

struct Person		//��ϵ�˻�����Ϣ����
{
	char name[12];
	char telephone[12];
	char category[8];	//��ϵ�����������ˣ�ͬ�£�����
}Per[N];



void Sort()
{
	struct Person temp;
	for(int j=0; j<per_i-1; j++)
		for(int k=0; k<per_i-j-1; k++)
			if(strcmp(Per[k].name,Per[k+1].name)>0){
				temp=Per[k];
				Per[k]=Per[k+1];
				Per[k+1]=temp;
			}
}

void Get()		//¼�������Ϣ     //�������ֵ�˳������
{
	//������ʾ��
	int n;
	printf("������Ҫ¼�����ϵ�˸�����"); 
	scanf("%d", &n);
	int i;
	for(i=0; i<n; i++){
		Add();
	}
	Show();
	fun();
}

void Show()		//���ÿһ����ϵ�˻�����Ϣ
{	
	if(per_i==0)
		printf("ͨѶ¼��û����ϵ�˶\n");
	else{
		//���䰴�ֵ�����
		Sort();
		printf("����ȫ����ϵ������\n");
		for(int k=0; k<per_i; k++)		//���
			printf("%d.%s��%s\t%s\n",k+1,Per[k].name,Per[k].telephone,Per[k].category);
	}	
	fun();
}

void Check()		//��ѯ��ϵ��
{
	//��ѯ
	char name_temp[12];
	printf("������������");
	getchar();
	gets(name_temp);
	int flag=0;
	for(int j=0; j<per_i; j++){
		if(strcmp(name_temp,Per[j].name)==0){
			flag=1;
			printf("%d.%s��%s\t%s\n",j+1,Per[j].name,Per[j].telephone,Per[j].category);
		}
	}
	if(flag==0)
			printf("�ף��鲻������Ŷ\n");
	fun();
}

void Add()		//�����ϵ�˵绰 
{
	//���������Ϣ
	scanf("%s", Per[per_i].name);
	scanf("%s", Per[per_i].telephone);
	scanf("%s", Per[per_i].category);
	per_i++;
}

void Delete()		//ɾ����ϵ��
{
	//ɾ����ʾ
	char name_temp[12];
	printf("��������Ҫɾ������ϵ�ˣ�");
	getchar();
	gets(name_temp);
	for(int j=0; j<per_i; j++){
		if(strcmp(name_temp,Per[j].name)==0){
			if(j==per_i-1){
				per_i--;
			}
			else{
				per_i--;
				for(int k=j; k<per_i; k++){
					Per[k]=Per[k+1];
				}
			}
		}
	}
	fun();		
}

void fun()
{
	printf("����������ѡ��");
	//ѡ����ʵ��
	loop: int x;
	scanf("%d", &x);
	switch(x){
			case 1:Get();break;
			case 2:Show();break;
			case 3:Check();break;
			case 4:Add();break;
			case 5:Delete();break;
			case 6: exit(0);break;
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
	printf("*   1.���������ϵ��                           2.��ʾ��ϵ��  *\n");
	printf("*   3.��ѯ��ϵ��                               4.������ϵ��  *\n");
	printf("*   5.ɾ����ϵ��                               6.ǧ���ѡ    *\n");
	printf("**************************************************************\n");
	fun();
}
	

int main()
{
	//�˵�
	Menu();
}
