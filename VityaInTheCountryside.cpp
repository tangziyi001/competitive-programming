/*
 *	Codeforces 719A - VityaInTheCountryside
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

vi all;
int moon[30] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.push_back(tmp);
	}
	int sz = all.size();
	int match = 0;
	string re = "";
	REP(i,0,30){
		int flag = true;
		REP(j,0,sz){
			if(all[j] != moon[(i+j)%30])
				flag = false;
		}
		if(flag){
			match++;
			if((i+sz-1)%30 >= 15)
				re = "DOWN";
			else
				re = "UP";
		}
	}
	if(match > 1)
		cout << -1 << endl;
	else{
		cout << re << endl;
	}
	return 0;
}