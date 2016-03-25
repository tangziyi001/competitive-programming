/*
 *	UVA 11701
 *	Coded by Ziyi Tang
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

int main(){
	string tmp;
	while(cin >> tmp && tmp != "END"){
		if(tmp == "0" || tmp == "1"){
			cout << "MEMBER" << endl;
			continue;
		}
		double now = stod(tmp);
		int in = floor(now);
		double res = now-in;
		int cont = 0;
		int flag = 1;
		while(res > fabs(1e-14) && cont < 8){
			cont++;
			now = 3*res;
			in = floor(now);
			if(in == 1){
				flag = 0;
				break;
			}
			//cout << in << endl;
			res = now-in;
		}
		if(flag)
			cout << "MEMBER" << endl;
		else
			cout << "NON-MEMBER" << endl;
		
	}
	return 0;
}