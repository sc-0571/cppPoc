#include<bits/stdc++.h>
using namespace std;
double f[151][151],m[151],minx,temp,x[151],y[151],maxint=1e12;
double dist(int i,int j)
{
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])); 
}
int main() 
{
	int i,j,k,n;char c;
	cin>>n;
	for(i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin>>c;
			if(c=='1')f[i][j]=dist(i,j);
			else f[i][j]=maxint;
		}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(i!=j&&j!=k&&k!=i)
					if(f[i][k]<maxint-1&&f[k][j]<maxint-1)
						if(f[i][k]+f[k][j]<f[i][j])
							f[i][j]=f[i][k]+f[k][j];
	memset(m,0,sizeof(m));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(f[i][j]<maxint-1&&m[i]<f[i][j])m[i]=f[i][j];
	minx=1e20;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j&&f[i][j]>maxint-1)
			{
				temp=dist(i,j);
				if(minx>m[i]+m[j]+temp)minx=m[i]+m[j]+temp;
			}
	for(i=1;i<=n;i++)if(m[i]>minx)minx=m[i];
	printf("%.6lf",minx);
}
