/*
 *	CodeForces 667A - Pouring Rain
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
#define PI 3.14159265358979323846  /* pi */

int main(){
	int d,h,v,e;
	cin >> d >> h >> v >> e;
	double r = (double)d/2;
	double vv = (e-v/(PI*r*r));
	if(vv >= 0){
		cout << "NO" << endl;
	}
	else{
		printf("YES\n");
		double re = -h/vv;
		printf("%.9lf\n", re);
	}

		

	return 0;
}