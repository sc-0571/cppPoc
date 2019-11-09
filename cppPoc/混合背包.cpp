#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int maxm = 200000 + 100;
int n,c,v,w,s,d[maxm];
int main()
{
    scanf("%d%d",&n, &c);
    _for(i,0,n){
        scanf("%d%d%d",&v,&w,&s);
        if(s==1) 
            for(int j=c;j>=v;j--)
                d[j]=max(d[j],d[j-v]+w);
        if(s==-1||s*v>=c)
            _rep(j, v, c) d[j] = max(d[j], d[j - v] + w);
        else 
		{  
            int k=1;
            while(k<s) 
			{
                for(int j=c;j>=k*v;j--)
                    d[j]=max(d[j],d[j-k*v]+k*w);
                s-=k;
                k*=2;
            }
            for(int j=c;j>=s*v;j--)d[j]=max(d[j],d[j-s*v]+s*w);
        }
    }
    int ans=0;
    _rep(i,0,c)ans=max(ans,d[i]);
    printf("%d\n",ans);
    return 0;
}
