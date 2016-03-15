/*
 *	USACO 2015 February Contest, Bronze 1
 *	Coded by Ziyi Tang
 *	String Comparison (Build string from the tail)
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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
string line;
string p;
string re;

int main(){
	freopen("censor.in", "r", stdin);
  	freopen("censor.out", "w", stdout);
	cin >> line >> p;
	int sz = line.size();
	int n = p.size();
	int rz = 0;
	REP(i,0,sz){
		re+=line[i];
		rz++;
		//cout << re << endl;
		if(i >= n-1 && rz >= n && re[rz-1] == p[n-1] && re.substr(rz-n,n) == p){
			re = re.substr(0,rz-n);
			rz-=n;
		}
	}
	cout << re << endl;
	return 0;
}