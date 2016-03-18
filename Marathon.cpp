/*
 *	USACO 2014 December Contest, Bronze 1
 *	Coded by Ziyi Tang
 *	
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
#define MAXN 1000


int xall[100005];
int yall[100005];
int xsum = 0;
int ysum = 0;
int main(){
	freopen("marathon.in", "r", stdin);
  	freopen("marathon.out", "w", stdout);
  	int n;
  	cin >> n;
  	REP(i,0,n){
  		int a,b;
  		cin >> a >> b;
  		xall[i] = a;
  		yall[i] = b;
  		if(i > 0){
  			xsum += abs(xall[i]-xall[i-1]);
  			ysum += abs(yall[i]-yall[i-1]);
  		}
  	}
  	int sum = xsum+ysum;
  	int minp = sum;
  	REP(i,1,n-1){
  		int orix = abs(xall[i]-xall[i-1]) + abs(xall[i+1]-xall[i]);
  		int oriy = abs(yall[i]-yall[i-1]) + abs(yall[i+1]-yall[i]);
  		int newx = abs(xall[i+1]-xall[i-1]);
  		int newy = abs(yall[i+1]-yall[i-1]);
  		minp = min(minp, sum-orix-oriy+newx+newy);
  	}
  	cout << minp << endl;
	return 0;
}