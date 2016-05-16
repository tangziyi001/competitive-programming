/*
 *	673D - Bear and Two Paths
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
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

int n,k;
vi all;
vi re1;
vi re2;
vi re;
int main(){
	cin >> n >> k;
	int a1,a2,b1,b2;
	cin >> a1 >> a2 >> b1 >> b2;
	a1--;a2--;b1--;b2--;
	if(n <= 4 || k <= n) cout << -1 << endl;
	else{
		re.assign(n,-1);
		if(n|1){
			int mid = n/2;
			re[0] = a1;
			re[n-1] = a2;
			re[mid-1] = b1;
			re[mid+1] = b2;
		}
		else{
			int midl = n/2-1;
			int midr = n/2;
			re[0] = a1;
			re[n-1] = a2;
			re[midl-1] = b1;
			re[midr+1] = b2;
		}
		int idx = 0;
		REP(i,0,n){
			while(idx == a1 || idx == a2 || idx == b1 || idx == b2){
				idx++;
			}
			if(re[i] == -1){
				re[i] = idx;
				idx++;
			}
		}
		// REP(i,0,n){
		// 	cout << re[i] << endl;
		// }
		REP(i,0,n){
			re1.push_back(i);
		}
		if(n|1){
			int mid = n/2;
			for(int i = mid-1; i >= 0; i--){
				re2.push_back(i);
			}
			re2.push_back(mid);
			for(int i = n-1; i >= mid+1; i--){
				re2.push_back(i);
			}
		}
		else{
			int midl = n/2-1;
			int midr = n/2;
			for(int i = midl-1; i >= 0; i--){
				re2.push_back(i);
			}
			re2.push_back(midl);
			re2.push_back(midr);
			for(int i = n-1; i >= midr+1; i--){
				re2.push_back(i);
			}
		}
		REP(i,0,n){
			if(i != 0) cout << " ";
			cout << re[re1[i]]+1;
		}
		cout << endl;
		REP(i,0,n){
			if(i != 0) cout << " ";
			cout << re[re2[i]]+1;
		}
		cout << endl;
	}
	return 0;
}