//UVA 594
// Bit Set and Bit Reverse
#include <bitset>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main(){
	long tmp;
	while (cin >> tmp){
		bitset<32> a(tmp);
		long re = 0;
		for (int i = 0; i < 32; i++){
			if (a[i]){
				re |= 1 << ((3-i/8)*8 + i%8);
			}
		}
		cout << tmp << " converts to " << re << endl;

	}
	return 0;
}