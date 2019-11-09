#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
#define N 12
bool b[N+1]={0};
int total=0,a[N+1]={0};
int search(int);
int print();
bool pd(int,int); 

int main() {
	search(1);
	cout<<total<<endl;
} 
bool pd(int x, int y) {
	int k = 2, i = x + y;
	while (k <= sqrt(i) && i %k != 0) k++;
	if (k > sqrt(i)) return 1;
	    else return 0;
}
int search(int t) {
	int i;
	for (i=1; i<=N; i++)
	  if (pd(a[t-1], i) && ( !b[i])) {
	  	a[t]=i;
	  	b[i]=1;
	  	if (t == N) { if (pd(a[N], a[1])) print(); }
	  	    else search(t+1);
	  	b[i]=0;
	  }
}
int print() {
	total++;
	cout << "<" << total <<">";
	for (int j=1; j<=N; j++)
	    cout<<a[j]<<" ";
	cout <<endl;
}
