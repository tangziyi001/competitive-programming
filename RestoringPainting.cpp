/*
 *	
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
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int main(){
	int n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	vi all;
	int ab = a+b;
	int bd = b+d;
	int dc = c+d;
	int ca = c+a;
	all.push_back(ab);
	all.push_back(bd);
	all.push_back(dc);
	all.push_back(ca);
	int maxp = *max_element(all.begin(), all.end());
	int minp = *min_element(all.begin(), all.end());
	//cout << minp << " " << maxp << endl;
	ll diff = (minp+n)-(maxp+1);
	//cout << diff << endl;
	if(diff < 0LL)
		cout << 0 << endl;
	else{
		ll re = n*(diff+1LL);
		cout << re << endl;
	}

	return 0;
}