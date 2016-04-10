/*
 *	Google Code Jam 2016 Online Qualification Round 3
 *	Coded by Ziyi Tang， CS480 S16 Algorithmic Problem Solving, New York University
 *
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
typedef unsigned long long ll;
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
#define MAXN 1000000010
#define MAXM 1000000

int n,j;
ll dig[12][20];
ll _sieve_size; 
bitset<MAXN> bs; 
vi primes;
vector<int> re;
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
ll power(ll base, ll p){
	if(p == 0) return 1LL;
	ll tmp = power(base,p/2);
	tmp = tmp*tmp;
	if(p&1)
		tmp*=base;
	return tmp;
}
bool check(ll cur){
	REP(i,2,11){
		ll sum = 0LL;
		REP(j,0,n){
			if(cur & (1 << j)){
				sum+=dig[i][j];
			}
		}
		//cout << sum << endl;
		if(isPrime(sum)) return false;
		int sz =  primes.size();
		//cout << sum << endl;
		REP(i,0,sz){
			if(sum%primes[i] == 0){
				re.push_back(primes[i]);
				break;
			}
		}
	}
	return true;
}
void ConvertToBinary(int n)
{
    if (n / 2 != 0) {
        ConvertToBinary(n / 2);
    }
    printf("%d", n % 2);
}
int main(){
	int test;
	cin >> test;
	sieve(MAXN);
	REP(cas,1,test+1){
		re.clear();
		ll now = 0LL;
		//cout << "go" << endl;
		REP(i,2,11){
			REP(j,0,20){
				dig[i][j] = power(i,j);
				//cout << dig[i][j] << endl;
			}
		}
		cin >> n >> j;
		ll cur = (1 << (n-1));
		int cont = 0;
		printf("Case #%d:\n", cas);
		while(cur <= (1 << n)-1){
			if(!(cur&1)) cur|=1;
			if(check(cur)){
				cont++;
				ConvertToBinary(cur);
				REP(i,2,11){
					cout << " ";
					cout << re[i-2];
				}
				//cout << "sz" << re.size() << endl;
				cout << endl;
				
			}
			cur+=1;
			re.clear();
			if(cont == j) break;
		}
	}
	return 0;
}