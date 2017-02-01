/*
 *	UVA 719
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

int n;
int main(){
	int test; cin >> test;
	while(test--){
		string line;
		cin >> line;
		string mins = line;
		int minp = 0;
		int n = line.size();
		REP(i,1,n){
			string tmp = line.substr(1,n-1);
			tmp += line[0];
			if(tmp < mins){
				mins = tmp;
				minp = i;
			}
			line = tmp;
		}
		cout << minp+1 << endl;
	}
	return 0;
}