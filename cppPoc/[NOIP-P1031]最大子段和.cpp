#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int maxn=a[0],tmp;
	for(int i=1;i<=n;i++)
	{
		if(tmp>0)tmp+=a[i];
		else tmp=a[i];
		maxn=max(maxn,tmp);
	}
	if(maxn==0){cout<<-100;return 0;}
	cout<<maxn;
}
