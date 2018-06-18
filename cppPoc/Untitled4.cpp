 #include<iostream>
#include<string>
#include<vector>
using namespace std;

 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int s1=0, s2=0;
    int halfLength = (nums1.size() + nums2.size())/2 + 1; 
    int l = 0;
    int current;
    int m1, m2;
    int even = (nums1.size() + nums2.size())%2? 0: 1;
    while(s1 < nums1.size() || s2 < nums2.size()) {
        if (s1 == nums1.size()) {
            current = nums2.at(s2);
            s2++;
        } else if (s2 == nums2.size()) {
            current = nums1.at(s1);
            s1++;
        } else {
            if (nums1.at(s1) <= nums2.at(s2)) {
            current = nums1.at(s1);
            s1++;
                            
            } else {
                current = nums2.at(s2);
                s2++;
            }
        }
        l++;
        if (!even && l == halfLength) {
            return current;
        }
        if (even && l == (halfLength - 1)) {
            m1 = current;
        } 
        if (even && l == halfLength) {
            return ((double) current + m1 )/2;
        } 
    }
}

int main4() {
   vector<int> s1;
   s1.push_back(1); s1.push_back(2);
   vector<int> s2;
   s2.push_back(3); s2.push_back(4);
   
   cout << 	findMedianSortedArrays(s1, s2) << endl;
	
}
