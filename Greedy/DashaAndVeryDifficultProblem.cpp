/*
 *	Codeforces 761D - Dasha and Very Difficult Problem
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
#define MAXN 1000
#define MOD 1000000007

vpi all;
vi re;
int minp,maxp;
map<int,int> reco;
int main(){
	int n;
	cin >> n >> minp >> maxp;
	re.assign(n,0);
	REP(i,0,n){
		int tmp;
		scanf("%d", &tmp);
		all.push_back(make_pair(0,tmp));
	}
	REP(i,0,n){
		int tmp;
		scanf("%d", &tmp);
		all[i].first = tmp;
		reco[tmp] = i;
	}
	sort(all.begin(), all.end());
	int now = -INF;
	int flag = 1;
	REP(i,0,n){
		int low = minp-all[i].second;
		int high = maxp-all[i].second;
		if(now > high){
			flag = 0;
			break;
		}
		now = max(now, low);
		re[reco[all[i].first]] = now+all[i].second;
		now++;
	}
	if(flag){
		REP(i,0,n){
			printf("%d ", re[i]);
		}
		cout << endl;
	} else
		cout << -1 << endl;
	return 0;
}