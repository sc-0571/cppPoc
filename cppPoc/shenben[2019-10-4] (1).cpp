#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int* pa=&a;//将&a的值赋给pa
	int* pb=&b;//将&b的值赋给pb
	int s=*pa + *pb;//将a+b的值存入s
	int t=*pa * *pb;//将a*b的值存入t
	cout<<s<<" ";
	cout<<t<<endl;
	return 0;
}