#include<bits/stdc++.h>
using namespace std;
int X1,Y1,X2,Y2;
int n=0,minn,r,x,y;
struct node{int r1,r2;}a[10000000];
bool cmp(node a,node b){return a.r1>b.r1;}
int main()
{
	cin>>X1>>Y1>>X2>>Y2>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		a[i].r1=(X1-x)*(X1-x)+(Y1-y)*(Y1-y);
		a[i].r2=(X2-x)*(X2-x)+(Y2-y)*(Y2-y);
	} 
	sort(a+1,a+n+1,cmp);
	int i=2,rr1=a[1].r1,rr2=0;
	minn=rr1+rr2;
	while(i<=n)
  {
    rr2=max(rr2,a[i-1].r2);
    minn=min(minn,rr1+rr2);
    rr1=a[i].r1 ;
    i++;
  }
  cout<<minn<<endl;
}

