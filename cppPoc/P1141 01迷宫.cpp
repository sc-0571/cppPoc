#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,0,-1,1},
		dy[4]={1,-1,0,0};
char map1[1001][1001];
int flag[1001][1001],a[1000001];
struct mg{
  int x,y;
}q[1000001];
int main()
{
  int sx,sy,i,j,n,m,l,nx,ny,k,f,r,sum,d;
  scanf("%d %d",&n,&m);
  memset(a,0,sizeof(a));
  memset(flag,0,sizeof(flag));
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      cin>>map1[i][j];
  d=0;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      if(flag[i][j]==0)
      {
        d++,f=1,r=1;
      	q[f].x=i,q[f].y=j,flag[i][j]=d;
        sum=1;
        while(f<=r)
        {
    			for(k=0;k<4;k++)
          {
            nx=q[f].x+dx[k];
            ny=q[f].y+dy[k];
          	if(flag[nx][ny]==0&&nx>=1&&nx<=n&&ny>=1&&ny<=n&&((map1[nx][ny]=='1'&&map1[q[f].x][q[f].y]=='0')||(map1[nx][ny]=='0'&&map1[q[f].x][q[f].y]=='1')))
            {
              r++,sum++;
              flag[nx][ny]=d;
              q[r].x=nx;
          		q[r].y=ny;
            }
          }
          f++;
      	}
        a[d]=sum; 
      }
  for(i=1;i<=m;i++){cin>>sx>>sy;cout<<a[flag[sx][sy]]<<endl;}
  return 0;
}
