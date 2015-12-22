/*
 *	UVA 11157
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

vi all1;
vi all2;
int main(){
	int test;
	cin >> test;
		REP(t,1,test+1){
			all1.clear();
			all2.clear();
			int n,d;
			int seq = 0;
			cin >> n >> d;
			all1.push_back(0);
			all2.push_back(0);
			getchar();
			string line;
			getline(cin,line);
			stringstream ss(line);
			string now;
			REP(i,0,n){
				ss >> now;
				int sz = now.size();
				string subs = now.substr(2,sz-2+1);
				if(now[0] == 'B'){
					all1.push_back(stoi(subs));
					all2.push_back(stoi(subs));
					seq = 0;
				}
				else if(now[0] == 'S'){
					if(seq == 0){
						all1.push_back(stoi(subs));
						seq = 1;
					}
					else{
						all2.push_back(stoi(subs));
						seq = 0;
					}
				}

			}
			all1.push_back(d);
			all2.push_back(d);
			int sz1 = all1.size();
			int sz2 = all2.size();
			int maxp = 0;
			// REP(i,0,all1.size()){
			// 	cout << all1[i] << endl;
			// }
			REP(i,1,sz1){
				int tmp = all1[i]-all1[i-1];
				if (tmp > maxp)
					maxp = tmp;
			}
			REP(i,1,sz2){
				int tmp = all2[i]-all2[i-1];
				if (tmp > maxp)
					maxp = tmp;
			}
			printf("Case %d: %d\n", t,maxp);
		}
	return 0;
}
