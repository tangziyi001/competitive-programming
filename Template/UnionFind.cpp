/*
 *	Union Find
 *	Created by Ziyi Tang
 *
 */
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
#define MAXN 100


vi all;
int n;
int p[MAXN];
int rank[MAXN];
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
int main(){
	cin >> n;
	all.assign(n,0);
	for(int i = 0; i < n; i++){
		all[i] = i;
	}



	return 0;
}

