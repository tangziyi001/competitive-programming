/*
 *	CodeForces 230B
 *	Created by Ziyi Tang
 *	Square of Primes
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
#define MAXN 1000

ll n;
ll tmp;
ll sn = (ll)sqrt((ll)1E12);
vector<ll> all;
set<ll> ss;
int main(){
	all.assign(sn+1,0);
	for(ll i = 2; i < sn; i++){
		if(all[i] == 0){
			ss.insert(i*i);
			for(ll j = 2; j*i < sn; j++){
				all[j*i] = 1;
			}
		}
	}
	cin >> n;
	while(n--){
		cin >> tmp;
		if(ss.find(tmp) != ss.end())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
