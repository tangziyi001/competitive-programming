//UVA 10258
// Multi-field sort
// Trap: A contestant may repeatly submit the answer to the same question

#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,vector<int> > piv;
typedef vector<piv> vp;

bool comp(piv a, piv b){
	if ((a.second)[0] != (b.second)[0]){
		return (a.second)[0] > (b.second)[0];
	}
	else if ((a.second)[1] != (b.second)[1]){
		return (a.second)[1] < (b.second)[1];
	}
	else{
		return a.first < b.first;
	}
}
int main(){
	int test;
	scanf("%d",&test);
	string tmp;
	getline(cin,tmp);
	getline(cin,tmp);
	while (test--){
		// 0: correct
		// 1: time
		// 2-10: prob incorrect time
		vector<int> tmp(11,0);
		vp all(105, make_pair(-1,tmp));
		string tmp1;
		int people, prob, time;
		char sig;
		while (getline(cin,tmp1) && tmp1 != ""){
			stringstream ss(tmp1);
			ss >> people >> prob >> time >> sig;
			all[people].first = people;
			if (sig == 'C' && (all[people].second)[prob+1] != -1){
				(all[people].second)[1] += (time+20*(all[people].second)[prob+1]);
				(all[people].second)[0] += 1;
				(all[people].second)[prob+1] = -1;
			}
			else if(sig == 'I' && (all[people].second)[prob+1] != -1){
				(all[people].second)[prob+1] += 1;
			}
			
		}
		sort(all.begin(), all.end(), comp);
		for (auto it = all.begin(); it != all.end(); it++){
			if ((*it).first != -1){
				printf("%d %d %d\n", (*it).first, ((*it).second)[0],((*it).second)[1]);
			}
		}
		if (test != 0){
				printf("\n");
		}
		

		
	}



	return 0;
}
