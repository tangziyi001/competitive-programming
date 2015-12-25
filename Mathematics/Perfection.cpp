/*
 *	UVA 00382
 *	Created by Ziyi Tang
 *	Find Divisors
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
	int now;
	printf("PERFECTION OUTPUT\n");
	while(cin >> now && now != 0){
		int sum = 0;
		REP(i,1,now){
			if(now % i == 0)
				sum += i;
		}
		if(now > sum)
			printf("%5d  DEFICIENT\n", now);
		else if(now < sum)
			printf("%5d  ABUNDANT\n", now);
		else
			printf("%5d  PERFECT\n", now);
	}
	printf("END OF OUTPUT\n");
	return 0;
}
