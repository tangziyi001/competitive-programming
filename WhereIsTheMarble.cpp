/*
 *	UVA 10474
 *	Created by Ziyi Tang
 *  Fill a frequency table.
 *	Use an array to record in ith entry how many numbers are smaller than i.
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

int all[10005];
int re[10005];
int main(){
	int n,q;
	int t = 0;
	while(cin >> n >> q && (n != 0 || q != 0)){
		t++;
		FILL(all,0);
		FILL(re,0);
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			all[tmp]+=1;
		}
		re[0] = 0;
		REP(i,1,10001){
			re[i] = re[i-1] + all[i-1];
		}
		printf("CASE# %d:\n", t);
		REP(i,0,q){
			int tmp;
			cin >> tmp;
			if(all[tmp] != 0){
				printf("%d found at %d\n", tmp, re[tmp]+1);
			}
			else{
				printf("%d not found\n", tmp);
			}
		}
	}
	return 0;
}
