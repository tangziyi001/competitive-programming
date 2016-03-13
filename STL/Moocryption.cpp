/*
 *	USACO 2015 US Open, Bronze 1
 *	Created by Ziyi Tang
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
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

unordered_map<string,int> all;
char grid[55][55];
int n,m;
bool check(int x,int y){
	if(x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}
int main(){
	ifstream ifile("moocrypt.in");
	ifile >> n >> m;
	REP(i,0,n){
		string line;
		ifile >> line;
		REP(j,0,m)
			grid[i][j] = line[j];
	}
	ifile.close();
	REP(i,0,n) REP(j,0,m){
		char now = grid[i][j];
		REP(k,0,8){
			int nx = i + dir[k][0];
			int ny = j + dir[k][1];
			int tx = i + 2*dir[k][0];
			int ty = j + 2*dir[k][1];
			if(check(nx,ny) && check(tx,ty)){
				if(grid[tx][ty] == grid[nx][ny] && grid[i][j] != grid[tx][ty] && grid[i][j] != 'M' && grid[tx][ty] != 'O'){
					string now = "";
					now += grid[i][j];
					now += grid[nx][ny];
					now += grid[tx][ty];
					if(all.find(now) == all.end())
						all[now] = 1;
					else all[now] += 1;
					//cout << all[now] << " " << now << endl;
				}
			}
		}
	}
	int maxp = 0;
	for(auto it = all.begin(); it != all.end(); it++){
		maxp = max(maxp, (*it).second);
	}
	cout << maxp << endl;
	ofstream ofile("moocrypt.out");
	ofile << maxp << endl;
	ofile.close();
	return 0;
}