/*
 *	USACO 2015 US Open, Bronze 2
 *	Created by Ziyi Tang
 *	Parity Check
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

int n;
int oe[7][2];
bool check(int b,int e,int s,int i,int g,int o,int m){
	//cout << b << e<<s<<i<<g<<o<<m << endl;
	return ((b+e+s+s+i+e)*(g+o+e+s)*(m+o+o) % 2) == 0;
}
int main(){
	ifstream ifile("geteven.in");
	ifile >> n;
	FILL(oe,0);
	REP(i,0,n){
		char tmp;
		int num;
		ifile >> tmp >> num;
		int idx = 0;
		if(tmp == 'B') idx=0;
		if(tmp == 'E') idx=1;
		if(tmp == 'S') idx=2;
		if(tmp == 'I') idx=3;
		if(tmp == 'G') idx=4;
		if(tmp == 'O') idx=5;
		if(tmp == 'M') idx=6;
		// Notice that negative number has a remainder of -1
		if(num % 2 == 0) oe[idx][0]++;
		else oe[idx][1]++;
	}
	ifile.close();
	// REP(i,0,7){
	// 	cout << oe[i][0] << " ";
	// }
	// cout << endl;
	// REP(i,0,7){
	// 	cout << oe[i][1] << " ";
	// }
	// cout << endl;
	ll cont = 0;
	for(int i = 0; i < (1 << 7); i++){
		if (check((i & (1 << 6) ? 1 : 0),
			(i & (1 << 5) ? 1 : 0),
			(i & (1 << 4) ? 1 : 0),
			(i & (1 << 3) ? 1 : 0),
			(i & (1 << 2) ? 1 : 0),
			(i & (1 << 1) ? 1 : 0),
			(i & (1 << 0) ? 1 : 0))){
			ll prod = 1;
			REP(j,0,7){
				prod*=oe[j][(i & (1 << (6-j))) ? 1 : 0];
			}
			//cout << "p " << prod << endl;
			cont+=prod;
		}
	}
	cout << cont << endl;
	ofstream ofile("geteven.out");
	ofile << cont << endl;
	ofile.close();
	return 0;
}