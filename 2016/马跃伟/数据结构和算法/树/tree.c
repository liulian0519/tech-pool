#include"tree.h"
#include <stdio.h>

void PreOrderTraversal(BinTree BT) //���� --������������������
{
    if(BT)
    {
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}
void InOrderTraversal(BinTree BT) //����---������������������
{
  if(BT)
    {
        PreOrderTraversal(BT->Left);
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Right);
    }
}
void PostOrderTraversal(BinTree BT) //����---������������������
{
    if(BT)
    {
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
        printf("%d",BT->Data);
    }
}
