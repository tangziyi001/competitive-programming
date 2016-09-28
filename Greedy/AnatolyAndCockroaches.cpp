/*
 *	Codeforces 719B - Anatoly and Cockroaches
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
const int INF = (int)1E9;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int main(){
	int n;
	cin >> n;
	string line;
	cin >> line;
	int re = 0;
	string aa;
	string bb;
	REP(i,0,n){
		aa += (i%2) ? 'r' : 'b';
		bb += (i%2) ? 'b' : 'r';
	}
	int aadd = 0;
	int account = 0;
	REP(i,0,n){
		if(line[i] != aa[i]){
			if(aa[i] == 'r'){
				aadd++;
				account++;
			}
			else{
				aadd--;
				account++;
			}
		}
	}
	account = (account-abs(aadd))/2 + abs(aadd);
	int bbdd = 0;
	int bccount = 0;
	REP(i,0,n){
		if(line[i] != bb[i]){
			if(bb[i] == 'r'){
				bbdd++;
				bccount++;
			}
			else{
				bbdd--;
				bccount++;
			}
		}
	}
	bccount = (bccount-abs(bbdd))/2 + abs(bbdd);
	cout << min(abs(account),abs(bccount)) << endl;
	return 0;
}