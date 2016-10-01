/*
 *	Codeforces 721A - One-dimensional Japanese Crossword
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
const int INF = (int)1E9;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int n;
int main(){
	int count = 0;
	cin >> n;
	string tmp;
	cin >> tmp;
	int len = 0;
	vector<int> re;
	REP(i,0,n){
		if(tmp[i] == 'B' && (i-1 < 0 || tmp[i-1] == 'W')){
			len = 1;
			count++;
		} else if (tmp[i] == 'B'){
			len++;
		} else if(tmp[i] == 'W' && len && tmp[i-1] == 'B'){
			re.push_back(len);
			len = 0;
		}
	}
	if(len){
		re.push_back(len);
	}
	cout << count << endl;
	REP(i,0,count){
		if(i) cout << " ";
		cout << re[i];
	}
	cout << endl;
	return 0;
}