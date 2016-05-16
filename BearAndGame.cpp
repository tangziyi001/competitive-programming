/*
 *	CodeForces 673A - Bear and Game
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
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

vi all;
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.push_back(tmp);
	}
	int start = 0;
	int flag = 0;
	REP(i,0,n){
		int now  = all[i];
		if(start+15 < now){
			flag = 1;
			break;
		}
		else
			start = now;
	}
	if(start + 15 < 90)
		flag = 1;

	if(flag)
		cout << start+15 << endl;
	else
		cout << 90 << endl;
	return 0;
}