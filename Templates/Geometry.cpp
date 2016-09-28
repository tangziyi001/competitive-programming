/*
 *	Geometry Template
 *	Coded by Ziyi Tang
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


// ---------- Vector ----------
struct vec{
	double x,y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b){
	return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s){
	return vec(v.x * s, v.y * s);
}
// Translate a point
point translate(vec v, point p){
	return point(v.x + p.x, v.y + p.y);
}
// Dot Product
double dot(vec a, vec b){
	return a.x * b.x + a.y * b.y;
}
// Norm Square
double norm_sq(vec v){
	return v.x * v.x + v.y * v.y;
}
// Cross Product
double cross(vec a, vec b){ 
	return a.x * b.y - a.y * b.x;
}
// returns true if point r is on the same line as the line pq 
bool collinear(point p, point q, point r) {
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; 
}
// Vector Angle: returns angle aob in rad 
double angle(point a, point o, point b){ 
	vec oa = toVec(o, a);
	vec ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); 
}
// CCW Check
bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > 0; 
}

// Check Intersection for two line segment
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

// ---------- Polygon ----------

// Polygon Area
vector<point> Poly; // Last point is the replicate of the first point
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

// Is convex
// returns true if we always make the same turn while examining
// all the edges of the polygon one by one
bool isConvex(const vector<point> &P) {
  int sz = (int)P.size();
  if (sz <= 3) return false;   // a point/sz=2 or a line/sz=3 is not convex
  bool isLeft = ccw(P[0], P[1], P[2]);               // remember one result
  for (int i = 1; i < sz-1; i++)            // then compare with the others
    if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
      return false;            // different sign -> this polygon is concave
  return true; }  

// Point in polygon
// returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const vector<point> &P) {
	if ((int)P.size() == 0) 
		return false;
  		double sum = 0;    // assume the first vertex is equal to the last vertex
  	for (int i = 0; i < (int)P.size()-1; i++) {
	    if (ccw(pt, P[i], P[i+1]))
	         sum += angle(P[i], pt, P[i+1]);                   // left turn/ccw
	    else sum -= angle(P[i], pt, P[i+1]); 				   // right turn/cw
	}                 
  	return fabs(fabs(sum) - 2*M_PI) < EPS; 
}

// Graham’s Scan algorithm
point pivot(0,0);
bool angleCmp(point a, point b){
	if(collinear(pivot,a,b))
		return dist(pivot, a) < dist(pivot, b);
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}
vector<point> CH(vector<point> P){ 
  	int i, j, n = (int)P.size();
  	if (n <= 3) {
	    if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
	    return P;                           // special case, the CH is P itself
  	}
  	// first, find P0 = point with lowest Y and if tie: rightmost X
	int P0 = 0;
	for (i = 1; i < n; i++)
	if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
	  	P0 = i;
	point temp = P[0]; P[0] = P[P0]; P[P0] = temp;    // swap P[P0] with P[0]
	// second, sort points by angle w.r.t. pivot P0
	pivot = P[0];                    // use this global variable as reference
	sort(++P.begin(), P.end(), angleCmp);              // we do not sort P[0]
	// third, the ccw tests
	vector<point> S;
	S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);   // initial S
	i = 2;                                         // then, we check the rest
	while (i < n){           // note: N must be >= 3 for this method to work
		j = (int)S.size()-1;
		if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);  // left turn, accept
		else S.pop_back(); 
	}
	return S; 
}  



int main(){
	point a(10,10);
	point b(10,10);
	point c(5,18);
	if(a == b) cout << "eq" << endl;
	if(c < b) cout << "bi" << endl;
	return 0;
}