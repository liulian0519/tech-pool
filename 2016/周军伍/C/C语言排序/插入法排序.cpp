/* ���뷨����*/ 

#include <stdio.h>
#include<stdlib.h>

//���������� 
void CrSort(int arr[], int n) 
{
	int i, j, temp;
	for(i=1;i<n;i++){		//ÿ����һ����Ϊ��׼�� ����ǰ��ıȻ�׼������Ƶ�����ȥ
		temp=arr[i];
		for(j=i; j>0 && arr[j-1]>temp; j--)	
			arr[j]=arr[j-1];
		arr[j]=temp;
	}
}


int main() 
{ 	
	int i, n;
	int *arr;
	printf("���������������"); 
	while(scanf("%d",&n)!=EOF){
		arr=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++){	
			scanf("%d",&arr[i]);
		}

		CrSort(arr, n);
		
		//������ź�������� 
		for(i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n");
		free(arr);
	}
	return 0;
	system("pause");
}
