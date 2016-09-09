/*
 *	Codeforces Round #369 Div.2 B
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 505
#define MOD 1000000007

int n;
ll all[MAXN][MAXN];
int main(){
	cin >> n;
	REP(i,0,n){
		ll tmp;
		REP(j,0,n){
			cin >> tmp;
			all[i][j] = tmp;
		}
	}
	ll now = 0LL;
	ll tmpnow = 0LL;
	REP(i,0,n){
		ll sum = 0;
		int flag = 1;
		REP(j,0,n){
			sum += all[i][j];
			if(all[i][j] == 0) {
				flag = 0;
			}
		}
		if(flag == 1){
			if(now == 0 || now == sum)
				now = sum;
			else{
				cout << -1 << endl;
				return 0;
			}
		} else {
			if(tmpnow == 0 || sum == tmpnow)
				tmpnow = sum;
			else{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	REP(j,0,n){
		ll sum = 0;
		int flag = 1;
		REP(i,0,n){
			sum += all[i][j];
			if(all[i][j] == 0) {
				flag = 0;
			}
		}
		if(flag == 1){
			if(now == 0 || now == sum)
				now = sum;
			else{
				cout << -1 << endl;
				return 0;
			}
		} else {
			if(tmpnow == 0 || sum == tmpnow)
				tmpnow = sum;
			else{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	ll sum = 0LL;
	int flag = 1;
	REP(i,0,n){
		int j = n-i-1;
		sum += all[i][j];
		if(all[i][j] == 0) flag = 0;
	}
	if(flag == 1){
		if(now == 0 || now == sum)
			now = sum;
		else{
			cout << -1 << endl;
			return 0;
		}
	} else {
		if(tmpnow == 0 || sum == tmpnow)
			tmpnow = sum;
		else{
			cout << -1 << endl;
			return 0;
		}
	}
	sum = 0LL;
	flag = 1;
	REP(i,0,n){
		int j = i;
		sum += all[i][j];
		if(all[i][j] == 0) flag = 0;
	}
	if(flag == 1){
		if(now == 0 || now == sum)
			now = sum;
		else{
			cout << -1 << endl;
			return 0;
		}
	} else {
		if(tmpnow == 0 || sum == tmpnow)
			tmpnow = sum;
		else{
			cout << -1 << endl;
			return 0;
		}
	}
	if(tmpnow == 0 && now == 0) {
		cout << 1 << endl;
		return 0;
	}
	ll re = now-tmpnow > 0 ? now-tmpnow : -1;
	cout << re << endl;
	return 0;
}