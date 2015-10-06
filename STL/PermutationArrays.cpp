//UVA 482
// Map for Index
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;
int main(){
	string tmp;
	int test;
	getline(cin,tmp);
	test = stoi(tmp);
	while (test--){
		string blank;
		string fir;
		string sec;
		map<int, string> result;
		getline(cin,blank);
		getline(cin,fir);
		getline(cin,sec);
		stringstream first(fir),second(sec);
		int index;
		string value;
		while (first >> index){
			second >> value;
			result[index] = value;

		}
		for (auto it = result.begin(); it != result.end(); it++){
			cout << (*it).second << endl;
		}
		if (test >= 1){
			cout << endl;
		}
	}


	return 0;
}