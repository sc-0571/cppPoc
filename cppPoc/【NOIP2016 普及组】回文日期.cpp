#include<bits/stdc++.h>
using namespace std;
char begin_c[14],end_c[14];
int day_c[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int line_c[10],end_time_c[10],year_c,a,b,c,d,sum;
bool ifing(int x,int y,int z)
{
	if(x%400==0)day_c[2]=29;
	else if(x%4==0&&x%100!=0) day_c[2]=29;
	else day_c[2]=28;
	int p=0;
	if(x<a and y<=12 and z<=day_c[y]) p=1; 
	else if(x==a and y<=12 and y<b and z<=day_c[y]) p=1;
	else if(x==a and y<=12 and y==b and z<=day_c[y] and z<=c) p=1;
	day_c[2]=28;return p;
}
int search()
{
	for(int i=year_c;i<=a;i++)
	{
		int ii=i,o[6]={0},now_date[6]={0};
		for(int j=4;j>=1;j--)o[j]=ii%10,ii/=10;
		now_date[1]=i;now_date[2]=o[4]*10+o[3];
		now_date[3]=o[2]*10+o[1];
		if(ifing(now_date[1],now_date[2],now_date[3])) sum++;
	}
	return sum;
}
int main()
{
	scanf("%s\n%s",begin_c+1,end_c+1); 
	for(int i=1;i<=8;i++)line_c[i]=begin_c[i]-'0';
	year_c=line_c[1]*1000+line_c[2]*100+line_c[3]*10+line_c[4]; 
	for(int i=1;i<=8;i++)line_c[i]=end_c[i]-'0';
	a=line_c[1]*1000+line_c[2]*100+line_c[3]*10+line_c[4];
	b=line_c[5]*10+line_c[6];
	c=line_c[7]*10+line_c[8];
	printf("%d",search());
}
