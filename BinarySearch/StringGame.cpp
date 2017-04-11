/*
 *	Codeforces 779D
 *	Created by Ziyi Tang
 *	Binary Search the maximum number of removal
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
#define MAXN 200010
#define MOD 1000000007

vi all;
int mark[MAXN];
int main(){
	string a,b;
	cin >> a >> b;
	REP(i,0,a.size()){
		int tmp;
		scanf("%d",&tmp);
		all.push_back(tmp-1);
	}
	int i = 0, j = all.size();
	while(i <= j){
		int mid = (i+j)/2;
		FILL(mark,0);
		REP(k,0,mid){
			mark[all[k]] = 1;
		}
		int idx = 0;
		REP(k,0,a.size()){
			if(idx < b.size() && mark[k] == 0 && a[k] == b[idx])
				idx++;
		}
		if(idx == b.size())
			i = mid+1;
		else
			j = mid-1;
	}
	cout << j << endl;
	return 0;
}