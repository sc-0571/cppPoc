#include<stdio.h>
#include<string.h>

char str[] = "ABCDE";

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



int main6() {
	int n = strlen(str);
	permute(str, 0, n-1);
	return 0;
}
