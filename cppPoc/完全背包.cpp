#include<cstdio>
#include<algorithm>
using namespace std;
int w[300],c[300],f[300010];
int V,n;
int main()
{
    scanf("%d%d",&V,&n);
    for(int i=1;i<=n;i++){scanf("%d%d",&w[i],&c[i]);}
    for(int i=1;i<=n;i++)
    	for(int j=w[i];j<=V;j++)f[j]=max(f[j],f[j-w[i]]+c[i]);
    printf("max=%d\n",f[V]);
    return 0;
 
}

