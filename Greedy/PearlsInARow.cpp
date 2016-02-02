/*
 *	CodeForces ER6C
 *	Created by Ziyi Tang
 *	Pay attention to the right border. The last segment should extend to the
 *	last element. Use set instead of unordered_set
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
#include <unordered_set>
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

set<int> ss;
vpi re;
int main(){
	int n;
	scanf("%d",&n);
	int tmp;
	int l = 0;
	REP(i,0,n){
		scanf("%d",&tmp);
		if(ss.find(tmp) == ss.end()) ss.insert(tmp);
		else{
			re.push_back(make_pair(l+1,i+1));
			l = i+1;
			ss.clear();
		}
	}
	if(re.size() == 0) printf("-1\n");
	else{
		int sz = re.size();
		re[sz-1].second = n;
		printf("%d\n",sz);
		REP(i,0,sz){
			printf("%d %d\n", re[i].first,re[i].second);
		}
	}
	return 0;
}
