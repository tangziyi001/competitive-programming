/*
 *	USACO 2014 March Contest, Bronze 3
 *	Coded by Ziyi Tang
 *	
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
#define MAXN 1000010


int all[MAXN];
ll pre[MAXN+1];
int main(){
	freopen("lazy.in", "r", stdin);
  	freopen("lazy.out", "w", stdout);
  	int n,k;
  	cin >> n >> k;
  	REP(i,0,n){
  		int g,x;
  		cin >> g >> x;
  		all[x] = g;
  	}
  	pre[0] = 0;
  	REP(i,0,MAXN){
  		pre[i+1] = pre[i] + all[i];
  	}
  	ll maxp = 0;
  	int pos = -1;
  	REP(i,0,MAXN){
  		ll left = max(0,i-k);
  		ll right = min(MAXN-1, i+k);
  		if(pre[right+1]-pre[left] > maxp){
  			pos = i;
  			maxp = max(maxp, pre[right+1]-pre[left]);
  		}
  	}
  	//cout << pos+1 << endl;
  	cout << maxp << endl;
	return 0;
}