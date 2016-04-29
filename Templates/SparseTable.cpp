/*
 *	Sparse Table
 *	Coded by Ziyi Tang
 *
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

// Sparse Table
#define LOG_TWO_N 10 // 2^10 > 1000
struct SparseTable{
	int _A[MAXN], SpT[MAXN][LOG_TWO_N];
	SparseTable(int n, int A[]){ // Number of element; Original array
		for(int i = 0; i < n; i++){
			_A[i] = A[i];
			SpT[i][0] = i; // RMQ of i + length of 2^0
		}
		for(int j = 1; (1 << j) <= n; j++){ // 2^j <= n
			for(int i = 0; i + (1 << j) - 1 < n; i++){ // for each valid i
				if(_A[SpT[i][j-1]] < _A[SpT[i + (1 << (j-1))][j-1]]){
					SpT[i][j] = SpT[i][j-1];
				}
				else{
					SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
				}
			}
		}
	}
	int query(int i, int j){
		int k = (int)floor(log((double)j-i+1)/log(2.0));
		if(_A[SpT[i][k]] <= _A[SpT[j-(1 << k)+1][k]])
			return SpT[i][k];
		else
			return SpT[j-(1<<k)+1][k];
	}
};


int main(){
	int a[10] = {7,3,5,2,4,6,1,10,3,2};
	SparseTable st(10,a);
	cout << a[st.query(0,0)] << endl;
	return 0;
}