#include<bits/stdc++.h>
using namespace std;
const int M=5e5+7;
int n,m,first[M],cnt,w[M],dep[M],f[M][25];
struct node{int to,next;}e[2*M];
struct pos{int x,s;};
vector<pos>e1[M],e2[M];
int ans1[2*M],ans2[2*M],ans[M];
void ins(int a,int b){e[++cnt]=(node){b,first[a]};first[a]=cnt;}
void insert(int a,int b){ins(a,b);ins(b,a);}
void dfs(int x)
{
  for(int i=1;(1<<i)<=dep[x];i++)f[x][i]=f[f[x][i-1]][i-1];
  for(int i=first[x];i;i=e[i].next)
	{
    int now=e[i].to;
    if(!dep[now])
		{
      dep[now]=dep[x]+1;
      f[now][0]=x;
      dfs(now);
    }
  }
}
int find(int x,int y)
{
  if(dep[x]<dep[y])swap(x,y);
  int d=dep[x]-dep[y];
  for(int i=0;(1<<i)<=d;i++)if(1<<i&d)x=f[x][i];
  if(x==y)return x;
  for(int i=20;i>=0;i--) 
    if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
  return f[x][0];
}
void pans(int x)
{
  ans[x]-=ans1[w[x]+dep[x]];
  ans[x]-=ans2[w[x]-dep[x]+n];
  pos*p=e1[x].data();
  for(int i=0;i<e1[x].size();i++)ans1[p[i].x]+=p[i].s;
  p=e2[x].data();
  for(int i=0;i<e2[x].size();i++)ans2[p[i].x+n]+=p[i].s;
  for(int i=first[x];i;i=e[i].next)
	{
    int now=e[i].to;
    if(f[x][0]==now)continue;
    pans(now);
  }
  ans[x]+=ans1[w[x]+dep[x]];
  ans[x]+=ans2[w[x]-dep[x]+n];
}
int main()
{
	int x,y;scanf("%d%d",&n,&m);
  for(int i=1;i<n;i++)scanf("%d%d",&x,&y),insert(x,y);
  for(int i=1;i<=n;i++)scanf("%d",&w[i]);
  dep[1]=1;dfs(1);
  for(int i=1;i<=m;i++)
	{
  	scanf("%d%d",&x,&y);
    int lca=find(x,y),fa=f[lca][0];
    e1[x].push_back((pos){dep[x],1});
    e1[lca].push_back((pos){dep[x],-1});
    e2[y].push_back((pos){dep[x]-2*dep[lca],1});
    e2[fa].push_back((pos){dep[x]-2*dep[lca],-1});
  }pans(1);
  for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	printf("\n");
}
