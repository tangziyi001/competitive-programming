/*
 *	UVA 10074
 *	Created by Ziyi Tang
 *	Prefix Sum
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

int all[101][101];
int sum[105][105];
int main(){
	int m,n;
	while(cin >> m >> n && m != 0 && n != 0){
		FILL(all,0);
		FILL(sum,0);
		int tmp;
		REP(i,0,m){
			REP(j,0,n){
				cin >> tmp;
				all[i][j] = tmp;
			}
		}
		REP(i,0,m){
			REP(j,0,n){
				sum[i+1][j+1] = sum[i][j+1]+sum[i+1][j]+all[i][j]-sum[i][j];
				//cout << sum[i+1][j+1] << endl;
			}
		}
		int maxp = 0;
		REP(x,1,m+1){
			REP(y,1,n+1){
				REP(i,x,m+1){
					REP(j,y,n+1){
						int now = sum[i][j]-sum[x-1][j]-sum[i][y-1]+sum[x-1][y-1];
						//cout << now << endl;
						if(now == 0){
							maxp = max(maxp, (i-x+1)*(j-y+1));
						}
					}
				}
			}
		}
		cout << maxp << endl;

	}
	return 0;
}

