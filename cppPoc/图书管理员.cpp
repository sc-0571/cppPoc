#include<bits/stdc++.h>
using namespace std;
int book,reader,book1[1005];
int main()
{
    scanf("%d%d",&book,&reader);
    for(int i=0;i<book;i++) scanf("%d",&book1[i]);
    sort(book1,book1+book);
    for(int i=0;i<reader;i++)
    {
        bool find=false;
        int reader1,len;scanf("%d%d",&len,&reader1);
        int Mod=pow(10,len);
        for(int j=0;j<book;j++)
            if(book1[j]%Mod==reader1)
            {
                find=true;
                printf("%d\n",book1[j]);
                break;
            }
        if(!find) printf("-1\n");
    }
    return 0;
}
