/*
 *	UVA 714
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
#define MOD 1000000007

vi all;
int m,k;
bool check(ll mid){
	for(int i = 0; i < m; i++){
		if(all[i] > mid) return false;
	}
	int count = 1;
	ll sum = 0;
	for(int i = 0; i < m; i++){
		if(sum + all[i] <= mid){
			sum += all[i];
		}
		else{
			sum=0;
			i--;
			count++;
		}
	}
	//cout << count << " " << k << endl;
	if(count <= k)
		return true;
	else
		return false;
}
int main(){
	int test;
	cin >> test;
	while(test--){
		cin >> m >> k;
		all.clear();
		REP(i,0,m){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		ll i = 0LL, j = 10000000000LL;
		while(i <= j){
			ll mid = (i+j)/2;
			//cout << mid << endl;
			if(check(mid))
				j = mid-1;
			else
				i = mid+1;
		}
		ll sum = 0LL;
		set<int> split;
		for(int kk = m-1; kk >= 0; kk--){
			int a = 0;
			// while(a != 1e9) a++;

			//cout << kk << endl;
			if(sum+all[kk] <= i && kk >= k-split.size()-1){
				sum += all[kk];
			}
			else{
				split.insert(kk); 
				if(kk >= k-split.size()-1)
					kk++;
				sum = 0;
			} 
		}
		REP(i,0,m){
			if(i != 0) cout << " ";
			cout << all[i];
			if(split.find(i) != split.end()){
				cout << " /";
			}
		}
		cout << endl;
	}
	return 0;
}