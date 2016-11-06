/*
 *	The 2nd ProgNova Multi-University Programming Contest E
 *	Created by Ziyi Tang
 *	Enumerate subsets with DP and bitwise manipulation
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
#define MAXN 1005
#define MOD 1000000007
ll _sieve_size; 
bitset<MAXN> bs; 
vi primes;
int all[MAXN];
int facs[15000];
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
void checkFac(){
	facs[0] = 0;
	REP(i,1,14100){
		for(int j = 0; j < primes.size() && primes[j] <= i; j++) if(i%primes[j] == 0){
			facs[i]++;
		}
	}
}
int dp[16500];
int main(){
	sieve(MAXN);
	checkFac();
	int n;
	cin >> n;
	REP(i,0,n){
		scanf("%d", &all[i]);
	}
	FILL(dp,0);
	// Subsets Enumeration with DP
	for(int j = 0; j < (1<<n); j++){
		for(int s = 0; s < (1<<n); s++) if((s&j)==s){
			int sum = 0;
			for(int k = 0; k < n; k++) if(s&(1<<k)){
				sum += all[k];
			}
			dp[j] = max(dp[j], facs[sum]+dp[j^s]);
		}
	}
	cout << dp[(1<<n)-1] << endl;
	return 0;
}




