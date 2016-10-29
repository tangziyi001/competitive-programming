/*
 *	The 2nd ProgNova Multi-University Programming Contest B
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

char grid[35][35];
int dp[35][35][35][35];
vector<pi> start;
int n,m;
bool che(int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}
bool checkBlock(int x, int y){
	char now = grid[x][y];
	REP(i,x,x+3){
		REP(j,y,y+3){
			if(grid[i][j] != now) return false;
		}
	}
	return true;
}
bool process(int t, int b, int l, int r){
	if( dp[t][b][l][r] != -1) return  dp[t][b][l][r];
	//cout << t << " " << b << " " << l << " " << r << endl;
	int yes = 0;
	int move = 0;
	// Top
	if(t > 0){
		int flag = 1;
		int tt = t-1;
		char now = grid[tt][l];
		if(now != 'W'){
			REP(i,l,r+1){
				if(grid[tt][i] != now){
					flag = 0; break;
				}
			}
		} else {
			flag = 0;
		}
		if(flag){
			move = 1;
			yes |= process(t-1,b,l,r);
		}
	}
	if(b < n-1){
		int flag = 1;
		int bb = b+1;
		char now = grid[bb][l];
		if(now != 'W'){
			REP(i,l,r+1){
				if(grid[bb][i] != now){
					flag = 0; break;
				}
			}
		} else {
			flag = 0;
		}
		if(flag){
			move = 1;
			yes |= process(t,b+1,l,r);
		}
	}

	if(l > 0){
		int flag = 1;
		int ll = l-1;
		char now = grid[t][ll];
		if(now != 'W'){
			REP(i,t,b+1){
				if(grid[i][ll] != now){
					flag = 0; break;
				}
			}
		} else {
			flag = 0;
		}
		if(flag){
			move = 1;
			yes |= process(t,b,l-1,r);
		}
	}

	if(r < m-1){
		int flag = 1;
		int rr = r+1;
		char now = grid[t][rr];
		if(now != 'W'){
			REP(i,t,b+1){
				if(grid[i][rr] != now){
					flag = 0; break;
				}
			}
		} else {
			flag = 0;
		}
		if(flag){
			move = 1;
			yes|=process(t,b,l,r+1);
		}
	}
	if(!move){
		//cout << "her" << endl;
		int flag = 1;
		REP(i,0,n){
			REP(j,0,m){
				if(grid[i][j] != 'W' && (i > b || i < t || j > r || j < l )){
					flag = 0; break;
				}
			}
		}
		return flag;
	}
	return dp[t][b][l][r] = yes;
}
int main(){
	FILL(dp,-1);
	string line;
	cin >> n >> m;
	REP(i,0,n){
		cin >> line;
		REP(j,0,m){
			grid[i][j] = line[j];
		}
	}
	int yes = 0;
	REP(i,0,n-2) REP(j,0,n-2){
		if(grid[i][j] != 'W' && checkBlock(i,j)){
			yes |= process(i,i+2,j,j+2);
			//start.push_back(make_pair(i,j));
		}
	}
	int bb = 1;
	REP(i,0,n){
		REP(j,0,m){
			if(grid[i][j] != 'W'){
				bb = 0; break;
			}
		}
	}
	yes |= bb;
	if(yes)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}