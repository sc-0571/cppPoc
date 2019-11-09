#include<bits/stdc++.h>
using namespace std;
int k,f[110];
int main()
{
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=10;i++)cin>>f[i];
	cin>>k;
	for(int i=2;i<=k;i++)
		for(int j=1;j<i;j++)
			f[i]=min(f[i],f[j]+f[i-j]);
	printf("%d\n",f[k]);
	return 0;
}

