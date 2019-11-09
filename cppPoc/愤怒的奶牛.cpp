#include<bits/stdc++.h>
using namespace std; 
int n,k,a[50001],l,r,ans;
int main()
{
  scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
  l=0,r=a[n];
  while(l<=r)
	{
    int mid=(l+r)/2,p=-0x3f,t=0;
		bool chenggong=0;
    for(int i=1;i<=n;i++)
		{
    	if(a[i]-p>2*mid)t++,p=a[i];
      if(t>k){chenggong=1;break;}
    }
    if(chenggong==0)r=mid-1,ans=mid;
		else l=mid+1;
  }
  printf("%d",ans);
}
