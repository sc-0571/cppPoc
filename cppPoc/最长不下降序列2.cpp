#include<cstdio>
#include<cstring>
int y,c;
int a[200][10];
int main()
{
	int n;
	scanf("%d",&n);
	for(int l=1;l<=n;l++)
	{
		scanf("%d",&a[l][1]);
		a[l][2]=1;//初始长度都为1
		a[l][3]=0;
	}
	for(int l=n-1;l>=1;l--)
	{
		y=0;c=0;//注意每次都要清零
	    for(int j=l+1;j<=n;j++)	
	    {
		
			if(a[j][1]>a[l][1]&&(a[j][2]>y))//最后一句话不能省
			{
				y=a[j][2];//最大长度
				c=j;
			}
			if(y>0)
			{
				a[l][2]=y+1;//a[l][2]=a[j][2]+1这样也行吗？当然不行！当a[j][1]在第一个if中不满足条件时，y就不会改变，但如果用a[j][2]则是要改变的。
				a[l][3]=c;
			}
		}
	}
	c=1;
	for(int j=1;j<=n;j++)
		if(a[j][2]>a[c][2]) c=j;
	printf("%d\n",a[c][2]);//最大的长度
	while(c!=0)
	{
	  printf("%d ",a[c][1]);
	  c=a[c][3];	
	}
}
