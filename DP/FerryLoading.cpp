/*
 *	
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int dp[305][10005];
int maxp = 0;
int di[305][10005];
int sum[305];
vector<string> re;
vi all;
int n = 0;
int main(){
	int test;
	cin >> test;
	REP(t,0,test){
		if(t != 0) cout << endl;
		all.clear();
		maxp = 0;
		FILL(sum,0);
		n=0;
		re.clear();
		FILL(dp,0);
		FILL(di,-1);
		dp[0][0] = 1;
		int f = 0;
		cin >> f;
		f*=100;
		int tmp;
		while(cin >> tmp && tmp != 0){
			all.push_back(tmp);
			n++;
			sum[n] = sum[n-1]+tmp;
			//if(n > 250) break;
		}
		REP(i,1,n+1){
			int now = all[i-1];
			REP(j,0,f+1) {
				if(j+now <= f){
					dp[i][j+now] |= dp[i-1][j];
					if(dp[i-1][j]){
						di[i][j+now] = 0;
						maxp = i;
					}
				}
				int k = sum[i-1]-j;
				if(k < 0) break;
				if(k >= 0 && k+now <= f){
					dp[i][j] |= dp[i-1][j];
					if(dp[i-1][j]){
						di[i][j] = 1;
						maxp = i;
					}
				}
				// if(dp[i-1][j] > 0){
				// 	cout << i-1 << " " << j << " " << k << endl;
				// }
			}
		}
		int mm = maxp;
		cout << mm << endl;
		int jj;
		REP(j,0,f+1) {
			if(dp[mm][j] == 1){
				jj = j;
				break;
			}
		}
		while(mm != 0){
			if(di[mm][jj] == 0){
				re.push_back("port");
				jj = jj-all[mm-1];
			} else {
				re.push_back("starboard");
			}
			mm--;
		}
		for(int i = maxp-1; i >= 0; i--){
			cout << re[i] << endl;
		}
	}
	return 0;
}