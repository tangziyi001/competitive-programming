//UVA 299
// Inversion Index Problem with Bubble Sort

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int test;
	cin >> test;
	while (test--){
		int num;
		cin >> num;
		vector<int> all;
		int count = 0;
		while (num--){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		int sz = all.size();
		for (int i = sz-1; i >= 0; i--){
			for (int j = 0; j < i; j++){
				int a = all[j];
				int b = all[j+1];
				if (a > b){
					all[j+1] = a;
					all[j] = b;
					count += 1;
				}
			}
			
		}
		cout << "Optimal train swapping takes " << count << " swaps."<< endl;

	}



	return 0;
}