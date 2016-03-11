/*
 *	USACO 2016 January Contest, Silver 1
 *	Created by Ziyi Tang
 *	Binary Search the result and greedy test it.
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

vi all;
int n,k;
bool test(int r){
	int cont = 0;
	int tmp = -1;
	REP(i,0,n){
		if(all[i] > tmp){
			cont++;
			tmp = all[i] + 2*r;
		}
	}
	return cont <= k;
}
int main(){
	ifstream ifile("angry.in");
	ifile >> n >> k;
	REP(i,0,n){
		int tmp;
		ifile >> tmp;
		all.push_back(tmp);
	}
	ifile.close();
	int re = 0;
	sort(all.begin(),all.end());
	if(k < n){
		int i = 0, j = 50005;
		while(i <= j){
			int mid = (i+j)/2;
			if(test(mid)) j = mid-1;
			else i = mid+1;
		}
		re = i;
	}
	ofstream ofile("angry.out");
	//cout << re << endl;
	ofile << re << endl;
	ofile.close();
	return 0;
}