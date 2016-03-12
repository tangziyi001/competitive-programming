/*
 *	
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

int sum[100005][3];
int n,q;
int main(){
	FILL(sum,0);
	ifstream ifile("bcount.in");
	ifile >> n >> q;
	REP(i,1,n+1){
		int tmp;
		ifile >> tmp;
		REP(j,0,3){
			sum[i][j] = sum[i-1][j];
		}
		sum[i][tmp-1] += 1;
	}
	ofstream ofile("bcount.out");
	REP(i,0,q){
		int a,b;
		ifile >> a >> b;
		ofile << sum[b][0]-sum[a-1][0] << " " << sum[b][1]-sum[a-1][1] << " " << sum[b][2]-sum[a-1][2] << endl;;
	}
	ifile.close();
	ofile.close();
	return 0;
}