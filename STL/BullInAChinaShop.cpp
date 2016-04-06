/*
 *	USACO 2016 US Open Contest, Bronze 2
 *	Coded by Ziyi Tang
 *	Brute Force and STL
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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
#define MAXN 10

set<int> grid;
vvi all;
int n,k;

bool check(vi a, vi b){
	int sza = a.size();
	int szb = b.size();
	int flag = 0;
	for(int i = -n*n; i < n*n; i++){
		for(int j = -n*n; j < n*n; j++){
			set<int> aa;
			int con = 0;
			REP(c,0,sza){
				aa.insert(a[c]+i);
			}
			REP(c,0,szb){
				if(aa.find(b[c]+j) != aa.end()){
					con = 1;
					break;
				}else{
					aa.insert(b[c]+j);
				}
			}
			if(con) continue;
			if(aa == grid)
				return true;
		}
	}
	return false;
}
int main(){
	freopen("bcs.in", "r", stdin);
  	freopen("bcs.out", "w", stdout);
	cin >> n >> k;
  	REP(i,0,n){
  		string line;
  		cin >> line;
  		REP(j,0,n){
  			if(line[j] == '#'){
  				//cout << i*n+j << " ";
  				grid.insert(i*n+j);
  			}
  		}
  	}

  	all.assign(k,vi(0,0));
  	REP(i,0,k){
  		REP(j,0,n){
  			string line;
  			cin >> line;
  			REP(g,0,n) if(line[g] == '#'){
  				all[i].push_back(j*n+g);
  			}
  		}
  	}
  	int first = -1, second = -1;
  	REP(i,0,k-1){
  		REP(j,i+1,k){
  			vi a = all[i];
  			vi b = all[j];
  			if(check(a,b)){
  				first = i+1;
  				second = j+1;
  				break;
  			}
  		}
  		if(first != -1 && second != -1)
  			break;
  	}
  	cout << first << " " << second << endl;
	return 0;
}