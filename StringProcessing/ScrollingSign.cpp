/*
 *	UVA 11576
 *	Created by Ziyi Tang
 *	KMP check identical prefix and suffix
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

string line1,line2;
string P;
int b[MAXN], m;
void kmpPre(){
	int i = 0, j = -1;
	b[0] = -1;
	while(i < m){
		while(j >= 0 && P[i] != P[j])
			j = b[j];
		i++;j++;
		b[i] = j;
	}
}
int main(){
	int test;
	cin >> test;
	while(test--){
		int k,w;
		cin >> k >> w;
		int sum = k;
		cin >> line1;
		REP(i,0,w-1){
			cin >> line2;
			P = line2+'#'+line1;
			m = 2*k+1;
			kmpPre();
			sum += k-b[2*k+1];
			line1 = line2;
		}
		cout << sum << endl;
	}
	return 0;
}