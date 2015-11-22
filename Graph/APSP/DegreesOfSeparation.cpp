/*
 *	UVA 01056
 *	Created by Ziyi Tang
 *	Floyd Warshall for finding the diameter of a graph
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
#define MAXN 55

map<string,int> strint;
vector<string> intstr;
int all[MAXN][MAXN];

int main(){
	int n,m;
	int test = 0;
	while(cin >> n >> m && (n != 0 || m != 0)){
		test++;
		REP(i,0,n)	REP(j,0,n){
				all[i][j] = (i == j) ? 0: INF;
		}
		strint.clear();
		intstr.clear();
		string sta,ter;
		int idx = 0;
		REP(i,0,m){
			cin >> sta >> ter;
			if(strint.find(sta) == strint.end()){
				strint[sta] = idx;
				intstr.push_back(sta);
				idx++;
			}
			if(strint.find(ter) == strint.end()){
				strint[ter] = idx;
				intstr.push_back(ter);
				idx++;
			}
			all[strint[sta]][strint[ter]] = 1;
			all[strint[ter]][strint[sta]] = 1;
		}
		REP(k,0,n) REP(i,0,n) REP(j,0,n){
			if(all[i][k] == INF || all[k][j] == INF) continue;
			all[i][j] = min(all[i][j], all[i][k]+all[k][j]);
		}
		int maxp = 0;
		REP(i,0,n) REP(j,0,n){
			maxp = max(maxp, all[i][j]);
		}
		if(maxp == INF)
			printf("Network %d: DISCONNECTED\n", test);
		else
			printf("Network %d: %d\n", test, maxp);
		cout << endl;
	}

	return 0;
}
