/*
 *	UVA 10718
 *	Created by Ziyi Tang
 *	Check from the most significant bit if the bit can be set to 1 
 *	when the corresponding bit from the original integer is 0 and the 
 *	resulting integer will not exceed the upperbound, or the corresponding 
 *	bit from the original integer is 1 and the resulting integer will not exceed the lowerbound.
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
	unsigned long long n,l,u;
	while(cin >> n >> l >> u){
		queue<int> que;
		bitset<32> a(n);
		bitset<32> b(0);
		for (int i = 31; i >= 0; i--){
			bitset<32> tmp = b;
			tmp[i] = 1;
			if(a[i] == 0 && tmp.to_ullong() <= u){
				b = tmp;
			}
			else if(a[i] == 1 && tmp.to_ullong() <= l){
				b = tmp;
			}
		}
		cout << b.to_ullong() << endl;
	}
 	return 0;
}
