#include <iostream>
#include <string>
using namespace std;
int main(){

	string a = "hahaha";
	char b[] = {'a','b'};
	*b = a + *b;
	cout << a << endl;
	return 0;
}