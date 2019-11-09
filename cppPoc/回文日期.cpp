#include<iostream>
using namespace std;
int main(void)
{
 
	int s,e,y1,y2,ans=0;
	cin>>s>>e;
	int i,m,d;
	y1=s/10000;
	y2=e/10000;
 
	for(i=y1;i<=y2;i++)
	{
		m=(i%10)*10+(i/10)%10;
		d=((i/100)%10)*10+(i/1000);
		switch(m)
		{
		  case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			  if(d<=31)
				  ans++;
			  break;
	      case 4:case 6:case 9:case 11:
		      if (d <= 30)
			      ans++;
		      break;
	      case 2:
		     if((i%4==0&&i%100!=0)||(i%400==0))
				if(d<=29)
					ans++;
			 else if(d<=28)
				    ans++;
		     break;
		}
	}
	cout<<ans;
	return 0;
} 
