/*
 *	Codeforces 754A - Lesha and array splitting
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
vi non;
vpi re;
int main(){
	int n;
	cin >> n;
	int flag = 0;
	REP(i,0,n){
		int tmp; cin >> tmp;
		all.push_back(tmp);
		if(tmp != 0){
			flag = 1;
			non.push_back(i);
		}
	}
	if(flag){
		cout << "YES" << endl;
		cout << non.size() << endl;
		int pre = 0;
		REP(i,0,non.size()){
			if(i == non.size()-1){
				cout << pre+1 << " " << n << endl;
			} else {
				cout << pre+1 << " " << non[i]+1 << endl;
			}
			pre = non[i]+1;
		}
	} else {
		cout << "NO" << endl;
	}
	return 0;
}