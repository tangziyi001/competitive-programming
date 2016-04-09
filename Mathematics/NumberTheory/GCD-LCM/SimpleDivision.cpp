/*
 *	UVA 10407
 *	Coded by Ziyi Tang
 *	Same Remainder & GCD/LCM
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

vi all;
vi diff;
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}
int main(){
	string line;
	while(getline(cin,line)){
		if(line[0] == '0') break;
		all.clear();
		diff.clear();
		stringstream ss(line);
		int now;
		while(ss >> now && now != 0) all.push_back(now);
		int sz = all.size();
		REP(i,0,sz-1){
			diff.push_back(abs(all[i+1]-all[i]));
			//cout << diff[i] << endl;
		}
		int allgcd = diff[0];
		sz = diff.size();
		REP(i,1,sz){
			allgcd = gcd(allgcd,diff[i]);
		}
		cout << allgcd << endl;
	}
	return 0;
}