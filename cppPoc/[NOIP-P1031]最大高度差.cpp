#include<bits/stdc++.h>
using namespace std;
int n,s,k,a[80][80];
int main()
{
  cin>>n>>s>>k;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>a[i][j];
  int x,y,minn,maxn;
  for(int t=1;t<=k;t++)
  {
    minn=0x7f,maxn=0;
    cin>>x>>y;
    for(int i=x;i<x+s;i++)
      for(int j=y;j<y+s;j++)
      {
        maxn=max(maxn,a[i][j]);
        minn=min(minn,a[i][j]);
      }
    printf("%d\n",maxn-minn);
  }
}
