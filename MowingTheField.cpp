/*
 *	USACO 2016 January Contest, Bronze 3
 *	Created by Ziyi Tang
 *	Implementation & Simulation
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

int all[2010][2010];
int n;

int main(){
	ifstream ifile("mowing.in");
	ifile >> n;
	FILL(all,-1);
	int x = 1005;
	int y = 1005;
	int minp = INF;
	all[x][y] = 0;
	REP(i,0,n){
		char direc;
		int tmp;
		int diridx = 0;
		ifile >> direc >> tmp;
		if(direc == 'N') diridx = 0;
		if(direc == 'E') diridx = 1;
		if(direc == 'S') diridx = 2;
		if(direc == 'W') diridx = 3;
		int tx,ty;
		while(tmp--){
			tx = x + dir[diridx][0];
			ty = y + dir[diridx][1];
			//cout << tx << " " << ty << endl;
			if(all[tx][ty] != -1) minp = min(minp, all[x][y]+1-all[tx][ty]);
			all[tx][ty] = all[x][y] + 1;
			x = tx;
			y = ty;
		}
	}
	ifile.close();
	//cout << minp << endl;
	ofstream ofile("mowing.out");
	if(minp == INF)
		ofile << -1 << endl;
	else 
		ofile << minp << endl;
	ofile.close();
	return 0;
}

