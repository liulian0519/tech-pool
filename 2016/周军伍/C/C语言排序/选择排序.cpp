/* ѡ������ */

#include<stdio.h>
#include<stdlib.h>

void XzSort(int *arr, int n)
{
	int i, j, temp;		//������ʣ���Ԫ���в�����ֵԪ�أ����뵽����λ��
	for (i = 0; i < n; i++) {	//������ѭ���ҵ�һ����ֵ��Ȼ�󽻻�
		for (j = i+1; j < n; j++) {
			if (arr[i] > arr[j]) {		//j�Ĳ��ҷ�Χʼ������i�ĺ��棬�����ܹ��ҵ���ֵ
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int n, *arr, i;
	printf("����������Ԫ�صĸ�����");
	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(n * sizeof(int));
		
		for (i = 0; i < n; i++)
			scanf("%d", arr + i);
		
		XzSort(arr, n);

		for (i = 0; i < n; i++)
			printf("%d ", *(arr + i));
		printf("\n");
	}
	return 0;
	system("pause");
}