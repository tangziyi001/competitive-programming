/*
 *	Topcoder SRM 588 1
 *	Created by Ziyi Tang
 *	Enumerate the max tone and min tone. Greedily select songs within 
 *  the bound and has less duration
 *  Note: In some case you can only sing one song
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

class GUMIAndSongsDiv1 {
public:
	int maxSongs(vector <int>, vector <int>, int);
};

vpi all;
int GUMIAndSongsDiv1::maxSongs(vector <int> duration, vector <int> tone, int T) {
	for(int i = 0; i < duration.size(); i++){
		all.push_back(make_pair(duration[i], tone[i]));
	}
	sort(all.begin(), all.end());
	int re = 0;
	// Sing One Song
	for(int i = 0; i < duration.size(); i++) if(all[i].first <= T) re = 1;
	// Sing Two or More Songs
	for(int i = 0; i < duration.size()-1; i++) for(int j = i+1; j < duration.size(); j++) {
		int maxp = max(all[i].second,all[j].second);
		int minp = min(all[i].second,all[j].second);
		//cout << i << " " << j << " " << maxp << " " << minp << endl;
		int rem = T-(maxp-minp)-all[i].first-all[j].first;
		//cout << rem << endl;
		if(rem < 0) continue;
		int tmp = 2;
		for(int k = 0; k < duration.size(); k++) if(k != i && k != j){
			if(rem < all[k].first) break;
		    if(rem >= all[k].first && all[k].second >= minp && all[k].second <= maxp){
		    	tmp++; rem-=all[k].first;
		    }
		}
		re = max(re, tmp);
	}
	return re;
}


//Powered by [KawigiEdit] 2.0!