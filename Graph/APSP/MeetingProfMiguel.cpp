/*
 *	UVA 10171
 *	Created by Ziyi Tang
 *	Floyd-Warshall on two graphs
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

int n;
vvpi all;
vpi re;
int grid[30][30];
int grida[30][30];
int gridb[30][30];
int allow[30][30];
int main(){
	while(cin >> n && n != 0){
		all.clear();
		re.clear();
		REP(i,0,30){
			REP(j,0,30){
					grid[i][j] = INF;
					grida[i][j] = INF;
					gridb[i][j] = INF;
			}
		}
		char a,b,x,y;
		int e;
		REP(i,0,n){
			cin >> a >> b >> x >> y >> e;
			int tx = (int)x-65;
			int ty = (int)y-65;
			if(a=='Y'){
				grid[tx][ty] = e;
				grida[tx][ty] = e;
				if(b=='B'){
					grida[ty][tx] = e;
					grid[ty][tx] = e;
				}
			}
			else{
				grid[ty][tx] = e;
				gridb[tx][ty] = e;
				if(b=='B'){
					gridb[ty][tx] = e;
					grid[tx][ty] = e;
				}
			}
		}
		REP(k,0,30){
			REP(i,0,30){
				REP(j,0,30){
					if(grid[i][k] != INF && grid[k][j] != INF){
						grid[i][j] = min(grid[i][j],grid[i][k]+grid[k][j]);
					}	
					if((grida[i][k] != INF && grida[k][j] != INF) && (grida[i][k]+grida[k][j] < grida[i][j])){
						grida[i][j] = grida[i][k]+grida[k][j];
					}
					if((gridb[i][k] != INF && gridb[k][j] != INF) && (gridb[i][k]+gridb[k][j] < gridb[i][j])){
						gridb[i][j] = gridb[i][k]+gridb[k][j];
					}
				}
			}
		}

		char tx,ty;
		cin >> tx >> ty;
		int minp = grid[(int)tx-65][(int)ty-65];
		x = (int)tx-65;
		y = (int)ty-65;
		if(x == y){
			cout << 0 << " " << (char)(x+65) << endl;
		}
		else{
				if(minp != INF){
				cout << minp;
				vi re;
				REP(i,0,26){
					int cost = grida[x][i]+gridb[y][i];
					if(cost == minp)
						re.push_back(i);
				}
				sort(re.begin(),re.end());
				int sz = re.size();
				REP(i,0,sz){
					cout << " ";
					cout << (char)(re[i]+65);
				}
				cout << endl;
			}
			else{
				cout << "You will never meet." << endl;
			}

		}
		
	}
	return 0;
}
