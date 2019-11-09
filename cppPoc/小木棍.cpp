#include<bits/stdc++.h>
using namespace std;
int n=0,sum=0,n,maxa,mina=70,a[70];
void pd(int rest,int lei,int ans,int can)
{
	if(rest==0){printf("%d",ans);exit(0);}
	if(lei==ans){pd(rest-1,0,ans,maxa);return;}
	for(int i=can;i>=mina;i--)
		if((a[i])&&(i+lei<=ans))
	  {
			a[i]--,pd(rest,lei+i,ans,i),a[i]++;
			if(lei==0||(i+lei==ans))break;
	  }
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int x;scanf("%d",&x);
		if(x<=50)
		{
			a[x]++,sum+=x;
			maxa=max(x,maxa),mina=min(x,mina);
		}
	}
	for(int i=maxa;i<=sum>>1;i++)
	 if(sum%i==0)pd(sum/i,0,i,maxa);
  printf("%d",sum);
}
