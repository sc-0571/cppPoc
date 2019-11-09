#include<bits/stdc++.h>
using namespace std;
struct node{int x,y;}p[100001];
char mp[1001][1001];
int n,m,sx,sy,b[1001][1001];
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void bfs(int x,int y)
{
	int ans=1,h=0,t=1;
  p[h].x=x,p[h].y=y,b[x][y]=1;
  while(h<t)
  {
  	for(int k=0;k<=3;k++)
    {
      int tx=p[h].x+d[k][0],ty=p[h].y+d[k][1];
      if(tx<1||ty<1||tx>n||ty>n||b[tx][ty]!=0||mp[p[h].x][p[h].y]==mp[tx][ty])continue;
      p[t].x=tx,p[t].y=ty,b[tx][ty]=1;
      ans++,t++;
    }
    h++;
  }
  for(int j=0;j<=t;j++)b[p[j].x][p[j].y]=ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;	j<=n;j++)cin>>mp[i][j];
	for(int i=1;i<=m;i++)
	{
		cin>>sx>>sy;
		if(b[sx][sy]!=0)cout<<b[sx][sy]<<endl;
		else bfs(sx,sy),cout<<b[sx][sy]<<endl;
	}
}//462098663
