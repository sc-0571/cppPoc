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
		a[l][2]=1;//��ʼ���ȶ�Ϊ1
		a[l][3]=0;
	}
	for(int l=n-1;l>=1;l--)
	{
		y=0;c=0;//ע��ÿ�ζ�Ҫ����
	    for(int j=l+1;j<=n;j++)	
	    {
		
			if(a[j][1]>a[l][1]&&(a[j][2]>y))//���һ�仰����ʡ
			{
				y=a[j][2];//��󳤶�
				c=j;
			}
			if(y>0)
			{
				a[l][2]=y+1;//a[l][2]=a[j][2]+1����Ҳ���𣿵�Ȼ���У���a[j][1]�ڵ�һ��if�в���������ʱ��y�Ͳ���ı䣬�������a[j][2]����Ҫ�ı�ġ�
				a[l][3]=c;
			}
		}
	}
	c=1;
	for(int j=1;j<=n;j++)
		if(a[j][2]>a[c][2]) c=j;
	printf("%d\n",a[c][2]);//���ĳ���
	while(c!=0)
	{
	  printf("%d ",a[c][1]);
	  c=a[c][3];	
	}
}
