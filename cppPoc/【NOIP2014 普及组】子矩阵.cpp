#include<bits/stdc++.h>
using namespace std;
int n,m,r,c;
int a[20][20],f[20][20],sum[20],d[20],s[20][20];
int main()
{
	int t,o=0,ans=0x3f3f3f3f;
	cin>>n>>m>>r>>c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=1;i<(1<<n);i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)if(!!(i& (1<<j-1)))d[++cnt]=j;
		if(cnt!=r)continue;
		for(int j=1;j<=m;j++)
		{
      sum[j]=0;
      for(int k=1;k<=r-1;k++)sum[j]+=abs(a[d[k]][j]-a[d[k+1]][j]);
    }
    for(int j=1;j<=m;j++)
    	for(int k=j+1;k<=m;k++)
    	{
        s[j][k]=0;
        for(int l=1;l<=r;l++)s[j][k]+=abs(a[d[l]][j]-a[d[l]][k]);
      }
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    for(int j=1;j<=c;j++)
      for(int k=1;k<=m;k++)
			{
        int tot=0;
        for(int l=0;l<=k-1;l++)f[j][k]=min(f[j][k],f[j-1][l]+s[l][k]+sum[k]);
    	}
    for(int j=1;j<=m;j++)ans=min(ans,f[c][j]);
	}
	cout<<ans;
}
