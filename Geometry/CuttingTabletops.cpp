/*
 *	UVA 10406
 *	Coded by Ziyi Tang
 *	Geometry
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
#define EPS 1e-8

// Point
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

// Polygon Area
vector<point> Poly;
double area(const vector<point> &P) {
	double result = 0.0, x1, y1, x2, y2;
	int sz = P.size();
	for (int i = 0; i < sz-1; i++) {
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y; 
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0; 
}

// Vector
struct vec{
	double x,y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b){
	return vec(b.x - a.x, b.y - a.y);
}
// Dot Product
double dot(vec a, vec b){
	return a.x * b.x + a.y * b.y;
}
// Norm Square
double norm_sq(vec v){
	return v.x * v.x + v.y * v.y;
}


// Vector Angle: returns angle aob in rad 
double angle(point a, point o, point b){ 
	vec oa = toVec(o, a);
	vec ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); 
}

int main(){
	double d;
	int n;
	while(cin >> d >> n && (fabs(d-0.0) > EPS || n != 0)){
		Poly.clear();
		REP(i,0,n){
			double tx,ty;
			cin >> tx >> ty;
			Poly.push_back(point(tx,ty));
		}
		Poly.push_back(Poly[0]);
		double ori_area = area(Poly);
		//cout << ori_area << endl;
		REP(i,0,n){
			point a = Poly[i];
			point b = Poly[i+1];
			double dis = dist(a,b);
			ori_area -= dis*d;
		}
		REP(i,0,n){
			point now = Poly[i];
			point left = Poly[(i-1+n)%n];
			point right = Poly[i+1];
			double ang = angle(left,now,right);
			if(fabs(ang - M_PI/2.0) < EPS){
				//cout << "an" << endl;
				ori_area += d*d;
			}else{
				double theta = ang/2.0;
				double tri_double = d*d/(tan(theta));
				ori_area += tri_double;
			}
		}
		printf("%.3lf\n", ori_area);
	}
}