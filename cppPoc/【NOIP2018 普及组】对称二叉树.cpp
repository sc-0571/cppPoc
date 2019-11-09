#include<bits/stdc++.h>
using namespace std;
int l[1000001],r[1000001],m,a[1000001],ans=1;
bool f;
int dfs(int x,int y,int s)
{
	if(x==1&&y==-1)return 0;
	if(x==1||y==1&&x!=y){f=1;return 0;}
	if(a[x]!=a[y]){f=1;return 0;}
	return dfs(l[x],r[y],2)+dfs(r[x],l[y],2)+s;
}
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d%d",&l[i],&r[i]);
	for(int i=1;i<=m;i++)
	{
		int s=dfs(l[i],r[i],3);
		if(s>ans&&f==0)ans=s;
		f=0;
	}
	printf("%d",ans);
}
