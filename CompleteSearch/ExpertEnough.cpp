/*
 *	UVA 01237
 *	Created by Ziyi Tang
 *	Complete Comparison
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

vector<string> all;
vi low;
vi high;
int main(){
	int test;
	cin >> test;
	REP(t,0,test){
		if(t!=0)
			cout << endl;
		all.clear();
		low.clear();
		high.clear();

		int num;
		cin >> num;
		REP(i,0,num){
			string name;
			int l,h;
			cin >> name >> l >> h;
			all.push_back(name);
			low.push_back(l);
			high.push_back(h);
		}
		int q;
		cin >> q;
		REP(i,0,q){
			string re = "UNDETERMINED";
			int tmp;
			cin >> tmp;
			REP(j,0,num){
				if(tmp >= low[j] && tmp <= high[j] && re == "UNDETERMINED"){
					re = all[j];
				}
				else if(tmp >= low[j] && tmp <= high[j]){
					re = "UNDETERMINED"; break;
				}
			}
			cout << re << endl;
		}

	}
	return 0;
}
