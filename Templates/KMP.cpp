/*
 *	Knuth-Morris-Pratt's Algorithm
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

string T,P;
int b[MAXN], n, m;
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
void kmpSearch(){
	int i = 0, j = 0;
	while(i < n){
		while(j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		if(j == m){ // Find
			printf("P is found at %d in T", i - j);
			j = b[j];
		}
	}
}
int main(){
	return 0;
}
