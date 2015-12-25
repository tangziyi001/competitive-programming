/*
 *	UVA 11723
 *	Created by Ziyi Tang
 *	Basic Math
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
	int n,r;
	int test = 0;
	while(cin >> r >> n && r != 0 && n != 0){
		test++;
		if(r > 27*n)
			printf("Case %d: impossible\n",test);
		else{
			int re = 0;
			if(n >= r)
				re = 0;
			else{
				int rem = r-n;
				re = (int)ceil((double)rem/n);
			}
			printf("Case %d: %d\n",test,re);
		}
	}
	return 0;
}
