/*
 *	CodeForces 327A
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


vi all;
int main(){
	all.clear();
	int n;
	cin >> n;
	int tmp;
	int sum = 0;
	REP(i,0,n){
		cin >> tmp;
		sum+=tmp;
		all.push_back(tmp);
	}
	int maxp = sum-1;
	REP(i,0,n){
		REP(j,i,n){
			int len = j-i+1;
			int tmpsum = 0;
			REP(k,i,j+1){
				tmpsum+=all[k];
			}
			int chsum = len-tmpsum;
			maxp=max(maxp,sum+chsum-tmpsum);
		}
	}
	cout << maxp << endl;

	return 0;
}
