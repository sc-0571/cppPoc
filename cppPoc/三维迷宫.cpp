#include<iostream>
using namespace std;
int xx[6]={-1,1,0,0,0,0}, 
    yy[6]={0,0,-1,1,0,0}, 
    zz[6]={0,0,0,0,-1,1};
int h[2700][5];
bool a[31][31][31];
int main()
{
	int l,r,c,head,tail,x,y,z,fx,fy,fz;
	char ch;
	bool s;
	while(cin>>l>>r>>c)
	{
		if(l==0&&r==0&&c==0)
		  return 0;
		for(x=1;x<=l;x++)
		for(y=1;y<=r;y++)
		for(z=1;z<=c;z++)
		{
			cin>>ch;
		}
		if(ch=='S')
		{a[x][y][z]=false;
		h[1][1]=x;
		h[1][2]=y;
		h[1][3]=z;
		h[1][4]=0;
		}
		else if(ch=='E')
		{
			a[x][y][z]=true;
			fx=x;
			fy=y;
			fz=z;
		}
		else if(ch=='#')a[x][y][z]=false;
		else a[x][y][z]=true;
	}
	head=0,tail=1;
	s=false;
	while(head<tail&&s==false)
	{
		head++;
		for(int i=0;i<6;i++)
		{
			x=h[head][1]+xx[i];
			y=h[head][2]+yy[i];
			z=h[head][3]+zz[i];
			if((x>0)&&(x<=l)&&(y>0)&&(y<=r)&&(z>0)&&(z<=c)&&a[x][y][z])
			{
				a[x][y][z]=false;
				tail++;
				h[tail][1]=x;
				h[tail][2]=y;
				h[tail][3]=z;
				h[tail][4]=h[head][4]+1;
				if(x==fx&&y==fy&&z==fz)
				{
					cout<<"Escaped in"<<h[tail][4]<<"minute(s)."<<endl;
					s=true;
					break; 
				}
			}
			
		} 
	}
	if(s==false)
	  cout<<"Trapped!"<<endl;
	return 0;
}
