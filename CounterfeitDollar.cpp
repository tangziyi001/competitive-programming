/*
 *	POJ 1013
 *	Created by Ziyi Tang
 *	Enumerate all possibilities
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

vector<vector<string> > all;
map<char,int> vals;
bool check(){
	REP(i,0,3){
		int left = 0, right = 0;
		string now = all[i][0];
		REP(k,0,now.size()){
			left += vals[now[k]];
		}
		now = all[i][1];
		REP(k,0,now.size()){
			right += vals[now[k]];
		}
		if(all[i][2] == "up" && !(left < right))
			return false;
		if(all[i][2] == "down" && !(left > right))
			return false;
		if(all[i][2] == "even" && !(left == right))
			return false;
	}
	return true;
}
int main(){
	all.assign(3,vector<string>(3,""));
	int n;
	cin >> n;
	while(n--){
		REP(i,0,3){
			REP(j,0,3){
				string line;
				cin >> line;
				all[i][j] = line;
			}
		}
		REP(i,0,12){
			char now = 'A'+i;
			vals[now] = 0;
		}
		REP(i,0,12){
			char now = 'A'+i;
			vals[now] = -1;
			if(check()){
				printf("%c is the counterfeit coin and it is heavy.\n", now);
			}
			vals[now] = 1;
			if(check()){
				printf("%c is the counterfeit coin and it is light.\n", now);
			}
			vals[now] = 0;
		}
	}
	return 0;
}