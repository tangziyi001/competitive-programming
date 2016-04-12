/*
 *	UVA 11181
 *	Coded by Ziyi Tang
 *	Conditional Probability
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

int n,r;
vector<double> all;
vector<int> who; // Who of the r people buys something
double pab[30]; // Prob that person i buy something and r people buy something
double pb; // Prob that r people buy something

void compute(){
	double now = 1.0;
	REP(i,0,n){
		now *= all[i];
	}
	pb += now;
	REP(i,0,who.size()){
		//cout << who[i] << " ";
		pab[who[i]] += now;
	}
	//cout << endl;
}
void dfs(int pos, int flip){
	if(flip == r && pos == n){
		compute(); return;
	}
	else if(pos == n) return;
	dfs(pos+1, flip);
	double tmp = all[pos];
	all[pos] = 1-all[pos];
	who.push_back(pos);
	dfs(pos+1, flip+1);
	who.pop_back();
	all[pos] = tmp;
}

int main(){
	int test = 0;					
	while(cin >> n >> r && (n!=0 || r!=0)){
		all.clear();
		who.clear();
		pb = 0;
		REP(i,0,n)
			pab[i] = 0.0;
		test++;
		double tmp;
		REP(i,0,n){
			cin >> tmp;
			all.push_back(1.0-tmp);
		}
		dfs(0,0);
		printf("Case %d:\n", test);
		REP(i,0,n){
			printf("%.6lf\n", pab[i]/pb+1e-9);
		}
		
	}
	return 0;
}