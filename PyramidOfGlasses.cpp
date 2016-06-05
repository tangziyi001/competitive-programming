/*
 *	CodeForces 676B
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
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int all[105];
int mark[105];
int main(){
	int n,t;
	cin >> n >> t;
	int num = (n+1)*n/2;
	int pre = 1;
	mark[pre] = 1;
	REP(i,1,10){
		mark[pre+i] = i+1;
		pre += i;
	}
	int now = 1;
	REP(i,1,105){
		if(mark[i] == 0)
			mark[i] = now;
		else
			now = mark[i];
	}
	REP(i,0,101)
		all[i] = 0;
	REP(i,1,t+1){
		all[1] += 1024;
		REP(j,1,num+1){
			if(all[j] > 1024){
				int duo = all[j]-1024;
				all[j] = 1024;
				int level = mark[j];
				all[j+level] += duo/2;
				all[j+level+1] += duo/2;
			}
		}
	}
	int cnt = 0;
	REP(i,1,num+1) {
		if(all[i] == 1024)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}