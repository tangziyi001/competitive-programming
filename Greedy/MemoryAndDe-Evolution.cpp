/*
 *	Codeforces 712C - Memory and De-Evolution
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
#define MAXN 1000
#define MOD 1000000007

vi tri;
int a,b;
bool checkCom(vector<int>& tri){
	if(tri[0] == a && tri[1] == a && tri[2] == a)
		return true;
	return false;
}
int main(){
	cin >> a >> b;
	REP(i,0,3){
		tri.push_back(b);
	}
	int cont = 0;
	while(!checkCom(tri)){
		REP(i,0,3) if(tri[i] != a){
			tri[i] = min(a, tri[(i+1)%3]+tri[(i+2)%3]-1);
			cont++;
		}
	}
	cout << cont << endl;
	return 0;
}