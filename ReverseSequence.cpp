#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string a;
	cin >> a;
	int sz = a.size();
	reverse(&a[0],&a[sz]);
	cout << a << endl;


	return 0;
}