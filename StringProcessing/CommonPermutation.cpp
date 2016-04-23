/*
 *	
 *	Coded by Ziyi Tang, CS480 S16 New York University
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
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

string a,b;
map<char,int> all;
int main(){
	while(getline(cin,a)){
		getline(cin,b);
		if(a == "" || b == ""){
			cout << "" << endl;
			continue;
		}
		all.clear();
		int sz = a.size();
		REP(i,0,sz){
			all[a[i]]++;
		}
		string re;
		sz = b.size();
		REP(i,0,sz){
			if(all[b[i]] != 0){
				all[b[i]]--;
				re += b[i];
			}
		}
		sort(re.begin(), re.end());
		cout << re << endl;
	}
	return 0;
}