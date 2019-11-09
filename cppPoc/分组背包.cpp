#include<iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
struct ss
{
    int w,p;
}array1[1005];
int ans[1005],map1[1005][1005];
int main ()
{
    int V,N,T,team;
    while(scanf("%d%d%d",&V,&N,&T)!=EOF)
    {
        memset(ans,0,sizeof(ans));
        memset(map1,0,sizeof(map1));
        for(int i=0; i<N; i++)
        {
            scanf("%d %d %d",&array1[i].w,&array1[i].p,&team);
            map1[i][team]=1;
        }
        for(int j=1; j<=T; j++)  
            for(int i=V;i>=0;i--)
                for(int k=0;k<N;k++)
                    if(map1[k][j]&&i>=array1[k].w) 
                       ans[i]=(ans[i]>ans[i-array1[k].w]+array1[k].p?ans[i]:ans[i-array1[k].w]+array1[k].p);
        printf("%d\n",ans[V]);
    }
    return 0;
}
