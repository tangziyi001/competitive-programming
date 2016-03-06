/*
 *	CodeForces 344A
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

vi a1;
vi a2;
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		a1.push_back(tmp);
	}
	REP(j,0,n){
		int tmp;
		cin >> tmp;
		a2.push_back(tmp);
	}
	int maxp = 0;
	REP(i,0,n){
		int tmp1 = 0;
		int tmp2 = 0;
		tmp1 |= a1[i];
		tmp2 |= a2[i];
		REP(j,i,n){
			tmp1 |= a1[j];
			tmp2 |= a2[j];
			maxp = max(maxp, tmp1+tmp2);
		}
	}
	cout << maxp << endl;
	return 0;
}

