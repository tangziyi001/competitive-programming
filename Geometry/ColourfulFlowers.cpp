/*
 *	UVA 11152
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
struct point{
	double x,y;
	point(){x=y=0;}
	point(double x_, double y_) : x(x_), y(y_) {}
};
double perimeter(double a, double b, double c){
	return a+b+c;
}
double area(double a, double b, double c){
	double p = perimeter(a,b,c);
	p/=2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
double rInCircle(double ab, double bc, double ca) {
	return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca)); }
double rCircumCircle(double ab, double bc, double ca) { 
	return ab * bc * ca / (4.0 * area(ab, bc, ca)); }
int main(){
	double a,b,c;
	while(cin >> a >> b >> c){
		double A = area(a,b,c);
		double in = rInCircle(a,b,c)*rInCircle(a,b,c)*M_PI;
		double out = rCircumCircle(a,b,c)*rCircumCircle(a,b,c)*M_PI;
		printf("%.4f %.4f %.4f\n", out-A,A-in,in);
	}
	return 0;
}
