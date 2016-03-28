/*
 *	CodeForces 658A - Bear and Reverse Radewoosh
 *	Coded by Ziyi Tang
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

int n,c;
vi p;
vi t;
int main(){
	cin >> n >> c;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		p.push_back(tmp);
	}
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		t.push_back(tmp);
	}
	int a=0,b=0;
	REP(i,0,n){
		a+=p[i];
		b+=p[i];
	}
	int now = 0;
	REP(i,0,n){
		a = a-min(p[i],c*(now+t[i]));
		now += t[i];
	}
	now = 0;
	for(int i = n-1; i >= 0; i--){
		b = b-min(p[i],c*(now+t[i]));
		now += t[i];
	}
	if(a > b)
		cout << "Limak" << endl;
	else if(a < b)
		cout << "Radewoosh" << endl;
	else
		cout << "Tie" << endl;
	return 0;

}