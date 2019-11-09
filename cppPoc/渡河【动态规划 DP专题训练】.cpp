#include<bits/stdc++.h>
using namespace std;
struct node{int x,y;}temp[2004];
int cmp(node a,node b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int main()
{
  int n,dp[2004];
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d%d",&temp[i].x,&temp[i].y);
    dp[i]=1;
  }
  sort(temp,temp+n,cmp);
  for(int i=0;i<n;i++)
    for(int j=0;j<=i;j++)
      if(temp[i].y>temp[j].y&&dp[i]<dp[j]+1)
        dp[i]=dp[j]+1;
  int cnt=0;
  for(int i=0;i<n;i++)if(cnt<dp[i])cnt=dp[i];
  printf("%d\n",cnt);
}
