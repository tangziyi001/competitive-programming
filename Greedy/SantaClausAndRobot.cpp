/*
 *	Codeforces 752C - Santa Claus and Robot
 *	Created by Ziyi Tang
 *	Greedy
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

int n;
string line;
set<char> ss;
int main(){
	cin >> n >> line;
	int cont = 1;
	char pre = '#';
	REP(i,0,n){
		ss.insert(line[i]);
		if(ss.size() == 3 || (line[i] == 'R' && pre == 'L')
			|| (line[i] == 'L' && pre == 'R')
			|| (line[i] == 'U' && pre == 'D')
			|| (line[i] == 'D' && pre == 'U')){
			cont++;
			ss.clear();
			ss.insert(line[i]);
		}
		pre = line[i];
	}
	cout << cont << endl;
	return 0;
}