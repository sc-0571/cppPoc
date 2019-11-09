#include<bits/stdc++.h>
using namespace std;
int a[101],b[101],c[101],n;
int main()
{
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
		c[i]=1;
		for(int j=i+1;j<=n;j++)
			if((a[i]>a[j])&&c[j]+1>c[i])
				c[i]=c[j]+1; 
	}
	int maxx=0;
	for(int i=1;i<=n;i++)
		if(b[i]+c[i]>maxx)maxx=b[i]+c[i];
	cout<<n-maxx+1;
}
