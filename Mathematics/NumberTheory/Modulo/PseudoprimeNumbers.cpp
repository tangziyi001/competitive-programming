/*
 *	UVA 11287
 *	Coded by Ziyi Tang
 *	Pow Mod
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
#define MAXN 10000010

ll _sieve_size; 
bitset<MAXN> bs; 
vi primes;
ll power(ll base, ll n, ll mod){
	if(n == 0LL) return 1LL;
	//if(n == 1LL) return base;
	ll tmp = power(base,n/2,mod);
	ll now = (tmp%mod*tmp%mod)%mod;
	if(n&1){
		now = base*now%mod;
	}
	return now;
}
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
	sieve(1000010);
	ll p,a;
	while(cin >> p >> a && (p != 0 || a != 0)){
		if(isPrime(p))
			cout << "no" << endl;
		else{
			//cout << power(a,p)%p << endl;
			if(power(a,p,p) == a){
				cout << "yes" << endl;
			}
			else
				cout << "no" << endl;
		}
	}

}