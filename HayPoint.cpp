// UVA 10295
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main(){
	int m, n;
	cin >> m >> n;
	map<string,int> all;
	for (int i = 0; i < m; ++i){
		string line;
		int num;
		cin >>line>>num;
		all[line] = num;	
	}

	string sen;
	for (int i = 0; i < n; i++){
		int count = 0;
		string sen;
		while(cin >> sen && sen != "."){
			if (all.find(sen) != all.end()){
						count = count + all[sen];
			}
		}
		cout << count << endl;

	}
	return 0;
}