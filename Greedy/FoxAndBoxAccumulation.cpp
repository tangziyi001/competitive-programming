/*
 *	
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 105
#define MOD 1000000007
vi all;
int mark[MAXN];
bool check(int n){
	REP(i,0,n){
		if(mark[i] == 0) return false;
	}
	return true;
}
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		int tmp; cin >> tmp;
		all.push_back(tmp);
	}
	FILL(mark,0);
	sort(all.begin(), all.end());
	int cont = 0;
	while(!check(n)){
		cont++;
		int high = 0;
		REP(i,0,n){
			if(mark[i] == 0 && all[i] >= high){
				mark[i] = 1;
				high++;
			}
		}
	}
	cout << cont << endl;
	return 0;
}