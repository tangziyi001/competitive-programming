/*
 *	UVA 12135
 *	Created by Ziyi Tang
 *	BFS with bitmask
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 35000
#define MOD 1000000007

int mark[MAXN];
vvi all;
int n,m;
queue<int> qq;
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		all.clear();
		FILL(mark,-1);
		cin >> n >> m;
		all.assign(m,vi(0,0));
		REP(i,0,m){
			int num = 0;
			cin >> num;
			REP(j,0,num){
				int tmp;
				cin >> tmp;
				all[i].push_back(tmp);
			}
		}
		qq.push(0);
		mark[0] = 0;
		while(!qq.empty()){
			int now = qq.front();qq.pop();
			REP(i,0,m){
				int tmp = now;
				int num = all[i].size();
				REP(j,0,num){
					int tog = all[i][j];
					tmp ^= (1 << tog);
				}
				if(mark[tmp] == -1){
					mark[tmp] = 1+mark[now];
					qq.push(tmp);
				}
			}
		}
		int q;
		printf("Case %d:\n", t);
		cin >> q;
		REP(i,0,q){
			string line;
			int bi = 0;
			cin >> line;
			REP(i,0,n){
				bi += (line[i] == '1') ? pow(2,n-1-i) : 0;
			}

			cout << mark[bi] << endl;
		}
		cout << endl;
	}
	return 0;
}