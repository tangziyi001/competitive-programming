/*
 *	USACO 2015 December Contest, Silver 2
 *	Created by Ziyi Tang
 *	Greedy Comparison
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

set<int> ss;
vi a;
vi b;
int main(){
	ifstream ifile("highcard.in");
	int n;
	ifile >> n;
	REP(i,0,n){
		int tmp;
		ifile >> tmp;
		ss.insert(tmp);
		a.push_back(tmp);
	}
	REP(i,1,2*n+1){
		if(ss.find(i) == ss.end())
			b.push_back(i);
	}
	ifile.close();
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int idx1 = 0;
	int idx2 = 0;
	int cont = 0;
	while(idx1 < n && idx2 < n){
		if(b[idx2] > a[idx1]){
			cont++; idx2++; idx1++;
		}
		else
			idx2++;
	}
	cout << cont << endl;
	ofstream ofile("highcard.out");
	ofile << cont << endl;
	ofile.close();
	return 0;
}