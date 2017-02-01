/*
 *	Facebook Hacker Cup 2017 Qualification Round B
 *	Created by Ziyi Tang
 *	Two Pointers
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
bool comp(int a, int b){
	return a > b;
}
int main(){
	int t,n;
	cin >> t;
	REP(cas,1,t+1){
		cin >> n;
		all.clear();
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		sort(all.begin(), all.end(), comp);
		int i = 0, j = n-1, cont = 0;
		while(i <= j){
			int least = ceil(50.0/all[i]);
			//cout << all[i] << " " << all[j] << " " << least << endl;
			j -= least-1;
			if(i <= j) cont++;
			i++;
		}
		printf("Case #%d: ", cas);
		cout << cont << endl;
	}

	return 0;
}