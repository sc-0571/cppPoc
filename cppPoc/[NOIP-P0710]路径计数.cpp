#include<bits/stdc++.h>
using namespace std;
#define mod 100003
int a[1011][1011];
bool b[1011][1011];
int n,m;
int main()
{
	memset(b,0,sizeof(b));
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		b[x][y]=1;
	}
	a[1][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==1&&j==1)continue;
			a[i][j]=(a[i-1][j]+a[i][j-1])%mod;
			if(b[i][j]==1)a[i][j]=0;
		}
	printf("%d",a[n][n]);		
}
