/*
 *	
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

map<string,int> si;
vector<string> is;
double all[35][35][35];
int main(){
	int n;
	int test = 0;
	while(cin >> n && n != 0){
		test++;
		si.clear();
		is.clear();
		FILL(all,0);
		REP(i,0,35) REP(j,0,35){
			if(i == j) all[i][j][0] = 1;
		}
		REP(i,0,n){
			string line;
			cin >> line;
			si[line]=i;
			is.push_back(line);
		}
		int m;
		cin >> m;
		getchar();
		REP(i,0,m){
			string line;
			getline(cin,line);
			stringstream ss(line);
			string sta,ter;
			double cost;
			ss >> sta >> cost >> ter;
			all[si[sta]][si[ter]][0] = cost;
		}
		REP(t,1,n+1){
			REP(k,0,n) REP(i,0,n) REP(j,0,n){
				all[i][j][t] = max(all[i][j][t], all[i][k][t-1]*all[k][j][0]);
			}
		}
		// REP(i,0,n) {
		// 	REP(j,0,n){
		// 		cout << all[i][j][n] << " ";
		// 	}
		// 	cout << endl;
		// }
		bool flag = false;
		REP(i,0,n){
			if(all[i][i][n] > 1.0){
				flag = 1;break;
			}
		}
		if(flag){
			printf("Case %d: Yes\n", test);
		}
		else
			printf("Case %d: No\n", test);
	}
	return 0;
}