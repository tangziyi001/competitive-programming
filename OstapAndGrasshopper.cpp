/*
 *	Codeforces 735A - Ostap and Grasshopper
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

int n,m;
string line;
int main(){
	cin >> n >> m;
	cin >> line;
	int sta,ter;
	REP(i,0,n){
		if(line[i] == 'G') sta = i;
		if(line[i] == 'T') ter = i;
	}
	for(int i = sta; i < line.size(); i+=m){
		if(line[i] == '#') break;
		if(i == ter){
			cout << "YES" << endl;
			return 0;
		}
	}
	for(int i = sta; i >= 0; i-=m){
		if(line[i] == '#') break;
		if(i == ter){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}