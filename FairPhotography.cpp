/*
 *	USACO 2014 US Open, Silver 1
 *	Coded by Ziyi Tang
 *	If 
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
#define MAXN 2000010

vpi data; //(pos, sign)
vi sum;
int all[MAXN];
int st[4*MAXN+1];
int rmq(int p, int L, int R, int l, int r){
  if(l > R || r < L)
    return -1;
  if(L >= l && R <= r)
    return st[p];
  int left = p << 1;
  int right = (p << 1) + 1;
  int p1_idx = rmq(left, L, (L+R)/2, l, r);
  int p2_idx = rmq(right, (L+R)/2+1, R, l, r);
  if(p1_idx == -1) return p2_idx;
  if(p2_idx == -1) return p1_idx;
  return (all[p1_idx] >= all[p2_idx]) ? p1_idx : p2_idx;
}

void update(int p, int L, int R, int i){
  if(L == R)
    st[p] = L;
  else{
    int left = p << 1;
    int right = (p << 1) + 1;
    if(i <= (L+R)/2)
      update(left, L, (L+R)/2, i);
    else
      update(right, (L+R)/2+1, R, i);
    int p1_idx = st[left];
    int p2_idx = st[right];
    st[p] = (all[p1_idx] >= all[p2_idx]) ? p1_idx : p2_idx;
  }
}


int main(){
	  freopen("fairphoto.in", "r", stdin);
    freopen("fairphoto.out", "w", stdout);

  	int n;
  	cin >> n;
    FILL(st,0);
    FILL(all,0);
  	REP(i,0,n){
  		int pos;
  		char c;
  		cin >> pos >> c;
  		int sign;
  		if(c == 'W') sign = 1;
  		else sign = -1;
  		data.push_back(make_pair(pos,sign));
  	}
  	sort(data.begin(),data.end());
  	sum.push_back(0);
    REP(i,1,n+1){
      sum.push_back(sum[i-1] + data[i-1].second);
    }

    int maxp = 0;
    for(int i = n; i >= 1; i++){
      int p = rmq(1,0,n-1,sum[i],MAXN-1);
      all[sum[i]] = max(i-1, all[p]);
      maxp = max(maxp, all[p])
      update(1,0,n-1,sum[i]);
    }

	return 0;
}