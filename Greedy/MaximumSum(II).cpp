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
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000

vi all;
vi aft;
int main(){
	int n;
	while(cin >> n && n != 0){
		all.clear();
		aft.clear();
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		REP(i,0,n){
			if(all[i] == 0)
				continue;
			else{
				aft.push_back(all[i]);
			}
		}
		if(!aft.empty()){
			int sz = aft.size();
			REP(i,0,sz){
				if(i != 0)
					cout << " ";
				cout << aft[i];
			}
			cout << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
	return 0;
}
