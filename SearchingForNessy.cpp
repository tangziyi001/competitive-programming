//UVA 11044
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int main(){
	double num;
	cin >> num;
	double r, c;
	while (cin >> r >> c){
		double n = r - 2;
		double m = c - 2;
		double row = ceil(n/3);
		double col = ceil(m/3);
		int re = (int)(row * col);
		cout << re << endl;
	}



	return 0;
}