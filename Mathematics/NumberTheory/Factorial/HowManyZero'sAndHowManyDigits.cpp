/*
 *	UVA 10061
 *  Coded by Ziyi Tang
 *	When b is the base, the number of digits x for n satisfies b^(x-1) -> n.
 *	So x = log(b,n) + 1
 *	Find all prime factors of n, and check how many ways that some factors can
 * 	be multiplied to form b
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

int n,b;
int cont[10000];
int main(){
	while(cin >> n >> b){
		FILL(cont,0);
		double dig = 0.0;
		REP(i,1,n+1){
			dig += log10(i)/log10(b);
		}
		int re = floor(dig+1e-9)+1;
		REP(k,1,n+1){
			int now = k;
			// Find all prime factors for each k
			for(int i = 2; i <= k && i <= b; i++){
				while(now%i == 0){
					cont[i]++;
					now/=i;
				}
			}
		}
		int num = 0;
		while(1){
			int now = b;
			REP(i,2,b+1){
				while(now%i == 0 && cont[i] > 0){
					cont[i]-=1;
					now/=i;
				}
			}
			if(now == 1) num++;
			else break;
		}
		cout << num << " " << re << endl;
	}
	return 0;
}