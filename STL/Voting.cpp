/*
 *	Codeforces 749C - Voting
 *	Created by Ziyi Tang
 *	Queue
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

queue<int> a;
queue<int> b;
int main(){
	int n;
	string line;
	cin >> n >> line;
	REP(i,0,n){
		if(line[i] == 'D') a.push(i);
		else b.push(i);
	}
	while(1){
		if(a.empty()){
			cout << "R" << endl;
			break;
		}
		if(b.empty()){
			cout << "D" << endl;
			break;
		}
		if(a.front() < b.front()){
			b.pop();
			a.push(a.front()+n);
			a.pop();
		} else {
			a.pop();
			b.push(b.front()+n);
			b.pop();
		}
	}
	return 0;
}