/*
 *	UVA 11876
 *	Created by Ziyi Tang
 *	Divisor counting
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000005
#define MOD 1000000007
ll _sieve_size; 
bitset<MAXN> bs; 
vi primes;
void sieve(ll upperbound){ 
	_sieve_size = upperbound + 1; 
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
		for (ll j = i * i; j <= _sieve_size; j += i)
			bs[j] = 0;
		primes.push_back((int)i); 
	}
}
ll numDiv(ll N){
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1; // start from ans = 1 
	while (PF * PF <= N){
		ll power = 0; // count the power 
		while (N % PF == 0){ 
			N /= PF; power++; 
		}
		ans *= (power + 1);
		PF = primes[++PF_idx]; 
	}
  	if(N != 1)
  		ans *= 2;
	return ans; 
}
vi all;
int main(){
	int now = 1;
	sieve(MAXN);
	while(now <= 1000000){
		all.push_back(now);
		int nxt = now + numDiv(now);
		now = nxt;
	}
	int test;
	cin >> test;
	REP(t,1,test+1){
		int a,b;
		cin >> a >> b;
		printf("Case %d: %ld\n",t, upper_bound(all.begin(), all.end(), b) - lower_bound(all.begin(), all.end(), a));
	}
	return 0;
}