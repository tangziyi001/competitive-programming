/*
 *	Codeforces 782A - Andryusha and Socks
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
#define MAXN 1000
#define MOD 1000000007
set<int> ss;
int main(){
	int n;
	cin >> n;
	int maxp = 0;
	int cont = 0;
	REP(i,0,2*n){
		int tmp;
		cin >> tmp;
		if(ss.count(tmp)){
			ss.erase(tmp);
			cont--;
		} else{
			ss.insert(tmp);
			cont++;
		}
		maxp = max(maxp, cont);
	}
	cout << maxp << endl;
	return 0;
}