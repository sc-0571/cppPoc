#include<iostream>
using namespace std;
int n,began[1001],ended[1001];
void init()
{
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>began[i]>>ended[i];
} 
void qsort(int x,int y)
{
    int i,j,mid,t;
    i=x;j=y;mid=ended[(x+y)/2];
    while(i<=j)
    {
        while(ended[i]<mid)i++;
        while(ended[j]>mid)j--;
        if(i<=j)
        {
            t=ended[j];ended[j]=ended[i];ended[i]=t;
            t=began[j];began[j]=began[i];began[i]=t;
            i++;j--;
        }
    }
    if(x<j)qsort(x,j);
    if(i<y)qsort(i,y);
}
void solve()
{
    int ans=0;
    for(int i=1,t=-1;i<=n;i++)
      if(began[i]>=t){ans++;t=ended[i];}
    cout<<ans<<endl;
}
int main()
{
    init();
    qsort(1,n);
    solve();
    return 0;
}

