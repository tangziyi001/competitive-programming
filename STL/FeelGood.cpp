/*
 *	POJ 2796
 *	Created by Ziyi Tang
 *	Monotonic Stack
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
#define MAXN 100005
#define MOD 1000000007

vector<ll> all;
ll sum[MAXN];
int leftEle[MAXN];
int rightEle[MAXN];
int main(){
	int n;
	cin >> n;
	sum[0] = 0LL;
	REP(i,0,n){
		ll tmp;
		scanf("%lld", &tmp);
		all.push_back(tmp);
		sum[i+1] = sum[i] + tmp;
	}
	stack<int> ss;
	ll maxp = -1;
	int rl = 0, rr = 0;
	REP(i,0,n){
		ll now = all[i];
		while(!ss.empty() && all[ss.top()] >= now){
			ss.pop();
		}
		int l = ss.empty() ? 0 : ss.top()+1;
		leftEle[i] = l;
		ss.push(i);
	}
	while(!ss.empty()) ss.pop();
	for(int i = n-1; i >= 0; i--){
		ll now = all[i];
		while(!ss.empty() && all[ss.top()] >= now){
			ss.pop();
		}
		int r = ss.empty() ? n-1 : ss.top()-1;
		rightEle[i] = r;
		ss.push(i);
	}
	REP(i,0,n){
		//cout << leftEle[i] << " " << i << " " << rightEle[i] << endl;
		ll val = all[i]*(sum[rightEle[i]+1]-sum[leftEle[i]]);
		if(val > maxp){
			maxp = val;
			rl = leftEle[i];
			rr = rightEle[i];
		}
		
	}
	cout << maxp << endl;
	cout << rl+1 << " " << rr +1<< endl;
	return 0;
}