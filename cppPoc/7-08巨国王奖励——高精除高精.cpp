#include<iostream>
#include<cstring>
using namespace std;
int a[256],b[256],c[256],d,i;   

void init(int a[]) 
{    

}
void print(int a[])//��ӡ���
{

}
int compare (int a[],int b[])  
			//�Ƚ�a��b�Ĵ�С��ϵ����a>b��Ϊ1��a<b��Ϊ-1,a=b��Ϊ0 
{    

} 

void numcpy(int p[],int q[],int det)//����p���鵽q�����det��ʼ�ĵط�
{
 
}
void sub(int a[],int b[]) //����a=a-b
{ 
	int flag,i; 
	flag=?;              //���ñȽϺ����жϴ�С 
	if (flag==0)//���
	{   
	
	}    
	if(flag==1)                     //a���� b  
	{
	    //�������������Ͻ�һλ 
		//����a���λ��0
		return;
	} 
} 
void high_divide(int a[],int b[],int c[])//�߾����߾� 
{
	int tmp[256]; 
	c[0]=a[0]-b[0]+1;
	for (int i=c[0];i>0;i--)
	{
		 //memset�������� 
		//��i��ʼ�ĵط�����b���鵽temp����;
		//�ü�����ģ��
	}
	//����c���λ��0 
	return ;
}

int main()
{
  	init(a);init(b);
  	high_divide(a,b,c);
  	print(c);//����� 
  	print(a);//������� 
  	return 0;
}




