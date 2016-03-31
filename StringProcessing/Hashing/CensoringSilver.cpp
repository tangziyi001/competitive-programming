/*
 *	USACO 2015 February Contest, Bronze 1
 *	Coded by Ziyi Tang
 *	String Comparison (Build string from the tail with rolling hashing)
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
#define MAXN 1000005
#define MOD 1000000007

ll pre[MAXN];
char all[MAXN];
ll power(ll base, ll n){
	if(n == 0) return 1;
	if(n&1){
		ll tmp = power(base,(n-1)/2)%MOD;
		return (base*tmp*tmp+MOD)%MOD;
	}
	else{
		ll tmp = power(base,n/2);
		return (tmp*tmp+MOD)%MOD;
	}
}

ll buildHash(string now){
	int sz = now.size();
	ll sum = 0LL;
	REP(i,0,sz){
		sum += (ll)now[i]*power(7,i)%MOD;
	}
	return sum%MOD;
}
int main(){
	freopen("censor.in", "r", stdin);
  	freopen("censor.out", "w", stdout);
	string S,T;
	cin >> S >> T;
	int idx = 0;
	int ssz = S.size();
	int tsz = T.size();
	ll Thash = buildHash(T);
	pre[idx] = 0;
	REP(i,0,ssz){
		all[idx] = S[i];
		pre[idx+1] = ((S[i]*power(7,idx))%MOD + pre[idx] + MOD)%MOD;
		//cout << pre[idx+1] << all[idx] << endl;
		if(idx >= tsz-1){
			ll newThash = (Thash*power(7,idx-tsz+1)+MOD)%MOD;
			if(newThash == (pre[idx+1]-pre[idx+1-T.size()]+MOD)%MOD){
				idx-=T.size();
			}
		}
		idx++;
	}
	all[idx] = '\0';
	int t = 0;
	while(all[t]){
		cout << all[t];
		t++;
	}
	cout << endl;

	return 0;
}