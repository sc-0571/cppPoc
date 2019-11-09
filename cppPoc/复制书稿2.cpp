#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int x,y,i,j,m,n,k,t,l;
int a[501],f[501][501],d[501];
int maxl(int x,int y)
{
	if(x>y)return x;
	else return y;
} 
int print(int i,int j)
{
	int t,x;
	if(j==0)return 0;
	if(j==1)
	{
		cout<<1<<" "<<i<<endl;
		return 0; 
	}
	t=i;x=a[i];
	while(x+a[t-1]<=f[k][m])
	{
		x+=a[t-1];
		t--;
	}
	print(t-1,j-1);
	cout<<t<<" "<<i<<endl;
}
int main()
{
	cin>>m>>k;
	for(i=0;i<=500;i++)
	  for(j=1;j<=500;j++)
	    f[i][j]=10000000;
	for(j=1;j<=m;j++)
	{
		cin>>a[j];
		d[j]=d[j-1]+a[j];
		f[1][j]=d[j];
	} 
	for(i=2;i<=k;i++)
	  for(j=1;j<=m;j++)
	    for(l=1;l<=j-1;l++)
	      if(maxl(f[i-1][l],d[j]-d[l])<f[i][j])
	        f[i][j]=maxl(f[i-1][l],d[j]-d[l]);
	print(m,k);
} 
