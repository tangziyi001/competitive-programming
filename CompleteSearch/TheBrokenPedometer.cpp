/*
 *	UVA 11205
 *	Created by Ziyi Tang
 *	All permutation C(n,k) by using bit manipulation
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
#define MAXN 105

int all[MAXN];
int mark[100005];
int main(){
	int t;
	cin >> t;
	while(t--){
		FILL(all,0);
		int n,m;
		cin >> m >> n;
		REP(i,0,n){
			int now = 0;
			REP(j,0,m){
				int bit;
				cin >> bit;
				now |= (bit << (m-1-j));
			}
			all[i] = now;
		}
		int num = INF;
		for(int permu = 0; permu <= (1 << m) - 1; permu++){
			//cout << "p" << permu << endl;
			FILL(mark,0);
			int flag = 1;
			// bitset<7> see(permu);
			// cout << see << endl;
			REP(i,0,n){
				int tmp = 0;
				REP(j,0,m){
					if((permu & (1 << j)) == 0) continue;
					tmp |= (all[i] & (1 << j));
				}
				if(mark[tmp]) {
					flag = 0;
					break;
				}
				else mark[tmp] = 1;
			}
			if(flag){
				//cout << "go" << endl;
				int cont = 0;
				REP(i,0,m){
					if(permu & (1 << i)){
						cont++;
					}
				}
				num = min(num, cont);
			}
		}
		cout << num << endl;
	}
	return 0;
}
