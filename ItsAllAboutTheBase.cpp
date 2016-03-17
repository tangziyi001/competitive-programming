/*
 *	USACO 2015 January Contest, Bronze 3
 *	Coded by Ziyi Tang
 *	Store and Find
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
#include <unordered_map>
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

int k;
unordered_map<int,ll> ss;
int main(){
	freopen("whatbase.in", "r", stdin);
  	freopen("whatbase.out", "w", stdout);
	cin >> k;
	REP(t,0,k){
		ss.clear();
		int a,b;
		int x = -1,y = -1;
		cin >> a >> b;
		int a1  = a%10;
		int a2 = (a/10)%10;
		int a3 = a/100;
		int b1  = b%10;
		int b2 = (b/10)%10;
		int b3 = b/100;
		REP(i,10,15001){
			ss[a1+a2*i+a3*i*i] = i;
		}
		REP(i,10,15001){
			if(ss.find(b1+b2*i+b3*i*i) != ss.end()){
				x = ss[b1+b2*i+b3*i*i];
				y = i;
				break;
			}
		}
		cout << x << " " << y << endl;
	}
	return 0;
}