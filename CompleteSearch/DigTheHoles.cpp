/*
 *	UVA 11412
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

vector<string> vs(6,"");
vector<string> all;
set<string> ss;
vector<string> first;
void fill(string now, int pos){
	if(pos == 4){
		all.push_back(now);
	}
	else{
		for(int i = 0; i < 6; i++){
			if(ss.find(vs[i]) == ss.end()){
				ss.insert(vs[i]);
				string tmp = now+vs[i];
				fill(tmp,pos+1);
				ss.erase(vs[i]);
			}
		}
	}
}
int checkF(string a, string b){
	int cont = 0;
	REP(i,0,4) if(a[i] == b[i]) cont++;
	return cont;
}
int checkS(string a, string b){
	set<char> ts;
	int cont = 0;
	REP(i,0,4) ts.insert(a[i]);
	REP(i,0,4) if(ts.find(b[i]) != ts.end() && a[i] != b[i]) cont++;
	return cont;
}
int main(){
	vs[0] = "R";
	vs[1] = "G";
	vs[2] = "B";
	vs[3] = "Y";
	vs[4] = "O";
	vs[5] = "V";
	fill("", 0);
	int sz = all.size();
	// for(auto it = all.begin(); it != all.end(); it++){
	// 	cout << *it << endl;
	// }
	int t;
	cin >> t;
	while(t--){
		first.clear();
		string com;
		int a,b;
		cin >> com >> a >> b;
		// First Line
		REP(i,0,sz){
			if(checkF(all[i],com) == a && checkS(all[i],com) == b){
				//cout << all[i] << endl;
				first.push_back(all[i]);
			}
		}
		int ssz = first.size();
		int flag = 0;
		cin >> com >> a >> b;
		REP(i,0,ssz){
			if(checkF(first[i],com) == a && checkS(first[i],com) == b){
				flag = 1;
				break;
			}
		}
		if(flag)
			cout << "Possible" << endl;
		else
			cout << "Cheat" << endl;

	}
	return 0;
}
