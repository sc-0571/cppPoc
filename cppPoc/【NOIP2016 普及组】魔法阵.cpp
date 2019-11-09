#include<bits/stdc++.h>
int cnt[16000],a[40005],s[16000],n,m;
int a1[40005],b1[40005],c1[40005],d1[40005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=1;i*9<n;i++)
	{
		memset(s,0,sizeof(s));
		for(int j=2*i+1;j<=n-7*i-1;j++)s[j]=cnt[j-2*i]*cnt[j];
		for(int j=1;j<=n;j++)s[j]+=s[j-1];
		for(int j=9*i+1;j<=n;j++)d1[j]+=s[j-7*i-1]*cnt[j-i];
		for(int j=7*i+1;j<=n-i;j++)c1[j]+=s[j-6*i-1]*cnt[j+i];
		memset(s,0,sizeof(s));
		for(int j=9*i+1;j<=n;j++)s[j]=cnt[j-i]*cnt[j];
		for(int j=n;j>=1;j--)s[j]+=s[j+1];
		for(int j=2*i+1;j<=n-7*i-1;j++)b1[j]+=s[j+7*i+1]*cnt[j-2*i];
		for(int j=1;j<=n-9*i-1;j++)a1[j]+=s[j+9*i+1]*cnt[j+2*i];
	}
	for(int i=1;i<=m;i++)printf("%d %d %d %d\n",a1[a[i]],b1[a[i]],c1[a[i]],d1[a[i]]);
}
