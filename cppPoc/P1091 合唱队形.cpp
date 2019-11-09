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
		c[i]=1;//错误点3:不是对b[i]进行初始化,而是对c[i]进行初始0赋值 
		for(int j=i+1;j<=n;j++)
			if((a[j]<a[i])&&(c[j]+1>c[i]))//错误点1:不是b[j]+1>b[i];而是c[j]+1>c[i]
			//错误点2:从后往前应是越来越小,所以应填小于号
			//错误点4:对于比较,应是a[j]在前,a[i]在后 
				c[i]=c[j]+1;
	}
	int maxx=0;
	for(int i=1;i<=n;i++)
		if(b[i]+c[i]>maxx)
			maxx=b[i]+c[i];
	cout<<n-maxx+1<<endl;
} 
