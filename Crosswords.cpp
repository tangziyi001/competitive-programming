/*
 *	USACO 2014 December Contest, Bronze 2
 *	Coded by Ziyi Tang
 *	
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

int n,m;
char all[55][55];
vpi re;
bool inbound(int x, int y){
	if(x >= 0 && y >= 0 && x < n && y < m)
		return true;
	return false;
}
bool check(int x, int y){
	bool flag = false;
	if(all[x][y] == '.' && inbound(x+1,y) && all[x+1][y] == '.' && inbound(x+2,y) && all[x+2][y] == '.' && (!inbound(x-1,y) || all[x-1][y] == '#'))
		flag = true;
	if(all[x][y] == '.' && inbound(x,y+1) && all[x][y+1] == '.' && inbound(x,y+2) && all[x][y+2] == '.' && (!inbound(x,y-1) || all[x][y-1] == '#'))
		flag = true;
	return flag;
}
int main(){
	freopen("crosswords.in", "r", stdin);
  	freopen("crosswords.out", "w", stdout);
  	cin >> n >> m;
  	REP(i,0,n){
  		string line;
  		cin >> line;
  		REP(j,0,m){
  			all[i][j] = line[j];
  		}
  	}
  	REP(i,0,n) REP(j,0,m){
  		if(check(i,j))
  			re.push_back(make_pair(i,j));
  	}
  	int sz = re.size();
  	cout << sz << endl;
  	REP(i,0,sz){
  		cout << re[i].first+1 << " " << re[i].second+1 << endl;
  	}
	return 0;
}