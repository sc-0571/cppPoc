#include<iostream> 
#include<cstring>
using namespace std;
int a[1001];//��������ʱ�ĸ߶� 
int l[1001];//���ص�����͸߶� 
int main()
{
	memset(a,0,sizeof(a));
	memset(l,0,sizeof(l));
	int n;//n��ʾһ���м������� 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int k=1;//���ص���ϵͳ��
	int p,j=1;
	l[k]=a[1];//���һ���������еĸ߶�Ϊ��С�߶� 
	for(int i=2;i<=n;i++) 
	{
		p=0;//ע��ÿ��ѭ��ʱ��Ҫp=0 
		for(int j=1;j<=k;j++)//ע��,j<=k 
		{
			if(l[j]>=a[i])
			{
				if(p==0) p=j;
				else if(l[p]>l[j]) p=j;//Ӧ��Ӧ����Сֵ��ֵ����С����ϵͳ 
			}
		}
		if(p==0)
		{
			k++;//�������a[i]>l[j],��Ӧ������һ��ϵͳ 
			l[k]=a[i];//������ϵͳ����Сֵ 
		}
		else l[p]=a[i];//����ԭϵͳ��������Сֵ 
	}
	cout<<k<<endl;
	return 0;
}

