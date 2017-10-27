#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    NODE *pLeft;
    NODE *pRight;
    int nMaxLeft;
    int nMaxRight;
    char chValue;
};

int nMaxLen = 0;

void FindMaxLen(NODE* root)
{
	//�ݹ����
    if(root==NULL)    return;
    
    //����Ϊ��
    if(root->pLeft==NULL)
        root->nMaxLeft=0;
	
    //����Ϊ��
    if(root->pRight==NULL)
        root->nMaxRight=0;
	
    //������Ϊ��
    if(root->pLeft!=NULL)
    {
        FindMaxLen(root->pLeft);
    }
	
    //������Ϊ��
    if(root->pRight!=NULL)
    {
        FindMaxLen(root->pRight);
    }
	
    //��������������
    if(root->pLeft!=NULL)
    {
        int nTempMax=0;
        if(root->pLeft->nMaxLeft>root->pLeft->nMaxRight)
            nTempMax=root->pLeft->nMaxLeft;
        else
            nTempMax=root->pLeft->nMaxRight;
        root->nMaxLeft=nTempMax+1;
    }
	
    //��������������
    if(root->pRight!=NULL)
    {
        int nTempMax=0;
        if(root->pRight->nMaxLeft>root->pRight->nMaxRight)
            nTempMax=root->pRight->nMaxLeft;
        else
            nTempMax=root->pRight->nMaxRight;
        root->nMaxRight=nTempMax+1;
    }
	
    //����������
    if(root->nMaxLeft>=root->nMaxRight)
        nMaxLen=root->nMaxLeft;
    else
        nMaxLen=root->nMaxRight;
}

NODE* InitTree()
{
	int i;
	
    NODE* tree[50];
    
    for(int i=0;i<50;i++)
    {
        tree[i]=(NODE*)malloc(sizeof(NODE));
        tree[i]->nMaxLeft=0;
        tree[i]->nMaxRight=0;
        tree[i]->pLeft=NULL;
        tree[i]->pRight=NULL;
        tree[i]->chValue=(char)i;
    }
    for(i=0;i<=23;i++)
    {
        tree[i]->pLeft=tree[2*i+1];
        tree[i]->pRight=tree[2*i+2];
    }
    return tree[0];
}

int main()
{
	FindMaxLen(InitTree());
	printf("%d\n",nMaxLen);
    return 0;
}
