/*
 *	UVA 10346
 *	Created by Ziyi Tang
 *	Modulo Iteration. Cumulate the remain numbers.
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

int main(){
	ll n,k;
	while(scanf("%lld %lld",&n,&k)!=EOF){
		ll re = 0;
		ll rem = 0;
		while(n != 0){
			re += n;
			ll tmp = n%k;
			n /= k;
			rem += tmp;
			if(rem >= k){
				rem -= k;
				n += 1;
			}
		}
		cout << re << endl;
	}
	return 0;
}
