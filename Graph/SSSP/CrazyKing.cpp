/*
 *	UVA 11352
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
const ll INFL = (ll)1E18;
const int dir[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

const int dd[8][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
char all[105][105];
int mark[105][105];
vector<pair<int,int> > hor;
pair<int,int> A;
pair<int,int> B;
int n,m;
queue<pair<int,int> > qq;
bool check(int a, int b){
	if(a >= 0 && a < n && b >= 0 && b < m){
		return true;
	}
	return false;
}
int main(){
	int test;
	cin >> test;
	while(test--){
		while(!qq.empty())
			qq.pop();
		hor.clear();
		FILL(all,0);
		FILL(mark,-1);
		cin >> n >> m;
		REP(i,0,n){
			REP(j,0,m){
				char tmp;
				cin >> tmp;
				all[i][j] = tmp;
				if(tmp == 'Z') hor.push_back(make_pair(i,j));
				if(tmp == 'A') A = make_pair(i,j);
				if(tmp == 'B') B = make_pair(i,j);
			}
		}
		int hsz = hor.size();
		REP(i,0,hsz){
			int a = hor[i].first;
			int b = hor[i].second;
			REP(i,0,8){
				int ta = a + dd[i][0];
				int tb = b + dd[i][1];
				if(check(ta, tb) && all[ta][tb] == '.'){
					all[ta][tb] = 'Z';
				}
			}
		}
		qq.push(A);
		mark[A.first][A.second] = 0;
		while(!qq.empty()){
			pair<int,int> now = qq.front();qq.pop();
			int x = now.first;
			int y = now.second;
			REP(i,0,8){
				int tx = x + dir[i][0];
				int	ty = y + dir[i][1];
				if(check(tx,ty) && all[tx][ty] != 'Z' && mark[tx][ty] == -1){
					mark[tx][ty] = mark[x][y] + 1;
					qq.push(make_pair(tx,ty));
				}
			}
		}
		int re = mark[B.first][B.second];
		if(re == -1){
			cout << "King Peter, you can\'t go now!" << endl;
		} else {
			printf("Minimal possible length of a trip is %d\n", re);
		}
	}
	return 0;
}