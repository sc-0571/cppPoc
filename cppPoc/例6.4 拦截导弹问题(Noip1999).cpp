#include<iostream> 
#include<cstring>
using namespace std;
int a[1001];//导弹飞来时的高度 
int l[1001];//拦截导弹最低高度 
int main()
{
	memset(a,0,sizeof(a));
	memset(l,0,sizeof(l));
	int n;//n表示一共有几个导弹 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int k=1;//拦截导弹系统数
	int p,j=1;
	l[k]=a[1];//令第一个导弹飞行的高度为最小高度 
	for(int i=2;i<=n;i++) 
	{
		p=0;//注意每次循环时需要p=0 
		for(int j=1;j<=k;j++)//注意,j<=k 
		{
			if(l[j]>=a[i])
			{
				if(p==0) p=j;
				else if(l[p]>l[j]) p=j;//应该应将最小值赋值给最小拦截系统 
			}
		}
		if(p==0)
		{
			k++;//如果发现a[i]>l[j],则应该增加一个系统 
			l[k]=a[i];//更新新系统的最小值 
		}
		else l[p]=a[i];//更新原系统的拦截最小值 
	}
	cout<<k<<endl;
	return 0;
}

