#include<bits/stdc++.h>
using namespace std;
int n,m,a[11];
bool b[11];

int dfs(int k)
{
	for(int i=a[k-1]+1;i<=n;i++)
		if(!b[i])
		{
			a[k]=i;
			b[i]=1;
			if(k==m)
			{
				for(int i=1;i<=m-1;i++)
					cout<<a[i]<<" ";
				cout<<a[m]<<endl;
			}
			else dfs(k+1);
			b[i]=0;
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	dfs(1);
}
