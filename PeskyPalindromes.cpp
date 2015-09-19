//UVA 353
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

bool check(string str, int a, int b){
	while(a < b){
		if (str[a] != str[b]){
			return false;
		}
		a ++;
		b --;

	}
	return true;
}
int main(){
	string str;
	while(cin >> str){
		set<string> exi;
		int count = 0;
		int len = str.size();
		for (int i = 0; i < len; i++){
			for (int j = i; j< len; j++){
				if (check(str, i, j) == true){
					string tmp = str.substr(i, j-i+1);
					if (exi.find(tmp) == exi.end()){
						count += 1;
						exi.insert(tmp);
					}
				}
			}
		}
		cout << "The string " << "\'" << str << "\'" << " contains " << count << " palindromes."<< endl;

		

	}





	return 0;
}