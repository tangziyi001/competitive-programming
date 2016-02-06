/*
 *	UVA 11683
 *	Created by Ziyi Tang
 *	Trick: for each bar i, add a[i] - a[i-1] to the sum if i is taller than i-1.
 *	For the last bar, add the difference between the max height and that bar.
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

vector<int> all;
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m) && (n != 0 && m != 0)){
		all.clear();
		int sum = 0;
		REP(i,0,m){
			int tmp;
			scanf("%d",&tmp);
			all.push_back(tmp);
		}
		all.push_back(n);
		REP(i,1,m+1){
			//cout << all[i]-all[i-1] << endl;
			sum += (all[i]-all[i-1] > 0 ? (all[i]-all[i-1]) : 0);
		}
		cout << sum << endl;
	}
	return 0;
}
