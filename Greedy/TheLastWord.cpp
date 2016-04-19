/*
 *	Google Codejam 2016 Round 1A 1
 *	Coded by Ziyi Tang, CS480 S16 New York University
 *	Greedy
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
	int test;
	cin >> test;
	REP(t,1,test+1){
		string line;
		cin >> line;
		string tmp = "";
		int sz = line.size();
		char cur = line[0];
		tmp = cur;
		REP(i,1,sz){
			if(line[i] >= cur){
				cur = line[i];
				string nn = cur+tmp;
				tmp = nn;
			}
			else{
				tmp += line[i];
			}
		}
		printf("Case #%d: %s\n", t, tmp.c_str());
	}
	return 0;
}