#include<bits/stdc++.h>
using namespace std;
int e[300],s[300][300],n,maxn=-1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){cin>>e[i];e[n+i]=e[i];}
	for(int i=2;i<n*2;i++)
		for(int j=i-1;i-j<n&&j>=1;j--)
		{
			for(int k=j;k<i;k++)
        s[j][i]=max(s[j][i],s[j][k]+s[k+1][i]+e[j]*e[k+1]*e[i+1]);
      if(s[j][i]>maxn)maxn=s[j][i];
		}
	cout<<maxn<<endl;
	return 0;
}
