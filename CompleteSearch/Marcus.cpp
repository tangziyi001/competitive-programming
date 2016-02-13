/*
 *	UVA 10452
 *	Created by Ziyi Tang
 *	Basic Search
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
#define MAXN 10

char all[MAXN][MAXN];
int n,m;
int check(int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < m) return true;
	return false;
}
int main(){
	int t;
	cin >> t;
	const string str = "IEHOVA";
	while(t--){
		cin >> n >> m;
		pi start;
		pi end;
		REP(i,0,n){
			REP(j,0,m){
				char tmp;
				cin >> tmp;
				all[i][j] = tmp;
				if(tmp == '@'){
					start.first = i;
					start.second = j;
				}
				if(tmp == '#'){
					end.first = i;
					end.second = j;
				}
			}
		}
		pi now = start;
		int idx = 0;
		while(now != end){
			int x = now.first;
			int y = now.second;
			REP(i,0,4){
				if(i == 2) continue;
				int tx = x+dir[i][0];
				int ty = y+dir[i][1];
				if(check(tx,ty) && (all[tx][ty] == str[idx] || all[tx][ty] == '#')){
					now = make_pair(tx,ty);
					if(idx != 0) cout << " ";
					if(i == 0) cout << "forth";
					if(i == 1) cout << "right";
					if(i == 3) cout << "left";
					idx++;
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
