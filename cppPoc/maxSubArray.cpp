#include <iostream>
#include <vector>
using namespace std;

 
    
int maxSubArray(vector<int>& nums) {
  int n = nums.size();
  if (n <=0) return 0;
  if (n == 1) return nums[0];
  int currentMax = nums[0];
  for(int i= 0; i < n ; i++) {
  	int temp = 0;
	for(int j=i; j<n; j++) {
		temp += nums[j];
		cout << "temp=" << temp << endl;
		currentMax = max(currentMax, temp);
	}
  }
 
  return currentMax;
}


int main() {
	int array[] = {-2,1,-3,4,-1,2,1,-5,4};
	
	vector<int> v(array, array+sizeof(array)/sizeof(int));
	cout << "maxSubArray=" << maxSubArray(v) << endl;
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}    

