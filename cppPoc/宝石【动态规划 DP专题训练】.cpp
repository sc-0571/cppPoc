#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 210000000
struct qwq{int st,ed;ll v;int id;}ee[1010];
int n,m;
bool f[1010];
int num[1010],nnn=0;
struct qaq{int y,nt;ll v;}e[3000];
int len=0,rev[3000],lin[50];
ll ans;
int level[50],q[50],s,t;
bool mycmp(qwq aa,qwq bb){return aa.v>bb.v||(aa.v==bb.v&&aa.id<bb.id);}
void insert(int x,int y,ll v)
{
	len++;e[len].v=v,e[len].y=y;
	e[len].nt=lin[x];lin[x]=len;rev[len]=len+1;
	len++;e[len].v=0;e[len].y=x;
	e[len].nt=lin[y];lin[y]=len;rev[len]=len-1;
}
bool make_level()
{
	memset(level,-1,sizeof(level));
	int head=0,tail=1;
	q[tail]=s;level[s]=0;
	while(head++<tail)
	{
		int x=q[head];
		for(int i=lin[x];i;i=e[i].nt)
			if(e[i].v&&level[e[i].y]==-1)
			{
				level[e[i].y]=level[x]+1;
				q[++tail]=e[i].y;
			}
	}
	return level[t]>=0;
}
ll max_flow(int k,ll flow)
{
  if(k==t) return flow;
  ll d=0,maxn=0;
  for(int i=lin[k];i&&(maxn<flow);i=e[i].nt)
    if(e[i].v&&level[e[i].y]==level[k]+1)
      if(d=max_flow(e[i].y,min(e[i].v,flow-maxn)))
      	maxn+=d,e[i].v-=d,e[rev[i]].v+=d;
  if(!maxn) level[k]=-1;
  return maxn;
}

ll dinic()
{
    ll tv=0;
    ll td=0;
    while(make_level())
        while(td=max_flow(s,INF))
            tv+=td;
    return tv;
}
void cut_line()
{
  sort(ee+1,ee+1+m,mycmp);
  int cnt=0;
  memset(f,0,sizeof(f));
  for(int i=1;i<=m;i++)
  {
    f[ee[i].id]=1;
    memset(e,0,sizeof(e));
    memset(lin,0,sizeof(lin));
    len=0;
    for(int i=1;i<=m;i++)
    {
      if(f[ee[i].id]) continue;
      insert(ee[i].st,ee[i].ed,ee[i].v);
    }
    int tmp=dinic();
    if(tmp+cnt+ee[i].v==ans)
    {
      cnt+=ee[i].v;
      num[++nnn]=ee[i].id;
    }
    else f[ee[i].id]=0;
  }
}

int main()
{
  scanf("%d%d",&n,&m);
  s=1;t=n;
  for(int i=1;i<=m;i++)
  {
    scanf("%d%d",&ee[i].st,&ee[i].ed);
    scanf("%lld",&ee[i].v);
    ee[i].id=i;
    insert(ee[i].st,ee[i].ed,ee[i].v*1001+1);
  }
  ans=dinic();
  printf("%lld %lld\n",ans/1001,ans%1001);
  ans/=1001;
  cut_line();
  sort(num+1,num+1+nnn);
  for(int i=1;i<=nnn;i++) printf("%d\n",num[i]);
}
