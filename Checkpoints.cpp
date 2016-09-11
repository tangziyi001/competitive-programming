/*
 *	Codeforces 709B - Checkpoints
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

vi all;
int main(){
	int n,a;
	cin >> n >> a;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.push_back(tmp);
	}
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	vi allmin = all;
	vi allmax = all;
	auto maxp = max_element(allmax.begin(), allmax.end());
	allmax.erase(maxp);
	auto minp = min_element(allmin.begin(), allmin.end());
	allmin.erase(minp);
	int maxmax = *max_element(allmax.begin(), allmax.end());
	int maxmin = *min_element(allmax.begin(), allmax.end());
	int minmax = *max_element(allmin.begin(), allmin.end());
	int minmin = *min_element(allmin.begin(), allmin.end());
	int maxdis = min(abs(a-maxmax),abs(a-maxmin)) + maxmax-maxmin;
	int mindis = min(abs(a-minmax),abs(a-minmin)) + minmax-minmin;
	cout << min(maxdis, mindis) << endl;
	return 0;
}