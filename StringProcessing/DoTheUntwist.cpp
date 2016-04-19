/*
 *	UVA 00641
 *	Coded by Ziyi Tang, CS480 S16 New York University
 *	Basic String processing
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
#define MOD 1000000007

vi cc;
vi pc;
map<char, int> mm;
vector<char> ii;
int main(){
	int n,k;
	string line;
	ii.assign(28,'n');
	mm['_'] = 0;
	ii[0] = '_';
	mm['.'] = 27;
	ii[27] = '.';
	REP(i,0,26){
		mm[(char)(i+'a')] = i+1;
		ii[i+1] = (char)(i+'a');
	}
	while(cin >> k && k != 0){
		cin >> line;
		cc.clear();
		pc.clear();
		n = line.size();
		REP(i,0,n){
			cc.push_back(mm[line[i]]);
		}
		pc.assign(n,0);
		REP(i,0,n){
			int idx = (k*i)%n;
			pc[idx] = (cc[i]+i)%28;
		}
		string re = "";
		REP(i,0,n){
			re+=ii[pc[i]];
		}
		cout << re << endl;
	}
	return 0;
}