#include<bits/stdc++.h>
using namespace std;
long long f[5000005],a[5000005][2],n,d,k,ok,l,r;
bool check(int g)
{
	l=d-g,r=d+g;
	if(l<0)l=1;
	memset(f,-127,sizeof(f)),f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=i-1;j>=0;j--)
		{
			if(a[i][0]-a[j][0]<l)continue;
			if(a[i][0]-a[j][0]>r)break;
			f[i]=max(f[i],f[j]+a[i][1]);
			if(f[i]>=k)return 1;
		}
	return 0;
}
int main()
{
  int i,ans=-1,l,r,m;
  scanf("%lld%lld%lld",&n,&d,&k);
  for(i=1;i<=n;i++)scanf("%lld%lld",&a[i][0],&a[i][1]);
  l=0,r=1005,m=(l+r)/2;
  while(l<=r)
  {
  	if(check(m)){ans=m;r=m-1;}
    else l=m+1;
    m=(l+r)/2;
  }
  cout<<ans;
  return 0;
}
