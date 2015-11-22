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
#define MAXN 205

map<string, int> strint;
vector<string> intstr;
vvi all;
int dist[MAXN];
int s,t;
queue<int> que;

bool check(string a, string b){
	int sza = a.size();
	int szb = b.size();
	if(sza != szb) return false;
	int flag = 0;
	REP(i,0,sza){
		char ai = a[i];
		char bi = b[i];
		if(ai != bi)
			flag++;
	}
	if(flag == 1){
		return true;
	}
	else{
		return false;
	}
}


int main(){
	string line;
	int test;
	cin >> test;
	getchar();
	getchar();
	while(test--){
		int idx = 0;
		vi tmp;
		all.clear();
		all.assign(MAXN,tmp);
		intstr.clear();
		strint.clear();
		while(getline(cin,line) && line != "*"){
			strint[line] = idx;
			intstr.push_back(line);
			REP(i,0,idx){
				if(check(intstr[i], intstr[idx])){
					all[i].push_back(idx);
					all[idx].push_back(i);
				}
			}
			idx++;
		}
		while(getline(cin,line) && line != ""){
			while(!que.empty()){
				que.pop();
			}
			FILL(dist,-1);
			stringstream ss(line);
			string sta,ter;
			ss >> sta >> ter;
			s = strint[sta];
			t = strint[ter];
			que.push(s);
			dist[s] = 0;
			int re = -1;
			while(!que.empty()){
				int now = que.front();que.pop();
				int nsz = all[now].size();
				REP(i,0,nsz){
					int tmp = all[now][i];
					if(dist[tmp] == -1){
						dist[tmp] = dist[now]+1;
						que.push(tmp);
					}
					if(tmp == t){
						re = dist[tmp];break;
					}
				}
				if(re != -1) break;
			}
			cout << intstr[s] << " " << intstr[t] << " " << re << endl;

		}
		if(test != 0)
			cout << endl;

		
		

	}
	return 0;
}
