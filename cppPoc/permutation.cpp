#include<stdio.h>
#include<string.h>

/*char str[] = "1234";

void swap(char * x, char*y) {
    //printf("swap x=%d, y=%d\n", x-str, y-str);	
	char temp;
	temp = *x;
	
	*x = *y;
	*y = temp;
    
} 


void permute(char *a, int l, int r) {
	//printf("l=%d, r=%d\n", l, r);
	int i;
	if(l == r) 
	   printf("%s\n", a);
	else {
		for(int i=l; i<=r; i++) {
			swap((a+l), (a+i));
			permute(a, l+1, r);
			swap((a+l), (a+i));
		}
	}
}
*/
int ii = 0;
void print_permutation(int n, int* A, int cur) {
    printf("index = %d\n", ii++);
    if(cur == n) { 
        printf("log  cur = %d\n", cur);
        for(int i = 0; i < n; i++) printf("%d ", A[i]);
        printf("\n");
    }
    else for(int i = 1; i <= n; i++) { 
        if (cur == 0 && i > 1) {
      //      continue;
        }        
      //  printf("log  cur = %d, i=%d\n", cur, i);
        int ok = 1;
        for(int j = 0; j < cur; j++)
            if(A[j] == i) ok = 0; 
        if(ok) {
            A[cur] = i;
            print_permutation(n, A, cur+1); 
        }
    }
}


int main() {
	//int n = strlen(str);
	//permute(str, 0, n-1);
    int A[] = {1, 2, 3, 4};
    print_permutation(sizeof(A)/sizeof(int), A, 0);
	return 0;
}
