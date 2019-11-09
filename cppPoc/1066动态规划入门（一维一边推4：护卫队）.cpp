#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
double f[1001];
int w[1001],s[1001];
int mw,ml,n;
int main()
{
        scanf("%d%d%d",&mw,&ml,&n);
        for (int i=1;i<=n;i++)
        {
                scanf("%d%d",&w[i],&s[i]);
                f[i]=0xFFFFFFF;
        }
        f[0]=0.0;
        long long temp,lest;
        for (int i=1;i<=n;i++)
        {
                temp=w[i];lest=s[i];
                f[i]=f[i-1]+(ml*1.0)/lest;
                for (int j=i-1;j>=0;j--)
                {
                        if (temp>mw) break;
                        if (f[i]>f[j]+(ml*1.0)/lest)
                                f[i]=f[j]+(ml*1.0)/lest;
                        temp+=w[j];
                        if (lest>s[j]) lest=s[j];
                }
        }
        printf("%0.1lf\n",f[n]*60.0);
        return 0;
}
