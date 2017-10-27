#include "list.h"
int Length(List PtrL) //���
{
    List p =PtrL;
    int j = 0;
    while(p){
        p = p->Next;
        j++;
    }
    return j;
}

List FindKth(int K,List PtrL) //�ҳ���K��Ԫ�ص�λ��
{
    List p = PtrL;
    int i = 1;
    while(p != NULL && i < K){
        p = p->Next;
        i++;
    }
    if (i == K) return p;   //�ڶ�����������ѭ��,�ҵ���
    else return NULL;       //������,û�ҵ�,
}

List Find(ElementType a ,List PtrL) //�ҵ���һ��ֵΪa�������λ��
{
    List  p = PtrL;
    while(p != NULL && p->Data!=a )
        p = p->Next;
    return p;
}

List Insert(ElementType X, int i,List PtrL) //�ڵ�i��λ�ò���һ��ֵΪX�Ľڵ�.
{
    List p,s;
    if (i == 1)                                              //�����ڱ�ͷ
    {
        s = (List)malloc(sizeof(struct LNode));             //����ռ�,д������
        s ->Data = X;
        s ->Next = NULL;
        return s;                                               //�����µ�ͷָ��
    }
    p = FindKth(i-1,PtrL);
    if (p == NULL)
    { printf("��������.");
        return NULL;
    } else{
        s = (List)malloc(sizeof(struct LNode));             //����ռ�,д������
        s ->Data = X;
        s ->Next = p ->Next;                                  //�½ڵ�����ڵ�i-1�����ĺ���
        p ->Next = s;
        return PtrL;
    }
}

List Delete(int i,List PtrL)   //ɾ����i�����
{
    List  p,s;
    if( i == 1){                                //���ɾ������ͷ���
        s =PtrL ;
        if(PtrL != NULL) PtrL = PtrL->Next;
        else return NULL;
        free(s);
        return PtrL;
    }
    p = FindKth(i-1,PtrL);                      //��Ҫɾ���ĵĽ���ǰһ������λ��Ϊp
    if (p == NULL) {
        printf("�Ҳ�����%d�����", i - 1);
        return NULL;
    }else if(p->Next == NULL) {
        printf("�Ҳ�����%d�����", i - 1);
        return NULL;
    }else{                                    //sָ��Ҫɾ���Ľ��
        s = p->Next;                          //ȥ��Ҫɾ���Ľ��
        p->Next = s->Next;
        free(s);                              //�ͷ�Ҫɾ�������ռ���ڴ�ռ�
        return PtrL;
    }
}

List Chage(ElementType X,int i,List PtrL)  //�޸ĵ�i��λ�õĵ�ֵΪX
{
    List p;
    p = FindKth(i,PtrL);
    if(p == NULL) {
        printf("�Ҳ���%d�����.", i);
        return NULL;
    }
    else{
        p->Data = X;
        printf("�޸ĳɹ�");
        return PtrL;
    }
}

void Show(int i,List PtrL)//�����i��λ�õĽ��
{
    List p;
    p = FindKth(i,PtrL);
    if( p == NULL ){
        printf("�Ҳ���%d�����.", i);
    }else{
        printf("%s",p->Data);
    }

}

void show_all(List PrtL)
{
    while (PrtL != NULL) {
        int i = 1;
        printf("����%d :", i);
        Show(i, PrtL);
        printf("\t__________________________________________________\n");
        PrtL = PrtL->Next;
        i++;
    }}

void show_one(List PrtL) {
    int F;
    printf("�������������\n");
    scanf("%d", &F);
    printf("����%d :", F);
    Show(F, PrtL);
    printf("\t__________________________________________________\n");
}
void wirte_one(List PrtL){
    char temp[81];
    int L;
    printf("����������:");
    gets(temp);
    L = Length(PrtL);
    if (L == 1) PrtL = Insert(temp, 1, PrtL);
    else Insert(temp, L, PrtL);
}
void change_one(List PrtL){
    char temp[81];
    int C;
    printf("������Ҫ�޸����Ե����\n");
    scanf("%d", &C);
    printf("�������޸ĺ������\n");
    gets(temp);
    Chage(temp, C, PrtL);
}
void delete_one(List PrtL){
    int D;
    printf("������Ҫɾ�����������\n");
    scanf("%d", &D);
    Delete(D, PrtL);
}
