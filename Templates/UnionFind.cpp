/*
 *	Union Find Template
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
#define MAXN 1000


vi all;
int n;
int p[MAXN];
int rk[MAXN];
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
		if (rk[i] > rk[j]){
			p[j] = i;
		}
		else if(rk[i] < rk[j]){
			p[i] = j;
		}
		else{
			p[i] = j;
			rk[j]++;
		}
	}
}
int main(){
	// Input n elements
	cin >> n;

	// Clear
	all.clear();
	all.assign(n,0);
	for(int i = 0; i < n; i++){
		all[i] = i;
	}
	



	return 0;
}

