#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

int countOfChar (string& s, char c) {
        int len = 0;
        for (int i=0; i < s.length(); i++) {
            if (s[i] == c) len++;
        }
        return len;
  }
    
  int findMaxForm(vector<string>& strs, int m, int n) {
    int g = strs.size();
    int dp[m+1][n+1];
    for (int i=0; i< m+1; i++)
      for (int j=0; j< n+1; j++)
           dp[i][j]=0;
    
    for (int i=1; i< g+1; i++) {
      int oneCount = countOfChar(strs[i-1], '1');
      int zeroCount = countOfChar(strs[i-1], '0');
      for (int j=0; j < m+1; j++) {
        for (int k =0; k < n+1; k++) {
           if (j < oneCount && k < zeroCount) {
             dp[j][k] = dp[j][k];
           } else {
             dp[j][k] = max(dp[j][k], dp[j-oneCount][k-zeroCount] + 1);
           }
        }   
      }
    }
    return dp[m][n];
  }
  
  int findMaxForm2(vector<string>& strs, int m, int n) {
    int dp[m+1][n+1];
    for (int j=0; j<=m; j++) 
        for (int k=0; k<=n; k++) 
            dp[j][k]=0;
    for( int i=0; i< strs.size(); i++) {
        int count0 = countOfChar(strs[i], '0');
        int count1 = countOfChar(strs[i], '1');
        for (int j=m; j>=0; j--) 
            for (int k=n; k>=0; k--) {
                if (j >= count0 && k >= count1) {
                  dp[j][k] = max(dp[j][k], dp[j-count0][k-count1]+1);
                } 
            }
    }
    return dp[m][n];
  }


int main() {
   vector<string> strs;
   strs.push_back("10");
   strs.push_back("0001");
   strs.push_back("111001");
   strs.push_back("1");
   strs.push_back("0");
//   strs.push_back("1");
   
   cout << "oneandzeros=" << findMaxForm2(strs, 5, 3) << endl;
}