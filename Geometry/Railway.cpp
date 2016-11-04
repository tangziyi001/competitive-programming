/*
 *	UVA 10263
 *	Created by Ziyi Tang
 *
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
#define MAXN 1000
#define MOD 1000000007

struct Point{
	double x,y;
	Point() {x = y = 0.0;}
	Point(double x_, double y_) : x(x_), y(y_) {}
};
struct vec{
	double x,y;
	vec(double x_, double y_) : x(x_), y(y_) {}
};
double dist(Point a, Point b){
	return hypot(a.x-b.x, a.y-b.y);
}
vec toVec(Point a, Point b){
	return vec(b.x-a.x, b.y-a.y);
}
double norm_sq(vec v){
	return v.x * v.x + v.y * v.y;
}
Point translate(Point p, vec v){
	return Point(v.x+p.x, v.y+p.y);
}
vec scale(vec v, double s){
	return vec(v.x*s, v.y*s);
}
double dot(vec a, vec b){
	return a.x*b.x+a.y*b.y;
}
double distToLine(Point p, Point a, Point b, Point &c) {
	// formula: c = a + u * ab
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u)); // translate a to c 
	return dist(p, c); 
} // Euclidean distance between p and c
double distToLineSeg(Point p, Point a, Point b, Point& c){
	vec ap = toVec(a,p);
	vec ab = toVec(a,b);
	double u = dot(ap,ab)/norm_sq(ab);
	if (u < 0.0) { c = Point(a.x, a.y);
		return dist(p, a); }
	if (u > 1.0) { c = Point(b.x, b.y);
		return dist(p, b); } 
	return distToLine(p, a, b, c);
}
int main(){
	double a,b;
	while(cin >> a >> b){
		Point m(a,b);
		int n;
		cin >> n;
		vector<Point> all;
		REP(i,0,n+1){
			double x,y; cin >> x >> y;
			all.push_back(Point(x,y));
		}
		double minp = INF;
		Point re;
		REP(i,0,n){
			Point a = all[i];
			Point b = all[i+1];
			Point c;
			double tmp = distToLineSeg(m, a, b, c);
			if(tmp < minp){
				re = c;
				minp = tmp;
			}
		}
		printf("%.4f\n%.4f\n",re.x, re.y);
	}
	return 0;
}
