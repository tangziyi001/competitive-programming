#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <vector>

char map[105][105];

bool bound(int r, int c, int gr, int gc){
	if (r < 1 || r > gr || c > gc || c < 1){
		return false;
	}
	else{
		return true;
	}
}


int main(){
	int test;
	cin >> test;
	while (test--){
		memset(map,"-1",sizeof(map));
		int r, c;
		int sr, sc;

	}


	return 0;
}