/*
 *	CodeForces 343A
 *	Created by Ziyi Tang
 *	Pair Counting
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
#define MAXN 1000

int all[105][105];
int main(){
	int n;
	cin >> n;
	getchar();
	string line;
	REP(i,0,n){
		getline(cin,line);
		REP(j,0,n){
			if(line[j] == 'C') all[i][j] = 1;
			else all[i][j] = 0;
		}
	}
	int num = 0;
	REP(i,0,n){
		int sum = 0;
		REP(j,0,n){
			sum+=all[i][j];
		}
		num+=(sum*(sum-1)/2);
	}
	REP(j,0,n){
		int sum = 0;
		REP(i,0,n){
			sum+=all[i][j];
		}
		num+=(sum*(sum-1)/2);
	}
	cout << num << endl;


	return 0;
}
