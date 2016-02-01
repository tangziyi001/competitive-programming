/*
 *	UVA 00416
 *	Created by Ziyi Tang
 *	If a displayed digit has a segment that the original digit doesn't have, then this
 *	cannot be the digit.
 *	Keep track of the malfunctioning segment. Check if a segment has already burned out previously. 
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

int digits[10];
vi all;
int num;
bool check(int now, int ori, int out){
	REP(i,0,7){
		if( ((1 << i) & now) && !((1 << i) & ori))
			return false;
		if( ((1 << i) & now) && ((1 << i) & out))
			return false;
	}
	return true;
}

int getOut(int now, int ori){
	int tmp = 0;
	REP(i,0,7){
		if( !((1 << i) & now) && ((1 << i) & ori))
			tmp |= (1 << i);
	}
	return tmp;
}
int rec(int pos, int digit, int out){
	if(pos == num)
		return 1;
	int flag = 0;
	REP(i,0,10){
		int ori = digits[i];
		int now = all[pos];
		//cout << i << " " << pos << "check" << check(now, ori, out) << " " << out << endl;
		if(check(now, ori, out) && (digit == -1 || digit-1 == i)){
			//cout << i << endl;
			flag |= rec(pos+1, i, out|getOut(now,ori));
		}
	}
	return flag;

}
int main(){
	digits[0] = (1 << 7) - 1 - 1;
	digits[1] = (1 << 4) + (1 << 5);
	digits[2] = (1 << 7) - 1 - (1 << 1) - (1 << 4);
	digits[3] = (1 << 7) - 1 - (1 << 1) - (1 << 2);
	digits[4] = (1 << 7) - 1 - (1 << 2) - (1 << 3) - (1 << 6);
	digits[5] = (1 << 7) - 1 - (1 << 5) - (1 << 2);
	digits[6] = (1 << 7) - 1 - (1 << 5);
	digits[7] = (1 << 4) + (1 << 5) + (1 << 6);
	digits[8] = (1 << 7) - 1;
	digits[9] = (1 << 7) - 1 - (1 << 2);


	while(cin >> num && num != 0){
		all.clear();
		string line;
		REP(i,0,num){
			cin >> line;
			int sz = line.size();
			int tmp = 0;
			for(int j = sz-1; j >= 0; j--){
				if(line[j] == 'Y')
					tmp += (1 << (sz-1-j));
			}
			all.push_back(tmp);
		}
		int re = rec(0,-1,0);
		if(re)
			cout << "MATCH" << endl;
		else
			cout << "MISMATCH" << endl;
	}

	return 0;
}
