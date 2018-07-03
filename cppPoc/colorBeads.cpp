#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define N 30

int getHash(char ch) {
	if(  ch>='0' && ch<='9') return ch-'0';
	else if (ch >='A' && ch <= 'Z') return ch -'A'+10; 
	else if (ch >='a' && ch <= 'z') return ch - 'a'+36;
	return -1;
}

void hashString(string & s, vector<int>& hashtable) {
    int len = s.size();
    for (int i=0; i< len; i++) {
        int k = getHash(s[i]);
        hashtable[k] ++;
    }
}

int testBeads(vector<string>& beads, string buy) {
    int n = beads.size();
    int dp[62][N];
    memset(dp, N, sizeof dp);
    vector<int> buyTable(62, 0);
    hashString(buy, buyTable);
    
    for (int i=0; i< n; i++) {
        string s = beads[i];
        vector<int> hashtable(62, 0);
        hashString(s, hashtable);
        for (int j=0; j<62; j++) {
            int h = hashtable[j];
            for (int k=buyTable[j]; k >=0&& h > 0; k--) {
                if (k < h) {
                //    cout << "j=" << j << ",k=" << k << ", h=" << h <<endl;
                    dp[j][k] = min(dp[j][k],1);
                }else {
                    dp[j][k] = min(dp[j][k], dp[j][k-h]+1);
                }
            }
        }
    }
    
    int res = 0;
    cout <<endl;
    for(int i=0; i<62; i++) {
      //if (buyTable[i]>0) {
          cout << endl << "row i " << i; 
          for(int j=0; j<N; j++) {
             if (dp[i][j] != N) {
               cout << "j=" << j << ", with value " << dp[i][j];
             };
          }
          
          res= max(dp[i][buyTable[i]], res);
     // }
    }
    
    if (res < N) {
        cout << "Yes " << res;
    } else {
        cout << "No";
    }
}

int main() {
	vector<string> beads;
    beads.push_back("1");
    beads.push_back("2");
    beads.push_back("3");
    beads.push_back("4");
    //beads.push_back("RRYg555");
    /*beads.push_back("8R5");
    beads.push_back("12346789");
    beads.push_back("gRg8h");
    beads.push_back("5Y37");
    beads.push_back("pRgYgbR52");
    beads.push_back("8Y");
    beads.push_back("8g");
    */
   testBeads(beads, "1234");
    
	return 0;
}