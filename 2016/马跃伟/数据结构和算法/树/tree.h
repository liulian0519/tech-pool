typedef struct TreeNode *PtrToNode;
struct TreeNode
{
    ElementType Element;    //��ǰ���������
    PtrToNode FirstChild;   //ָ�����ĵ�һ������
    PtrToNode NextSibling;  //ָ��������һ���ֵ�
};

//��������������
typedef struct Treenode *BinTree;
typedef BinTree Position;
struct Treenode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

#ifndef _Tree_H

Boolean IsEmpty(BinTree BT); //�ж϶������Ƿ�Ϊ��
void Traversal(BinTree BT); //����������ĳ��˳�����ÿһ�����
BinTree CreatBinTree(); //����һ��������

void PreOrderTraversal(BinTree BT); //���� --������������������
void InOrderTraversal(BinTree BT); //����---������������������
void PostOrderTraversal(BinTree BT); //����---������������������
void LevelOrderTraversal(BinTree BT); //��α��������ϵ��£�������
void MakeEmpty(BinTree BT); //��ʼ��һ����
#endif
