/*
 *	Codeforces 752B - Santa Claus and Keyboard Check
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
const int INF = 0x3f3f3f;
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007
char all[30];
int main(){
	string a,b;
	cin >> a >> b;
	REP(i,0,26){
		all[i] = '#';
	}
	int flag = 1;
	REP(i,0,a.size()){
		char aa = a[i];
		char bb = b[i];
		if(all[aa-'a'] == '#' && all[bb-'a'] == '#'){
			all[aa-'a'] = bb;
			all[bb-'a'] = aa;
			continue;
		}
		if(all[aa-'a'] != '#' && all[bb-'a'] != '#' && all[aa-'a'] == bb && all[bb-'a'] == aa)
			continue;
		flag = 0;
		break;
	}
	if(flag){
		int num = 0;
		REP(i,0,26){
			if(all[i] != '#' && all[i] != (i+'a')) num++;
		}
		num/=2;
		cout << num << endl;
		REP(i,0,26){
			if(all[i] != '#' && all[i] != (i+'a')) {
				cout << (char)('a'+i) << " " << all[i] << endl;
				all[all[i]-'a'] = '#';
			}
		}
	} else
		cout << -1 << endl;
	return 0;
}