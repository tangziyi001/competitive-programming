/*
 *	UVA 591
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
#define MAXN 55

vi all;
int main(){
	int test = 0;
	int n;
	while(cin >> n && n != 0){
		test++;
		all.clear();
		int sum = 0;
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			sum += tmp;
			all.push_back(tmp);
		}
		int bal = sum/n;
		int re = 0;
		REP(i,0,n){
			re+=abs(all[i]-bal);
		}
		printf("Set #%d\n",test);
		printf("The minimum number of moves is %d.\n", re/2);
		cout << endl;

	}
	return 0;
}
