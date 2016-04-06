/*
 *	Work with Prime
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
#define MAXN 10000010

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
bool isPrime(ll N){
	// note: only work for N <= (last prime in vi "primes")^2
	if (N <= _sieve_size) return bs[N]; 
	for (int i = 0; i < (int)primes.size(); i++)
		if (N % primes[i] == 0) 
			return false;
	return true;
}

// Number of Prime Factor of N (may have same number) O(sqrt(N)/ln*sqrt(N))
ll numPF(ll N){
	ll PF_idx = 0, PF = primes[PF_idx], ans = 0; 
	while (PF * PF <= N){
		while (N % PF == 0){ 
			N /= PF; ans++; 
		}
		PF = primes[++PF_idx]; 
	}
	if (N != 1) ans++;
		return ans; 
}

// Number of Divisors of N
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

// Sum of Divisors of N
ll sumDiv(ll N){
ll PF_idx = 0, PF = primes[PF_idx], ans = 1; // start from ans = 1 
	while (PF * PF <= N){
		ll power = 0;
		while (N % PF == 0){
			N /= PF;
			power++; 
		}
		ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1); 
		PF = primes[++PF_idx];
	}
	if(N != 1)
		ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); // last return ans;
}

// Number of integers < N that are relatively prime to N
ll EulerPhi(ll N){
	ll PF_idx = 0, PF = primes[PF_idx], ans = N; // start from ans = N 
	while (PF * PF <= N){
		if (N % PF == 0) ans -= ans / PF; 
		while (N % PF == 0) N /= PF;
		PF = primes[++PF_idx];
	}
	if (N != 1) ans -= ans / N; 
	return ans;
}

// Extended 
int main(){

	return 0;
}