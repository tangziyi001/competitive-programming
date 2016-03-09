/*
 *	APS Midterm E
 *	Created by Ziyi Tang
 *	LIS with Greedy + D&G
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


// LIS Greedy + Divide and Conquer
int LIS(vector<int>& s, int k)
{
    if (s.size() == 0) return 0;
    vector<int> v;
    v.push_back(s[0]);
    for (int i = 1; i < s.size(); ++i)
    {
        int n = s[i];
        if (n-k >= v.back())
            v.push_back(n);
        else{
            auto it = lower_bound(v.begin(), v.end(), n);
            if(it == v.begin() || n >= *(it-1)+k){
            	*it = n;
            }
        }
    }
    return v.size();
}

vi all;
int dp[100005];
int main(){
	int test;
	cin >> test;
	while(test--){
		all.clear();
		FILL(dp,0);
		int n,k;
		cin >> n >> k;
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		int re = LIS(all,k);
		cout << re << endl;
	}
	return 0;
}

