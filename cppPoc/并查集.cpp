#include<bits/stdc++.h>
using namespace std;
int father[10001];
int m,n,i,j,x,y,q;
int find(int x)
{
	if(father[x]!=x)father[x]=find(father[x]);
	return father[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)father[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&q,&x,&y);
		if(q==1)
		{
			int r1=find(x),r2=find(y);
			if(r1!=r2)father[r2]=r1;
		}
		if(q==2)
		{
			if(find(x)==find(y))printf("Y\n");
			else printf("N\n");
		}
	}
}
