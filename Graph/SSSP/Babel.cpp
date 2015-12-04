/*
 *	UVA 11492
 *	Created by Ziyi Tang
 *	Use Source and Sink for multi-sources and multi-destinations Dijkstra's Algorithm
 *	Words are vertices and languages are edges. Transform vertices' costs to edges' costs.
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
#define MAXN 2005

map<string,int> strint;
vector<string> intstr;
vvpi all;
vector<pair<string,string> > ppp;
priority_queue<pi, vpi, greater<pi> > pq;
int dis[MAXN];
int source = -1;

int main(){
	int n;
	string a,b;
	while(cin >> n && n != 0){
		strint.clear();
		intstr.clear();
		all.clear();
		vpi ttmp;
		all.assign(n+5,ttmp);
		ppp.clear();
		cin >> a >> b;
		string fir,sec,word;
		int idx = 0;
		REP(i,0,n+2){
			dis[i] = INF;
		}
		while(!pq.empty()){
			pq.pop();
		}
		// Graph Initialization
		REP(t,0,n){
			cin >> fir >> sec >> word;
			strint[word] = idx;
			intstr.push_back(word);
			ppp.push_back(make_pair(fir,sec));
			REP(i,0,idx){
				string ff = ppp[i].first;
				string ss = ppp[i].second;
				if((fir == ff || fir == ss || sec == ff || sec == ss) && word[0] != intstr[i][0]){
					//cout << idx << " " << i << " " << word.size() << " " << intstr[i].size() << endl;  
					all[idx].push_back(make_pair(i,word.size()));
					all[i].push_back(make_pair(idx,intstr[i].size()));
				}
			}
			// Source n
			if(fir == a || sec == a){
				all[n].push_back(make_pair(idx,0));
			}
			// Sink n+1
			if(fir == b || sec == b){
				all[idx].push_back(make_pair(n+1, word.size()));
			}
			idx++;
		}

		// Dijkstra
		source = n;
		dis[n] = 0;
		pq.push(make_pair(0,n));
		while(!pq.empty()){
			pi now = pq.top(); pq.pop();
			int d = now.first; 
			int u = now.second;
			if(d > dis[u])
				continue;
			int nsz = all[u].size();
			REP(i,0,nsz){
				pi tmp = all[u][i];
				if(dis[u] + tmp.second < dis[tmp.first]){
					dis[tmp.first] = dis[u] + tmp.second;
					pq.push(make_pair(dis[tmp.first], tmp.first));
				}
			}
		}
		if(dis[n+1] != INF){
			cout << dis[n+1] << endl;
		}
		else{
			cout << "impossivel" << endl;
		}
		// Test
		// REP(i,0,n+2){
		// 	cout << dis[i] << endl;
		// }

	}
	return 0;
}
