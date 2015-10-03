#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
	string a;
	getline(cin,a);
	int sz = a.size();
	char b[sz];
	for (int i = 0; i < sz; i++){
			if (a[i] != ' '){
				b[i]=toupper(a[i]);
			}
			else if(a[i] == '.'){
				
			}
			else{
				b[i] = ' ';
			}
	}
	b[sz]='\0';
	cout << b << endl;
	return 0;
}