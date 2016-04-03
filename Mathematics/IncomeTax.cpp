/*
 *	UVA 11247
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

ll m;
int x;
int main(){
	while(cin >> m >> x && (m != 0 || x != 0)){
		if(m == 1) cout << "Not found" << endl;
		else if(x == 0) cout << "Not found" << endl;
		else if(x == 100) cout << "Not found" << endl;
		else{
			ll tmp = (ll)(m-1)*100/(100-x);
			if((ll)(m-1)*100%(100-x)){
				if(tmp < m) cout << "Not found" << endl;
				else
					cout << tmp << endl;
			}
			else{
				if(tmp < m) cout << "Not found" << endl;
				else
					cout << tmp-1 << endl;
			}
			

		}
		
	}
	return 0;
}