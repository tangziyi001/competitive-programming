// Codechef CFRTEST
// Created by Ziyi Tang
// Basic Set

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

set<int> all;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		all.clear();
		cin >> n;
		for(int i = 0; i < n; i++){
			int tmp;
			cin >> tmp;
			all.insert(tmp);
		}
		cout << all.size() << endl;
	}
	return 0;
}