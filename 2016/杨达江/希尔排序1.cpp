#include<stdio.h>
shellsort(int Arr[],int n)
{
    int i, j, gap;  
  
    for (gap = n / 2; gap > 0; gap /= 2) //����  
        for (i = 0; i < gap; i++)       //��ͷ��gap��һ���� 
        {  
            for (j = i + gap; j < n; j += gap)   //���������� 
                if (Arr[j] < Arr[j - gap])  
                {  
                    int temp = Arr[j];  
                    int k = j - gap;  
                    while (k >= 0 && Arr[k] > temp)  //�����������ǰ������λ�� 
                    {  
                        Arr[k + gap] = Arr[k];  //����� 
                        k -= gap;  
                    }  
                    Arr[k + gap] = temp;  //���� 
                }  
        }  
}
int main()
{
	int i;
	int arr[10]={10,9,8,7,6,5,4,3,2,1};
	shellsort(arr,10);
	for(i=0;i<10;i++) printf("%d ",arr[i]);
	return 0;
 }
