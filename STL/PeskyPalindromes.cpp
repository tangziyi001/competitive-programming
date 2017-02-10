/*
 *	UVA 353
 *	Created by Ziyi Tang
 *	Search all palindromes
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

set<string> all;
int main(){
	string line;
	while(getline(cin,line) && line != ""){
		all.clear();
		int sz = line.size();
		REP(i,0,sz){
			int idx = 0;
			while(i-idx >= 0 && i+idx < sz){
				if(line[i+idx] == line[i-idx]){
					string tmp = line.substr(i-idx,i+idx-(i-idx)+1);
					all.insert(tmp);
				} else break;
				idx++;
			}
		}
		REP(i,0,sz-1){
			int idx = 0;
			while(i-idx >= 0 && i+1+idx < sz){
				if(line[i-idx] == line[i+1+idx]){
					string tmp = line.substr(i-idx,i+idx+1-(i-idx)+1);
					all.insert(tmp);
				} else break;
				idx++;
			}
		}
		cout << "The string \'"<< line << "\' contains " << all.size() << " palindromes." << endl;
	}
	return 0;
}
