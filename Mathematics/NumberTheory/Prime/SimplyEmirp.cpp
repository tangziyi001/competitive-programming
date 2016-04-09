/*
 *	UVA 10235
 *	Coded by Ziyi Tang
 *	Prime Test
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
#define MAXN 1000010

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

int main(){
	int num;
	sieve(MAXN);
	while(cin >> num){
		string now = to_string(num);
		reverse(now.begin(),now.end());
		int flag = 1;
		if(now[0] == 0) flag = 0;
		int rev = stoi(now);
		if(isPrime(num) && flag && isPrime(rev) && num != rev){
			printf("%d is emirp.\n", num);
		}
		else if(isPrime(num)){
			printf("%d is prime.\n", num);
		}
		else
			printf("%d is not prime.\n", num);
	}
	return 0;
}