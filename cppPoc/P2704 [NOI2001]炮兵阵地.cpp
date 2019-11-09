#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,s[1005],g[1005],map[103],f[102][1005][1005],ans;
char ma[103];
int get(int x)
{
  int e=0;
  while(x>0){++e;x-=x&(-x);}
  return e;
}
int main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    scanf("%s",ma);
    for(int j=0;j<m;++j)
      if(ma[j]=='H')map[i]+=1<<j;
  }
  for(int i=0;i<=(1<<m)-1;i++)
    if(((i&(i<<1))==0)&&((i&(i<<2))==0)&&((i&(i>>1))==0)&&((i&(i>>2))==0))
    {
      ++k;s[k]=i;
      g[k]=get(i);
      if((i&map[1])==0)f[1][0][k]=g[k];
    }
  for(int i=1;i<=k;i++)
    for(int j=1;j<=k;j++)
      if(((s[i]&s[j])==0)&&((s[j]&map[2])==0))
        f[2][i][j]=max(f[2][i][j],f[1][0][i]+g[j]); 
  for(int i=3;i<=n;i++)
    for(int j=1;j<=k;j++) 
      if((map[i]&s[j])==0)
        for(int p=1;p<=k;p++)
          if((s[p]&s[j])==0)
            for(int q=1;q<=k;q++)
              if(((s[q]&s[p])==0)&&((s[q]&s[j])==0))
                f[i][p][j]=max(f[i][p][j],f[i-1][q][p]+g[j]);
  for(int i=1;i<=k;i++)
    for(int j=1;j<=k;j++)
      ans=max(f[n][i][j],ans);
  cout<<ans<<endl;        
  return 0;
}
