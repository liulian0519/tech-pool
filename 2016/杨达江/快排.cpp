#include<stdio.h>
#define N 50
int Arr[N];
Quick_Sort(int left,int right)
{
	if(left>right) return 0;
	int i,j,t,temp;
	temp=Arr[left];
	i=left;
	j=right;
	while(i!=j)
	{
		while(i<j&&Arr[j]>=temp)//  �ҽϴ�λ�� 
		{
			j--;
		}
		while(i<j&&Arr[i]<=temp)  // �ҽ�Сλ�� ��ע��Ⱥţ�����Ⱥſɲ��ӣ��������ӣ�   
		{
			i++;
		}
	    if(i<j)     //  ���� 
	    {
	    	t=Arr[i]; 
            Arr[i]=Arr[j]; 
            Arr[j]=t; 
		}
	}   //  ���м�ֵ 
	Arr[left]=Arr[i];
	Arr[i]=temp;
	Quick_Sort(left,i-1);  //  �ݹ���� 
	Quick_Sort(i+1,right);  //  �ݹ��ұ� 
}
int main()
{
	int n;
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&Arr[i]);
	Quick_Sort(1,n);
	for(i=1;i<=n;i++) printf("%d ",Arr[i]);
	return 0;
 }
