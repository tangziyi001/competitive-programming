/*
 *	The 2nd ProgNova Multi-University Programming Contest A
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
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int main(){
	string line;
	cin >> line;
	int sum = 0;
	int a = 0,b = 0,c = 0;
	REP(i,0,line.size()){
		char now = line[i];
		if(now == 'T') a++;
		if(now == 'C') b++;
		if(now == 'G') c++;
	}
	sum += pow(a,2) + pow(b,2) + pow(c,2) + min(a,min(b,c))*7;
	cout << sum << endl;
	return 0;
}