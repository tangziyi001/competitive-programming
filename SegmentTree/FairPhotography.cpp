/*
 *	USACO 2014 US Open, Silver 1
 *	Coded by Ziyi Tang
 *	Two Segment Tree. Scan from right to left. Record the max position j such that
 *  sum[i] <= sum[j] via rmq(i,MAXN-1)
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
#define MAXN 200010
#define AUG 100005

vpi data; //(pos, sign)
vi sum;
int all1[MAXN];
int all2[MAXN];
int st1[4*MAXN+1];
int st2[4*MAXN+1];
int rmq(int* all, int* st, int p, int L, int R, int l, int r){
  if(l > R || r < L)
    return -1;
  if(L >= l && R <= r)
    return st[p];
  int left = p << 1;
  int right = (p << 1) + 1;
  int p1_idx = rmq(all, st, left, L, (L+R)/2, l, r);
  int p2_idx = rmq(all, st, right, (L+R)/2+1, R, l, r);
  if(p1_idx == -1) return p2_idx;
  if(p2_idx == -1) return p1_idx;
  return (all[p1_idx] >= all[p2_idx]) ? p1_idx : p2_idx;
}
void update(int* all, int* st, int p, int L, int R, int i){
  if(L == R)
    st[p] = L;
  else{
    int left = p << 1;
    int right = (p << 1) + 1;
    if(i <= (L+R)/2)
      update(all, st, left, L, (L+R)/2, i);
    else
      update(all, st, right, (L+R)/2+1, R, i);
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
    FILL(st1,0);
    FILL(st2,0);
    FILL(all1,0);
    FILL(all2,0);
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
    //REP(i,0,n+1) cout << sum[i] << endl;
    int maxp = 0;
    for(int i = n; i >= 1; i--){
      if(i&1){
        all1[sum[i]+AUG] = max(all1[sum[i]+AUG], i-1);
        update(all1,st1,1,0,MAXN-1,sum[i]+AUG);
        int p = rmq(all2,st2,1,0,MAXN-1,sum[i]+AUG,MAXN-1);
        maxp = max(maxp, data[all2[p]].first-data[i-1].first);
        //cout<< i << " " << all2[p] << endl;
      }
      else{
        all2[sum[i]+AUG] = max(all2[sum[i]+AUG], i-1);
        update(all2,st2,1,0,MAXN-1,sum[i]+AUG);
        int p = rmq(all1,st1,1,0,MAXN-1,sum[i]+AUG,MAXN-1);
        maxp = max(maxp, data[all1[p]].first-data[i-1].first);
        //cout<< i << " " << all1[p] << endl;
      }
    }
    cout << maxp << endl;
	return 0;
}