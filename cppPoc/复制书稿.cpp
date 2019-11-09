#include<bits/stdc++.h>
using namespace std;
int a[501],d[501];
int f[501][501];
int k,m;
void print(int i,int j)
{
	if(j==0)return;
	if(j==1){printf("1 %d\n",i);return;}
	int t=i,x=a[i];
	while(x+a[t-1]<=f[k][m])x+=a[t-1],t--;
	print(t-1,j-1);
	printf("%d %d\n",t,i);
}
int main()
{
	scanf("%d%d",&m,&k);
	memset(f,0x3f,sizeof(f));
	int i,j,l;
	for(j=1;j<=m;j++)
	{
		scanf("%d",&a[j]);
		d[j]=d[j-1]+a[j],f[1][j]=d[j];
	}
	for(i=2;i<=k;i++)
		for(j=1;j<=m;j++)
			for(l=1;l<j;l++)
				f[i][j]=min(f[i][j],max(f[i-1][l],d[j]-d[l]));
	print(m,k);
}

