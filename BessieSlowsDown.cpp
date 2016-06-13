/*
 *	
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
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

vector<double> alltime;
vector<double> alldis;
int main(){
	freopen("slowdown.in", "r", stdin);
  	freopen("slowdown.out", "w", stdout);
	int n;
	cin >> n;
	double time = 0.0;
	double dis = 0.0;
	double co = 1.0;
	REP(i,0,n){
		char c;
		double num;
		cin >> c >> num;
		if(c == 'T')
			alltime.push_back(num);
		else
			alldis.push_back(num);
	}
	sort(alltime.begin(), alltime.end());
	sort(alldis.begin(), alldis.end());
	int pt = 0, pd = 0;
	int tsz = alltime.size();
	int dsz = alldis.size();
	while(pt < tsz && pd < dsz){
		double tmpt = alltime[pt];
		double tmpd = alldis[pd];
		double tmpd_t = time + (tmpd-dis)*co;
		if(tmpd_t <= tmpt){
			time = tmpd_t;
			pd++;
			dis = tmpd;
		}else{
			dis += (tmpt-time)/co;
			pt++;
			time = tmpt;
		}
		co++;
	}
	while(pt != tsz){
		dis += (alltime[pt]-time)/co;
		time = alltime[pt];
		pt++;
		co++;
	}
	while(pd != dsz){
		time += (alldis[pd]-dis)*co;
		dis = alldis[pd];
		co++;
		pd++;
	}
	time += (1000.0-dis)*co;
	cout << round(time) << endl;
	return 0;
}