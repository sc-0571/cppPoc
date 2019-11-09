#include<stdio.h>
#include<string.h>
int dp[210],b[210],a[210];
int main()
{
	int i,j,n,m;
	memset(dp,0,sizeof(dp));
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]);
	for(i=1;i<=n;i++)
		for(j=m;j>=a[i];j--)
			if(dp[j]<dp[j-a[i]]+b[i]) dp[j]=dp[j-a[i]]+b[i];
	printf("%d\n",dp[m]);
	return 0;
} 
