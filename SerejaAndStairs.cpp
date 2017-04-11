/*
 *	
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

vi all;
vi re;
map<int,int> mm;
int main(){
	int n;
	cin >> n;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.push_back(tmp);
		mm[-tmp]++;
	}
	int maxf = 1;
	for(auto it = mm.begin(); it != mm.end(); it++){
		int now = -(it->first);
		int fre = it->second;
		if(maxf){
			re.push_back(now);
			maxf = 0;
		} else {
			re.push_back(now);
			if(fre >= 2){
				re.insert(re.begin(), now);
			}
		}
	}
	cout << re.size() << endl;
	REP(i,0,re.size()){
		cout << re[i] << " ";
	}
	cout << endl;
	return 0;
}	