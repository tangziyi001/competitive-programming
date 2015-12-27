/*
 *	UVA 10751
 *	Created by Ziyi Tang
 *	Find Pattern
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

int main(){
	int test;
	cin >> test;
	REP(i,0,test){
		if(i != 0)
			cout << endl;
		int num;
		cin >> num;
		if(num == 1)
			printf("%.3lf\n", 0.000);
		else if(num == 2)
			printf("%.3lf\n", 4.000);
		else
			printf("%.3lf\n", (num-1)*4+(num-2)*(num-2)*sqrt(2));
	}
	return 0;
}

