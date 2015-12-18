/*
 *	UVA 11292
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

priority_queue<int, vi, greater<int> > k;
priority_queue<int, vi, greater<int> > d;
int main(){
	int n,m;
	while(cin >> n >> m && n!=0 && m!=0){
		while(!d.empty()){
			d.pop();
		}
		while(!k.empty()){
			k.pop();
		}
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			d.push(tmp);
		}
		REP(i,0,m){
			int tmp;
			cin >> tmp;
			k.push(tmp);
		}
		int a,b;
		int sum = 0;
		while(1){
			if(!d.empty() && k.empty()){
				cout <<"Loowater is doomed!"<< endl;
				break;
			}
			if(d.empty()){
				cout << sum << endl;
				break;
			}
			a = d.top();
			b = k.top();
			if(b >= a){
				sum += b;
				k.pop();d.pop();
			}
			else{
				k.pop();
			}
		}

	}
	return 0;
}
