/*
 *	Codeforces 735D - Taxes
 *	Created by Ziyi Tang
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

bool isPrime(ll n){
	if(n == 2){
		cout << 1 << endl;
		return 0;
	}
	for(ll i = 2; i <= sqrt(n)+1; i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}
int main(){
	ll n;
	cin >> n;
	if(n == 2){
		cout << 1 << endl;
		return 0;
	}
	if(n == 3){
		cout << 1 << endl;
		return 0;
	}
	if(isPrime(n)){
		cout << 1 << endl;
		return 0;
	}
	if(n&1){
		if(isPrime(n-2)){
			cout << 2 << endl;
		} else {
			cout << 3 << endl;
		}
	} else {
		cout << 2 << endl;
	}
	return 0;
}