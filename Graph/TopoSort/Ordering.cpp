/*
 *	UVA 00872
 *	Created by Ziyi Tang
 *	Topological Sort with Kahn's Algorithm, All possible orders
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
vi ready;
vi tmp_sort;
bool valid;
void rec(){
	if (ready.empty()){
		re.push_back(tmp_sort);
		// cout << "done" << endl;
		// REP(i,0,tmp_sort.size()){
		// 	cout << tmp_sort[i] << " ";
		// }
		// cout << endl;
		if (tmp_sort.size() != var.size()){
			valid = false;
		}
	}
	else{
			int sz = ready.size();
			REP(i,0,sz){
				// Choose Next
				int tmp = ready[i];
				//cout << "index " << i << " " << tmp << endl;
				tmp_sort.push_back(tmp);
				ready.erase(ready.begin()+i);
				int rsz = all[tmp].size();
				REP(j,0,rsz){
					cou[all[tmp][j]]--;
					if (cou[all[tmp][j]] == 0){
						ready.push_back(all[tmp][j]);
					}
				}
				rec();
				// Recover
				tmp_sort.erase(tmp_sort.end()-1);
				REP(j,0,rsz){
					if (cou[all[tmp][j]] == 0){
						ready.erase(ready.end()-1);
					}
					cou[all[tmp][j]]++;
				}
				ready.insert(ready.begin()+i, tmp);
			}
			
	}
}
bool comp(vi a, vi b){
	int sz = a.size();
	REP(i,0,sz){
		if (a[i] < b[i])
			return true;
		else if(a[i] > b[i])
			return false;
		else
			continue;
	}
	return true;
}
int main(){
	int test;
	cin >> test;
	getchar();
	REP(t,1,test+1){
		valid = true;
		re.clear();
		tmp_sort.clear();
		var.clear();
		all.clear();
		FILL(cou,0);
		FILL(mark,0);
		ready.clear();
		all.assign(26,var);
		string line;
		getline(cin,line);
		getline(cin,line);
		stringstream ss(line);
		string tmp;
		while(ss >> tmp){
			var.push_back((int)tmp[0]-65);
			//cout << (int)tmp[0]-65 << endl;
		}
		int sz = var.size();
		getline(cin,line);
		stringstream st(line);
		while(st >> tmp){
			all[(int)tmp[0]-65].push_back((int)tmp[2]-65);
			//cout << (int)tmp[0]-65 << " " << (int)tmp[2]-65 << endl;
			cou[(int)tmp[2]-65]++;
		}

		REP(i,0,sz){
			if (cou[var[i]] == 0){
				//cout << var[i] << "var" << endl;
				ready.push_back(var[i]);
			}
		}

		
		rec();
		if (t != 1){
			cout << endl;
		}
		if (valid == false){
			cout << "NO" << endl;
		}
		else{
			sort(re.begin(),re.end(),comp);
			int rsz = re.size();
			REP(i,0,rsz){
				REP(j,0,re[i].size()){
					cout << (char)(re[i][j]+65);
					if(j != re[i].size()-1)
						cout << " ";
				}
				cout << endl;
				
			}
		}
		

	}

	return 0;
}
