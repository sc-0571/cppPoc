#include<bits/stdc++.h>
using namespace std;
struct node{int s,e,v;}s[500005];
vector<int>tim[500005];
int dp[500005];
int main()
{
	int n,T,cnt=0;
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)
	{
		int q;scanf("%d",&q);
		while(q--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(b>T)continue;
			s[++cnt].s=a;s[cnt].e=b,s[cnt].v=c;;
			tim[b].push_back(cnt);
		}
	}
	for(int i=1;i<=T;i++)
	{
		dp[i]=dp[i-1];
		if(tim[i].size())
		for(int j=0;j<=tim[i].size()-1;j++)
		{
			int u=tim[i][j];
      dp[i]=max(dp[i],dp[i-(s[u].e-s[u].s+1)]+s[u].v);
		}
	}
	cout<<dp[T]<<endl;
	
}
