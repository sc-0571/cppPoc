#include<bits/stdc++.h>
using namespace std;
int n,m,ans,in=1;
int t[10001],k[10001],c[10001];
queue<int>q;
void down(int x)
{
  int u=0;
	char c[11];
  while(x)c[++u]=(x%10)+48,x/=10;
  while(u)cout<<c[u--];
  cout<<"\n";
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>t[i]>>k[i];
		for(int j=1;j<=k[i];++j)
		{
			cin>>m;
			if(c[m]==0)ans++;
			c[m]++,q.push(m);
		}
		while(t[in]+86400<=t[i])
		{
			for(int j=1;j<=k[in];j++)
			{
				c[q.front()]--;
				if(!c[q.front()])ans--;
				q.pop();
			}
			++in;
		}
		down(ans);
	}
}
