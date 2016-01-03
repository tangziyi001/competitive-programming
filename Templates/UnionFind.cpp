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
#define FILL(x,v) memset(x,v,sizeof(x));


int all[MAXN];
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
		int p1 = findRep(i);
		int p2 = findRep(j);
		if (rk[p1] > rk[p2]){
			p[p2] = p1;
		}
		else if(rk[p1] < rk[p2]){
			p[p1] = p2;
		}
		else{
			p[p1] = p2;
			rk[p2]++;
		}
	}
}
int main(){
	// Input n elements
	cin >> n;

	// Clear
	FILL(all,0);
	FILL(rk,0);
	for(int i = 0; i < n; i++){
		all[i] = i;
		p[i] = i;
	}
	



	return 0;
}
