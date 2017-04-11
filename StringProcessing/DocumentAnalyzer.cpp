/*
 *	UVA 11860
 *	Created by Ziyi Tang
 *	String parsing and two pointers
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

map<string,int> mm;
set<string> ss;
int main(){
	int test;
	cin >> test;
	getchar();
	string line;
	REP(t,1,test+1){
		ss.clear();
		mm.clear();
		vector<string> all;
		while(getline(cin,line) && line != "END"){
			REP(i,0,line.size()){
				if(line[i] < 'a' || line[i] > 'z'){
					line[i] = ' ';
				}
			}
			stringstream sss(line);
			string tmp;
			while(sss >> tmp){
				all.push_back(tmp);
				ss.insert(tmp);
			}
		}
		int n = ss.size();
		int sta = 0, ter = 0;
		int minp = INF, msta = 0, mter = 0;
		while(ter < all.size()){
			string now = all[ter];
			if(!mm.count(now)){
				mm[now] = 1;
			} else {
				mm[now] += 1;
			}
			while(mm.size() == n){
				if(ter-sta+1 < minp && mm.size() == n){
					minp = ter-sta+1;
					msta = sta;
					mter = ter;
				}
				mm[all[sta]]--;
				if(mm[all[sta]] == 0) mm.erase(all[sta]);
				sta++;
			}
			ter++;
		}
		while(mm.size() == n){
			if(ter-sta+1 < minp && mm.size() == n){
				minp = ter-sta+1;
				msta = sta;
				mter = ter;
			}
			mm[all[sta]]--;
			if(mm[all[sta]] == 0) mm.erase(all[sta]);
			sta++;
		}
		printf("Document %d: %d %d\n", t, msta+1, mter+1);
	}
	return 0;
}