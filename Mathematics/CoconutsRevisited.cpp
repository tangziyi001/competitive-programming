/*
 *	UVA 00616
 *	Created by Ziyi Tang
 *	Brute Force up to ceil(sqrt(n))
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
	int num = 0;
	while(cin >> num && num != -1){
		int tar = ceil(sqrt(num));
		int maxp = -1;
		REP(i,1,tar+1){
			int flag = 1;
			int people = i;
			int coc = num;
			REP(j,0,i){
				if(coc%people != 1){
					flag = 0;
					break;
				}
				coc -= (coc/people+1);
			}
			if(flag == 0)
				continue;
			if(coc%people != 0)
				continue;
			maxp = max(maxp,i);
		}
		if(maxp == -1)
			printf("%d coconuts, no solution\n",num);
		else
			printf("%d coconuts, %d people and 1 monkey\n", num, maxp);
	}
	return 0;
}
