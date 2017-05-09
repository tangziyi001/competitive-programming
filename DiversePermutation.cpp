/*
 *	CodeForces 482A
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
int main(){
	int n,m;
	cin >> n >> m;
	all.assign(n,0);
	int left = 1, right = n;
	REP(i,0,n){
		if(i&1){
			all[i] = right--;
		} else
			all[i] = left++;
	}
	//REP(i,0,n) cout << all[i] << endl;
	m-=1;
	sort(all.begin()+m, all.end());
	if(m&1){
		reverse(all.begin()+m, all.end());	
	}
	REP(i,0,n){
		cout << all[i] << " ";
	}
	cout << endl;
	return 0;
}