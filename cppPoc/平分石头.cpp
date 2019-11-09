#include<bits/stdc++.h>
using namespace std;
long long n,m,d=0,ans=20e9;
long long a[100001];
bool b[100001]={0};
void dfs(long long k,long long d,long long last)
{
	if(k>n||ans==m)return;
	if(abs(ans-m)>abs(d-m))ans=d;
	for(long long i=last+1;i<=n;i++)
		if(!b[i])
			if(i+d<=m||abs(ans-m)>abs(d-m))
			{
				b[i]=1;
				dfs(k+1,d+a[i],i);
				b[i]=0;
			}
}
int main()
{
	cin>>n>>m;
  for(long long i=1;i<=n;i++)cin>>a[i];
  dfs(1,0,0);
  cout<<ans<<endl;
}
