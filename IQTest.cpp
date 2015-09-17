#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int count;
	cin >> count;
	vector<int> odd;
	vector<int> even;
	int ro = 0;
	int re = 0;
	for (int i = 1; i <= count; ++i){
		int num;
		cin >> num;
		if (num % 2 == 1){
			odd.push_back(num);
			ro = i;
		}
		else{
			even.push_back(num);
			re = i;
		}
		if (odd.size() == 1 && even.size() > 1){
			cout << ro << endl;
			break;
		}
		else if (even.size() == 1 && odd.size() > 1){
			cout << re << endl;
			break;
		}
	}
	return 0;
}