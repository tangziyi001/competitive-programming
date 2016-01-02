/*
 *	UVA 10976
 *	Created by Ziyi Tang
 *	Complete Search
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

vpi re;
int main(){
	int k;
	while(cin >> k){
		int x = INF;
		re.clear();
		int y = k+1;
		int sz = 0;
		while(x >= y){
			if((k*y)%(y-k) == 0){
				x = k*y/(y-k);
				if(y > x) break;
				re.push_back(make_pair(x,y));
				sz++;
			}
			y++;
		}
		printf("%d\n",sz);
		REP(i,0,sz){
			printf("1/%d = 1/%d + 1/%d\n",k,re[i].first,re[i].second);
		}
	}
	return 0;
}
