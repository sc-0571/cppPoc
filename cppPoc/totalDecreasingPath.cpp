#include <iostream>
#include <vector>
using namespace std;

#define N 3
 
int caculate(int m[N][N], int dp[N][N], int x, int y) {
	if (dp[x][y] != 0) {
		return dp[x][y];
	}
	int delta[4][2] = { {1, 0},
	                    {-1, 0},
						{0, 1},
						{0, -1}};
	int c = 1;
    for(int k=0; k<4; k++) {
    	int newx = x + delta[k][0];
    	int newy = y + delta[k][1];
    	if( newx >=0 && newx < N && newy >=0 && newy < N && m[newx][newy] < m[x][y]) {
    		c += caculate(m, dp, newx, newy) ;
    		cout << "x=" << x << "y=" << y << "c=" << c << endl;
    	}
    }
	return dp[x][y] = c;
}
    
int totalDecreasingPath(int m[N][N]) {
  int dp[N][N];
  for(int i=0; i < N; i++) 
  	 for(int j=0; j< N; j++) 
        dp[i][j] = 0;

  int  c = 0;
  for(int i=0; i < N; i++) {
  	 for(int j=0; j< N; j++) {
  	 	c += caculate(m, dp, i, j);
  	 }
  }
  
  return c;
}


int main() {
	int m[N][N] = { { 1, 2, 3 },
                    { 1, 3, 4 },
                    { 1, 5, 6 } }; 
                    
    //int m[N][N] =  { { 1, 2 }, { 1, 3 } };
	cout << "totalDecreasingPath=" << totalDecreasingPath(m) << endl;
	
	return 0;
}    

