/*
 *	UVA 11231
 *	Created by Ziyi Tang
 *	Find Formula
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
	int n,m,c;
	while(cin >> n >> m >> c && (n != 0 || m != 0 || c != 0)){
		if(c == 1)
			cout << ((n-7)/2)*((m-7)/2)+((n-6)/2)*((m-6)/2) << endl;
		else
			cout << ((n-7)/2)*((m-6)/2)+((n-6)/2)*((m-7)/2) << endl;
		
	}
	return 0;
}
