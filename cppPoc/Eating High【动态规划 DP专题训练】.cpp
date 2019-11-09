#include<bits/stdc++.h>
using namespace std;
long long dp[101][20001];
int c[101];
double e[101];
string s;
int main()
{
	int n,m;scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)cin>>s>>c[i]>>e[i];
	for(int i=1;i<20001;i++)dp[0][i]=0x3f3f3f3f;//初始设为无限大 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m*1000;j++)//由于后有3位小数,此处乘1000即可化为整数
		{
			int cj=j-(int)(e[i]*1000+0.5);//对e[i]进行四舍五入 
			if(cj<0)cj=0;//如果cj<(int)(e[i]*1000+0.5),就将cj等于0
			dp[i][j]=min(dp[i-1][j],dp[i][cj]+1000*c[i]);//不取与取的选择(完全背包)
		}
	cout<<dp[n][m*1000]/1000<<endl;//把最后一项dp输出即可
}
