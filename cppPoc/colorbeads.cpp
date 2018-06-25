#include <iostream>
#include <vector>
#include <string.h>
#define N 1000
using namespace std;
int hashtable[62]={0};
int getHash(char ch) {
	if(  ch>='0' && ch<='9') return ch-'0';
	else if (ch >='A' && ch <= 'Z') return ch -'A'+10; 
	else if (ch >='a' && ch <= 'z') return ch - 'a'+36;
	return -1;
}

int main() {
	char shopper[N] = "ppRYYGrrYBR2258";
	char hong[N] = "YrR8RrY";
	
	int len = strlen(shopper);
	for (int i=0; i< len; i++) {
		int k = getHash(shopper[i]);
		hashtable[k] ++;
	}
	len = strlen(hong);
	for (int i=0; i< len; i++) {
		int k = getHash(hong[i]);
		hashtable[k] --;
	}
	
	int more=0, less = 0;
	for (int i=0; i<62; i++) {
		if (hashtable[i] < 0) {
			less -= hashtable[i];
		} else if (hashtable[i] > 0) {
			more += hashtable[i];
		}
	}
	
	if (less >0) {
		cout << "NO " << less << endl;
	} else if (more > 0) {
		cout << "YES " << more << endl;
	} 
	
	return 0;
}
