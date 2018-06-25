#include <iostream>
#include <vector>
using namespace std;

int f(int m, int i, int A[], int dp[]) {
	if (i==13) {
		return 0;
	}
    if (A[i] > m) {
    	return f(m, i+1, A, dp);
    }
    return max(f(m, i+1, A, dp), A[i] + f(m-A[i], i+1, A, dp));
}
 
int backPack(int m, int A[]) {
    int n = 13;
    int dp[n];
    return f(m, 0, A, dp);
}

int main() {
   // int m[] = {12,3,7,4,5,13,2,8,4,7,6,5,7};                
	//cout << "backPack=" << backPack(90, m) << endl;
	int i=0;
	cout << (i^0x01) << endl;
	return 0;
}   
