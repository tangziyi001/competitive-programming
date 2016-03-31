/*
 *	USACO 2014 March Contest, Bronze 1
 *	Coded by Ziyi Tang
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

int n;
vi all1;
vi pos;
int main(){
	freopen("reorder.in", "r", stdin);
  	freopen("reorder.out", "w", stdout);
	cin >> n;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all1.push_back(tmp);
	}
	pos.assign(n+1,0);
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		pos[tmp] = i;
	}
	int maxp = 0;
	int cont = 0;
	REP(i,0,n){
		int tmax = 0;
		int tmp = all1[i];
		if(i != pos[tmp]){
			cont++;tmax=1;
		}
		while(i != pos[tmp]){
			int nxt = all1[pos[tmp]];
			all1[pos[tmp]] = tmp;
			tmp = nxt;
			tmax++;
		}
		all1[i] = tmp;
		maxp = max(maxp,tmax);
	}
	if(cont == 0) maxp = -1;
	cout << cont << " " << maxp << endl;
	return 0;
}