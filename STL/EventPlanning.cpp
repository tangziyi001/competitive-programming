/*
 *	UVA 11559
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
#define MAXN 100

int n,b,h,w;
int p;
vvi all;
int price[MAXN];
int main(){

	while(cin >> n >> b >> h >> w){
		int idx = 0;
		vi tmp;
		all.assign(h,tmp);
		REP(i,0,h){
			cin >> p;
			price[idx] = p;
			REP(j,0,w){
				int now;
				cin >> now;
				all[idx].push_back(now);
			}
			idx++;
		}
		int minp = INF;

		REP(i,0,w){
			REP(j,0,h){
				int np = price[j];
				int ava = all[j][i];
				if(n*np > b){
					continue;
				}
				if(ava >= n && minp > n*np){
					minp = n*np;
				}
			}
		}
		if(minp  == INF){
			cout << "stay home" << endl;
		}
		else{
			cout << minp << endl;
		}

	}

	return 0;
}
