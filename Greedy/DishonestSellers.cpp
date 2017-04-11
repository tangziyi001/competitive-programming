/*
 *	Codeforces 779C
 *	Created by Ziyi Tang
 *	Greedy Algorithm
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

vi all1;
vi all2;
vpi all;
int main(){
	int n,k;
	cin >> n >> k;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all1.push_back(tmp);
	}
	int cont = 0;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all2.push_back(tmp);
		all.push_back(make_pair(all1[i]-tmp,i));
		if(all[i].first < 0){
			cont++;
		}
	}
	cont = max(cont,k);
	int sum = 0;
	sort(all.begin(), all.end());
	REP(i,0,cont){
		sum += all1[all[i].second];
	}
	REP(i,cont,n){
		sum += all2[all[i].second];
	}
	cout << sum << endl;
	return 0;
}