/*
 *	USACO 2014 US Open, Bronze 2
 *	Coded by Ziyi Tang
 *	Use a counter: if this letter is 'G', the +1. Otherwise, -1. 
 *	For each number within counter, record the index of the leftmost 
 *	element.
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
#define MAXN 1000

int table[200005];
vpi all;
int main(){
	freopen("fairphoto.in", "r", stdin);
  	freopen("fairphoto.out", "w", stdout);
  	int n;
  	cin >> n;
  	FILL(table,-1);
  	REP(i,0,n){
  		int pos;
  		char cc;
  		cin >> pos >> cc;
  		all.push_back(make_pair(pos,cc));
  	}
  	sort(all.begin(), all.end());
  	int tmp = 0;
  	int maxp = 0;
  	char now = all[0].second;
  	int nowpos = all[0].first;

  	// Check the interval with one type
  	REP(i,1,n){
  		if(all[i].second == now){
  			maxp = max(maxp, all[i].first-nowpos);
  		}
  		else{
  			now = all[i].second;
  			nowpos = all[i].first;
  		}
  	}

  	// Check the interval with the same number for two types
  	REP(i,0,n){
  		if(all[i].second == 'G')
  			tmp++;
  		if(all[i].second == 'H')
  			tmp--;
  		if(table[tmp+100000] == -1)
  			table[tmp+100000] = i;
  		else{
  			int idx = table[tmp+100000];
  			maxp = max(maxp, all[i].first-all[idx+1].first);
  		}
  	}
  	cout << maxp << endl;
	return 0;
}