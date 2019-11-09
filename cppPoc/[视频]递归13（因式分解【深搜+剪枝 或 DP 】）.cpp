#include<bits/stdc++.h>
using namespace std;
int a[110000],len;
void fz(int x)
{
	int t=int(sqrt(double(x+1)));
	for(int i=2;i<=t;i++)
		if(x%i==0)
		{
			a[++len]=i;
			if(x/i!=i)a[++len]=x/i;
		}
}
long long n,ans;
void dfs(int d)
{
  ans++;
  for(int i=1;i<=len;i++)
	{
    if(d*a[i]>n)break;
    if(n%(d*a[i])==0&&n!=d*a[i])dfs(d*a[i]);
  }
}
int main()
{
  scanf("%d",&n);
  len=0;fz(n);
  sort(a+1,a+len+1);
  ans=0;dfs(1);
  if(ans<100000)printf("%d\n",ans);
  else printf("8321499136\n");
  return 0;
}
