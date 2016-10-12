/*
 *	UVA 10608
 *	Created by Ziyi Tang
 *	Union Find
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
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define MAXN 30005
#define FILL(x,v) memset(x,v,sizeof(x));


int all[MAXN];
int n,m;
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
	int test;
	cin >> test;
	REP(t,0,test){

		// Input n elements
		cin >> n >> m;

		// Clear
		FILL(all,0);
		FILL(rk,0);
		REP(i,0,n){
			all[i] = i;
			p[i] = i;
		}
		REP(i,0,m){
			int a,b;
			cin >> a >> b;
			unionSet(a,b);
		}
		int maxp = 0;
		map<int, int> mm;
		REP(i,0,n){
			mm[findRep(i)]++;
			maxp = max(mm[findRep(i)], maxp);
		}
		cout << maxp << endl;
	}


	return 0;
}
