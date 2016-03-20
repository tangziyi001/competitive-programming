/*
 *	UVA 10603
 *	Coded by Ziyi Tang
 *	Implicit BFS. Minimize the amount of water for each state.
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
#define MP(a,b) make_pair(a,b)
#define MAXN 1000

int all[205][205];
queue<pi> qq;
int main(){
	int test;
	cin >> test;
	REP(t,0,test){
		FILL(all,-1);
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		all[0][0] = 0;
		qq.push(make_pair(0,0));
		while(!qq.empty()){
			pi now = qq.front();qq.pop();
			int ta = now.first;
			int tb = now.second;
			int tc = c-ta-tb;
			//cout << ta << " " << tb << " " << tc << endl;
			if(ta != 0){
				int pourB = min(b-tb,ta);
				int pourC = min(c-tc,ta);
				if(all[ta-pourB][tb+pourB] == -1 || all[ta-pourB][tb+pourB] > all[ta][tb] + pourB){
					all[ta-pourB][tb+pourB] = all[ta][tb] + pourB;
					qq.push(MP(ta-pourB, tb+pourB));
				}
				if(all[ta-pourC][tb] == -1 || all[ta-pourC][tb] > all[ta][tb] + pourC){
					all[ta-pourC][tb] = all[ta][tb] + pourC;
					qq.push(MP(ta-pourC, tb));
				}
			}
			if(tb != 0){
				int pourA = min(a-ta,tb);
				int pourC = min(c-tc,tb);
				if(all[ta+pourA][tb-pourA] == -1 || all[ta+pourA][tb-pourA] > all[ta][tb] + pourA){
					all[ta+pourA][tb-pourA] = all[ta][tb] + pourA;
					qq.push(MP(ta+pourA, tb-pourA));
				}
				if(all[ta][tb-pourC] == -1 || all[ta][tb-pourC] > all[ta][tb] + pourC){
					all[ta][tb-pourC] = all[ta][tb] + pourC;
					qq.push(MP(ta,tb-pourC));
				}
			}
			if(tc != 0){
				int pourA = min(a-ta, tc);
				int pourB = min(b-tb, tc);
				if(all[ta+pourA][tb] == -1 || all[ta+pourA][tb] > all[ta][tb] + pourA){
					all[ta+pourA][tb] = all[ta][tb] + pourA;
					qq.push(MP(ta+pourA,tb));
				}
				if(all[ta][tb+pourB] == -1 || all[ta][tb+pourB] > all[ta][tb] + pourB){
					all[ta][tb+pourB] = all[ta][tb] + pourB;
					qq.push(MP(ta,tb+pourB));
				}
			}
		}
		// REP(i,0,10){
		// 	REP(j,0,10){
		// 		cout << all[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		int ans = INF;
		int td = -1;
		REP(i,0,205) REP(j,0,205){
			if(all[i][j] != -1){
				int ta = i;
				int tb = j;
				int tc = c-i-j;
				if(ta <= d && (d-ta) < (d-td))
					td = ta;
				if(tb <= d && (d-tb) < (d-td))
					td = tb;
				if(tc <= d && (d-tc) < (d-td))
					td = tc;
			}
		}
		REP(i,0,205) REP(j,0,205){
			int ta = i;
			int tb = j;
			int tc = c-i-j;
			if(all[i][j] != -1 && (ta == td || tb == td || tc == td)){
				ans = min(ans,all[i][j]);
			}
		}
		cout << ans << " " << td << endl;
	}
	return 0;
}