#include <iostream>
#include <vector>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0;
    if ( k >= n/2) {
        int max_p = 0;
        for (int i=1; i < n; i++ ) {
            if ( prices[i] > prices[i-1]) {
                max_p += (prices[i] - prices[i-1]);
            }
        }
        return max_p;
    }
    
    int dp[k+1][n];
    for(int i=0; i <= k; i++) 
        for(int j=0; j < n; j++)
        dp[i][j] = 0;
    
    
    for(int j=1; j<= k; j++) {
       cout << "j=" << j << endl;
      for(int i=1; i< n; i++) {  // day
         int max_v = 0;
          for(int m = 0; m < i; m++) {
              max_v  = max(max_v, dp[j-1][m] + prices[i] - prices[m]);
          }
          dp[j][i] = max(dp[j][i-1], max_v);
          cout << "dp[" << j << "][" << i << "]=" << dp[j][i] << endl;    
      }
      
    }
    return dp[k][n-1];
}

int main() {
    int k = 3;
    vector<int> prices = {2, 5, 7, 1,4,3, 1, 3};
    cout << maxProfit(k, prices);
    return 0;
}