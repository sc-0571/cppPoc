#include <iostream>
#include <vector>
using namespace std;
int f(vector<int>& nums, int l, int r) {
    if ( r <= l) {
        return 0;
    }
    if ( (r-l) == 1) {
       
        return nums.at(l);
    }
    int k = nums.at(l);
    return max( k + f(nums, l+2, r), nums.at(l+1) + f(nums, l+3, r));
}

int rob(vector<int>& nums) {
    
 
 
    return f(nums, 0, nums.size());
}

int main() {
	vector<int> v;
	//[2,7,9,3,1, ];
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	//v.push_back(9);
	//v.push_back(3);
	//v.push_back(1);
	cout << rob(v) << endl;
	
	return 0;
}


