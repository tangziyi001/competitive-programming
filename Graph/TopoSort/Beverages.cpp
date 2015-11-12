/*
 *	UVA 11060
 *	Created by Ziyi Tang
 *	
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


map<string,int> var;
vector<string> name;
vvi all;
priority_queue<int,vector<int>, greater<int> > que;
vi re;
int cont[105];
int main(){
	int n;
	int cas = 0;
	while (cin >> n){
		cas++;
		re.clear();
		var.clear();
		all.clear();
		name.clear();
		while(!que.empty()){
			que.pop();
		}
		
		FILL(cont,0);
		all.assign(105, re);
		REP(i,0,n){
			string tmp;
			cin >> tmp;
			var.insert(make_pair(tmp,i));
			name.push_back(tmp);
		}
		int num;
		cin >> num;
		string sta,ter;
		REP(i,0,num){
			cin >> sta >> ter;
			int a = var[sta];
			int b = var[ter];
			all[a].push_back(b);
			cont[b]++;
		}
		REP(i,0,n){
			if (cont[i] == 0)
				que.push(i);
		}
		while(!que.empty()){
			int now = que.top();que.pop();
			re.push_back(now);
			int sz = all[now].size();
			REP(i,0,sz){
				cont[all[now][i]]--;
				if(cont[all[now][i]]==0){
					que.push(all[now][i]);
				}
			}
		}

		printf("Case #%d: Dilbert should drink beverages in this order: ", cas);
		REP(i,0,n){
			if(i != 0)
				cout << " ";
			cout << name[re[i]];
		}
		cout << "." << endl;
		cout << endl;

	
	}

	return 0;
}
