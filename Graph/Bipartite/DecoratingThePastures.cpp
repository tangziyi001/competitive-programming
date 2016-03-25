/*
 *	USACO 2014 US Open, Bronze 3
 *	Coded by Ziyi Tang
 *	Bipartite Graph Check
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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

vvi all;
int mark[50005];
int cont[2];
queue<int> qq;
int main(){
	freopen("decorate.in", "r", stdin);
  	freopen("decorate.out", "w", stdout);
  	int n,m;
  	cin >> n >> m;
  	FILL(mark,-1);
  	all.assign(n,vi(0,0));
  	REP(i,0,m){
  		int a,b;
  		cin >> a >> b;
  		all[a-1].push_back(b-1);
  		all[b-1].push_back(a-1);
  	}
  	int maxp = 0;
  	int flag = 1;
  	REP(i,0,n){
  		if(mark[i] == -1 && flag){
  			FILL(cont,0);
  			mark[i] = 0; cont[0]++;
  			qq.push(i);
  			while(!qq.empty()){
  				int now = qq.front();qq.pop();
  				int sz = all[now].size();
  				REP(j,0,sz){
  					int tmp = all[now][j];
  					if(mark[tmp] == -1){
  						mark[tmp] = 1-mark[now]; 
  						cont[1-mark[now]]++;
  						qq.push(tmp);
  					}
  					else if(mark[tmp] == mark[now]){
  						flag = 0;
  						break;
  					}
  				}
  				if(flag == 0) break;
  			}
  			maxp += max(cont[0],cont[1]);
  		}
  		if(flag == 0) break;
  	}
  	if(flag)
  		cout << maxp << endl;
  	else
  		cout << -1 << endl;
	return 0;
}