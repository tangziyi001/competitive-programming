/*
 *	USACO 2014 February Contest, Silver 1
 *	Coded by Ziyi Tang
 *	Binary Search for String Comparison
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
#define MOD 1000000007

vector<pair<string, int> >all;
int sscmp(string a, string b){
	int sz = a.size();
	REP(i,0,sz){
		if(a[i] > b[i]) return 1;
		if(a[i] < b[i]) return -1;
	}
	return 0;
}
int main(){
	freopen("auto.in", "r", stdin);
  	freopen("auto.out", "w", stdout);
	int n,q;
	cin >> n >> q;
	REP(i,0,n){
		string tmp;
		cin >> tmp;
		all.push_back(make_pair(tmp,i));
	}
	sort(all.begin(), all.end());
	REP(i,0,q){
		int idx = 0;
		int tmp;
		string line;
		cin >> tmp >> line;
		int sz = line.size();
		int sta = 0, ter = n;
		while(sta <= ter){
			int mid = (sta+ter)/2;
			if(sscmp(line, all[mid].first.substr(0,sz)) > 0){
				sta = mid+1;
			}
			else{
				ter = mid-1;
			}
		}
		int re = -1;
		if(sta+tmp-1 < n && all[sta+tmp-1].first.substr(0,sz) == line)
			re = all[sta+tmp-1].second;
		if(re != -1) re++;
		cout << re << endl;
	}

	return 0;
}