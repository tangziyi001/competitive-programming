//NYUREV
// String reverse and Palindrome

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

bool check(string str){
	int i = 0;
	int j = str.size()-1;
	while (i <= j){
		if (str[i] != str[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}


int main(){
	int test;
	cin >> test;
	while (test--){
		string str;
		cin >> str;
		int sz = str.size();
		int com = 0;
		int a = -1;
		int b = -1;
		for (int i = 0; i <= sz-1; i++){
			if (com == 1){
				break;
			}
			for (int j = i+1; j <= sz; j++){
				reverse(&str[i],&str[j]);
				if (check(str) == true){
					com = 1;
					a = i + 1;
					b = j - 1 + 1;
					break;
				}
				reverse(&str[i],&str[j]);
			}
		}
		if (a == -1 || b == -1){
			cout << "impossible" << endl;
		}
		else{
			cout << a << " " << b << endl;
		}

	}



	return 0;
}