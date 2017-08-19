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
typedef vector<ld> vd;
typedef vector<vd> vvd;
const int INF = 0x3f3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ISZERO(x) (fabs(x) < EPS)
#define ISPOS(x) ((x) > EPS)
#define MAXN 1000
#define MOD 1000000007

void pivot(vvd &A, int r, int c) {
  int m = A.size(), n = A[0].size(); ld tmp = A[r][c];
  for (int i = 0; i < n; ++i) A[r][i]/=tmp;
  for (int i = 0; i < m; ++i) if (i != r) { ld k = A[i][c];
    for (int j = 0; j < n; ++j) A[i][j] -= A[r][j]*k; } }
bool gaussian(vvd& A) { int m=A.size(), n=A[0].size()-1; vector<bool> used(m,0);
  for (int c = 0; c < n; ++c) for (int r = 0; r < m; ++r)
    if (!used[r] && !ISZERO(A[r][c]) ) { pivot(A, r, c); used[r] = true; }
  for (int r = 0; r < m; r++) if (!used[r] && !ISZERO(A[r].back())) return false;
  return true; }

int main(){
	
	return 0;
}