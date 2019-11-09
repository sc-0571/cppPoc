#include<bits/stdc++.h>
using namespace std;
int s,w,x,y,n,m;
char c[301][301];
bool flag;
void dfs(int x,int y)
{
  if(!c[x][y]){flag=true;return;}
  if(c[x][y]=='#')return;
  if(c[x][y]=='o')s++;
  else if(c[x][y]=='v')w++;
  c[x][y]='#';dfs(x+1,y);dfs(x-1,y);dfs(x,y+1);dfs(x,y-1);
}
int main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>c[i][j];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(c[i][j]!='#')
      {
        flag=0;s=0;w=0;dfs(i,j);
        if(!flag){if(s>w)x+=s;else y+=w;}
      }
  cout<<x<<" "<<y;
}
