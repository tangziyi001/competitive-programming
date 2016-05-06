/*
 *	UVA 11378
 *	Coded by Ziyi Tang
 *	Find the min of max(horizontal distance, vertical distance) for each pair of points
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

// H/V Distance
int dist(point a, point b){
	return max(abs(a.x-b.x), abs(a.y-b.y));
}
vector<point> all;
int main(){
	int n;
	while(cin >> n){
		all.clear();
		REP(i,0,n){
			int a,b;
			cin >> a >> b;
			all.push_back(point(a,b));
		}
		sort(all.begin(),all.end());
		int minp = INF;
		REP(i,0,n-1){
			REP(j,i+1,n){
				if(all[j].x - all[i].x > minp) break;
				minp = min(minp, dist(all[i],all[j]));
			}
		}
		cout << minp << endl;
	}

	return 0;
}