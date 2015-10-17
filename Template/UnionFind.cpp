#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

// Union Find
class UnionFind{
private:
	vi p,rank;
public:
	UnionFind (int N){
		rank.assign(N,0);
		p.assign(N,0);
		for (int i = 0; i < N; i++){
			p[i] = i;
		}
	}
	int findRep(int i){
		if (p[i] == i){
			return i;
		}
		return p[i] = findRep(p[i]); // Update parent to the root;
	}
	bool isSameSet(int i, int j){
		return findRep(i) == findRep(j);
	}
	void unionSet(int i, int j){
		if (!isSameSet(i,j)){
			if (rank[i] > rank[j]){
				p[j] = i;
			}
			else if(rank[i] < rank[j]){
				p[i] = j;
			}
			else{
				p[i] = j;
				rank[j]++;
			}
		}
	}

};
