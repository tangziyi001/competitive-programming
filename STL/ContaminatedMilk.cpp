/*
 *	USACO 2015 December Contest, Bronze 3
 *	Created by Ziyi Tang
 *	
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
#include <unordered_set>
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

int n,m,d,s;
vector<unordered_set<int> > ss;
vector<vpi> all;
int main(){
	ifstream ifile("badmilk.in");
	ifile >> n >> m >> d >> s;
	vpi vtmp;
	unordered_set<int> qtmp;
	all.assign(n,vtmp);
	ss.assign(m,qtmp);
	REP(i,0,d){
		int p,m,t;
		ifile >> p >> m >> t;
		all[p-1].push_back(make_pair(m-1,t-1));
		ss[m-1].insert(p-1);
	}

	int filter[50];
	REP(i,0,m) filter[i] = 1;
	REP(i,0,s){
		int tmp[50];
		FILL(tmp,0);
		int p,t;
		ifile >> p >> t;
		vpi now = all[p-1];
		int psz = now.size();
		REP(j,0,psz){
			if(now[j].second < t-1){
				tmp[now[j].first] = 1;
			}
		}
		REP(j,0,m){
			filter[j] = (filter[j] & tmp[j]);
		}
	}
	ifile.close();
	int maxp = 0;
	REP(i,0,m){
		if(filter[i])
			maxp = max(maxp, (int)ss[i].size());
	}
	cout << maxp << endl;
	ofstream ofile("badmilk.out");
	ofile << maxp << endl;
	ofile.close();
	return 0;
}