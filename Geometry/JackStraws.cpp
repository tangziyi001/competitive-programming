/*
 *	UVA 273
 *	Coded by Ziyi Tang
 *	Check intersection for two line segments
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
#define MOD 1000000007
#define EPS 1e-9

// ---------- Point ----------
struct point{
	double x,y;
	point(){x = y = 0;}
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point tmp) const{
		if(fabs(x - tmp.x) > EPS)
			return x < tmp.x;
		return y < tmp.y;
	}
	bool operator == (point tmp) const{
		return (fabs(x - tmp.x) < EPS && fabs(y - tmp.y) < EPS);
	}
};

// Euclid Distance
double dist(point a, point b){
	return hypot(a.x-b.x, a.y-b.y);
}

// ---------- Vector ----------
struct vec{
	double x,y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b){
	return vec(b.x - a.x, b.y - a.y);
}
// Cross Product
double cross(vec a, vec b){ 
	return a.x * b.y - a.y * b.x;
}
// CCW
bool ccw(point p, point q, point r){
	//if(collinear(p,q,r)) return 0;
	return cross(toVec(p,q), toVec(p,r)) > 0;
}

vector<pair<point, point> > all;
int adj[15][15];


// Check Intersection
bool check(pair<point, point> a, pair<point, point> b){
	if(max(a.first.x,a.second.x) >= min(b.first.x, b.second.x)
		&& max(a.first.y,a.second.y) >= min(b.first.y, b.second.y)
		&& max(b.first.x,b.second.x) >= min(a.first.x, a.second.x)
		&& max(b.first.y,b.second.y) >= min(a.first.y, a.second.y)){
		if(cross(toVec(a.first, b.first), toVec(a.first, a.second)) * cross(toVec(a.first, a.second), toVec(a.second, b.second)) >= 0
		&& cross(toVec(b.first, a.first), toVec(b.first, b.second)) * cross(toVec(b.first, b.second), toVec(b.second, a.second)) >= 0 )
		return true;
	}
	return false;
}
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		all.clear();
		FILL(adj,0);
		if(t != 1) cout << endl;
		int n;
		cin >> n;
		REP(i,0,n){
			int x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			all.push_back(make_pair(point(x1,y1),point(x2,y2)));
		}
		REP(i,0,n)
			adj[i][i] = 1;
		REP(i,0,n){
			REP(j,0,n){
				if(check(all[i],all[j])){
					adj[i][j] = 1;
					adj[j][i] = 1;
				}
			}
		}
		REP(k,0,n) REP(i,0,n) REP(j,0,n){
			adj[i][j] |= (adj[i][k] & adj[k][j]);
		}
		// REP(i,0,n){
		// 	REP(j,0,n){
		// 		cout << adj[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		int f,s;
		while(cin >> f >> s && f != 0 && s != 0){
			if(adj[f-1][s-1])
				cout << "CONNECTED" << endl;
			else
				cout << "NOT CONNECTED"<< endl;
		}
	}

	return 0;
}