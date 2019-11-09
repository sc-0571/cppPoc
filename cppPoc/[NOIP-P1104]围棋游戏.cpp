#include<bits/stdc++.h>
using namespace std;
int dx[9]={0,1,-1,0,0,-1,-1,1,1},
		dy[9]={0,0,0,-1,1,-1,1,-1,1};
int n,m,a[501][501],cnt=0,f[501*501];
int father(int x)
{
  if(f[x]==x)return x;
  return f[x]=father(f[x]);
}
int main()
{
  memset(a,255,sizeof a);
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
  {
    int c,x,y;
    scanf("%d%d%d",&c,&x,&y);
    a[x][y]=c;cnt++;
    int temp=(x-1)*n+y,xx=-1,yy=1;f[temp]=temp;
    for(int j=1;j<=4;j++)
    {
      int tx=x+dx[j],ty=y+dy[j];
      if(tx<0||tx>n||ty<0||ty>n)continue;
      if(a[tx][ty]==a[x][y])
      {
        xx=tx,yy=ty;int temp2=(xx-1)*n+yy;
        int r1=father(temp2),r2=father(temp);
        if(r1!=r2)f[r1]=r2,cnt--;
      }
    }
    printf("%d\n",cnt);
  }
}
