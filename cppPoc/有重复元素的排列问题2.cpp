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
		count[s[i]-96]++;//��¼���ֵĴ��� //97��1�Ĳ�� 
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
	  if(count[i])//�Գ��� 
   	  {
	  	 q[x]=s[i-1];
		 count[i]--;
		 if(x==n-1)print();
		   else search(x+1);
		 count[i]++;
	  }
}
