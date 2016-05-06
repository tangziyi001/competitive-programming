/*
 *	UVA 321
 *	Created by Ziyi Tang
 *	BFS with multi-states represented by bitmask
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
#define MOD 1000000007

typedef pair<pi, int> pii;
#define MP(a,b) make_pair(a,b)

map<pi, int> all;
map<pi,pi> rec;
queue<pi> qq;
vvi graph;
vvi switches;

pi start;
pi final;
int main(){
	int r,d,s;
	int cas = 0;
	while(cin >> r >> d >> s && (r != 0 || d != 0 || s != 0)){
		cas++;
		graph.clear();
		switches.clear();
		all.clear();
		rec.clear();
		graph.assign(r, vi(0,0));
		switches.assign(r,vi(0,0));
		REP(i,0,d){
			int a,b;
			cin >> a >> b;
			graph[a-1].push_back(b-1);
			graph[b-1].push_back(a-1); // Bidirectional
		}
		REP(i,0,s){
			int a,b;
			cin >> a >> b;
			switches[a-1].push_back(b-1); // Unidirectional
		}
		start = MP(0, 1);
		final = MP(r-1, 1 << (r-1));
		all[start] = 0;
		qq.push(start);
		while(!qq.empty()){

			pi now = qq.front();qq.pop();
			//cout << now.first << " " << now.second << endl;
			int pos = now.first;
			int ssz = switches[pos].size();
			int tsz = graph[pos].size();
			int bit = now.second;
			int now_step = all[now];

			// Go to the next position in next step
			REP(i,0,tsz){
				if(bit & (1 << graph[pos][i])){
					pi nxt = MP(graph[pos][i], bit);
					if(all.find(nxt) == all.end()){
						all[nxt] = now_step+1;
						rec[nxt] = now;
						qq.push(nxt);
					}
				}
			}

			// Switch a light in next step
			REP(j,0,ssz){
				int tmp = switches[pos][j];
				pi nxt = MP(pos, bit^(1 << tmp));
				if(tmp == pos) continue;
				if(all.find(nxt) == all.end()){
						all[nxt] = now_step+1;
						rec[nxt] = now;
						qq.push(nxt);
				}
			}
		}
		printf("Villa #%d\n", cas);
		if(all.find(final) != all.end()){
			printf("The problem can be solved in %d steps:\n", all[final]);
			// Recover commands
			vector<pi> commands;
			while(final != start){
				if(rec[final].first == final.first){
					int bit1 = final.second;
					int bit2 = rec[final].second;
					REP(i,0,r){
						if((bit1 & (1 << i)) != (bit2 & (1 << i))){
							if(bit1 & (1 << i)) commands.push_back(MP(0,i));
							else commands.push_back(MP(-1,i));
							break;
						}
					}
					
				}else{
					commands.push_back(MP(1,final.first));
					
				}
				final = rec[final];
			}
			reverse(commands.begin(), commands.end());
			int sz = commands.size();
			REP(i,0,sz){
				if(commands[i].first == -1){
					printf("- Switch off light in room %d.\n", commands[i].second+1);
				}
				else if(commands[i].first == 0){
					printf("- Switch on light in room %d.\n", commands[i].second+1);
				}
				else{
					printf("- Move to room %d.\n", commands[i].second+1);
				}
			}
		}
		else{
			cout << "The problem cannot be solved." << endl;
		}
		cout << endl;
	}
	return 0;
}