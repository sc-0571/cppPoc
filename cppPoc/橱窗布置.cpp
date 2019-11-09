#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int a[101][101],b[101][101],c[101][101],d[101];
int main()
{
    int f,v,k;
    scanf("%d%d",&f,&v);
    memset(b,128,sizeof(b));
    for(int i=1;i<=f;i++)
    for(int j=1;j<=v;j++)
    {
    scanf("%d",&a[i][j]);
    }    
    for(int i=1;i<=v-f+1;i++)
    b[1][i]=a[1][i];
    for(int i=2;i<=f;i++)
    {
        for(int j=i;j<=v-f+i;j++)
        {
            for(k=i-1;k<=j-1;k++)
            {
                if(b[i][j]<b[i-1][k]+a[i][j])
                {
                    b[i][j]=b[i-1][k]+a[i][j];
                    c[i][j]=k;
                }
            }
        }
    }
    int maxx=-210000000,sig;for(int i=f;i<=v;i++)
    {
        if(b[f][i]>maxx)
        {
        maxx=b[f][i];
        sig=i;    //标记最后一束花的位置； 
        }
    }
    printf("%d\n",maxx);
   for(int i=1;i<=f;i++)
   {
       d[i]=sig;
       sig=c[f-i+1][sig];//下一束花的位置 
    } 
    for(int i=f;i>=2;i--)
    cout<<d[i]<<" ";
    cout<<d[1]<<endl;
    return 0;
}
