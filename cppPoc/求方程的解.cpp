#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    if(a==0)
	{  
	    if(b!=0){printf("%.6lf\n",-c/b);return 0;}
		if(b==0){printf("No\n");return 0;} 
	}
	else
	{
    	double delta;
    	delta=b*b-4*a*c;
    	double x1,x2;
    	if(delta<0)
        	printf("No\n");
    	if(delta==0)
    	{
        	x1=(-b)/(2*a);
        	printf("%.6lf\n",x1);
    	}
    	if(delta>0)
    	{
	        x1=(-b+sqrt(delta))/(2*a);
	        x2=(-b-sqrt(delta))/(2*a);
        	if(x1>x2)
            	printf("%.6lf\n%.6lf\n",x1,x2);
        	else
            	printf("%.6lf\n%.6lf\n",x2,x1);
    	}
	}
    return 0;
}
