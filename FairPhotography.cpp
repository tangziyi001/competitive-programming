/*
 *	USACO 2014 US Open, Silver 1
 *	Coded by Ziyi Tang
 *	If 
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

vpi all; //(pos, sign)
vi sum;
vpi luOdd; // (prefix, idx);
vpi luEven;
int main(){
	 freopen("fairphoto.in", "r", stdin);
  	freopen("fairphoto.out", "w", stdout);

  	int n;
  	cin >> n;
  	REP(i,0,n){
  		int pos;
  		char c;
  		cin >> pos >> c;
  		int sign;
  		if(c == 'W') sign = 1;
  		else sign = -1;
  		all.push_back(make_pair(pos,sign));
  	}
  	sort(all.begin(),all.end());
  	sum.push_back(0);
  	REP(i,1,n){
      sum.push_back(sum[i-1] + all[i-1].second);
    }
    int tmpOdd = INF;
    int tmpEven = INF;
    REP(i,0,n+1){
      if((i&1) && sum[i] < tmpOdd){
        luOdd.push_back(make_pair(sum[i], i-1));
        tmpOdd = sum[i];
      }
      else if(!(i&1) && sum[i] < tmpEven){
        luEven.push_back(make_pair(sum[i], i-1));
        tmpEven = sum[i];
      } 
    }
    // REP(i,0,luOdd.size()){
    //   cout << luOdd[i].first << " " << luOdd[i].second << endl;
    // }
    // //cout << "even" << endl;
    // REP(i,0,luEven.size()){
    //   cout << luEven[i].first << " " << luEven[i].second << endl;
    // }
    reverse(luOdd.begin(), luOdd.end());
    reverse(luEven.begin(), luEven.end());
    int maxp = 0;
    REP(i,0,n){
      if(!((i+1)&1)){
        auto it = upper_bound(luEven.begin(), luEven.end(), make_pair(sum[i+1], -INF));
        it--;
        int idx = (*it).second;
        // cout << idx << endl;
        // cout << all[i].first-all[idx+1].first << endl;
        maxp = max(maxp, all[i].first-all[idx+1].first);
      }
      else{
        auto it = upper_bound(luOdd.begin(), luOdd.end(), make_pair(sum[i+1], -INF));
        it--;
        int idx = (*it).second;
        // cout << idx << endl;
        // cout << all[i].first-all[idx+1].first << endl;
        maxp = max(maxp, all[i].first-all[idx+1].first);
      }
    }
    cout << maxp << endl;
    
  	

	return 0;
}