/*
 *	Google Code Jam 2016 Online Qualification Round 1
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
	int t;
	cin >> t;
	REP(cas,1,t+1){
		ll mark = 0;
		ll n;
		cin >> n;
		ll flag = -1;
		REP(c,1,100000){
			ll now = c*n;
			//cout << now << endl;
			ll tmp = now;
			while(tmp != 0){
				int cur = tmp%10;
				mark |= (1 << cur);
				tmp/=10;
			}
			if(mark == (1 << 10) - 1){
				flag = now;
				break;
			}
		}
		if(flag == -1){
			printf("Case #%d: INSOMNIA\n",cas);
		}
		else{
			ll pro = flag*n;
			printf("Case #%d: %lld\n",cas, flag);
		}

	}
	return 0;
}
