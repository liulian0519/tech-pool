viod insertion_sort(int *Array,int N)   //���� 
{
	int i,temp,p;
	for(i = 1; i < N ; i++)    //�ӵڶ�����ʼ,��ǰ���ź���Ķ���������� 
	{
		temp = a[i];			//�ó���ǰҪ����ı��� 
		p = i - 1;		
		while(p >= 0 && a[p] <temp )	//�Ƚϵ�ͷ�������ҵ���Ҫ����ı���С��Ԫ�� 
		{
			a[p+1] = a[p];
			p--;
		}
		a[p+1] = temp;					//���뵽�ҵĵ�Ԫ�ض����� 
	}
}
