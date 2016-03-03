/*
 *	ICPC NY 2008B
 *	Created by Ziyi Tang
 *	Basic Map
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

map<char,char> all;
int main(){
	int n;
	cin >> n;
	getchar();	
	REP(t,1,n+1){
		all.clear();
		string line1, line2;
		getline(cin, line1);
		getline(cin, line2);
		REP(i,0,26){
			all[(char)('A'+i)] = line2[i];
		}
		int sz = line1.size();
		REP(i,0,sz){
			if(line1[i] != ' ')
				line1[i] = all[line1[i]];
		}
		printf("%d %s\n",t,line1.c_str());
	}

	return 0;
}

