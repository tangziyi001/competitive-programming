/*
 *	UVA 10298
 *	Created by Ziyi Tang
 *	KMP: Find P in P+P+P+...
 *	The smallest cycle is len-b[len];
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
#define MAXN 1000100

string T,P;
int b[MAXN], n, m;
int counter;
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
	string line;
	while(cin >> line && line != "."){
		P = line;
		int sz = P.size();
		m = sz;
		kmpPre();
		if(m%(m-b[m]) == 0)
			cout << m/(m-b[m]) << endl;
		else
			cout << 1 << endl;
		
	}
	return 0;
}
