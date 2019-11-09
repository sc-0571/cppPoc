#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
int main()
{
	long n,i,j,x,f[100],c[100],a[100][100];
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	cin>>n;
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	    cin>>a[i][j];
	for(i=1;i<=n;i++)
	  f[i]=1000000;
	f[n]=0;
	for(i=n-1;i>=1;i--)
	  for(x=i+1;x<=n;x++)
	    if((a[i][x]>0)&&(f[x]!=1000000)&&(f[i]>a[i][x]+f[x]))
		{
			f[i]=a[i][x]+f[x];
			c[i]=x;
		} 
	cout<<"minlong="<<f[1]<<endl;
	x=1;
	while(x!=0)
	{
		cout<<x<<' ';
		x=c[x];
	}
	cout<<endl;
}
