/*
 *	USACO 2015 US Open, Bronze 4
 *	Created by Ziyi Tang
 *	Store left-upper triangular prefix. Check right-lower triangular prefix for
 *	for each square on the diagnal.
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

char grid[23][23];
int n;
set<string> ss;
set<string> re;
void dfs1(int x, int y, int tx, int ty, string now){
	now += grid[tx][ty];
	if(tx == x && ty == y){
		//cout << now << endl;
		ss.insert(now);
		return ;
	}
	if(tx < x)
		dfs1(x,y,tx+1,ty,now);
	if(ty < y)
		dfs1(x,y,tx,ty+1,now);
}
void dfs2(int x, int y, int tx, int ty, string now){
	now += grid[tx][ty];
	if(tx == x && ty == y){
		if(ss.find(now) != ss.end())
			re.insert(now);
	}
	if(tx > x)
		dfs2(x,y,tx-1,ty,now);
	if(ty > y)
		dfs2(x,y,tx,ty-1,now);
}
int main(){
	ifstream ifile("palpath.in");
	ifile >> n;
	string line;
	REP(i,0,n){
		ifile >> line;
		REP(j,0,n){
			grid[i][j] = line[j];
		}
	}
	REP(i,0,n){
		ss.clear();
		int x = i;
		int y = n-1-i;
		dfs1(x,y,0,0,"");
		dfs2(x,y,n-1,n-1,"");
	}
	ifile.close();
	cout << re.size() << endl;
	ofstream ofile("palpath.out");
	ofile << re.size() << endl;
	ofile.close();
	return 0;
}