/*
 *	UVA 11130
 *	Created by Ziyi Tang
 *	Reflection of Table. Use of sin, cos functions with Rad. Rad = 3.1415*angle/180
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

int main(){
	int a,b,v,A,s;
	while(cin >> a >> b >> v >> A >> s && (a!=0||b!=0||v!=0||A!=0||s!=0)){
		double len = (double)v*s/2;
		double hor = len*cos(A*3.1415/180);
		double ver = len*sin(A*3.1415/180);
		int h = (hor-0.5*a)/a;
		int v = (ver-0.5*b)/b;
		if(hor >= 0.5*a) h++;
		if(ver >= 0.5*b) v++;
		printf("%d %d\n",h,v);
	}
	return 0;
}
