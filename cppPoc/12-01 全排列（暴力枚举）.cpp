#include<iostream>
using namespace std;
int main()
{
	int total=0;
	for(int a=1;a<=4;a++)
	  for(int b=1;b<=4;b++)
	    for(int c=1;c<=4;c++)
	      for(int d=1;d<=4;d++)
	      {
	      	if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
			  cout<<a<<b<<c<<d<<" ";
			  total++;
	      }
	cout<<total;
    return 0;
} 
