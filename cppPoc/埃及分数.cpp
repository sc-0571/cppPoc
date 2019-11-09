#include<bits/stdc++.h>
using namespace std;
int a,b,len;
long long minn=1e9,s[105],ans[105];
void dfs(int k,long long m,long long x,long long y)
{
	if(k>len)
	{
		if(x==0&&s[len]<minn)
		{
			for(long long i=1;i<=len;i++)ans[i]=s[i];
			minn=s[len];
		}
		return;
	}
	long long l=max(m+1,y/x),r=y/x*(len-k+1);
	for(long long i=l;i<=r;i++)
	{
		long long nx=x*i-y,ny=y*i;
		if(nx<0)continue;
		s[k]=i,dfs(k+1,i,nx,ny);
	}
}
int main()
{
	scanf("%d%d",&a,&b);
	for(len=2;;len++)
	{
		dfs(1,1,a,b);
		if(minn<1e9)break;
	}
	for(long long i=1;i<=len;i++)printf("%lld ",ans[i]);
}
