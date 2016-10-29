/*
 *	UVA 10252
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int all[26];
int all2[26];
int main(){
	string line1, line2;
	while(getline(cin,line1)){
		getline(cin, line2);
		FILL(all,0);
		FILL(all2,0);
		REP(i,0,line1.size()){
			all[line1[i]-'a']++;
		}
		REP(i,0,line2.size()){
			all2[line2[i]-'a']++;
		}
		string re = "";
		REP(i,0,26){
			REP(j,0,min(all[i],all2[i])){
				re+=(char)('a'+i);
			}
		}
		sort(re.begin(), re.end());
		cout << re << endl;
	}
	return 0;
}