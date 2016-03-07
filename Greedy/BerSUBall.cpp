/*
 *	CodeForces 277.5B
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
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

priority_queue<int,vi,greater<int> > boy;
priority_queue<int, vi, greater<int> > girl;
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		boy.push(tmp);
	}
	int m;
	cin >> m;
	REP(i,0,m){
		int tmp;
		cin >> tmp;
		girl.push(tmp);
	}
	int cont = 0;
	while(!boy.empty() && !girl.empty()){
		if(abs(boy.top()-girl.top()) <= 1){
			cont++;
			boy.pop();girl.pop();
		}
		else if(boy.top() > girl.top())
			girl.pop();
		else
			boy.pop();
	}
	cout << cont << endl;
	return 0;
}

