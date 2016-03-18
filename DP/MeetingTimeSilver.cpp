/*
 *	USACO 2015 January Contest, Silver 3
 *	Coded by Ziyi Tang
 *	DP: dp[i][k+d[j][i]] = (dp[j][k] == true) ? true : false for j < i
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

int A[100][10010];
int B[100][10010];
vvpi allA;
vvpi allB;
int main(){
	freopen("meeting.in", "r", stdin);
  	freopen("meeting.out", "w", stdout);
  	int n,m;
  	cin >> n >> m;
  	FILL(A,0);
  	FILL(B,0);
  	vpi ttmp;
  	allA.assign(n,ttmp);
  	allB.assign(n,ttmp);
  	int a,b,ad,bd;
  	REP(i,0,m){
  		cin >> a >> b >> ad >> bd;
  		allA[a-1].push_back(make_pair(b-1, ad));
  		allB[a-1].push_back(make_pair(b-1, bd));
  	}
  	A[0][0] = 1;
  	B[0][0] = 1;
  	REP(i,0,n-1){
  		vpi nowA = allA[i];
  		vpi nowB = allB[i];
  		int sz = nowA.size();
  		REP(j,0,sz){
  			int uA = nowA[j].first;
  			int dA = nowA[j].second;
  			int uB = nowB[j].first;
  			int dB = nowB[j].second;
  			REP(k,0,10010){
  				if(A[i][k] == 1)
  					A[uA][k+dA] = 1;
  				if(B[i][k] == 1)
  					B[uB][k+dB] = 1;
  			}
  		}
  	}
  	int flag = -1;
  	REP(i,0,10010) if(A[n-1][i] == 1 && B[n-1][i] == 1){
  		flag = i; break;
  	}
  	if(flag == -1)
  		cout << "IMPOSSIBLE" << endl;
  	else
  		cout << flag << endl;

	return 0;
}