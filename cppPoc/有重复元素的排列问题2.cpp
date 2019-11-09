#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int search(int);
int print();
int n,count[501],sum;
string s;
char q[501]; 
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
		count[s[i]-96]++;//记录出现的次数 //97和1的差别 
	search(0);
	cout<<sum<<endl;
	return 0;
}
int print()
{
	sum++;
	for(int i=0;i<n;i++)
		cout<<q[i];
	cout<<endl;
}
int search(int x)
{
	for(int i=1;i<=26;i++)
	  if(count[i])//仍出现 
   	  {
	  	 q[x]=s[i-1];
		 count[i]--;
		 if(x==n-1)print();
		   else search(x+1);
		 count[i]++;
	  }
}
