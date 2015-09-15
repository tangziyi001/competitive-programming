#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;


int main(){
	char str [1000000];
	int qu;
	int count = 1;
	while (cin >> str >> qu){
		cout << "Case " << count << ":" << endl;
		count += 1;
		for (int i = 0; i < qu; ++i){
			int a, b;
			cin >> a >> b;
			char judge = str[min(a,b)];
			int res = 1;
			for (int i = min(a,b) + 1; i <= max(a, b); ++i){
				if (str[i] != judge){
					res = 0;
					break;
				}
			}
			if (res == 0){
				cout << "No" << endl;
			}
			else {
				cout << "Yes" << endl;
			}
		}
	}



	return 0;
}