/*
 *	Codeforces 764A
 *	Created by Ziyi Tang
 *	Simulation or LCM
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
#define MAXN 10005
#define MOD 1000000007

int mark[MAXN];
// GCD
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b){
	return a * (b / gcd(a , b));
}
int main(){
	int n,m,z;
	FILL(mark,0);
	cin >> n >> m >> z;

	// int nn = n,mm = m;
	// while(nn <= z){
	// 	mark[nn] = 1;
	// 	nn += n;
	// }
	// int cont = 0;
	// while(mm <= z){
	// 	if(mark[mm]) cont++;
	// 	mm += m;
	// }
	// cout << cont << endl;

	int gg = lcm(n,m);
	cout << z/gg << endl;
	return 0;
}