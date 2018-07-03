#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

#define MAX_N 30

int n;
int A[MAX_N] = {-45, -41, -36, -36, 26, -32};
int B[MAX_N] = {22, -27, 53, 30, -38,-54};
int C[MAX_N] = {42, 56, -37, -75, -10, -6};
int D[MAX_N] = {-16, 30, 77, -46, 62, 45};
int CD[MAX_N * MAX_N];

void solve() {
  for (int i=0; i<n; i++) {
    for (int j =0; j< n; j++) {
        CD[i*n + j] = C[i] + D[j];
    }
  }
  sort(CD, CD + n * n);
  long long res =0;
  for (int i=0; i < n; i++) {
    for (int j=0; j < n; j++) {
        int cd= - (A[i] + B[j]);
        res += upper_bound(CD, CD+ n*n, cd) - lower_bound(CD, CD + n*n, cd);
    }
  }
 printf("%lld\n", res);
}

int main() {

    n = 6;

    solve();
    
    return 0;
}