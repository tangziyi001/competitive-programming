/*
 *	Code Jam to IO 2016 for Women A
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

vi all;
vi re;
map<int,int> ss;
int main(){
	int test;
	cin >> test;
	REP(t,1,test+1){
		all.clear();
		ss.clear();
		re.clear();
		int n;
		cin >> n;
		REP(i,0,2*n){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		ss[all[0]]=1;
		re.push_back(all[0]);
		REP(i,1,2*n){
			if(ss.find(all[i]/4*3) == ss.end() || ss[all[i]/4*3] == 0){
				re.push_back(all[i]);
				ss[all[i]] += 1;
			}
			else
				ss[all[i]/4*3]--;
		}
		printf("Case #%d: ",t);
		
		REP(i,0,n){
			printf(" %d",re[i]);
		}
		printf("\n");

	}	
	return 0;
}

