/*
 *	USACO 2016 January Contest, Silver 2
 *	Created by Ziyi Tang
 *	Prefix Sum with remainder
 *	If (a-b)%7 == 0 then a%7 = b%7
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

vi all;
vector<ll> sum;
int n;
int main(){
	ifstream ifile("div7.in");
	ifile >> n;
	all.push_back(0);
	sum.push_back(0);
	REP(i,1,n+1){
		int tmp;
		ifile >> tmp;
		all.push_back(tmp);
		sum.push_back(sum[i-1]+tmp);
		sum[i] %= 7;
	}
	//REP(i,0,n+1) cout << sum[i] << " ";
	ifile.close();
	int maxp = 0;
	REP(i,0,6){
		int a = -1, b = -1;
		REP(j,1,n+1){
			if(sum[j] == i && a == -1) 
				a = j;
			else if(sum[j] == i)
				b = j;
		}
		if(a != -1 && b != -1)
			maxp = max(maxp, b-a);
	}
	cout << maxp << endl;
	ofstream ofile("div7.out");
	ofile << maxp << endl;
	ofile.close();
	return 0;
}