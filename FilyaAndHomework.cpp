/*
 *	Codeforces 714B - Filya and Homework
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

set<int> all;
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.insert(tmp);
	}
	if(all.size() > 3){
		cout << "NO" << endl;
		return 0;
	}
	int now = *all.begin();
	if(all.size() == 1){
		cout << "YES" << endl;
	}
	else if(all.size() == 2){
		cout << "YES" << endl;
	}
	else{
		int sta = *all.begin();
		int end = *all.rbegin();
		int mid = *(++all.begin());
		if(mid - sta == end - mid)
			cout << "YES" << endl;
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}