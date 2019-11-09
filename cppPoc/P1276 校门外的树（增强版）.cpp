#include<bits/stdc++.h>
using namespace std;
int a[10001],ans1,ans2;
int main()
{
  int l,n;
  cin>>l>>n;
  memset(a,1,sizeof(a));
  for(int i=1;i<=n;i++)
  {
    int k,t1,t2;
    scanf("%d%d%d",&k,&t1,&t2);
    if(k==0)
      for(int j=t1;j<=t2;j++)
      {
        if(a[j]==2)ans1++;
        a[j]=0;
      }
    else
      for(int j=t1;j<=t2;j++)
        if(a[j]==0)a[j]=2;
  }
  for(int i=0;i<=l;i++)
    if(a[i]==2)
      ans2++;
  cout<<ans2<<endl<<ans1;
  return 0;
}
