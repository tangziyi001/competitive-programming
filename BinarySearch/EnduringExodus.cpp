/*
 *	CodeForces 655C
 *	Coded by Ziyi Tang
 *	Binary Search the answer
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

int sum[100005];
int main(){
	int n,k;
	string line;
	cin >> n >> k;
	cin >> line;
	sum[0] = 0;
	REP(i,1,n+1)
		sum[i] = (int)(line[i-1]-'0')+sum[i-1];
	int i = 0;
	int j = n;
	while(i <= j){
		//cout << i << " " << j << endl;
		int mid = (i+j)/2;
		int flag = 0;
		REP(t,1,n+1) if(line[t-1] == '0'){
			int left = max(t-mid, 1);
			int right = min(t+mid, n);
			int tmp = sum[right]-sum[left-1];
			if(right-left+1-tmp >= k+1){
				flag = 1; break;
			}
		}
		if(flag == 1)
			j = mid-1;
		else
			i = mid+1;
	}
	cout << i << endl;
	return 0;
}

