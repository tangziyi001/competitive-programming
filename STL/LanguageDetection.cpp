/*
 *	UVA 12250
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

map<string,string> all;
int main(){
	all["HELLO"] = "ENGLISH";
	all["HOLA"] = "SPANISH";
	all["HALLO"] = "GERMAN";
	all["BONJOUR"] = "FRENCH";
	all["CIAO"] = "ITALIAN";
	all["ZDRAVSTVUJTE"] = "RUSSIAN";
	string now;
	int cas = 0;
	while(cin >> now && now != "#"){
		cas++;
		if(all.find(now) != all.end()){
			printf("Case %d: %s\n", cas, all[now].c_str());
		}
		else{
			printf("Case %d: UNKNOWN\n",cas);
		}
	}
	return 0;
}
