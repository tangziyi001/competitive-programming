/*
 *	UVA 00872
 *	Created by Ziyi Tang
 *	Topological Sort, All possible orders
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
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

vi var;
vvi all;
int cou[26];
int mark[26];
vvi re;
queue<int> ready;
int main(){
	int test;
	cin >> test;
	getchar();
	while (test--){
		var.clear();
		all.clear();
		FILL(cou,0);
		FILL(mark,0);
		while(!ready.empty()){
			ready.pop();
		}
		all.assign(26,var);
		string line;
		getline(cin,line);
		getline(cin,line);
		stringstream ss(line);
		string tmp;
		while(ss >> tmp){
			var.push_back((int)tmp[0]-65);
			cout << (int)tmp[0]-65 << endl;
		}
		int sz = var.size();
		getline(cin,line);
		stringstream st(line);
		while(st >> tmp){
			all[(int)tmp[0]-65].push_back((int)tmp[2]-65);
			cout << (int)tmp[0]-65 << " " << (int)tmp[2]-65 << endl;
			cou[(int)tmp[2]-65]++;
		}

		REP(i,0,sz){
			if (cou[var[i]] == 0){
				cout << var[i] << "var" << endl;
				ready.push(var[i]);
			}
		}

		while(!ready.empty()){
			int now = ready.front();ready.pop();
			cout << "now " << now << endl;
			tmp_sort.push_back(now);
			int vsz = all[now].size();
			REP(i,0,vsz){
				int mtmp = all[now][i];
				cou[mtmp]--;
				if (cou[mtmp] == 0){
					cout << "push " << mtmp << endl;
					ready.push(mtmp);
				}
			}
		}

		int rsz = tmp_sort.size();
		REP(i,0,rsz){
			cout << tmp_sort[i] << " ";
		}
		cout << endl;

	}

	return 0;
}
