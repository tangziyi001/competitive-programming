/*
 *	UVA 524
 *	Created by Ziyi Tang
 *	DFS
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
int n;
int mark[30];
void rec(int idx, vector<int>& tmp, vvi& re){
	if(idx == n && isPrime(1+tmp[tmp.size()-1])){
		re.push_back(tmp);
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(mark[i] == 0 && isPrime(tmp[idx-1]+i)){
			mark[i] = 1;
			tmp.push_back(i);
			rec(idx+1, tmp, re);
			tmp.pop_back();
			mark[i] = 0;
		}
	}
}
int main(){
	sieve(100);
	int test = 0;
	while(cin >> n){
		test++;
		if(test != 1) cout << endl;
		FILL(mark,0);
		vector<int> tmp;
		vvi re;
		tmp.push_back(1);
		mark[1] = 1;
		rec(1, tmp, re);
		printf("Case %d:\n", test);
		REP(i,0,re.size()){
			REP(j,0,re[i].size()){
				if(j != 0) cout << " ";
					cout <<  re[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}