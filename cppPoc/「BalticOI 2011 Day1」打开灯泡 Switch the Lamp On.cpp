#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
	bool operator<(const node &b)const{return z>b.z;}
}l;
priority_queue<node>d;
int dx[4]={1,1,-1,-1},
		dy[4]={1,-1,1,-1};
int n,m,x,y,a[501][501];
char s[501][501];
int main()
{
	memset(a,63,sizeof(a));
	scanf("%d%d",&n,&m);
	l=(node){a[0][0]=0,0,0};
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(d.push(l);d.size();d.pop())
		for(int i=0;i<4;i++)
		{
			x=d.top().x+dx[i];
			y=d.top().y+dy[i];
			if(x<0||x>n||y<0||y>m)continue;
			l.x=x,l.y=y,l.z=d.top().z;
			l.z+=((i==0&&s[x][y]=='/')||(i==1&&s[x][y+1]=='\\')||(i==2&&s[x+1][y]=='\\')||(i==3&&s[x+1][y+1]=='/'));
			if(a[x][y]>l.z)
			{
				a[x][y]=l.z;d.push(l);
				if(x==n&&y==m){printf("%d\n",l.z);return 0;}
			}
		}
	cout<<"NO SOLUTION"<<endl;
}

