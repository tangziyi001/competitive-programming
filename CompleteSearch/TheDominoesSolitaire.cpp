/*
 *	UVA 10503
 *	Created by Ziyi Tang
 *	Recursive Backtracking with Mark
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

int n,m;
int mark[20];
vvi all;
vi first;
vi second;
int rec(int num, int pos){
	//cout << num << " " << pos << endl;
	if(pos == n)
		return num == second[0];
	int flag = 0;
	REP(i,0,m){
		if(mark[i]) continue;
		vi now = all[i];
		if(now[0] == num){
			mark[i] = 1;
			flag |= rec(now[1], pos+1);
			mark[i] = 0;
		}
		if(now[1] == num){
			mark[i] = 1;
			flag |= rec(now[0],pos+1);
			mark[i] = 0;
		}
	}
	return flag;
}
int main(){
	while(cin >> n && n != 0){
		FILL(mark,0);
		all.clear();
		first.clear();
		second.clear();
		cin >> m;
		int a,b;
		cin >> a >> b;
		first.push_back(a);
		first.push_back(b);
		cin >> a >> b;
		second.push_back(a);
		second.push_back(b);
		REP(i,0,m){
			cin >> a >> b;
			vi ttmp;
			ttmp.push_back(a);
			ttmp.push_back(b);
			all.push_back(ttmp);
		}
		int re = rec(first[1],0);
		if(re)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
