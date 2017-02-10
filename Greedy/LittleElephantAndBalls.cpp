/*
 *	Topcoder 592 Div1 1
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

class LittleElephantAndBalls {
public:
	int getNumber(string);
};

int LittleElephantAndBalls::getNumber(string S) {
	map<char,int> mm;
	mm['R']=0;
	mm['G']=0;
	mm['B']=0;
	int sz = S.size();
	int cont = 0;
	REP(i,0,sz){
		char now = S[i];
		int r = min(mm['R'],2);
		int g = min(mm['G'],2);
		int b = min(mm['B'],2);
		//cout << r << " " << g << " " << b << endl;
		cont += r+g+b;
		mm[now]++;
	}
	return cont;
}


//Powered by [KawigiEdit] 2.0!