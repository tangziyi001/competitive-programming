/*
 *	Codeforces 742D - Arpa's weak amphitheater and Mehrdad's valuable Hoses
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
#define MAXN 1005
#define MOD 1000000007

int n,w,m;
vi ww;
vi bb;
vvi all;
map<int,int> pp;
int p[MAXN];
int dp[MAXN][MAXN];
int findRep(int idx){
	if(p[idx] == idx) return idx;
	else return p[idx] = findRep(p[idx]);
}
bool isSameSet(int a, int b){
	return findRep(a) == findRep(b);
}
void unionSet(int a, int b){
	if(isSameSet(a,b)) return ;
	int pa = findRep(a);
	int pb = findRep(b);
	p[pa] = pb;
}
int main(){
	int tmp;
	cin >> n >> m >> w;
	FILL(dp,0);
	REP(i,0,n){
		cin >> tmp;
		ww.push_back(tmp);
		p[i] = i;
	}
	REP(i,0,n){
		cin >> tmp;
		bb.push_back(tmp);
	}
	REP(i,0,m){
		int a,b;
		cin >> a >> b;
		unionSet(a-1,b-1);
	}
	int idx = 0;
	REP(i,0,n){
		int nowp = findRep(i);
		if(pp.find(nowp) == pp.end()){
			pp[nowp] = idx++;
		}
	}
	all.assign(idx, vi(0,0));
	REP(i,0,n){
		all[pp[findRep(i)]].push_back(i);
	}
	int maxp = 0;
	REP(i,1,idx+1){
		REP(j,0,w+1){
			int sumW = 0;
			int sumB = 0;
			dp[i][j] = dp[i-1][j];
			REP(k,0,all[i-1].size()){
				int now = all[i-1][k];
				if(ww[now] <= j){
					int remW = j-ww[now];
					dp[i][j] = max(dp[i][j], dp[i-1][remW]+bb[now]);
				}
				sumW += ww[now];
				sumB += bb[now];
			}
			if(sumW <= j){
				int remW = j-sumW;
				dp[i][j] = max(dp[i][j], dp[i-1][remW]+sumB);
			}
		}
	}
	int re = 0;
	REP(i,0,w+1){
		re = max(re, dp[idx][i]);
	}
	cout << re << endl;
	return 0;
}