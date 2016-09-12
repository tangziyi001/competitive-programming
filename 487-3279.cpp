/*
 *	UVA 755
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int n;
map<string,int> mm;
map<char, int> cc;
string int2str(int &i) {
  string s;
  stringstream ss(s);
  ss << i;
  return ss.str();
}
int main(){
	int nn = 2;
	int counter = 0;
	REP(i,0,26){
		if('A' + i == 'Q') continue;
		if('A' + i == 'Z') continue;
		//cout << (char)('A' + i) << " " << nn << endl;
		cc[(char)((int)'A'+i)] = nn;
		counter++;
		if(counter == 3){
			counter = 0;
			nn++;
		}
	}
	int cas = 0;
	cin >> cas;
	REP(ca,0,cas){
		mm.clear();
		if(ca != 0) cout << endl;
		scanf("%d",&n);
		REP(j,0,n){
			string now;
			cin >> now;
			string tmp = "";
			REP(i,0,now.size()){
				if(now[i] == '-'){
					continue;
				}
				if((int)now[i] >= (int)'A' && (int)now[i] <= (int)'Z'){
					tmp += int2str(cc[now[i]]);
				} 
				else {
					tmp += now[i];
				}
			}
			mm[tmp]++;
		}
		int flag = 0;
		for(map<string,int>::iterator it = mm.begin(); it != mm.end(); it++){
			string now = it->first;
			if(it->second < 2) continue;
			printf("%s", now.substr(0,3).c_str());
			printf("-");
			printf("%s ", now.substr(3).c_str());
			printf("%d\n", it->second);
			flag = 1;
		}
		if(!flag){
			printf("No duplicates.\n");
		}
	}
	return 0;
}