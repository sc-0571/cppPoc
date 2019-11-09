#include<bits/stdc++.h>
using namespace std;
int dx[8]={0,0,-1,1,1,1,-1,-1},
		dy[8]={-1,1,0,0,1,-1,-1,1};
struct node{int x,y;node(){}node(int x,int y):x(x),y(y){}}st;
queue<node>q;
char s[101][101];
int n,m,d[101][101];
int main()
{
	scanf("%d%d%d%d",&m,&n,&st.y,&st.x);
	for(int i=n;i>=0;i--)scanf("%s",s[i]+1);
	memset(d,-1,sizeof(d));d[st.x][st.y]=0;
	q.push(st);int ans=0;
	while(!q.empty())
	{
		node t=q.front();q.pop();
		for(int i=0;i<8;i++)
		{
			node nxt=t;
			int x=nxt.x+dx[i],y=nxt.y+dy[i];
			if(x<1||x>n||y<1||y>m||s[x][y]=='*')continue;
			if(d[x][y]==-1)
			{
				d[x][y]=d[t.x][t.y]+1;
				ans=max(d[x][y],ans);
				nxt=node(x,y);
				q.push(nxt);
			}
		}
	}
	printf("%d\n",ans);
}
