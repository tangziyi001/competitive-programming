/*
 *	UVA 11561
 *	Created by Ziyi Tang
 *	Basic BFS
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

int n,m;
char all[55][55];
int mark[55][55];
queue<pi> que;

bool check(int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < m && all[x][y] != '#' && all[x][y] != 'T') 
		return true;
	return false;
}
bool checkRound(int x, int y){
	REP(i,0,4){
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(x >= 0 && x < n && y >= 0 && y < m && all[tx][ty] == 'T') return false;
	}
	return true;
}
int main(){
	while(scanf("%d %d",&m,&n) != EOF){
		while(!que.empty()) que.pop();
		FILL(all,0);
		FILL(mark,0);
		string line;
		getchar();
		REP(i,0,n){
			getline(cin,line);
			REP(j,0,m){
				all[i][j] = line[j];
				if(all[i][j] == 'P'){
					que.push(make_pair(i,j));
					mark[i][j] = 1;
				}
			}
		}
		// REP(i,0,n){
		// 	REP(j,0,m){
		// 		cout << all[i][j];
		// 	}
		// 	cout << endl;
		// }
		int cont = 0;
		while(!que.empty()){
			pi now = que.front(); que.pop();
			int x = now.first;
			int y = now.second;
			if(all[x][y] == 'G') cont++;
			//cout << x << " " << y << " " << all[x][y] << endl;
			if(!checkRound(x,y)) continue;
			REP(i,0,4){
				int tx = x + dir[i][0];
				int ty = y + dir[i][1];
				if(check(tx,ty) && mark[tx][ty] == 0){
					mark[tx][ty] = 1;
					que.push(make_pair(tx,ty));
				}
			}
		}
		cout << cont << endl;
	}
	return 0;
}

