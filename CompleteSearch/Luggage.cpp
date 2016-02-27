/*
 *	UVA 10664
 *	Created by Ziyi Tang
 *	Complete Search or DP
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

int n;
vi all;
int sz;
bool rec(int a, int b, int pos){
	if(pos == sz) return a == b;
	bool re = false;
	re |= rec(a+all[pos], b,pos+1);
	re |= rec(a, b+all[pos],pos+1);
	return re;
}

int main(){
	cin >> n;
	getchar();
	while(n--){
		all.clear();
		string line;
		getline(cin,line);
		stringstream ss(line);
		int tmp;
		while(ss >> tmp){
			all.push_back(tmp);
		}
		sz = all.size();
		if(rec(0,0,0)){
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;

	}
	return 0;
}

