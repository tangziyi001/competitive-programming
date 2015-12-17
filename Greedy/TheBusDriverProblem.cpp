/*
 *	UVA 11389
 *	Created by Ziyi Tang
 *	Greedy Algorithm: Sort two vectors.
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

priority_queue<int, vi, greater<int> > mor;
priority_queue<int, vi, less<int> > aft;
int main(){
	int n,d,r;
	while(cin >> n >> d >> r && n != 0 && d != 0 && r != 0){
		int re = 0;
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			mor.push(tmp);
		}
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			aft.push(tmp);
		}
		REP(i,0,n){
			int a = mor.top();mor.pop();
			int b = aft.top();aft.pop();
			int sum = a+b;
			if(sum-d >= 0)
				re += (sum-d)*r;

		}
		cout << re << endl;
	}
	
	return 0;
}
