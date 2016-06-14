/*
 *	TopCoder SRM 557 250
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

class FoxAndMountainEasy{
public:
	static string possible(int n, int s, int t, string line){
		int low = 0;
		int dis = 0;
		int sz = line.size();
		REP(i,0,sz){
			if(line[i] == 'U')
				dis++;
			else
				dis--;
			low = min(low, dis);
		}
		int diff = t-dis-s;
		int rem = n-sz;
		if(rem >= abs(diff) && (rem&1) == (diff&1)){
			int up = (rem-abs(diff))/2;
			if(diff >= 0) up += diff;
			int ini = s + up;
			REP(i,0,sz){
				if(line[i] == 'U') ini++;
				else ini--;
				if(ini < 0) return "NO";
			}
			return "YES";
		}
		else
			return "NO";
	}
};

// The code below should not be copied
int main(){
	cout << FoxAndMountainEasy::possible(2198,0,2,"DDUUUUUD") << endl;;
	return 0;
}