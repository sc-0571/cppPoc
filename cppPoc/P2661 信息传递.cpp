#include<bits/stdc++.h>
int a[200001],f[200001],v[200001];
int read()
{
    int n=0;
    char c;
    c=getchar();
    while('0'<=c&&c<='9')
    n=n*10+(c-'0'),c=getchar();
    return n;
}
int main()
{
  int n=read(),p,t,x=200001;
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=1;i<=n;i++)
  {
    v[i]=1,t=i,p=a[i];
    while(f[p]!=i)
    {    
      if(f[p]!=0&&f[p]<i)break;        
      v[p]=v[t]+1,f[t]=i;
      t=p,p=a[t];
    }
    if(f[p]==i&&x>v[t]+1-v[p])x=v[t]+1-v[p];
  }
  printf("%d",x);
  return 0;
}
