int findMaxForm(vector<string>& strs, int m, int n) {
        int cost0,cost1;
        int dp[101][101];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<strs.size();i++){
            cost0=0;
            cost1=0;
            for(int j=0;j<strs[i].length();j++){
                if(strs[i][j]=='0')
                    cost0++;
                else
                    cost1++;
            }
            for(int j=m;j>=0;j--){
                for(int k=n;k>=0;k--){
                    if((j-cost0>=0)&&(k-cost1>=0))
                        dp[j][k]=max(dp[j-cost0][k-cost1]+1,dp[j][k]);
                    else
                        dp[j][k]=dp[j][k];
                }
            }
        }
        return dp[m][n];
    }
