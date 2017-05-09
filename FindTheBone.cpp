/*
 *	Codeforces 796B
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

vi all;
vi hole;
int main(){
	int n,m,k;
	int now = 0;
	cin >> n >> m >> k;
	all.assign(n,0);
	hole.assign(n,0);
	REP(i,0,m){
		int tmp;
		scanf("%d", &tmp);
		tmp--;
		hole[tmp] = 1;
	}
	REP(j,0,k){
		int a,b;
		if(hole[now] == 1){
			break;
		}
		scanf("%d %d", &a,&b);
		a--;b--;
		if(a == now){
			now = b;
		}
		else if(b == now){
			now = a;
		}
	}
	cout << now+1 << endl;
	return 0;
}