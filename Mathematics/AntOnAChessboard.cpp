/*
 *	
 *	Created by Ziyi Tang
 *	Use ceil(sqrt()) to locate the relative position
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
	int num;
	while(cin >> num && num != 0){
		int root = ceil(sqrt(num));
		int ref = root*root;
		int diff = ref-num;
		int x,y;
		if(root % 2 == 0){
			x=1;y=root;
			while(diff>0){
				if(x < root){
					x++;diff--;
				}
				else{
					y--;diff--;
				}
			}
		}
		else{
			x=root;y=1;
			while(diff>0){
				if(y < root){
					y++;diff--;
				}
				else{
					x--;diff--;
				}
			}
		}
		cout << y << " " << x << endl;
	}
	return 0;
}
