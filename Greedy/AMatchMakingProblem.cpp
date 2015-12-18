/*
 *	UVA 12210
 *	Created by Ziyi Tang
 *	Find the minimum one
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

vi ba;
vi sp;
int main(){
	int test = 0;
	int a,b;
	while(cin >> a >> b && (a != 0 || b != 0)){
		ba.clear();
		sp.clear();
		test++;
		REP(i,0,a){
			int tmp;
			cin >> tmp;
			ba.push_back(tmp);
		}
		REP(i,0,b){
			int tmp;
			cin >> tmp;
			sp.push_back(tmp);
		}

		int dif = a-b;
		if(dif <= 0)
			printf("Case %d: %d\n",test,0);
		else{
			printf("Case %d: %d %d\n",test,dif,*min_element(ba.begin(), ba.end()));
		}
	}
	return 0;
}
