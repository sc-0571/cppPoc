#include<iostream>
using namespace std;
int n,m,desx,desy,entx,enty,totstep,a[51],b[51],map[51][51];
bool f;
int dfs(int x,int y,int step);
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	    cin>>map[i][j];
	cout<<"input the enter:";
	cin>>entx>>enty;
	cout<<"input the exit:";
	cin>>desx>>desy;
	f=0;
	dfs(entx,enty,1);
	if(f)
	{
		for(i=1;i<=totstep;i++)
		  cout<<a[i]<<","<<b[i]<<endl;
	}
	else cout<<"no.way"<<endl;
	return 0;
}
int dfs(int x,int y,int step)
{
	map[x][y]=step;
	a[step]=x;  b[step]=y;
	if((x==desx)&&y==desy)
	{
		f=1;
		totstep=step;
	}
	else 
	{
		if((y!=m)&&(map[x][y+1]==0)) dfs(x,y+1,step+1);
		if((!f)&&(x!=n)&&(map[x+1][y]==0)) dfs(x+1,y,step+1);
		if((!f)&&(y!=1)&&(map[x][y-1]==0))  dfs(x,y-1,step+1);
		if((!f)&&(x!=1)&&(map[x-1][y]==0))  dfs(x-1,y,step+1);
	}
}
