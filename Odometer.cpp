/*
 *	USACO 2014 US Open, Bronze 1
 *	Coded by Ziyi Tang
 *	Brute force to find out all possible interesting numbers
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
#define MAXN 1000

vector<ll> all;
int main(){
	freopen("odometer.in", "r", stdin);
  	freopen("odometer.out", "w", stdout);
	ll cont = 0LL;
  	REP(i,3,17){
  		REP(j,0,10){
  			string now(i,(char)(j+'0'));
  			REP(k,0,i){
  				char ori = now[k];
  				int cur = ori-'0';
  				REP(h,1,10){
  					int nxt = (cur+h)%10;
  					now[k] = (char)(nxt+'0');
  					if(now[0] != '0'){
  						ll re = stoll(now);
						all.push_back(re);
						//cout << now << endl;
  					}
  				}
  				now[k] = ori;
  			}
  		}
  	}
  	ll big = 10000000000000000LL;
  	all.push_back(big);
  	int sz = all.size();
  	ll a,b;
  	cin >> a >> b;
  	REP(i,0,sz){
  		if(all[i] >= a && all[i] <= b)
  			cont++;
  	}
  	cout << cont << endl;
	return 0;
}