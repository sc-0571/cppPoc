#include<bits/stdc++.h>
using namespace std;
long long dp[101][20001];
int c[101];
double e[101];
string s;
int main()
{
	int n,m;scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)cin>>s>>c[i]>>e[i];
	for(int i=1;i<20001;i++)dp[0][i]=0x3f3f3f3f;//��ʼ��Ϊ���޴� 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m*1000;j++)//���ں���3λС��,�˴���1000���ɻ�Ϊ����
		{
			int cj=j-(int)(e[i]*1000+0.5);//��e[i]������������ 
			if(cj<0)cj=0;//���cj<(int)(e[i]*1000+0.5),�ͽ�cj����0
			dp[i][j]=min(dp[i-1][j],dp[i][cj]+1000*c[i]);//��ȡ��ȡ��ѡ��(��ȫ����)
		}
	cout<<dp[n][m*1000]/1000<<endl;//�����һ��dp�������
}
