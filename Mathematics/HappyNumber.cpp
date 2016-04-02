/*
 *	UVA 10591
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
	int n;
	cin >> n;
	REP(t,1,n+1){
		int now;
		cin >> now;
		ll tmp = now;
		int flag = 1;
		REP(i,0,1000){
			//cout << tmp << endl;
			ll nxt = 0;
			while(tmp != 0){
				int cur = tmp%10;
				tmp/=10;
				nxt += cur*cur;
			}
			if(nxt == 1){
				flag = 0;
				break;
			}
			else if(nxt == now){
				flag = 1;
				break;
			}
			tmp = nxt;
		}
		if(flag == 0)
			printf("Case #%d: %d is a Happy number.\n", t, now);
		else
			printf("Case #%d: %d is an Unhappy number.\n",t, now);
	}
	return 0;
}