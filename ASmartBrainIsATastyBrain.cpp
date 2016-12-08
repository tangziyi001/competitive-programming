/*
 *	UVALive 5125
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

string eq;
int rec(int sta, int ter){
	//cout << sta << " " << ter << endl;
	//cout << eq.substr(sta,ter-sta+1) << endl;
	if(sta == ter){
		//cout << eq[sta] << endl;
		return eq[sta] == 'f' ? 0 : 1;
	}
	int i = sta, j = i;
	char op;
	int left = 1;
	int Left = 1;
	int Right = 1;
	int recLeft = 0, recRight = 0;
	while(i <= ter){
		if(eq[i] == '('){
			j = i;
			int cont = 0;
			while(j <= ter){
				if(eq[j] == '(') cont++;
				else if(eq[j] == ')') cont--;
				if(cont == 0){
					if(left == 1){
						recLeft = rec(i+1, j-1);
						left = 0;
					}
					else
						recRight = rec(i+1, j-1);
					break;
				}
				j++;
			}
			i = j+1;
		} else if(eq[i] == '&'){
			op = '&';
			i++;
		} else if(eq[i] == '|'){
			op = '|';
			i++;
		} else if(eq[i] == '!'){
			if(left == 1){
				Left = 0;
			}else
				Right = 0;
			i++;
		} else if(eq[i] == 't'){
			if(left == 1){
				recLeft = 1;
				left = 0;
			}
			else recRight = 1;
			i++;
		} else if(eq[i] == 'f'){
			if(left == 1){
				recLeft = 0;
				left = 0;
			}
			else recRight = 0;
			i++;
		}
	}
	if(!Left){
		recLeft = 1-recLeft;
	}
	if(!Right){
		recRight = 1-recRight;
	}
	if(op == '&'){
		//cout << "AND " << (recLeft&recRight) << endl;
		return recLeft&recRight;
	}
	else {
		//cout << "OR " << (recLeft|recRight) << endl;
		return recLeft|recRight;
	}
}
int main(){
	int test;
	cin >> test; getchar();
	int tt = 0;
	while(test--){
		tt++;
		string line;
		getline(cin,line);
		stringstream ss(line);
		string ep;
		string ev;
		ss >> eq; ss >> ep; ss >> ev;
		int ff = 0;
		if(eq[0] == '!'){
			ff = 1;
			eq = eq.substr(1);
		}
		int re = rec(1,eq.size()-2);
		//cout << eq << " " << re << endl;
		if(ff){
			re = 1-re;
		}
		if((ev[0] == 't' && re) || (ev[0] == 'f' && !re)){
			printf("%d: Good brain\n", tt);
		} else {
			printf("%d: Bad brain\n", tt);
		}
	}
	return 0;
}