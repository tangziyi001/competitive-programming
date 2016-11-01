/*
 *	UVA 10724
 *	Created by Ziyi Tang
 *	Add one edge after floyd warshall
 *	Compute all changes to the shortest path of any two vertex
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
#define MAXN 55
#define MOD 1000000007
#define EPS 1e-7
int n,m;
double all[MAXN][MAXN];
int mark[MAXN][MAXN];
struct Point{
	int x,y;
	double dist(const Point& tmp) {
		return sqrt((x-tmp.x)*(x-tmp.x)+(y-tmp.y)*(y-tmp.y));
	}
} points[55];
int main(){
	while(cin >> n >> m && (n!=0||m!=0)){
		FILL(mark,0);
		REP(i,0,MAXN) REP(j,0,MAXN) {
			all[i][j] = INF;
			if(i == j) {
				all[i][j] = 0.0;
				mark[i][j] = 1;
			}
		}
		REP(i,0,n){
			int a,b;
			cin >> a >> b;
			points[i].x = a;
			points[i].y = b;
		}
		REP(i,0,m){
			int a,b;
			cin >> a >> b;
			mark[a-1][b-1] = mark[b-1][a-1] = 1;
			all[a-1][b-1] = all[b-1][a-1] = points[a-1].dist(points[b-1]);
		}
		REP(k,0,n) REP(i,0,n) REP(j,0,n) {
			if(all[i][k] == INF || all[k][j] == INF) continue;
			all[i][j] = min(all[i][j], all[i][k] + all[k][j]);
		}
		double sum = 0;
		int ri,rj;
		double sd = INF;
		REP(i,0,n){
			REP(j,0,n){
				sum += all[i][j]; 
			}
		}
		double after = sum;
		double tmp[55][55];
		REP(r,0,n-1) REP(c,r+1,n) if(mark[r][c] == 0) {
			REP(i,0,n) REP(j,0,n) tmp[i][j] = all[i][j];
			double len = points[r].dist(points[c]);
			double now = sum;
			REP(i,0,n) REP(j,0,n) {
				if(tmp[i][j] > tmp[i][r] + len + tmp[c][j] &&
					tmp[i][j] > tmp[i][c] + len + tmp[r][j]) {
					now = min(now-tmp[i][j] + tmp[i][r] + len + tmp[c][j], 
							now-tmp[i][j] + tmp[i][c] + len + tmp[r][j]);
					continue;
				}
				if(tmp[i][j] > tmp[i][r] + len + tmp[c][j]){
					now = now-tmp[i][j] + tmp[i][r] + len + tmp[c][j];
				}
				if(tmp[i][j] > tmp[i][c] + len + tmp[r][j]){
					now = now-tmp[i][j] + tmp[i][c] + len + tmp[r][j];
				}
			}
			if(now - after < 0.0){
				ri = r;
				rj = c;
				after = now;
				sd = len;
			} else if(fabs(now-after) < EPS && len-sd < 0.0){
				ri = r; rj = c;
				sd = len;
			}
		}
		if((sum-after) - 1.0 > EPS){
			cout << ri+1 << " " << rj+1 << endl;
		} else {
			cout << "No road required" << endl;
		}
	}
	return 0;
}