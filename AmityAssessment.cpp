/*
 *	CodeForces 655A
 *	Coded by Ziyi Tang
 *	Brute Force
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

vector<char> a;
vector<char> b;
int main(){
	string line;
	cin >> line;
	REP(i,0,2) if(line[i] != 'X') a.push_back(line[i]);
	cin >> line;
	for(int i = 1; i>=0;i--) if(line[i] != 'X') a.push_back(line[i]);
	cin >> line;
	REP(i,0,2) if(line[i] != 'X') b.push_back(line[i]);
	cin >> line;
	for(int i = 1; i>=0;i--) if(line[i] != 'X') b.push_back(line[i]);
	
	int tt = 0;
	REP(k,0,3){
		int flag = 1;
		REP(i,0,3){
			if(a[i] != b[(i+k)%3]){
				flag = 0;break;
			}
		}
		if(flag == 1){
			tt = 1;
			break;
		}
	}
	if(tt)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}

