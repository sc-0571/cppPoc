#include<cstdio>
#include<cstring>
#include<iostream> 
#include<cmath>
using namespace std;
int f[111000],a[110];
int t[111000];
int main()
{
    int n,l,sum;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,len=0;
        while(scanf("%d",&x)!=EOF)
        {
            if(x==-1) break;
            a[++len]=x; 
        }
        sum=0;
        memset(f,0,sizeof(f));f[0]=1;
        for(int j=1;j<=len;j++)
        {
            for(int k=sum;k>=0;k--)
            {
                if(f[k]==1)
                {
                    f[k+a[j]]=1;
                    sum=max(sum,k+a[j]);
                }

            }
    	}
        for(int i=0;i<=sum;i++)
            if(f[i]==1) t[i]++;
    }
    for(int i=sum;i>=0;i--)
        if(t[i]==n)
        {
            printf("%d\n",i);
            return 0;   
        } 
    return 0;   
} 
