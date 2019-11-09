#include <cstdlib>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N=25000+10;
const int M=65000+10;
int head[N],
    v[M],w[M],
    nxt[M],
    eid;
void addedge(int a,int b,int c){
  v[eid]=b;w[eid]=c;
  nxt[eid]=head[a];
  head[a]=eid;
  eid++;
}
int t,c,ts,te;
int rs,re,ci;
int dis[N],inq[N];
void spfa(){
  for(int i=0;i<N;i++)dis[i]=1<<30;
  queue<int> q;
  q.push(ts);inq[ts]=1;
  dis[ts]=0;
  while(!q.empty()){
    int t=q.front();q.pop();inq[t]=0;
    for(int i=head[t];i!=-1;i=nxt[i]){
      if(dis[v[i]]>dis[t]+w[i]){
        dis[v[i]]=dis[t]+w[i];
        if(!inq[v[i]]){
          q.push(v[i]);
          inq[v[i]]=1;
        }
      }
    }

  } 
}

int main(int argc, char *argv[])
{      
    memset(head,-1,sizeof(head));
    cin>>t>>c>>ts>>te;
    for(int i=0;i<c;i++)
		{
      cin>>rs>>re>>ci;
      addedge(rs,re,ci);
      addedge(re,rs,ci);
    }
    spfa();

    cout<<dis[te]<<endl;
    return 0;
}
