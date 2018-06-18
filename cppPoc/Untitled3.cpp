#include <iostream>
#include <vector>
using namespace std;

 int minCostClimbingStairs(vector<int>& cost) {
 	    int n = cost.size() + 1;
  
        vector<int> dp(n, 0);
		dp[0] = 0;
		dp[1] = 0;
		for(int i=2; i <  n ; i++) {
			dp[i] = min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
			
		}       
        return dp[n-1];
        
}

int main() {
	//int array[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
	int array[] = {10, 15, 20};
	
	vector<int> v(array, array+sizeof(array)/sizeof(int));
	cout << "minCostClimbingStairs=" << minCostClimbingStairs(v) << endl;
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}    

