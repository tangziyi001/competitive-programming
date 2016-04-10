/*
 *	Google Code Jam 2016 Online Qualification Round 2
 *	Coded by Ziyi Tang， CS480 S16 Algorithmic Problem Solving, New York University
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

string line;
int sz;
int cur;
int cont;
void rev(int ter){
	reverse(line.begin(),line.begin()+ter+1);
	REP(i,0,ter+1){
		if(line[i] == '+')
			line[i] = '-';
		else
			line[i] = '+';
	}
}
int main(){
	int t;
	cin >> t;
	REP(cas,1,t+1){
		cin >> line;
		cont = 0;
		sz = line.size();
		int flag = 1;
		while(flag){
			//cout << line << endl;
			cur = 0;
			while(line[cur] == '+'){
				cur++;
				if(cur == sz){
					flag = 0;
					break;
				}
			}
			if(flag && cur){
				rev(cur-1);
				cont++;
			}
			else if(flag){
				int tmp = sz-1;
				while(tmp >= 0){
					if(line[tmp] == '-'){
						rev(tmp);
						cont++;
						break;
					}
					else tmp--;
				}
			}
		}
		printf("Case #%d: %d\n",cas,cont);
	}
	return 0;
}