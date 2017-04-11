/*
 *	Codechef PRPALN
 *	Created by Ziyi Tang
 *	Choose the center and do multiple checks
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
#define MAXN 1000
#define MOD 1000000007

bool check(string left, string right){
	//cout << left << " " << right << endl;
	string maxp, minp;
	if(left.size() > right.size()){
		maxp = left; minp = right;
	} else {
		maxp = right; minp = left;
	}
	int i = 0, j = minp.size()-1;
	int cont = 0;
	while(i < maxp.size() && j >= 0){
		if(maxp[i] != minp[j]){
			i++;
			cont++;
			continue;
		}
		i++;j--;
	}
	return cont == 1;
}
bool checkSame(string left, string right){
	int i = 0, j = right.size()-1;
	if(left.size() != right.size()) return false;
	while(i < left.size()){
		if(left[i] != right[j])
			return false;
		i++;j--;
	}
	return true;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		string line;
		cin >> line;
		int n = line.size();
		if(n == 2){
			cout << "YES" << endl;
			continue;
		}
		bool flag = false;
		if(n&1){
			int mid = n/2;
			// Center at mid, mid+1
			flag |= (line[mid] == line[mid+1]) && check(line.substr(0,mid), line.substr(mid+2, n-1-(mid+2)+1));
			// Center at mid-1, mid
			flag |= (line[mid-1] == line[mid]) && check(line.substr(0,mid-1), line.substr(mid+1, n-1-(mid+1)+1));
			// Center at mid-1, mid+1
			flag |= (line[mid-1] == line[mid+1]) && checkSame(line.substr(0,mid), line.substr(mid+1, n-1-(mid+1)+1));
		} else {
			int mid = n/2-1;
			flag |= (check(line.substr(0,mid), line.substr(mid+1, n-1-(mid+1)+1)));
			flag |= (check(line.substr(0,mid+1), line.substr(mid+2, n-1-(mid+2)+1)));
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}