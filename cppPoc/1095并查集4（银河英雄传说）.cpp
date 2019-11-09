#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=500005;
int fa[maxn],front[maxn],num[maxn],x,y,i,j,n,t,ans;                                        
char s;
int find(int n) 
{                                      
    if(fa[n]==n)
        return fa[n];
    int fn=find(fa[n]);                               
    front[n]+=front[fa[n]];                               
    return fa[n]=fn;
}
int main()
{
    scanf("%d",&t);
    for(i=1;i<=30000;i++)
    {                                
        fa[i]=i;
        front[i]=0;
        num[i]=1;
    }
    for(int i=1;i<=t;i++)
    {
        cin>>s>>x>>y;
        int fx=find(x);                                    
        int fy=find(y);                                    
        if(s=='M') 
        {
            front[fx]+=num[fy];         
            fa[fx]=fy;    //��֦�����ڶ�Ӧ�ĸ��ڵ���                               
            num[fy]+=num[fx];                         
            num[fx]=0;                        
        }
        if(s=='C') //ѯ���������ս����
        {
            if(fx!=fy)printf("-1\n");       
            else cout<<abs(front[x]-front[y])-1<<endl;  
        }
    }
    return 0;
}
