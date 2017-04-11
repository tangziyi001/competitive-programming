/*
 *	Codeforces 791C
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

vector<string> all;
set<string> ss;
string selNew(){
	REP(i,0,all.size()){
		if(!ss.count(all[i])){
			ss.insert(all[i]);
			return all[i];
		}
	}
	return "Ab";
}
int main(){
	string tmp = "Aaaaaaaaaa";
	REP(i,0,26){
		tmp[1] = (char)('a'+(tmp[1]-'a'+1)%26);
		all.push_back(tmp);
		tmp[2] = (char)('a'+(tmp[1]-'a'+1)%26);
		all.push_back(tmp);
	}
	int n,k;
	cin >> n >> k;
	vector<string> re;
	REP(i,0,k-1){
		re.push_back(selNew());
	}
	REP(i,0,n-k+1){
		string now = "";
		cin >> now;
		if(now == "YES"){
			re.push_back(selNew());
		}else{
			re.push_back(re[i]);
		}	
	}
	REP(i,0,re.size()){
		cout << re[i] << " ";
	}
	cout << endl;
	return 0;
}