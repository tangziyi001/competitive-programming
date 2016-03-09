/*
 *	CodeForces 466C
 *	Created by Ziyi Tang
 *	Prefix Sum with two pointers
 *	Use prefix sum to count the number of ways 0...i has sum of sum/3.
 *	One pointer i iterates from right to left. Each time the sum on i's right
 *	equals to sum/3, we add prefixsum[i-2].
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

vi all;
vi sumcont;
int main(){
	int n;
	cin >> n;
	ll sum = 0;
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.push_back(tmp);
		sum+=tmp;
	}
	if(sum%3 != 0) cout << 0 << endl;
	else{
		ll tmp = 0L;
		sumcont.push_back(0);
		REP(i,0,n){
			sumcont.push_back(sumcont[i]);
			tmp+=all[i];
			if(tmp == sum/3)
				sumcont[i+1]++;
		}
		tmp = 0L;
		ll re = 0L;
		for(int i = n-1; i >= 2; i--){
			tmp += all[i];
			if(tmp == sum/3)
				re += sumcont[i-2+1];
		}
		cout << re << endl;
	}

	return 0;
}

