/*
 *	UVA 737
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

int all[1005][4]; //x,y,z,r
int main(){
	int n;
	while(cin >> n && n != 0){
		FILL(all,0);
		int t1 = 0 ,b1 = INF, l1 = 0, r1 = INF, fr = 0, ba = INF;
		REP(i,0,n){
			scanf("%d %d %d %d", &all[i][0],&all[i][1],&all[i][2],&all[i][3]);
		}
		REP(i,0,n){
			int t = all[i][1];
			int b = all[i][1]+all[i][3];
			int l = all[i][0];
			int r = all[i][0]+all[i][3];
			int f1 = all[i][2];
			int f2 = all[i][2]+all[i][3];
			t1 = max(t1, t);
			b1 = min(b1, b);
			l1 = max(l1, l);
			r1 = min(r1, r);
			fr = max(fr, f1);
			ba = min(ba, f2);
			//cout << t1 << " " << b1 << " " << l1 << " " << r1 << " " << fr << " " << ba << endl;
		}
		if(t1 < b1 && l1 < r1 && fr < ba){
			int area = (b1-t1)*(r1-l1)*(ba-fr);
			cout << area << endl;
		} else cout << 0 << endl;
	}
	return 0;
}
