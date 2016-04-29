/*
 *	UVA 920
 *	Coded by Ziyi Tang
 *	Triangle Computation
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

// Rotate by rotation matrix
point rotate(point now, double theta){
	double rad = theta * M_PI/180.0;
	return point(now.x * cos(rad) - now.y * sin(rad),
			now.x * sin(rad) + now.y * cos(rad));
}

vector<point> all;
int main(){
	int test;
	cin >> test;
	while(test--){
		all.clear();
		int n;
		cin >> n;
		REP(i,0,n){
			int a,b;
			cin >> a >> b;
			all.push_back(point(a,b));
		}
		sort(all.begin(), all.end());
		double height = 0.0;
		double re = 0.0;
		for(int i = n-2; i >= 0; i--){
			point now = all[i];
			if(now.y > height){
				point tmp = all[i+1];
				double hor = tmp.x-now.x;
				double ver = now.y-tmp.y;
				double rad = atan(hor/ver);
				//cout << rad << endl;
				double hh = now.y-height;
				double len = hh/cos(rad);
				re += len;
				height = now.y;
			}
		}
		printf("%.2lf\n", re);

	}
	return 0;
}