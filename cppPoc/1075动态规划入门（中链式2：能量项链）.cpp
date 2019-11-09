#include<iostream>
#include<cstdio>
using namespace std;
int num[20010];
int dp[450][450];
int sum[450][450];
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]),num[i+n]=num[i];
    for(int i=2;i<=2*n;i++)
      for(int j=1;j<=2*n-i+1;j++)
      {
        int k=i+j-1;
        for(int l=j;l<k;l++)
          dp[j][k]=max(dp[j][k],dp[j][l]+dp[l+1][k]+num[j]*num[l+1]*num[k+1]);
      }
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i][i+n-1]);
    cout<<ans;
    return 0;
}
