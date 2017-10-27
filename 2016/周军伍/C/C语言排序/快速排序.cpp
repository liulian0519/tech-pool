
#include<stdio.h>
#include<stdlib.h>

//��������

int KsSort(int arr[], int left, int right)
{
	int i, k, temp;
	i = left;
	k = right;
	temp = arr[left];
	if (left > right)
		return 0;
	//�ڿ�����
	while (i != k) {
		//�Ӻ���ǰɨ��
		while (temp < arr[k] && i < k)
			k--;
		if (i < k)
			arr[i++] = arr[k];

		while (temp > arr[i] && i < k)
			i++;
		if (i < k)
			arr[k--] = arr[i];
	}
	arr[i] = temp;
	KsSort(arr, left, i - 1);
	KsSort(arr, i+1, right);
}


int main()
{
	int n, i, *arr;
	printf("����������Ԫ�صĸ�����");
	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(n * sizeof(int));

		for (i = 0; i < n; i++)
			scanf("%d", arr + i);

		KsSort(arr, 0, n-1);

		for (i = 0; i < n; i++)
			printf("%d ", *(arr + i));
		printf("\n");
	}
	return 0;
	system("pause");
}