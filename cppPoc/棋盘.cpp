#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,d[1005][1005],a,b,c,e[1005][1005];
int f[10][5]={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int x,int y,int z)
{
    for(int i=0;i<=3;i++)
    {
        int xx=x+f[i][0],
		    yy=y+f[i][1];
        if(xx>=1&&xx<=m&&yy>=1&&yy<=m)
        {
            int r=-1;
            if(d[x][y]==d[xx][yy]&&d[xx][yy]!=0) r=0;
            else
            {
                if(d[xx][yy]) r=1;
                if(!d[xx][yy]&&z) r=2;
            }
            if(r!=-1&&(e[x][y]+r<e[xx][yy]||!e[xx][yy]))
            {
                e[xx][yy]=e[x][y]+r;
                if(r==2)
                {
                    d[xx][yy]=d[x][y];
                    dfs(xx,yy,0);
                    d[xx][yy]=0;
                }
                else
                    dfs(xx,yy,1);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
		scanf("%d%d%d",&a,&b,&c);
		d[a][b]=c+1;
	}
    e[1][1]=1;
	dfs(1,1,1);
    printf("%d",e[m][m]-1);
}

