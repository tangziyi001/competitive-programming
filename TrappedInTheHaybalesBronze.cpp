/*
 *	USACO 2015 US Open, Bronze 3
 *	Created by Ziyi Tang
 *	Simulation on each interval
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

vpi all;
vi itv;
int main(){
	ifstream ifile("trapped.in");
	int n;
	ifile >> n;
	REP(i,0,n){
		int sz,tmp;
		ifile >> sz >> tmp;
		all.push_back(make_pair(tmp,sz));
	}
	sort(all.begin(),all.end());
	REP(i,1,n){
		itv.push_back(all[i].first-all[i-1].first);
	}
	ifile.close();
	int cont = 0;
	REP(i,0,n-1){
		int left = i;
		int right = i+1;
		while(left >= 0 && right < n){
			int l =	all[left].first;
			int r = all[right].first;
			int diff = r - l;
			int flag = 0;
			if(diff > all[left].second){
				left--;
				flag = 1;
			}
			if(diff > all[right].second){
				right++;
				flag = 1;
			}
			if(!flag) break;
		}
		if(left >= 0 && right < n)
			cont += itv[i];
	}
	cout << cont << endl;
	ofstream ofile("trapped.out");
	ofile << cont << endl;
	ofile.close();
	return 0;
}