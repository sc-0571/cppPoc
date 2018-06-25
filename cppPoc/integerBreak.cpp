#include <iostream>
#include <vector>
using namespace std;

	int isPrime(int n) {
	  for(int i=2; i<= n/2; i++) {
	  	if ((n % i)==0) {
	  		return 0;
	  	}
	  }	
	  return 1;
	}

int integerN(vector<int>& dp, int n) {
	if (dp[n] > 0) return dp[n];
	
    if (n <=3) {
    	return dp[n] = n;
    }
	
	int m = 1;
	for(int i=2; i<n; i++) {
	    int temp = i * integerN(dp, n-i);
	    cout << "i=" << i << ", temp=" << temp << endl;
	    m = max(m, temp);
	}
	return dp[n] = m;
}
int integerBreak(int n) {
	if (n<= 3) {
		return 1 * (n-1);
	}
    vector<int> dp(n+1, 0);
    return integerN(dp, n);
}

int main() {
	
                    
    //int m[N][N] =  { { 1, 2 }, { 1, 3 } };
	cout << "integerBreak=" << integerBreak(5) << endl;
	
	return 0;
}   
