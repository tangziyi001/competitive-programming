/*
 *	CodeForces 676C
 *	Created by Ziyi Tang
 *	Two Pointers
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
string line;
int test(char now){
	int i = 0, j = 0;
	int count = 0;
	int maxp = 0;
	while(j < n){
		//cout << i << " " << j << endl;
		while(j < n){
			if(line[j] != now){
				count++;
			}
			if(count <= k){
				maxp = max(maxp, j-i+1);
				j++;
			}
			else{
				j++;
				break;
			}
		}
		while(i < n && line[i] == now) i++;
		i++;count--;
	}
	return maxp;
}
int main(){
	cin >> n >> k >> line;
	int maxp = 0;
	maxp = max(maxp, test('a'));
	maxp = max(maxp, test('b'));
	cout << maxp << endl;
	return 0;
}