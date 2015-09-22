//CodeForces 26A
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){
	int a;
	cin >> a;
	vector<int> pri;
	vector<int> result;
	vector<int> com;
	for (int k = 1; k <= a; k++){
		if (k == 1){
			continue;
		}
		if (k == 2 || k == 3){
			pri.push_back(k);
			continue;
		}

		bool ispri = true;
		for (auto it = pri.begin(); it != pri.end(); ++it){
			if (k % (*it) == 0){
				ispri = false;
				break;
			}
		}
		if (ispri == true){
			pri.push_back(k);
		}
		
	}
	int prisz = pri.size();
	for (int i = 0; i < prisz -1 ; ++i){
		for (int j = i + 1; j < prisz; ++j){
			if (pri[i]*pri[j] > a){
				break;
			}
			com.push_back(pri[i]*pri[j]);
		}
	}
	int comsz = com.size();
	for (int k = 1; k <= a; ++k){
		int dv = 0;
		for (int i = 0; i < comsz; ++i){
			if (k % com[i] == 0){
				dv += 1;
			}
			if (dv >= 2){
				break;
			}
		}
		if (dv == 1){
			result.push_back(k);
		}
		else{
			continue;
		}

	}
	cout << result.size() << endl;
	
	




	return 0;
}
