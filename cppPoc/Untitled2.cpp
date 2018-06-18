#include <iostream>
#include <vector>
using namespace std;

    int bitcount(int num) {
        int ret=0;
        while(num) {
        	ret += (num & 0x01);
        	num >>=1;
        }
        return ret;
    }
    
    vector<int> countBits(int num) {
        vector<int> v;
        for(int i=0; i<= num; i++) {
            int ret=0;
            int k=i;
	        while(k) {
	        	ret += (k & 0x01);
	        	k >>=1;
	        }
	        v.push_back(ret);
        }
        return v;
    }
    
int main() {
	vector<int> v;
	v = countBits(255);
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}

