/*
 *	Google Code Jam 2016 Round 1B 1
 *	Coded by Ziyi Tang, New York University CS480 APS S16
 *	Observation
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

int all[30];
vector<int> re;
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		FILL(all,0);
		re.clear();
		string line;
		cin >> line;
		int sz = line.size();
		REP(i,0,sz){
			all[line[i]-'A'] += 1;
		}
		int six = all['X'-'A'];
		all['S'-'A']-=six;
		all['I'-'A']-=six;
		all['X'-'A']-=six;
		REP(i,0,six){
			re.push_back(6);
		}
		int two = all['W'-'A'];
		all['T'-'A']-=two;
		all['W'-'A']-=two;
		all['O'-'A']-=two;
		REP(i,0,two){
			re.push_back(2);
		}
		int four = all['U'-'A'];
		all['F'-'A']-=four;
		all['O'-'A']-=four;
		all['U'-'A']-=four;
		all['R'-'A']-=four;
		REP(i,0,four){
			re.push_back(4);
		}
		int five = all['F'-'A'];
		all['F'-'A']-=five;
		all['I'-'A']-=five;
		all['V'-'A']-=five;
		all['E'-'A']-=five;
		REP(i,0,five){
			re.push_back(5);
		}
		int eight = all['G'-'A'];
		all['E'-'A']-=eight;
		all['I'-'A']-=eight;
		all['G'-'A']-=eight;
		all['H'-'A']-=eight;
		all['T'-'A']-=eight;
		REP(i,0,eight){
			re.push_back(8);
		}
		int zero = all['Z'-'A'];
		all['Z'-'A']-=zero;
		all['E'-'A']-=zero;
		all['R'-'A']-=zero;
		all['O'-'A']-=zero;
		REP(i,0,zero){
			re.push_back(0);
		}

		int one = all['O'-'A'];
		all['O'-'A']-=one;
		all['N'-'A']-=one;
		all['E'-'A']-=one;
		REP(i,0,one){
			re.push_back(1);
		}

		int seven = all['S'-'A'];
		all['S'-'A']-=seven;
		all['E'-'A']-=seven;
		all['E'-'A']-=seven;
		all['V'-'A']-=seven;
		all['N'-'A']-=seven;
		REP(i,0,seven){
			re.push_back(7);
		}

		int nine = all['I'-'A'];
		all['N'-'A']-=nine;
		all['I'-'A']-=nine;
		all['N'-'A']-=nine;
		all['E'-'A']-=nine;
		REP(i,0,nine){
			re.push_back(9);
		}

		int three = all['T'-'A'];
		all['T'-'A']-=three;
		all['T'-'A']-=three;
		all['T'-'A']-=three;
		all['T'-'A']-=three;
		all['T'-'A']-=three;
		REP(i,0,three){
			re.push_back(3);
		}

		sort(re.begin(),re.end());
		printf("Case #%d: ", t);
		int ssz = re.size();
		REP(i,0,ssz){
			cout << re[i];
		}
		cout << endl;
	}
	return 0;
}