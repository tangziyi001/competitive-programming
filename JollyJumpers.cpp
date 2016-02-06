/*
 *	
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

int mark[3005];
vector<int> all;
int main(){
	int n = 0;
	while(cin >> n){
		FILL(mark,0);
		all.clear();
		int tmp;
		int re = 0;
		REP(i,0,n){
			cin >> tmp;
			all.push_back(tmp);
			if(i == 0){
				mark[0] = 1;
				continue;
			}
			int dif = abs(all[i]-all[i-1]);
			mark[dif] = 1;
		}
		int i = 1;
		for(; i <= n-1; i++){
			if(mark[i] == 0){
				cout << "Not jolly" << endl;
				break;
			}
		}
		if(i == n) cout << "Jolly" << endl;
	}
	return 0;
}
