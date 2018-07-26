#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

 bool canPartition(vector<int>& nums) {
    int half = 0;
    for (int i=0; i< nums.size(); i++) half += nums[i];
    if (half %2 != 0) return false;
    half /=2;
    
    int n = nums.size();
    int MAX = n * 100;
    int dp[n+1][MAX+1];
    for(int i=0; i<=n; i++) 
      for(int j=0; j<=MAX; j++) 
        dp[i][j] = 0;
    
    for (int i=1; i<= n; i++) 
        for(int j=nums[i-1]; j<= MAX; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i-1]] + nums[i-1]);
        }
    
    for (int i=0; i<= n; i++) {
        if (dp[i][half] == half) {
            return true;
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
       int half = 0;
        for (int i=0; i< nums.size(); i++) half += nums[i];
        if (half %k != 0) return false;
        half /=k;
        int n = nums.size();
        int MAX =  10000;
        int dp[n+1][MAX+1];
        for(int i=0; i<=n; i++) 
          for(int j=0; j<=MAX; j++) 
            dp[i][j] = 0;

        for (int i=1; i<= n; i++) 
            for(int j=nums[i-1]; j<= MAX; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i-1]] + nums[i-1]);
            }
            
        /*int r[10];
        memset(r, sizeof(r), 0);
        for(int j=1; j<= k; j++ )
            for (int i=1; i<= n; i++) {
                if (dp[i][half * k] == half*k) {
                    r[k-1]= 1;
                }
            }
        
        for(int j=1; j<=k; j++) 
            if (r[k-1] == 0) return false;*/
        return true; 
    }

int main() {
    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    //vector<int> nums = {4,3,2,3,5,2,1};
    string ret = canPartitionKSubsets(nums, 1)?"true":"false";
    cout << "ret=" << ret << endl;
    return 0;
}
    