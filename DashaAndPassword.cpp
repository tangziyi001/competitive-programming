/*
 *	Codeforces 761C	
 *	Created by Ziyi Tang
 *	Brute Force
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
#define MAXN 55
#define MOD 1000000007

char all[MAXN][MAXN];
vi digit;
vi letter;
vi mark;
int main(){
	int n,m;
	cin >> n >> m;
	REP(i,0,n){
		string line;
		cin >> line;
		REP(j,0,m){
			all[i][j] = line[j];
		}
	}
	REP(i,0,n){
		int d = INF, l = INF, a = INF;
		REP(j,0,m){
			char now = all[i][j];
			if(now >= '0' && now <= '9'){
				d = min(d, min(j,m-j));
			}
			else if(now >= 'a' && now <= 'z'){
				l = min(l, min(j,m-j));
			}
			else {
				a = min(a, min(j,m-j));
			}
		}
		digit.push_back(d);
		letter.push_back(l);
		mark.push_back(a);
	}
	int minp = INF;
	REP(i,0,n) REP(j,0,n) REP(k,0,n){
		int d = digit[i];
		int l = letter[j];
		int a = mark[k];
		if(i == j || j == k || i == k){
			continue;
		}
		minp = min(minp, d+l+a);
	}
	cout << minp << endl;
	return 0;
}
