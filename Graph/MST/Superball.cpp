/*
 *	USACO 2015 February Contest, Silver 3
 *	Coded by Ziyi Tang
 *	Implicit MST
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
#include <unordered_map>
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

int p[2005];
unordered_map<int,int> intint;
vi all;
int n;
vector<pair<ll,pi> > edges;
int findRep(int i){
	if(i == p[i])
		return i;
	else 
		return p[i] = findRep(p[i]);
}
bool isSameSet(int i, int j){
	return findRep(i) == findRep(j);
}
void unionSet(int i, int j){
	int ip = findRep(i);
	int jp = findRep(j);
	if(!isSameSet(ip,jp))
		p[ip] = jp;
}
int main(){
	freopen("superbull.in", "r", stdin);
  	freopen("superbull.out", "w", stdout);
  	cin >> n;
  	REP(i,0,n){
  		p[i]=i;
  	}
  	int id = 0;
  	REP(i,0,n){
  		int tmp;
  		cin >> tmp;
  		all.push_back(tmp);
  		intint[tmp] = id++;
  	}
  	REP(i,0,n-1){
  		REP(j,0,n){
  			//cout << all[i] << all[j]<< endl;
  			edges.push_back(make_pair(all[i]^all[j], make_pair(all[i],all[j])));
  		}
  	}
  	sort(edges.begin(),edges.end());
  	int cont = 0;
  	ll sum = 0;
  	int idx = edges.size()-1;
  	while(cont < n-1){
  		pair<ll,pi> now = edges[idx];
  		if(!isSameSet(intint[now.second.first],intint[now.second.second])){
  			cont++;
  			sum += now.first;
  			//cout << now.first << endl;
  			unionSet(intint[now.second.first],intint[now.second.second]);
  		}
  		idx--;
  	}
  	cout << sum << endl;
	return 0;
}