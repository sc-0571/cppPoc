#include<cstdio>
#include<cstring>
#include<iostream> 
using namespace std;
int v,n,a[100],f[100000];
int main()
{
    cin>>v>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=v;j>=a[i];j--)
            f[j]=max(f[j-a[i]]+a[i],f[j]);
            cout<<v-f[v];
    return 0;
 }
