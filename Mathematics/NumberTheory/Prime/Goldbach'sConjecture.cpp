/*
 *	UVA 00543
 *	Created by Ziyi Tang
 *	Prime Sieve
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
#define MAXN 1000005

int all[MAXN];
int main(){
	FILL(all,0);
	for(int i = 2; i < MAXN; i++){
		if(all[i] == 0){
			for(int j = 2; j*i < MAXN; j++){
				all[i*j] = 1;
			}
		}
	}
	int num;
	while(cin >> num && num != 0){
		for(int i = 2; i < num; i++){
			if(all[i] == 0 && all[num - i] == 0){
				printf("%d = %d + %d\n", num, i, num-i);
				break;
			}
		}
	}
	return 0;
}
