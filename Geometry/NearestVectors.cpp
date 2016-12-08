/*
 *	CodeForces 598C
 *	Created by Ziyi Tang
 *	Sort Vectors based on rad and compare neighbors
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
#define M_PI 3.14159265359
struct vec{
	long double x,y;
	vec(long double _x, long double _y) : x(_x), y(_y) {}
	bool operator < (vec tmp) const {
		return atan2(y,x) < atan2(tmp.y, tmp.x);	
	}
};
long double ang(vec a){
	return atan2(a.y, a.x);
}
bool comp (vec a, vec b){
	return a < b;
}
vector<vec> all;
map<vec, int> mm;

int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		long double x,y;
		cin >> x >> y;
		all.push_back(vec(x,y));
		mm[vec(x,y)] = i;
	}
	int ii,jj;
	sort(all.begin(), all.end(), comp);
	long double minp = 1e9;
	REP(i,0,n-1){
		if(abs(ang(all[i+1])-ang(all[i])) < minp){
			ii = i+1; jj = i;
			minp = abs(ang(all[i+1])-ang(all[i]));
		}
	}
	if(ang(all[0])+2*M_PI-ang(all[n-1]) < minp){
			ii = 0; jj = n-1;
	}
	cout << mm[all[ii]]+1 << " " << mm[all[jj]]+1 << endl;
	return 0;
}
