/*
 *	CodeForces 611C
 *	Created by Ziyi Tang
 *	Prefix sum for both horizontal and vertical possibilities
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

int hdp[505][505];
int vdp[505][505];
char all[505][505];
int main(){
	FILL(hdp,0);
	FILL(vdp,0);
	int n,m;
	cin >> n >> m;
	REP(i,0,n+1) REP(j,0,m+1){
		all[i][j] = '#';
	}
	REP(i,1,n+1){
		string line;
		cin >> line;
		REP(j,1,m+1){
			all[i][j] = line[j-1];
		}
	}
	REP(i,1,n+1) REP(j,1,m+1){
		hdp[i][j] = hdp[i-1][j] + hdp[i][j-1] - hdp[i-1][j-1];
		if(all[i][j] == '.' && all[i][j-1] == '.')
			hdp[i][j]+=1;
		vdp[i][j] = vdp[i-1][j] + vdp[i][j-1] - vdp[i-1][j-1];
		if(all[i][j] == '.' && all[i-1][j] == '.')
			vdp[i][j]+=1;
	}
	REP(i,1,n+1){
		REP(j,1,m+1){
			cout << hdp[i][j] << " ";
		}
		cout << endl;
	}
	REP(i,1,n+1){
		REP(j,1,m+1){
			cout << vdp[i][j] << " ";
		}
		cout << endl;
	}
	int qq;
	cin >> qq;
	int r1,r2,c1,c2;
	int cont = 0;
	REP(i,0,qq){
		cin >> r1 >> c1 >> r2 >> c2;
		cont = hdp[r2][c2]-hdp[r1-1][c2]-hdp[r2][c1]+hdp[r1-1][c1]+hdp[r2][c1-1];
		cont += vdp[r2][c2]-vdp[r2][c1-1]-vdp[r1][c2]+vdp[r1][c1-1]+vdp[r1-1][c2];
		cout << cont << endl;
	}

	return 0;
}