/*
 *	UVA 11368
 *	Created by Ziyi Tang
 *	Dilworth's Theorem and Longest Non-decreasing Subsequence
 *	Chain Covering Problem
 * 	Smallest number of chain = Largest number of anti-chain
 *	Sort width from long to short, then height from short to long
 *	find longest non-decreasing of heights in the sorted sequence
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
#define MAXN 200010
#define MOD 1000000007

struct Doll{
	int w,h;
	bool operator < (const Doll& tmp) const{
		if(w == tmp.w)
			return h < tmp.h;
		return w > tmp.w;
	}
} all[MAXN];
int main(){
	int test;
	scanf("%d", &test);
	while(test--){
		int n;
		scanf("%d", &n);
		REP(i,0,n){
			scanf("%d %d", &all[i].w, &all[i].h);
		}
		sort(all, all+n);
		vector<int> lis;
		lis.push_back(all[0].h);
		REP(i,1,n){
			int now = all[i].h;
			if(now >= lis.back()) lis.push_back(now);
			else *upper_bound(lis.begin(), lis.end(), now) = now;
		}
		cout << lis.size() << endl;
	}
	return 0;
}