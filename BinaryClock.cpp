/*
 *	ICPC NY 2008C
 *	Created by Ziyi Tang
 *	Basic Binary
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
	int n;
	cin >> n;
	getchar();
	REP(t,1,n+1){
		string line;
		getline(cin,line);
		int h,m,s;
		vi all;
		h = stoi(line.substr(0,2));
		m = stoi(line.substr(3,2));
		s = stoi(line.substr(6,2));
		all.push_back(h);
		all.push_back(m);
		all.push_back(s);
		string hor, ver;
		for(int i = 5; i >= 0; i--){
			REP(j,0,3){
				if(all[j] & (1 << i))
					ver+='1';
				else
					ver+='0';
			}
		}
		REP(j,0,3){
			for(int i = 5; i >= 0; i--){
				if(all[j] & (1 << i))
					hor+='1';
				else
					hor+='0';
			}
		}
		printf("%d %s %s\n",t,ver.c_str(),hor.c_str());
	}
	return 0;
}

