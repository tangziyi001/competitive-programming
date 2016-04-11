/*
 *	UVA 11086
 *	Coded by Ziyi Tang
 *	Sieve the composite prime
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
#define MAXN 10000000
ll _sieve_size; 
bitset<MAXN> bs;
bitset<MAXN> cp;
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
bool isPrime(ll N){
	// note: only work for N <= (last prime in vi "primes")^2
	if (N <= _sieve_size) return bs[N]; 
	for (int i = 0; i < (int)primes.size(); i++)
		if (N % primes[i] == 0) 
			return false;
	return true;
}
int main(){
	sieve(MAXN);
	cp.set();
	int sz = primes.size();
	//REP(i,0,10) cout << primes[i] << endl;
	REP(i,0,sz) REP(j,i,sz){
		ll now = (ll)primes[i]*primes[j];
		if(now > MAXN) break;
		cp[now] = 0;
	}
	int n;
	while(cin >> n){
		ll cont = 0LL;
		while(n--){
			ll tmp = 0LL;
			cin >> tmp;
			if(!isPrime(tmp) && cp[tmp] == 0){
				//cout << tmp << endl;
				cont++;
			}
		}
		cout << cont << endl;
	}
	return 0;
}