#include<bits/stdc++.h>
using namespace std;
int m,s,t;
int z[300005],f[300005];
int main()
{
	scanf("%d%d%d",&m,&s,&t);
	for(int i=1;i<=t;i++)
	{
		if(m>=10)z[i]=z[i-1]+60,m-=10;
		else z[i]=z[i-1],m+=4; 
	}
	for(int i=1;i<=t;i++)
	{
		f[i]=max(f[i-1]+17,z[i]);
		if(f[i]>=s){printf("Yes\n%d",i);return 0;}
	}
	printf("No\n%d",f[t]);
}
