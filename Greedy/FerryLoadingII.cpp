/*
 *	POJ 2336
 *	Created by Ziyi Tang
 *	Greedy DP: The time for next trip should be 
 *  the max of the previous n's trip's backing time and the arriving time of this car.
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

int arr[1500];
int timestart[1500];
int num[1500];
int main(){
	int t;
	cin >> t;
	while(t--){
		FILL(arr,0);
		FILL(timestart,0);
		FILL(num,0);
		int n,t,m;
		cin >> n >> t >> m;
		REP(i,1,m+1){
			int tmp;
			cin >> tmp;
			arr[i] = tmp;
		}
		timestart[0] = 0;
		num[0] = 0;
		REP(i,1,m+1){
			timestart[i] = max(arr[i], timestart[max(0,i-n)])+2*t;
			num[i] = num[max(0,i-n)]+1;
		}
		cout << timestart[m]-t << " " << num[m] << endl; 
		// REP(i,0,m+1){
		// 	cout << timestart[i] << " ";
		// }
		// cout << endl;
	}

	return 0;
}
