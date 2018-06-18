#include <iostream>
#include <vector>
using namespace std;

 
    
int longestDecreaseSequence(vector<int>& nums) {
  int n = nums.size();
  vector<int> dp(n, 1);
  int m = 1;
  int mi = -1;
  for(int i= 1; i < n ; i++) {
	for(int j=0; j<i; j++) {
		if (nums[j] > nums[i] && dp[i] < dp[j] + 1) {
			dp[i] = dp[j] + 1;
			m = max(m, dp[i]);
			mi = i;
		}
	}
  }
  cout << "m=" << m << ",i= " << mi << endl;
  return m;
}


int main() {
	int array[] = {15, 27, 14, 38, 63, 55, 46, 65, 85};
	
	vector<int> v(array, array+sizeof(array)/sizeof(int));
	cout << "longestDecreaseSequence=" << longestDecreaseSequence(v) << endl;
	
	return 0;
}    

