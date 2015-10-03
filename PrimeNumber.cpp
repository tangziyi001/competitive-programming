//UVA 10539
// Prime Mark Technique

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
int mark[1000005];
int num[1000005];
int pri[1000005];

int main(){
	memset(mark,0,sizeof(mark));
	memset(num,0,sizeof(num));
	memset(pri,0,sizeof(pri));
	for (int i = 2; i < 1000000; i++){
		if (mark[i] == 1){
			continue;
		}
		pri[i] = 1;
		for (int j = 0; j*i < 1000000; j++){
			mark[j*i] = 1;
		}
	}
	for (int i = 2; i < 1000000; i++){
		num[i] = num[i-1];
		if (pri[i] == 1){
			num[i] += 1;
		}
	}

	int a;
	while (cin >> a){
		cout << num[a] << endl;
	}

	return 0;
}

