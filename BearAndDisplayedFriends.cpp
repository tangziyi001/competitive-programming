/*
 *	658B - Bear and Displayed Friends
 *	Coded by Ziyi Tang
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

int n,k,q;
vi all;
vpi disp;
int main(){
	cin >> n >> k >> q;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.push_back(tmp);
	}
	REP(i,0,q){
		int t,id;
		cin >> t >> id;
		if(t == 1){
			if(disp.size() < k){
				disp.push_back(make_pair(all[id-1], id-1));
				
			}
			else{
				if(all[id-1] > disp[0].first){
					disp[0] = make_pair(all[id-1],id-1);
					
				}
			}
			sort(disp.begin(),disp.end());
		}
		else{
			int sz = disp.size();
			int flag = 0;
			REP(i,0,sz){
				if(id-1 == disp[i].second)
					flag = 1;
			}
			if(flag)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}