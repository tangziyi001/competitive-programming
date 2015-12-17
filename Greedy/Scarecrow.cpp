/*
 *	UVA 12405
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
#define MAXN 1000

int mark[110];
int main(){
	int test;
	cin >> test;
	getchar();
	REP(t,1,test+1){
		FILL(mark,0);
		int num;
		cin >> num;
		getchar();
		string line;
		getline(cin,line);
		REP(i,0,num){
			if(line[i] == '.')
				mark[i] = 1;
		}
		int re = 0;
		REP(i,0,num){
			if(mark[i] == 1){
				re++;
				REP(k,0,3){
					mark[k+i] = 0;
				}
			}
		}
		printf("Case %d: %d\n", t, re);
	}
	return 0;
}
