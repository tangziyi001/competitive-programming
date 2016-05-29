/*
 *	CodeForces 675D - Tree Construction
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

map<int,int> le;
vi re;
set<int> ss;
int main(){
	int n, tmp;
	cin >> n;
	cin >> tmp;
	ss.insert(tmp);
	REP(i,0,n-1){
		int tmp;
		cin >> tmp;
		auto it = ss.upper_bound(tmp);
		if(it == ss.end() || le.count(*it) != 0){
			it--;
			re.push_back(*it);
			ss.insert(tmp);
		}
		else{
			re.push_back(*it);
			le[*it] = tmp;
			ss.insert(tmp);
		}
	}
	REP(i,0,n-1){
		cout << re[i] << " ";
	}
	cout << endl;
	
	return 0;
}