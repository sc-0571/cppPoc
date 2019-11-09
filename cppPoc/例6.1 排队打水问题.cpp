//Ì°ÐÄËã·¨Àý1£º
#include<iostream>
#include<cstring>
using namespace std;
float a[101],s[101];
void quick_sort(int left,int right)
{
	int i,j,t,temp;
	i=left;
	j=right;
	temp=a[(i+right)/2];
	do
	{
		while(a[i]<temp)i++;
		while(a[j]>temp)j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;j--;
		}
	}while(i<=j);
	if(left<j)quick_sort(left,j);
	if(i<right)quick_sort(i,right);
}
int main()
{
	int n,r=1;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	quick_sort(1,n);
	for(int i=1;i<=n;i++)
	  cout<<a[i]<<" ";
	cout<<endl;
	memset(s,0,sizeof(s));
	int j=0;
	float minx=0;
	for(int i=1;i<=n;i++)
    {
    	j++;
    	if(j==r+1) j=1;
    	s[j]+=a[i];
    	minx+=s[j];
    }
    printf("%.2f",minx/n);
    return 0;
}  
