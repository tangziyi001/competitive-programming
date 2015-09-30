//UVA 924
// BFS for finding the level containg most elements

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;
map<int,vector<int> > all;
typedef pair<int,int> PP;
map<int, int> countall;
queue<int> que;
set<int> exp;


void check(int source){

	que.push(source);
	que.push(-1);
	exp.insert(source);
	int layer = 0;
	int count = 0;
	while (!que.empty()){
		int tmp = que.front();que.pop();
		if (tmp == -1){
			countall[layer] = count;
			count = 0;
			layer = layer + 1;
			// Make sure to check this
			if (!que.empty()){
				que.push(-1);
			}
		}
		else {
			count += 1;
			for (auto it = all[tmp].begin(); it != all[tmp].end(); it++){
				if (exp.find(*it) == exp.end()){
					que.push(*it);
					exp.insert(*it);
				}
				
			}
		}

	}
}

int main (){
	int people;
	cin >> people;
	for (int i = 0; i < people; i++){
		int friends = 0;
		cin >> friends;
		for (int j = 0; j < friends; j++){
			int tmp;
			cin >> tmp;
			all[i].push_back(tmp);
		}
	}
	int test;
	cin >> test;
	while (test--){
		countall.clear();
		exp.clear();
		int tmp = 0;
		cin >> tmp;
		check(tmp);
		int sz = countall.size();
		int m = -1;
		int d = -1;
		for (int i = 1; i < sz; i++){
			if (countall[i] > m){
				m = countall[i];
				d = i;
			}
		}
		if (m <= 0){
			cout << 0 << endl;
		}
		else{
			cout << m << " " << d << endl;
		}

	}




	return 0;
}