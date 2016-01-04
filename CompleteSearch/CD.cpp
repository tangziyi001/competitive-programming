/*
 *	UVA 00624
 *	Created by Ziyi Tang
 *	DP and recursive backtracking. Make sure to terminate if already printed.
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

vvi dp;
vi all;
vi result;
bool already = false;
int n,num;
int rec(int length, int pos){
	if(length > n) return -INF;
	if(dp[length][pos] != -1)
		return dp[length][pos];
	if(pos == num) return length;
	return dp[length][pos] = max(rec(length+all[pos],pos+1),rec(length,pos+1));
}
void recprint(int pos, int sum, int tar){
	if(sum == tar){
		if(already)
			return;
		int sz = result.size();
		REP(i,0,sz)
			cout << result[i] << " ";
		already = true;
	}
	else if(pos == num){
		return;
	}
	else{
		result.push_back(all[pos]);
		recprint(pos+1, sum+all[pos], tar);
		result.pop_back();
		recprint(pos+1, sum, tar);
	}

}
int main(){
	while(cin >> n){
		all.clear();
		dp.clear();
		cin >> num;
		REP(i,0,num){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		vi ttmp;
		ttmp.assign(num+5,-1);
		dp.assign(n+5,ttmp);
		already = false;
		int re = rec(0,0);
		recprint(0, 0, re);
		cout << "sum:" << re << endl;
	}
	

	return 0;
}
