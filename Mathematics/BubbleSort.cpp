/*
 *	UVA 12004
 *	Created by Ziyi Tang
 *	Every two numbers have 1/2 probability to be swapped. The result is 1/2 * C(n,2)
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
typedef unsigned long long ull;
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
#define MAXN 100005

int main(){

	int test;
	cin >> test;
	REP(i,1,test+1){
		ll num;
		cin >> num;
		ll nom = (num*(num-1))/2;
		if(nom%2 == 0){
			printf("Case %d: %lld\n", i,nom/2);
		}
		else{
			printf("Case %d: %lld/2\n", i, nom);
		}
		
	}
	return 0;
}
