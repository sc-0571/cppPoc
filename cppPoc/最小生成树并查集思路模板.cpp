#include<bits/stdc++.h>
using namespace std;
struct point{int x,y,v;}a[400001];
int fat[10001],n,m,i,j,_x,_y,_v,tot,k;
int father(int x)
{
	if(x!=fat[x])fat[x]=father(fat[x]);
	return fat[x];
}
void unionn(int x,int y)
{
	int f1=father(x),f2=father(y);
	if(f1!=f2)fat[f1]=f2;
}
bool cmp(point a,point b){return a.v<b.v;}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>_x>>_y>>_v;
		if(_v!=0)a[i].x=_x,a[i].y=_y,a[i].v=_v;
	}
	for(int i=1;i<=n;i++)fat[i]=i;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(father(a[i].x)!=father(a[i].y))
		{
			unionn(a[i].x,a[i].y);
			tot+=a[i].v;
			k++;
		}
		if(k==n-1)break;
	}
	cout<<tot;
}
