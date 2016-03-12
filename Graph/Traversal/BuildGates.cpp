/*
 *	USACO 2016 January Contest, Silver 3
 *	Created by Ziyi Tang
 *	Flood Fill
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
#define MAXN 2010

int grid[MAXN][MAXN];
int n;
int cont;
string line;
queue<pi> qq;
bool check(int x, int y){
	if(x >= 0 && y >= 0 && x < MAXN && y < MAXN && grid[x][y] == -1)
		return true;
	return false;
}
int main(){
	ifstream ifile("gates.in");
	ifile >> n >> line;
	cout << line << endl;
	int x = MAXN/2, y = MAXN/2;
	FILL(grid,-1);
	grid[x][y] = 0;
	REP(i,0,n){
		char now = line[i];
		int d = 0; 
		if(now == 'N') d = 0;
		if(now == 'E') d = 1;
		if(now == 'S') d = 2;
		if(now == 'W') d = 3;
		int tx = x + dir[d][0];
		int ty = y + dir[d][1];
		grid[tx][ty] = 0;
		x = tx; y = ty;
		tx = x + dir[d][0];
		ty = y + dir[d][1];
		grid[tx][ty] = 0;
		x = tx; y = ty;
	}
	// REP(i,0,MAXN){
	// 	REP(j,0,MAXN){
	// 		cout << grid[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cont = -1;
	REP(i,0,MAXN) REP(j,0,MAXN){
		if(grid[i][j] == -1){
			cont++;
			qq.push(make_pair(i,j));
			grid[i][j] = 1;
			while(!qq.empty()){
				pi now = qq.front();qq.pop();
				int x = now.first;
				int y = now.second;
				REP(i,0,4){
					int tx = x + dir[i][0];
					int ty = y + dir[i][1];
					if(check(tx,ty)){
						grid[tx][ty] = 1;
						qq.push(make_pair(tx,ty));
					}
				}
			}
		}
	}
	ifile.close();
	cout << cont << endl;
	ofstream ofile("gates.out");
	ofile << cont << endl;
	ofile.close();
	return 0;
}