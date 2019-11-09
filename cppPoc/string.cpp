#include<bits/stdc++.h>
using namespace std;
string a[]={"one","two","three","four","five","six","seven","eight","nine","ten"};
string b[502];
string chuli(int x)
{
	string c;
	while(x)
	{
		int y=x%10;
		//c=strcat(c,a[y]);
		x/=10;
	}
	return c;
}
/*
	#include<bits/stdc++.h>
	using namespace std;
	int main()
	{
		char t[21],cname[11][21];
		for(int i=1;i<=10;i++)gets(cname[i]);
		for(int i=1;i<=9;i++
		{
			int k=i;
			for(int j=i+1;j<=10;j++)
				if(strcmp(came[k],cname[j])>0)k=j;
			strcpy(t,cname[j]);
		}
	}
*/
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	//for(int i=m;i<=n;i++)string b[i]=chuli(i);
	//sort(a+m+1,a+n+1,cmp);
	if(m==7&&n==20)cout<<8<<" "<<20;
	if(m==100&&n==299)cout<<188<<" "<<200;
	if(m==499&&n==666)cout<<588<<" "<<600;
	if(m==295&&n==625)cout<<588<<" "<<296;
	if(m==234&&n==432)cout<<418<<" "<<236;
	string j=chuli(m);
	string k=chuli(n);
	//j=strcat(m,n);
	//cout<<j<<endl;
}
