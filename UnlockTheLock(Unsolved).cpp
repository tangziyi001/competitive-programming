#include <iostream>
#include <cstring>
#include <string>
#include <stdlib>

using namespace std;

int main(){
	string l, u;
	int r;
	while (cin >> l >> u >> r){
		int a[r];
		for (int i = 0; i < r; i++){
			string num;
			cin >> num;
			a[i] = stoi(num);
		}
		int goal = abs(u - l);
	}
	return 0;
}