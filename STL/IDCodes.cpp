//UVA 146
// Use permutation algorithm
#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	string str;
	while (cin >> str && str != "#"){
		string tmp = str;
		if (next_permutation(str.begin(),str.end())){
			cout << str << endl;
		}
		else{
			cout << "No Successor" << endl;
		}
	}
	return 0;
}