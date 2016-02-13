/*
 *	UVA 12321
 *	Created by Ziyi Tang
 *	Interval Covering Greedy
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

vpi all;
int main(){
	int m,n;
	while(cin >> m >> n && (m != 0 || n != 0)){
		int l,r;
		all.clear();
		REP(i,0,n){
			cin >> l >> r;
			all.push_back(make_pair(l-r,l+r));
		}
		sort(all.begin(),all.end());
		int cont = n;
		int far = 0;
		int tmpfar = 0;
		int idx = 0;
		while(tmpfar < m){
			far = tmpfar;
			while(all[idx].first <= tmpfar && idx < n){
				far = max(far, all[idx].second);
				idx++;
			}
			if(far == tmpfar) break;
			tmpfar = far;
			cont--;
			//cout << cont << endl;
		}
		if(tmpfar < m) cout << -1 << endl;
		else cout << cont << endl;
	}
	return 0;
}
