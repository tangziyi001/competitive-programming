/*
 *	UVA 11221
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

set<int> sq;
bool check(int r, string now){
	for(int i = 0; i < r; i++){
		for(int j = 0; j <= i; j++){
			if(now[j+i*r] != now[i+j*r]) return false;
			string tmp = now;
			reverse(now.begin(),now.end());
			if(now!= tmp) return false;
		}
	}
	return true;
}
int main(){
	REP(i,0,101){
		sq.insert(i*i);
	}
	int n;
	cin >> n;
	getchar();
	string line;
	REP(i,1,n+1){
		getline(cin,line);

		string now = "";
		int sz = line.size();
		REP(j,0,sz) if((int)line[j] >= 97 && (int)line[j] <= 122){
			now += line[j];
		}
		sz = now.size();

		if(sq.find(sz) == sq.end()){
			printf("Case #%d:\nNo magic :(\n",i);
		}
		else{
			int tmp = (int)sqrt(sz);
			if(check(tmp,now))
				printf("Case #%d:\n%d\n",i,tmp);
			else{
				printf("Case #%d:\nNo magic :(\n",i);
			}
		}

	}
	return 0;
}
