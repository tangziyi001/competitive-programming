/*
 *	USACO 2016 US Open Contest, Silver 3
 *	Coded by Ziyi Tang
 *	UnionFind: reversely add each vertex and edges. First check if remained opened light belongs to 
 *  the same set, then open this light and unionSet all neighboring opened light.
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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
#define MAXN 3005

vvi all;
int mark[MAXN];
vi ord;
int p[MAXN];
stack<int> re;
int n,m;
int findRep(int i){
	return p[i] == i ? i : (p[i] = findRep(p[i]));
}
bool isSame(int i, int j){
	return findRep(i) == findRep(j);
}
void unionSet(int i, int j){
	int pi = findRep(i);
	int pj = findRep(j);
	if(!isSame(pi,pj))
		p[pi] = pj;
}
bool checkSet(){
	int head = -1;
	bool flag = true;
	REP(i,0,n) if(mark[i] == 1 && flag){
		if(head == -1) head = findRep(i);
		else{
			if(findRep(i) != head)
				flag = false;
		}
	}
	return flag;
}
int main(){
	freopen("closing.in", "r", stdin);
  	freopen("closing.out", "w", stdout);
  	cin >> n >> m;
  	if(n == 0){
  		cout << "YES" << endl;
  		return 0;
  	}
  	all.assign(n,vi(0,0));
  	REP(i,0,n){
  		p[i] = i;
  	}
  	REP(i,0,m){
  		int sta,ter;
  		cin >> sta >> ter;
  		all[sta-1].push_back(ter-1);
  		all[ter-1].push_back(sta-1);
  	}

  	REP(i,0,n){
  		int tmp;
  		cin >> tmp;
  		ord.push_back(tmp-1);
  	}
  	mark[ord[n-1]] = 1;
  	for(int i = n-2; i >= 0; i--){
  		int now = ord[i];
  		if(checkSet())
  			re.push(1);
  		else
  			re.push(0);
  		int sz = all[now].size();
  		mark[now] = 1;
  		REP(j,0,sz){
  			int tmp = all[now][j];
  			if(mark[tmp])
  				unionSet(now,tmp);
  		}
  	}
  	if(checkSet()) re.push(1);
  	else re.push(0);

  	while(!re.empty()){
  		int r = re.top();re.pop();
  		if(r)
  			cout << "YES" << endl;
  		else
  			cout << "NO" << endl;
  	}
	return 0;
}