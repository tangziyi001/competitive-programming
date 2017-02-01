/*
 *	Codeforces 760C
 *	Created by Ziyi Tang
 *	Find the number of cycles
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
#define MAXN 200010
#define MOD 1000000007

vi all;
int mark[MAXN];
void dfs(int now){
	//cout << now << endl;
	if(mark[all[now]] == 0){
		mark[all[now]] = 1;
		dfs(all[now]);
	}
}
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		int tmp;
		scanf("%d", &tmp);
		all.push_back(tmp-1);
	}
	int ss = 0;
	REP(i,0,n){
		int tmp;
		scanf("%d", &tmp);
		ss += tmp;
	}
	int re = 0;
	if(ss%2 == 0) re = 1;
	FILL(mark,0);
	int cont = 0;
	REP(i,0,n){
		if(mark[i] == 0){
			cont++;
			dfs(i);
		}
	}
	re += cont == 1 ? 0 : cont;
	cout << re << endl;
	return 0;
}