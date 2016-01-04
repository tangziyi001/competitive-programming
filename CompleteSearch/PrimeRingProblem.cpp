/*
 *	UVA 00524
 *	Created by Ziyi Tang
 *	Backtracking
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

int num;
vi now;
int mark[20];
int prime[40];
void findPri(){
	int pp[] = {2,3,5,7,11,13,17,19,23,29,37,31};
	REP(i,0,12){
		prime[pp[i]] = 1;
	}
}
void rec(int pos){
	if(pos == num){
		if(!prime[1+now[pos-1]])
			return;
		REP(i,0,num){
			if(i != 0)
				cout << " ";
			cout << now[i];
		}
		cout << endl;
	}
	else{
		REP(i,2,num+1){
			if(!mark[i] && prime[i+now[pos-1]]){
				now.push_back(i);
				mark[i] = 1;
				rec(pos+1);
				now.pop_back();
				mark[i] = 0;
			}
		}
	}
}
int main(){
	FILL(prime, 0);
	findPri();
	int test = 0;
	while(cin >> num){
		test++;
		if(test > 1)
			cout << endl;
		printf("Case %d:\n",test);
		FILL(mark,0);
		now.clear();
		now.push_back(1);
		rec(1);
	}
	return 0;
}
