/*
 *	658C - Bear and Forgotten Tree 3
 *	Coded by Ziyi Tang
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

int n,d,h;
vpi edges;
int main(){
	cin >> n >> d >> h;
	if(n <= d) cout << -1 << endl;
	else if(h == 1 && d == 1 && n == 2){
		cout << 1 << " " << 2 << endl;
	}
	else if(d == 1 && n > 2){
		cout << -1 << endl;
	}
	else if(h == 1 && d == 2){
		REP(i,2,n+1){
			edges.push_back(make_pair(1,i));
		}
		int sz = edges.size();
		REP(i,0,sz){
			cout << edges[i].first << " " << edges[i].second << endl;
		}
	}
	else if(d >= h && d <= 2*h && n > d){
		int now = 1; // ends with
		REP(i,0,h){
			edges.push_back(make_pair(now,now+1));
			now++;
		}
		int rd = d-h;
		int tmp = 1;
		REP(i,0,rd){
			edges.push_back(make_pair(tmp, now+1));
			tmp = now+1;
			now++;
		}
		int rem = n-now;
		REP(i,0,rem){
			edges.push_back(make_pair(2,now+1));
			now++;
		}
		int sz = edges.size();
		REP(i,0,sz){
			cout << edges[i].first << " " << edges[i].second << endl;
		}

	}
	else{
		cout << -1 << endl;
	}
	return 0;
}