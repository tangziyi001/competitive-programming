/*
 *	Yandex Algorithm Qualification Round A
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
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

map<string,int> mm;
set<string> ss;
vector<string> all;
bool check(string a, string b){
	int diff = 0;
	int sz = a.size();
	REP(i,0,sz){
		if(a[i] != b[i])
			diff++;
	}
	return diff <= 1;
}
int main(){
	int n;
	string line;
	cin >> n;
	REP(i,0,n){
		cin >> line;
		if(ss.find(line) == ss.end()){
			all.push_back(line);
			ss.insert(line);
		}
	}
	n = all.size();
	REP(i,0,n){
		REP(j,0,n){
			if(check(all[i],all[j]))
				mm[all[i]]++;
		}
	}
	for(auto it = mm.begin(); it != mm.end(); it++){
		if((*it).second == n){
			cout << (*it).first << endl;
			break;
		}
	}
	return 0;
}