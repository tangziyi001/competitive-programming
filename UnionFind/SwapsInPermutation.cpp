/*
 *	CodeForces 691D
 *	Created by Ziyi Tang
 *
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000010
#define MOD 1000000007

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
unordered_map<int, set<int> > ss;
int main(){
	int m;
	scanf("%d %d", &n, &m);
	// Clear
	FILL(rk,0);
	for(int i = 0; i < n; i++){
		p[i] = i;
	}
	REP(i,0,n){
		int tmp;
		scanf("%d", &tmp);
		all.push_back(tmp);
	}
	REP(i,0,m){
		int a,b;
		scanf("%d %d", &a, &b);
		unionSet(a-1,b-1);
	}
	REP(i,0,n){
		int p = findRep(i);
		if(ss.find(p) == ss.end()){
			ss[p] = set<int>();
		}
		ss[p].insert(all[i]);
	}
	REP(i,0,n){
		if(i != 0) printf(" ");
		int p = findRep(i);
		printf("%d",*ss[p].rbegin());
		auto it = ss[p].end();
		--it;
		ss[p].erase(it);
	}
	printf("\n");
	return 0;
}