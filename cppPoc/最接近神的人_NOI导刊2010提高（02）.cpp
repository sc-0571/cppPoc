#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
long long s;
void guibing(int t,int w)
{
  if(t==w)return;
  int m=(t+w)>>1;
  guibing(t,m);
  guibing(m+1,w);
  int j=m+1,l=t,x=t,y=w;
  while(t<=m&&j<=w)
	{
    if(a[t]<=a[j])b[l++]=a[t++];
    else{b[l++]=a[j++];s+=m-t+1;}
  }
  while(t<=m)b[l++]=a[t++];
  while(j<=w)b[l++]=a[j++];
  for(;x<=y;x++)a[x]=b[x];
}
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  guibing(0,n-1);
  cout<<s<<endl;
  return 0;
}
