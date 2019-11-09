#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;
int a=0;
int b=0;
int c=0;
int k=0;
int flag[105][105][105]={0};
struct Node 
{
	int a;
	int b;
	int c;
	int step;
}cur,start,temp;
int BFS(Node start) 
{
	queue<Node> que;
	que.push(start);
	flag[start.a][start.b][start.c] = 1;
	while (!que.empty()) {
		cur = que.front();
		if (cur.a == k || cur.b == k || cur.c == k) {
			printf("yes\n%d\n", cur.step);
			return 1;
		}
		que.pop();
		//v1->v2
		if (cur.a > 0 && cur.b < b) {
			int t = min(cur.a, b - cur.b);
			temp.a = cur.a - t;
			temp.b = cur.b + t;
			temp.c = cur.c;
			temp.step = cur.step + 1;
			if (flag[temp.a][temp.b][temp.c] != 1) {
				que.push(temp);
				flag[temp.a][temp.b][temp.c] = 1;
			}
		}
		//v1->v3
		if (cur.a > 0 && cur.c < c) {
			int t = min(cur.a, c - cur.c);
			temp.a = cur.a - t;
			temp.b = cur.b;
			temp.c = cur.c + t;
			temp.step = cur.step + 1;
			if (flag[temp.a][temp.b][temp.c] != 1) {
				que.push(temp);
				flag[temp.a][temp.b][temp.c] = 1;
			}
		}
		//v2->v1
		if (cur.b > 0 && cur.a < a) {
			int t = min(cur.b, a - cur.a);
			temp.a = cur.a + t;
			temp.b = cur.b - t;
			temp.c = cur.c;
			temp.step = cur.step + 1;
			if (flag[temp.a][temp.b][temp.c] != 1) {
				que.push(temp);
				flag[temp.a][temp.b][temp.c] = 1;
			}
		}
		//v2->v3
		if (cur.b > 0 && cur.c < c) {
			int t = min(cur.b, c - cur.c);
			temp.a = cur.a;
			temp.b = cur.b - t;
			temp.c = cur.c + t;
			temp.step = cur.step + 1;
			if (flag[temp.a][temp.b][temp.c] != 1) {
				que.push(temp);
				flag[temp.a][temp.b][temp.c] = 1;
			}
		}
		//v3->v1
		if (cur.c > 0 && cur.a < a) {
			int t = min(cur.c, a - cur.a);
			temp.a = cur.a + t;
			temp.b = cur.b;
			temp.c = cur.c - t;
			temp.step = cur.step + 1;
			if (flag[temp.a][temp.b][temp.c] != 1) {
				que.push(temp);
				flag[temp.a][temp.b][temp.c] = 1;
			}
		}
		//v3->v2
		if (cur.c > 0 && cur.b < b) {
			int t = min(cur.c, b - cur.b);
			temp.a = cur.a;
			temp.b = cur.b + t;
			temp.c = cur.c - t;
			temp.step = cur.step + 1;
			if (flag[temp.a][temp.b][temp.c] != 1) {
				que.push(temp);
				flag[temp.a][temp.b][temp.c] = 1;
			}
		}
	}
	return 0;
}
int main() {
	int answer = 0;
	while (~scanf("%d %d %d %d", &a, &b, &c, &k)) {
		memset(flag, 0, sizeof(flag));
		start.a = a;
		start.b = 0;
		start.c = 0;
		start.step = 0;
		if (!BFS(start)) {
			printf("no\n");
		}
	}
	return 0;
}
