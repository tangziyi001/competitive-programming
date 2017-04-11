/*
 *	Codeforces 792B
 *	Created by Ziyi Tang
 *
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

vi all;
vi tmp;
int main(){
	int n,k;
	cin >> n >> k;
	REP(i,0,k){
		int tmp; cin >> tmp;
		all.push_back(tmp);
	}
	REP(i,0,n){
		tmp.push_back(i);
	}
	int lea = 0;
	REP(i,0,k){
		int eli = (all[i]+lea)%(n-i);
		cout << tmp[eli]+1 << " ";
		tmp.erase(tmp.begin()+eli);
		lea = eli%(n-i-1);
	}
	cout << endl;
	return 0;
}