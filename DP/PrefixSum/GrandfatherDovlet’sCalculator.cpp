/*
 *	CodeForces ER6B
 *	Created by Ziyi Tang
 *	Prefix Sum
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
#define MAXN 1000010

int refer[10] = {6,2,5,5,4,5,6,3,7,6};
int all[MAXN];
int main(){
	int a,b;
	cin >> a >> b;
	all[0] = 0;
	REP(i,1,b+1){
		int now = 0;
		int tmp = i;
		while(tmp){
			now+=refer[tmp%10];
			tmp/=10;
		}
		all[i] = all[i-1]+now;
		//cout << all[i] << endl;
	}
	cout << all[b]-all[a-1] << endl;

	return 0;
}
