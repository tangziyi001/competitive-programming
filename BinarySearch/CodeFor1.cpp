/*
 *	Codeforces 768B
 *	Created by Ziyi Tang
 *	Divide & Conquer
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
ll cnt(ll temp){
  ll x=1;
  while(temp>1){
    temp/=2;
    x+=1;
  }
  return x;
}
// Power Computation
ll power(ll base, ll n){
	if(n == 0LL) return 1LL;
	//if(n == 1LL) return base;
	ll tmp = power(base,n/2);
	ll now = tmp*tmp;
	if(n&1){
		now = base*now;
	}
	return now;
}
ll rec(ll now, ll left, ll right, ll num){
	
	if(num == 1) return 1LL;
	ll re = 0LL;
	ll nr = left+(right-left)/2-1;
	ll nl = right-(right-left)/2+1;

	ll off = num%2;
	if(now <= nr) re = rec(now, left, nr, num/2);
	else if(now == nr+1) re = off + num/2;
	else re = off + rec(now, nl, right, num/2) + num/2;
	//cout << now << " " << left << " " << right << " " << num << " "<< re << endl;
	return re;
}
int main(){
	ll n,l,r;
	cin >> n >> l >> r;
	if(n == 0){
		cout << 0 << endl;
		return 0;
	}
	ll level = floor(log2((double)n))+1;
	ll total = power(2,cnt(n))-1; // 2^n-1
	// cout << level << ":" << total << endl;
	ll re1 = l == 1 ? 0 : rec(l-1,1,total, n);
	ll re2 = rec(r,1,total, n);
	//cout << re1 << "k " << re2 << endl;
	cout << re2-re1 << endl;
	return 0;
}