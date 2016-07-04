/*
 *	Codechef CHEFELEC
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
vi all;
vi ele;
string line;
int main(){
	cin >> t;
	while(t--){
		ele.clear();
		all.clear();
		cin >> n;
		cin >> line;
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		int sum = 0;
		REP(i,0,n) if(line[i] == '1')
			ele.push_back(i);
		int sz = ele.size();
		REP(i,0,sz){
			if(i == 0 && ele[i] != 0){
				sum += all[ele[i]]-all[0];
			}
			if(i == sz-1 && ele[i] != n-1){
				sum += all[n-1]-all[ele[i]];
			}
			if(i == 0) continue;
			if(ele[i] - ele[i-1] > 1){
				int sta = ele[i-1];
				int ter = ele[i];
				int maxp = 0;
				REP(j,sta,ter){
					maxp = max(maxp, all[j+1] - all[j]);
				}
				sum += all[ter]-all[sta]-maxp;
			}
		}
		cout << sum << endl;
	}
	return 0;
}