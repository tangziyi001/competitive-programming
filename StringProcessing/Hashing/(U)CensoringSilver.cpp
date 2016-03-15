/*
 *	USACO 2015 February Contest, Bronze 1
 *	Coded by Ziyi Tang
 *	String Comparison (Build string from the tail with rolling hashing)
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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
string line;
string p;
string re;
int hashPre[1000005];
int buildHash(string now){
	ll sum = 0LL;
	int sz = now.size();
	REP(i,0,sz){;
		sum += (now[i]-'a')*(ll)pow(7,i);
		sum%=MOD;
	}
	return sum;
}
int main(){
	freopen("censor.in", "r", stdin);
  	freopen("censor.out", "w", stdout);
	FILL(hashPre,0);
	cin >> line >> p;
	int sz = line.size();
	int n = p.size();
	int rz = 0;
	ll ori = buildHash(p); // The hashing of the pattern
	REP(i,0,sz){
		re+=line[i];
		rz++;
		if(rz == n){
			hashPre[rz-1] = buildHash(re.substr(0,n));
		}
		if(rz > n){
			//cout << re[rz-n-1] << " " << re[rz-1] << endl;
			hashPre[rz-1] = ((hashPre[rz-2]-(int)(re[rz-n-1]-'a'))/7+(int)(re[rz-1]-'a')*(ll)pow(7,n-1)%MOD)%MOD;
		}
		if(rz >= n && hashPre[rz-1] == ori && re.substr(rz-n,rz) == p){
			re = re.substr(0,rz-n);
			rz-=n;
		}
	}
	// REP(i,0,rz)
	// 	cout << hashPre[i] << " ";
	cout << re << endl;
	return 0;
}