/*
 *	UVA 10058
 *	Created by Ziyi Tang
 *	Backtracking
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007
string vv[8] = {"hate","love","know","like","hates","loves","knows","likes"};
string nn[8] = {"tom","jerry","goofy","mickey","jimmy","dog","cat","mouse"};
string aa[2] = {"the","a"};
set<string> v(vv, vv+8);
set<string> n(nn, nn+8);
set<string> a(aa, aa+2);
vector<string> all;

int alist(int i, int j){
	//cout << "alist" << i << " " << j << endl;
	if(i > j) return false;
	if(i == j){
		return n.count(all[i]);
	}else if (i == j-1){
		return a.count(all[i]) & n.count(all[j]);
	} else return false;
}
int action(int i, int j){
	//cout << "action" << i << " " << j << endl;
	if(i > j) return false;
	int flag = 1;
	int idx = i;
	REP(k,i,j){
		if(all[k] == "and"){
			flag &= alist(idx,k-1);
			idx = k+1;
		}
	}
	flag &= alist(idx, j);
	return flag;
}
int process(int i, int j){
	//cout << "process" << i << " " << j << endl;
	if(i > j) return false;
	int flag = 1;
	int verb = -1;
	REP(k,i,j+1){
		if(v.count(all[k])) {
			// More than one verb
			if(verb != -1) return false;
			verb = k;
		}
	}
	// No verb in Action
	if(verb == -1) return false;
	flag &= action(i,verb-1);
	flag &= action(verb+1,j);
	return flag;
}
int main(){
	string line;
	int flag;
	while(getline(cin, line)){
		flag = 1;
		all.clear();
		stringstream ss(line);
		string tmp;
		while(ss >> tmp){
			all.push_back(tmp);
		}
		int idx = 0;
		REP(i,0,all.size()){
			if(all[i] == ","){
				flag &= process(idx,i-1);
				idx = i+1;
			}
		}
		flag &= process(idx,all.size()-1);
		if(flag){
			cout << "YES I WILL" << endl;
		} else {
			cout << "NO I WON\'T" << endl;
		}
	}
	return 0;
}