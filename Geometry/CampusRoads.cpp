/*
 *	UVA 11473
 *	Created by Ziyi Tang
 *	Basic Geometry
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
#define MAXN 1q0
#define MOD 1000000007

int test;
vector<double> sum;
struct Point{
	double x,y;
	Point(): x(0), y(0) {}
};
double dist(Point a, Point b){
	return hypot(a.x-b.x,a.y-b.y);
}
vector<Point> all;
int main(){
	cin >> test;
	REP(cas,1,test+1){
		printf("Road #%d:\n", cas);
		all.clear();
		int k,t;
		cin >> k >> t;
		sum.assign(k,0.0);
		REP(i,0,k){
			double a,b;
			cin >> a >> b;
			Point tmp;
			tmp.x = a; tmp.y = b;
			all.push_back(tmp);
			if(i != 0){
				double dis = dist(all[i-1],all[i]);
				sum[i] = sum[i-1]+dis;
			}
		}
		double avg = sum[k-1]/(t-1);
		REP(i,0,t){
			if(i == 0) printf("%.2f %.2f\n", all[0].x, all[0].y);
			else if(i == t-1) printf("%.2f %.2f\n", all[k-1].x, all[k-1].y);
			else{
				auto now = upper_bound(sum.begin(), sum.end(), avg*i);
				int idx = distance(sum.begin(), now)-1;
				double rem = avg*i-sum[idx];
				double l = sum[idx+1]-sum[idx];
				double lx = all[idx+1].x-all[idx].x;
				double ly = all[idx+1].y-all[idx].y;
				double tx = all[idx].x;
				double ty = all[idx].y;
				tx += lx*rem/l;
				ty += ly*rem/l;
				//cout << distance(sum.begin(), now)<< ":" << avg*i << endl;
				printf("%.2f %.2f\n", tx, ty);
			}
		}
		cout << endl;
	}
	return 0;
}