/*
 *	CodeForces 472B
 *	Created by Ziyi Tang
 *	Greedy
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

priority_queue<int,vi, less<int> > a;
priority_queue<int,vi, greater<int> > b;
int main(){
	int tmp;
	while(cin >> tmp){
		if(a.size() == 0 && b.size() == 0){
			a.push(tmp);
			cout << a.top() << endl;
			continue;
		}
		if(!b.empty() && tmp > b.top()){
			b.push(tmp);
		}
		else{
			a.push(tmp);
		}
		if(a.size() >= 2+b.size()){
			int now = a.top();a.pop();
			b.push(now); 
		}
		if(a.size()+2 <= b.size()){
			int now = b.top();b.pop();
			a.push(now);
		}
		// cout << a.top() << endl;
		// cout << b.top() << endl;
		if(a.size() > b.size()){
			cout << a.top() << endl;
		}
		else if (a.size() < b.size()){
			cout << b.top() << endl;
		}
		else{
			cout << (int)(a.top()+b.top())/2 << endl;
		}

	}

	return 0;
}
