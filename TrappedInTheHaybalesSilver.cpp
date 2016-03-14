/*
 *	USACO 2015 US Open, Silver 2
 *	Created by Ziyi Tang
 *	Let haybale K be the rightmost haybale that is to the left of Bessie's starting place, 
 *  and start simulating this process where haybale K is the one we want to add hay to, 
 *  keeping track of the rightmost bale that Bessie breaks. 
 *  If we then select haybale K−1 as the bale to add hay to, 
 *  we already know that Bessie can reach the rightmost haybale as mentioned above.
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
#define MAXN 1000000000

vpi all;
vi add;
int n,b;

int main(){
	  freopen("trapped.in", "r", stdin);
  	freopen("trapped.out", "w", stdout);
  	cin >> n >> b;
  	int left = -1;
  	int right = -1;
  	add.assign(n,INF);
  	REP(i,0,n){
  		int sz,tmp;
  		cin >> sz >> tmp;
  		all.push_back(make_pair(tmp,sz));
  	}
  	sort(all.begin(),all.end());
    right = upper_bound(all.begin(),all.end(),make_pair(b,0))-all.begin();
    left = right-1;
    int j = right;

    // Sweep left side
  	for(int i = left; i >= 0; i--){
      while(j < n && all[j].first-all[i].first > all[j].second){
        j++;
      }
      if(j == n) break;
      add[i] = (all[j].first-all[i].first >= all[i].second) ? all[j].first-all[i].first-all[i].second: 0;
    }

    // Sweep right side
    j = left;
    for(int i = right; i < n; i++){
      while(j >= 0 && all[i].first-all[j].first > all[j].second){
        j--;
      }
      if(j < 0) break;
      add[i] = (all[i].first-all[j].first >= all[i].second) ? all[i].first-all[j].first-all[i].second: 0;
    }
    int minp = INF;
    REP(i,0,n){
      //cout << add[i] << " ";
      minp = min(minp, add[i]);
    }
    //cout << endl;
    if(minp == INF)
      cout << -1 << endl;
    else
      cout << minp << endl;

	return 0;
}