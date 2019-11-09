#include<bits/stdc++.h>
using namespace std;
int u[5]={0,0,1,0,-1},
		w[5]={0,1,0,-1,0};
int n,m,dx,dy,sx,sy,h,t,x,y,a[1210],b[1210],c[1210],step;
char mp[11][11];
bool f;

int bfs() {
	h=0,t=1;
		f=0;
		a[t]=sx,b[t]=sy, c[t]=0; 
		mp[sx][sy]='^';
		while(h!=t)
		{
			h++;
			for(int i=1;i<=4;i++)
			{
				x=a[h]+u[i];y=b[h]+w[i];step = c[h];
				if((x>0)&&(x<=n)&&(y>0)&&(y<=m)&&mp[x][y]=='*')
				{
					x+=u[i],y+=w[i];step=c[h];
					if((x>0)&&(x<=n)&&(y>0)&&(y<=m)&&mp[x][y]=='.')
					{
						t++,a[t]=x,b[t]=y;
						mp[x][y]='^';
						c[t]=step+1;
						if((x==dx)&&(y==dy))
						{
							return c[t];
						}
					}
				}
				else if((x>0)&&(x<=n)&&(y>0)&&(y<=m)&&mp[x][y]=='.')
				{
					t++,a[t]=x,b[t]=y;
					mp[x][y]='^';
					c[t] = step + 1;
					if((x==dx)&&(y==dy))
					{
							return c[t];
					}
				}
			}
			
	 }
	 return -1; 
}

int main()
{
	while(scanf("%d%d",&n,&m)&& n>=1 && n<=10 &&m>=1 && m<=10)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				char c='\n';
				while(c=='\n')scanf("%c",&c);
				mp[i][j]=c;
			}
		  cin>>sx>>sy>>dx>>dy;
		 cout<<bfs()<<endl;
		}
	 return 0;	
}	
