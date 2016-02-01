/*
 *	CodeForces 341B
 *	Created by Ziyi Tang
 *	Diagonal Manipulation
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
#define MAXN 1005

int all1[2010];
int all2[2010];
vpi pp;
int main(){
	int n;
	cin >> n;
	FILL(all1,0);
	FILL(all2,0);
	REP(i,0,n){
		int a,b;
		cin >> a >> b;
		all1[a+b]++;
		all2[a-b+1005]++;
	}
	int re = 0;
	REP(i,0,2010){
		int tmp1 = all1[i];
		int tmp2 = all2[i];
		if(tmp1 > 1) re = re + (1+tmp1-1)*(tmp1-1)/2;
		if(tmp2 > 1) re = re + (1+tmp2-1)*(tmp2-1)/2;
	}
	cout << re << endl;
	
	return 0;
}
