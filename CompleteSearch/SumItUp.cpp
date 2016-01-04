/*
 *	UVA 00574
 *	Created by Ziyi Tang
 *	Backtrack
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
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

vi all;
vi now;
set<vi> ss;
int n,k;
int cont = 0;
void rec(int pos, int sum){
	if(sum == n && ss.find(now) == ss.end()){
		int sz = now.size();
		ss.insert(now);
		cont++;
		REP(i,0,sz){
			if(i != 0)
				cout << "+";
			cout << now[i];
		}
		cout << endl;
		return;
	}
	if(pos == k) return;
	else{
		if(sum + all[pos] <= n){
			now.push_back(all[pos]);
			rec(pos+1, sum+all[pos]);
			now.pop_back();
		}
		rec(pos+1, sum);
	}
}
int main(){

	while(cin >> n >> k && n != 0 && k != 0){
		cont = 0;
		ss.clear();
		all.clear();
		now.clear();
		REP(i,0,k){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		printf("Sums of %d:\n", n);
		rec(0,0);
		if(cont == 0)
			cout << "NONE" << endl;

	}
	return 0;
}
