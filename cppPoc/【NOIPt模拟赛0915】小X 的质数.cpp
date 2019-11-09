#include<bits/stdc++.h>
using namespace std;
int q,l,r;
long long flag[1000005],prime[1000005],tot,ans,vis[1000005],vis2[1000005],maxn,sum[1000005];
int main()
{
	scanf("%d",&q);
	for(int o=1;o<=q;o++)
	{
		scanf("%d%d",&l,&r);
		maxn=r;
		for(int i=2;i<=maxn;i++)
		{
			if(!flag[i])prime[++tot]=i,vis[i]=1;
			for(int j=1;j<=tot;j++)
			{
				int t=i*prime[j];
				if(t>maxn)break;
				flag[t]=1;
				if(vis[i])vis2[t]=1;
				if(i%prime[j]==0)break;
			}
		}
		for(int i=2;i<=maxn;i++)
  	{
    	if(vis[i])sum[i]=sum[i-1]+vis[i];
    	else sum[i]=sum[i-1]+vis2[i];
 		}
  	printf("%lld\n",sum[r]-sum[l-1]);
	}
}
