#include<bits/stdc++.h>
using namespace std;
#define MAXN 205
const int nx[4] = {1,0,-1,0};//���������ĸ�����ÿ���߷��кű仯��
const int ny[4] = {0,1,0,-1};//���������ĸ�����ÿ���߷��кű仯��
int T;
int n,m,sx,sy,nn;//n��m��,sx,sy��ʾ��ʼλ��,nn ��ʾ��nn�������� 
char a[MAXN][MAXN];//���ͼ��
int x[MAXN*MAXN],y[MAXN*MAXN];//�洢����Ԫ��,x,y��ʾ�ߵ���x�У���y�е�λ��
int b[MAXN][MAXN];//�����ʾ�ﵽһ��״̬���ٵĲ���
int csx[MAXN],csy[MAXN];//�����ŵ�λ��
int head,tail;//����ͷβָ��
void csh() { //��ʼ������Ϊ�����������ݣ����������ȫ�ֱ�������ʼ��һ��
	T=0,n=0,m=0,sx=0,sy=0,nn=0;
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(b,0,sizeof(b));
	memset(csx,0,sizeof(csx));
	memset(csy,0,sizeof(csy));
	head=0,tail=0;
}
void push(int xx,int yy) { //���µ�Ԫ�����
	head++;
	x[head]=xx;
	y[head]=yy;
}
bool zj(int x,int y) { //�ж�һ��λ���Ƿ��������ڣ������߳��磩
	return x>=1&&x<=n&&y>=1&&y<=m;
}
void bfs() { //����
	memset(b,0x3f,sizeof(b));//��״̬��ȫ����ֵ���޴󣬱�ʾû�е���
	head=0,tail=1;
	b[sx][sy]=0; //��ʼ,״̬
	push(sx,sy);//��ʼ״̬���
	do{
		int ax=x[tail],ay=y[tail];
		tail++;
		if(a[ax][ay]=='E'){ //���﹫������λ��
			cout<<b[ax][ay]<<"\n"; //���
			return;
		}
		for(int i=0;i<=3;i++){//���������ĸ����� 
			int ex=ax+nx[i],ey=ay+ny[i];
			if(zj(ex,ey)) {
				if(a[ex][ey]=='$') { //�ߴ�����
					for(int i=1;i<=nn;i++) { //���ﴫ����ʱ�򣬿����ߵ��κ�һ��������
						if(b[csx[i]][csy[i]]>b[ax][ay]+1) {
							b[csx[i]][csy[i]]=b[ax][ay]+1;
							push(csx[i],csy[i]);
						}
					}
				} 
				else if(a[ex][ey]!='#') { //����ǽ���������ĵ�
					if(b[ex][ey]>b[ax][ay]+1) {
						push(ex,ey);
						b[ex][ey]=b[ax][ay]+1;
					}
				}
			}
		}
	}while(head>=tail);
	cout<<"oop!\n"; //����޽�
}
void rd() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			if(a[i][j]=='S') {//��ʼλ��
				sx=i;
				sy=j;
			}
			if(a[i][j]=='$') {//������
				nn++;
				csx[nn]=i;
				csy[nn]=j;
			}
		}

}
int main() {
	int T;
	cin>>T;
	while(T--) {
		csh();
		rd();
		bfs();
	}
	return 0;
}
/*
���� 
1
7 8 0
........
..S.$#..
.##.....
..#.....
...1#.$.
...##E..
........
*/
