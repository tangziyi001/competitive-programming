/*
 *	UVA 11926
 *	Created by Ziyi Tang
 *	Brute forcely mark array
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000005
#define MOD 1000000007

int mark[MAXN];
int main(){
	int n,m;
	while(cin >> n >> m && (n != 0 || m != 0)){
		int a,b,c;
		int flag = 1;
		FILL(mark,0);
		// Normal Intervals
		REP(i,0,n){
			cin >> a >> b;
			REP(j,a,b){
				if(mark[j]) {
					flag = 0;
				}
				mark[j] = 1;
			}
		}
		// Repeating Intervals
		REP(i,0,m){
			cin >> a >> b >> c;
			int sta = a;
			while(sta <= (int)(1e6)){
				int ter = min(sta+(b-a+1)-1, (int)(1e6));
				REP(j,sta,ter){
					if(mark[j]){
						flag = 0;
					}
					mark[j] = 1;
				}
				sta += c;
			}
		}

		if(!flag){
			cout << "CONFLICT" << endl;
		} else {
			cout << "NO CONFLICT" << endl;
		}
	}
	return 0;
}