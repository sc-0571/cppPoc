#include<iostream>
#include<cstring>
using namespace std;
int a[256],b[256],c[256],d,i;   

void init(int a[]) 
{    

}
void print(int a[])//打印输出
{

}
int compare (int a[],int b[])  
			//比较a和b的大小关系，若a>b则为1，a<b则为-1,a=b则为0 
{    

} 

void numcpy(int p[],int q[],int det)//复制p数组到q数组从det开始的地方
{
 
}
void sub(int a[],int b[]) //计算a=a-b
{ 
	int flag,i; 
	flag=?;              //调用比较函数判断大小 
	if (flag==0)//相等
	{   
	
	}    
	if(flag==1)                     //a大于 b  
	{
	    //若不够减则向上借一位 
		//修正a最高位的0
		return;
	} 
} 
void high_divide(int a[],int b[],int c[])//高精除高精 
{
	int tmp[256]; 
	c[0]=a[0]-b[0]+1;
	for (int i=c[0];i>0;i--)
	{
		 //memset数组清零 
		//从i开始的地方复制b数组到temp数组;
		//用减法来模拟
	}
	//修正c最高位的0 
	return ;
}

int main()
{
  	init(a);init(b);
  	high_divide(a,b,c);
  	print(c);//输出商 
  	print(a);//输出余数 
  	return 0;
}




