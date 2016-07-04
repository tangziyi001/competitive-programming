/*
 *	Codechef EGRANDR
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
#define MOD 1000000007

int t,n;
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		double sum = 0.0;
		int flag = 0;
		int fail = 0;
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			if(tmp == 2)
				fail = 1;
			sum += tmp;
			if(tmp == 5)
				flag = 1;
		}
		if(flag == 1 && (sum/n + 1e-9) >= 4.0 && fail == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}