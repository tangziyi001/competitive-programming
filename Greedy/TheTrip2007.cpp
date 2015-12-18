/*
 *	UV1 11100
 *	Created by Ziyi Tang
 *	Sorting the size of bags, use the largest number of same size as minimum pieces.
 *	Add one bag into each piece one at a time and so on.
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
vvi pack;
int main(){
	int num;
	while(cin >> num && num != 0){
		all.clear();
		pack.clear();
		REP(i,0,num){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		sort(all.begin(),all.end());
		int count = 1;
		int maxp = 1;
		int now = all[0];
		REP(i,1,num){
			if(all[i] != now){
				count = 1;
				now = all[i];
			}
			else{
				count++;
				if(count > maxp){
					maxp = count;
				}
			}
		}
		cout << maxp << endl;
		vi ttmp;
		pack.assign(maxp,ttmp);
		REP(i,0,num){
			pack[i%maxp].push_back(all[i]);
		}
		REP(i,0,maxp){
			int sz = pack[i].size();
			REP(j,0,sz){
				if(j != 0)
					cout << " ";
				cout << pack[i][j];
			}
			cout << endl;
		}

	}
	return 0;
}
