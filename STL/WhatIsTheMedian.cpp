/*
 *	UVA 10107
 *	Created by Ziyi Tang
 *	Two Priority Queues
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
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

int n,k;
vi all;

int main(){

	cin >> n >> k;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.push_back(tmp);
	}
	sort(all.begin(),all.end());
	int sz = all.size();
	int cont = 0;
	int sum = 2*all[sz-1]-2;
	for(int i = sz-1; i >= 0; i--){
		cont++;
		if(cont == k && i-1 >= 0){
			sum = sum + (2*all[i-1]-2);
			cont = 0;
		}

	}
	cout << sum << endl;





	return 0;
}
