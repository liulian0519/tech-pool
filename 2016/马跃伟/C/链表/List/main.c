#include "list.h"
int main() {
    struct LNode MessageBoard;
    MessageBoard.Next = NULL;
    MessageBoard.Data = "����˧";
    List PrtL;
    PrtL = &MessageBoard;
    int a;
    do {
        printf("                      ���԰�                          \n");
        printf("******************************************************\n");
        printf("                     ��ѡ����                        \n");
        printf("        1.�鿴��������                                 \n");
        printf("        2.�鿴һ������                                 \n");
        printf("        3.дһ������                                   \n");
        printf("        4.�޸�һ������                                 \n");
        printf("        5.ɾ��һ������                                 \n");
        printf("        0.�˳�                                         \n");
        printf("******************************************************\n");
        scanf("%d", &a);
        switch (a) {
            case 1:
                show_all(PrtL);
                break;
            case 2:
                show_one(PrtL);
                break;
            case 3:
                wirte_one(PrtL);
                break;
            case 4:
                change_one(PrtL);
                break;
            case 5:
                delete_one(PrtL);
                break;
        }
    } while (a != 0);
    return 0;
}


