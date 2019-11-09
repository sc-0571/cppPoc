#include<bits/stdc++.h>
using namespace std;
#define MAXN 205
const int nx[4] = {1,0,-1,0};//上下左右四个方向，每种走法行号变化量
const int ny[4] = {0,1,0,-1};//上下左右四个方向，每种走法列号变化量
int T;
int n,m,sx,sy,nn;//n行m列,sx,sy表示初始位置,nn 表示有nn个传送门 
char a[MAXN][MAXN];//存地图的
int x[MAXN*MAXN],y[MAXN*MAXN];//存储队列元素,x,y表示走到第x行，第y列的位置
int b[MAXN][MAXN];//这里表示达到一个状态最少的步数
int csx[MAXN],csy[MAXN];//传送门的位置
int head,tail;//队列头尾指针
void csh() { //初始化，因为多组输入数据，这里把所有全局变量都初始化一遍
	T=0,n=0,m=0,sx=0,sy=0,nn=0;
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(b,0,sizeof(b));
	memset(csx,0,sizeof(csx));
	memset(csy,0,sizeof(csy));
	head=0,tail=0;
}
void push(int xx,int yy) { //将新的元素入队
	head++;
	x[head]=xx;
	y[head]=yy;
}
bool zj(int x,int y) { //判断一个位置是否在区域内（不能走出界）
	return x>=1&&x<=n&&y>=1&&y<=m;
}
void bfs() { //广搜
	memset(b,0x3f,sizeof(b));//将状态先全部赋值无限大，表示没有到达
	head=0,tail=1;
	b[sx][sy]=0; //初始,状态
	push(sx,sy);//初始状态入队
	do{
		int ax=x[tail],ay=y[tail];
		tail++;
		if(a[ax][ay]=='E'){ //到达公主所在位置
			cout<<b[ax][ay]<<"\n"; //输出
			return;
		}
		for(int i=0;i<=3;i++){//上下左右四个方向 
			int ex=ax+nx[i],ey=ay+ny[i];
			if(zj(ex,ey)) {
				if(a[ex][ey]=='$') { //走传送门
					for(int i=1;i<=nn;i++) { //到达传送门时候，可以走到任何一个传送门
						if(b[csx[i]][csy[i]]>b[ax][ay]+1) {
							b[csx[i]][csy[i]]=b[ax][ay]+1;
							push(csx[i],csy[i]);
						}
					}
				} 
				else if(a[ex][ey]!='#') { //不是墙，是正常的地
					if(b[ex][ey]>b[ax][ay]+1) {
						push(ex,ey);
						b[ex][ey]=b[ax][ay]+1;
					}
				}
			}
		}
	}while(head>=tail);
	cout<<"oop!\n"; //输出无解
}
void rd() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			if(a[i][j]=='S') {//初始位置
				sx=i;
				sy=j;
			}
			if(a[i][j]=='$') {//传送门
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
样例 
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
