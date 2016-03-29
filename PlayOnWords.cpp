/*
 *	UVA 1O129
 *	Coded by Ziyi Tang
 *	Euler Path: There can only be two vertices whose in-degree and out-degree are
 *	differed by 1. The rest of vertices must have same number of in-degree and out-degree.
 *	Use UnionFind to check if the graph is connected. 
 *	i.e. All Head and tail letters appeared are connected.
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
#define MAXN 30

vpi all;
int p[MAXN];
int app[MAXN];
int findRep(int i){
	return p[i] == i ? i : p[i] = findRep(p[i]);
}
bool isSame(int i, int j){
	return findRep(i) == findRep(j);
}
void unionSet(int i, int j){
	int ai = findRep(i);
	int aj = findRep(j);
	if(!isSame(ai,aj)){
		p[ai]=aj;
	}
}
vector<pair<char,char> >  words;
int main(){
	int test;
	cin >> test;
	while(test--){
		FILL(app,0);
		REP(i,0,26)
			p[i] = i;
		all.clear();
		all.assign(26,make_pair(0,0));
		int n;
		cin >> n;
		string tmp;
		REP(i,0,n){
			cin >> tmp;
			int sz = tmp.size();
			app[tmp[0]-'a'] = 1;
			app[tmp[sz-1]-'a'] = 1;
			all[tmp[0]-'a'].first++;
			all[tmp[sz-1]-'a'].second++;
			unionSet(tmp[0]-'a', tmp[sz-1]-'a');
		}
		int conts = 0;
		int contt = 0;
		int flag = 1;
		REP(i,0,26){
			if(all[i].first == all[i].second+1)
				conts++;
			else if(all[i].first == all[i].second-1)
				contt++;
			if(all[i].first > all[i].second+1 || all[i].first < all[i].second-1)
				flag = 0;
			if(!flag) break;
		}
		set<int> pars;
		pars.insert(findRep(0));
		REP(i,1,26) if(app[i]){
			int tmp = findRep(i);
			if(pars.find(tmp) == pars.end())
				pars.insert(tmp);
		}
		if(pars.size() > 1)
			flag = 0;
		if(flag && ((conts == 1 && contt == 1) || (conts == 0 && contt == 0)))
			cout << "Ordering is possible." << endl;
		else
			cout << "The door cannot be opened." << endl;
	}
	return 0;
}