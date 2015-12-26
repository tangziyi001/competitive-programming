/*
 *	UVA 11254
 *	Created by Ziyi Tang
 *	Formula for arithmetic progression: Sn = na1 + n(n-1)d/2. Try different n and find valid a1.
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
	int sum;
	while(cin >> sum && sum != -1){
		int tar = ceil(sqrt(2*sum));
		int re = -1;
		int ini = -1;
		for(int n = tar; n > 0; n--){
			int nom = sum-n*(n-1)/2;
			if(nom%n == 0 && nom/n != 0){
				re = n; ini = nom/n; break;
			}
		}
		printf("%d = %d + ... + %d\n",sum,ini,ini+re-1);
	}
	return 0;
}
