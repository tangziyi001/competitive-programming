//UVA 11348
// Handle "zero" cases
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

int main(){
	int test;
	cin >> test;
	for (int i = 0; i < test; i++){
		int people;
		cin >> people;
		set<int> all;
		set<int> era;
		vector<int> indi[100];
		for (int j = 0;j < people; j++){
			int num;
			cin >> num;
			set<int> own_uni;
			for (int k = 0; k < num; ++k){
				int tmp;
				cin >> tmp;
				indi[j].push_back(tmp);
				
				if(all.find(tmp) == all.end() && era.find(tmp) == era.end()){
					all.insert(tmp);
					own_uni.insert(tmp);
				}
				else if (all.find(tmp) != all.end() && own_uni.find(tmp) != own_uni.end()){
					continue;
				}
				else{
					all.erase(tmp);
					era.insert(tmp);
				}
			}
		}

		int sa[100];
		int sum = 0;
		for (int j = 0; j < people; j++){
			vector<int> tmp = indi[j];
			int count = 0;
			set<int> exi;
			for (auto it = tmp.begin(); it != tmp.end(); ++it){
				if (all.find(*it) != all.end()){
					if (exi.find(*it) == exi.end()){
						count += 1;
						sum += 1;
						exi.insert(*it);
					}
					
				}
			}
			sa[j] = count;
		}
		
		cout << "Case " << i+1 << ":";
		if (sum == 0){
			// for (int i = 0; i < people; i++){
			// 	printf(" %.6f%%", 0.0);
			// }
			
		}
		else if(people < 1){

		}

		else{
			for (int i = 0; i < people; i++){
				printf(" %.6f%%", (double)(sa[i] * 100)/sum);
			}
		}
		cout << endl;



	}

	return 0;
}