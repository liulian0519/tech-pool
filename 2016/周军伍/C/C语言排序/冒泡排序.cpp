/* ð������ */

#include<stdio.h>
#include<stdlib.h>

void MpSort(int *arr, int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++) {		//�����Ƚϣ����������ͽ��������ѭ��һ�Σ���һ����ֵ����ĩβ
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int n, i, *arr;
	printf("����������Ԫ�ظ�����");
	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(n*sizeof(int));
		for (i = 0; i < n; i++)
			scanf("%d", (arr + i));
		//��������
		MpSort(arr, n);

		for (i = 0; i < n; i++)
			printf("%d ", *(arr + i));
		printf("\n");
	}
	return 0;
	system("pause");
}