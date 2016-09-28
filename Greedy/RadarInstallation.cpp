/*
 *	UVA 1193
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
const int INF = (int)1E9;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int n,d;
vector<pair<double,double> > inv;
int main(){
	int test = 0;
	while(cin >> n >> d && (n != 0 || d != 0)){
		test++;
		inv.clear();
		int flag = 1;
		REP(i,0,n){
			int a,b;
			cin >> a >> b;
			if(b > d){
				flag = 0;
			}
			double r = sqrt(d*d-b*b);
			inv.push_back(make_pair(a-r,a+r));
		}
		if(!flag){
			printf("Case %d: -1\n",test);
			continue;
		}
		sort(inv.begin(), inv.end());
		double tail = 0.0;
		int count = 1;
		tail = inv[0].second;
		REP(i,1,n){
			double sta = inv[i].first;
			double end = inv[i].second;
			if(sta > tail){
				count++;
				tail = end;
			} else {
				tail = min(tail, end);
			}
		}
		printf("Case %d: %d\n", test, count);
	}

	return 0;
}