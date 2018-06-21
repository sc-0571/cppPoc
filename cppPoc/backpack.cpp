public class Solution {
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int f(int m, int i, int[] A, int[][]dp) {
        if (dp[m][i] > 0) {
            return dp[m][i];
        }
    	if (i==A.length) {
    		return dp[m][i] = 0;
    	}
        if (A[i] > m) {
        	return dp[m][i] = f(m, i+1, A, dp);
        }
        return dp[m][i] = Math.max(f(m, i+1, A, dp), A[i] + f(m-A[i], i+1, A, dp));
    }
     
    public int backPack(int m, int[] A) {
        int n = A.length;
        int[][] dp = new int[n+1][m+1];
        for(int j=0; j< n+1; j++) {
          for(int i=0; i<m+1; i++) 
               dp[j][i] = 0;
        }
        //return f(m, 0, A, dp);
        for(int i=0; i< n+1; i++) 
            for(int j=0; j< m+1; j++) {
                dp[i+1][j] = Math.max(dp[i][j], dp[i][j-A[i]]+A[i]);
            }
        }
        return dp[n][m];

    }
    
    // Non recursive function
    public int backPack(int m, int[] A) {
        int n = A.length;
        int[][] dp = new int[n+1][m+1];
        for(int i=0; i<m+1; i++) 
            dp[0][i] = 0;
        
        for(int i=0; i< n; i++) 
            for(int j=0; j< m+1; j++) {
                if (j < A[i]) {
                    dp[i+1][j] = dp[i][j];
                } else {
                    dp[i+1][j] = Math.max(dp[i][j], dp[i][j-A[i]]+A[i]);
                }
        }
        return dp[n][m];

    }
    
}