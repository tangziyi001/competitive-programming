#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	int a, b;
	long long fib[100];
	fib[0] = 1;
	fib[1] = 2;
	while (cin >> a && a != 0){
		for (int i = 2; i < 100; ++i){
			fib[i] = fib[i-1] + fib[i-2];
		}
		cout << fib[a-1] << endl;
	}


return 0;
}