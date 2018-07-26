 #include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

 bool dfs(vector<int>& nums, int pos, int target, int k, int subSum[]) {
    if (pos == -1) {
        for(int i=0; i<k; i++) {
            
           // cout << "subSum[" << i << "]=" << target - subSum[i] << endl;
            if (subSum[i] != target) return false;
        }
        return true;
    }
    
    for(int i=0; i < k; i++) {
        if ( (subSum[i] + nums[pos]) > target) {
            continue;
        }
        
        subSum[i] += nums[pos];
        if (dfs(nums, pos-1, target, k, subSum)) return true;
        subSum[i] -= nums[pos];
    }
    return false;
}

 bool canPartitionKSubsets(vector<int>& nums, int k) {
    if (k <= 0) return false;
    if (k == 1) return true;
    int sum = 0;
    for(auto i : nums) sum+= i;
    if (sum % k) return false;
    int target = sum/k;
    cout << target << endl;
    int subSum[k];
    for(int i=0; i < k; i++) subSum[i] = 0;
    
    sort(nums.begin(), nums.end());
    for (int i=0; i< nums.size(); i++) {
       cout << i << "=" << nums[i] << endl;
    }
    
    return dfs(nums, nums.size() - 1, target, k, subSum);
    
}

int main() {
    vector<int> nums = {3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269};
    cout << canPartitionKSubsets(nums, 5);
    return 0;
}

