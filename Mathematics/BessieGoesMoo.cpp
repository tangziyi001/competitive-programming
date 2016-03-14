/*
 *	USACO 2015 US Open, Silver 1
 *	Created by Ziyi Tang
 *	Remainder Brute Force Check
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
ll rem[7][7];
bool check(int b,int e,int s,int i, int g,int o,int m){
	return ((b+e+s+s+i+e)%7 == 0 || (g+o+e+s)%7 == 0 || (m+o+o)%7 == 0);
}
int main(){
	ifstream ifile("bgm.in");
	ifile >> n;
	FILL(rem,0);
	REP(i,0,n){
		char now;
		int num;
		ifile >> now >> num;
		int idx = 0;
		if(now == 'B')idx = 0;
		if(now == 'E')idx = 1;
		if(now == 'S')idx = 2;
		if(now == 'I')idx = 3;
		if(now == 'G')idx = 4;
		if(now == 'O')idx = 5;
		if(now == 'M')idx = 6;
		// Pay attention to handle negative remainders
		// Notice that the counter could be really big
		rem[idx][(num%7+7)%7]++;
	}
	ifile.close();
	ll cont = 0;
	REP(b,0,7)
	REP(e,0,7)
	REP(s,0,7)
	REP(i,0,7)
	REP(g,0,7)
	REP(o,0,7)
	REP(m,0,7){
		if(check(b,e,s,i,g,o,m)){
			cont += rem[0][b]*rem[1][e]*rem[2][s]*rem[3][i]*rem[4][g]*rem[5][o]*rem[6][m];
		}
	}
	cout << cont << endl;
	ofstream ofile("bgm.out");
	ofile << cont << endl;
	ofile.close();
	return 0;
}

