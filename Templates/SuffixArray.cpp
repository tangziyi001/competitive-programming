/*
 *	Suffix Array
 *	Coded by Ziyi Tang, CS480 S16 New York University
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
#define MAXN 100010
#define MOD 1000000007

string T;
int n;
int RA[MAXN], tempRA[MAXN]; 
int SA[MAXN], tempSA[MAXN]; 
int c[MAXN];
int Phi[MAXN];                      // for computing longest common prefix
int PLCP[MAXN];
int LCP[MAXN];  // LCP[i] stores the LCP between previous suffix T+SA[i-1]
                                              // and current suffix T+SA[i]


void countingSort(int k) { 
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for (i = 0; i < n; i++)
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++){
		int t = c[i];
		c[i] = sum;
		sum+=t;
	}
	for(int i = 0; i < n; i++)
		tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	for(int i = 0; i < n; i++)
		SA[i] = tempSA[i];
}

void constructSA(){
	int i,k,r;
	for(i = 0; i < n; i++) RA[i] = T[i];
	for(i = 0; i < n; i++) SA[i] = i;
	for(k = 1; k < n; k <<= 1){
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for(i = 1; i < n; i++)
			tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		for(i = 0; i < n; i++)
			RA[i] = tempRA[i];
		if (RA[SA[n-1]] == n-1) break;
	} 
}

void computeLCP() {
	int i, L;
	Phi[SA[0]] = -1;
	for (i = 1; i < n; i++)
		Phi[SA[i]] = SA[i-1];
	for (i = L = 0; i < n; i++) {
		if (Phi[i] == -1) { 
			PLCP[i] = 0; 
			continue; 
		} 
		while (T[i + L] == T[Phi[i] + L]) 
			L++; 
		PLCP[i] = L;
		L = max(L-1, 0);
	}
	for (i = 0; i < n; i++)
		LCP[i] = PLCP[SA[i]];
}

int main(){
	cin >> T;
	T += '$';
	n = T.size();
	constructSA();
	for (int i = 0; i < n; i++) 
		printf("%2d\t%c\n", SA[i], T[SA[i]]);
	return 0;
}