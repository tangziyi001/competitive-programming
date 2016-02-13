/*
 *	UVA 11572
 *	Created by Ziyi Tang
 *	Sliding Window: Two Pointers for Unique Interval
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
#define MAXN 10000005

int mark[MAXN];
int all[MAXN];
int main(){
	int t;
	cin >> t;
	while(t--){
		FILL(mark,0);
		int n;
		cin >> n;
		int tmp;
		REP(i,0,n){
			cin >> tmp;
			all[i] = tmp;
		}
		int a,b;
		a = 0;
		b = 0;
		int maxp = 0;
		while(b < n){

			if(mark[all[b]] == 1){
				while(all[a] != all[b]){
					mark[all[a]] = 0;
					a++;
				}
				a++;
				maxp = max(maxp, b-a+1);
				mark[all[b]] = 0;
			} 
			else{
				mark[all[b]] = 1;
				maxp = max(maxp, b-a+1);
				b++;
			}
		}
		if(b == n){
			maxp = max(maxp, b-a);
		}
		cout << maxp << endl;
	}
	return 0;
}
