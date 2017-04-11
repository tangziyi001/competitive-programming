/*
 *	UVA 1197
 *	Created by Ziyi Tang
 *	Union Find
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
#define MAXN 30005
#define MOD 1000000007

int p[MAXN];
int findRep(int now){
	if(now != p[now]){
		return findRep(p[now]);
	} else return now;
}
bool isSame(int a, int b){
	return findRep(a) == findRep(b);
}
void unionSet(int a, int b){
	if(isSame(a,b)) return ;
	int pa = findRep(a);
	int pb = findRep(b);
	p[pa] = pb;
}

int main(){
	int n,m;
	while(cin >> n >> m && (n!=0||m!=0)){
		REP(i,0,n) p[i] = i;
		REP(i,0,m){
			int num = 0;
			cin >> num;
			int first = -1;
			REP(j,0,num){
				int tmp;
				scanf("%d", &tmp);
				if(first == -1) first = tmp;
				else unionSet(first, tmp);
			}
		}
		int pp = findRep(0);
		int cont = 0;
		REP(i,0,n){
			if(findRep(i) == pp) cont++;
		}
		cout << cont << endl;
	}
	return 0;
}