#include<bits/stdc++.h>
using namespace std;
int a[101],b[101],c[101];
int main()
{
	int n;
	cin>>n;
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		b[i]=1;
		for(int j=1;j<=i-1;j++)
			if((a[i]>a[j])&&(b[j]+1>b[i]))
				b[i]=b[j]+1;
	}
	for(int i=n;i>=1;i--)
	{
		c[i]=1;//�����3:���Ƕ�b[i]���г�ʼ��,���Ƕ�c[i]���г�ʼ0��ֵ 
		for(int j=i+1;j<=n;j++)
			if((a[j]<a[i])&&(c[j]+1>c[i]))//�����1:����b[j]+1>b[i];����c[j]+1>c[i]
			//�����2:�Ӻ���ǰӦ��Խ��ԽС,����Ӧ��С�ں�
			//�����4:���ڱȽ�,Ӧ��a[j]��ǰ,a[i]�ں� 
				c[i]=c[j]+1;
	}
	int maxx=0;
	for(int i=1;i<=n;i++)
		if(b[i]+c[i]>maxx)
			maxx=b[i]+c[i];
	cout<<n-maxx+1<<endl;
} 
