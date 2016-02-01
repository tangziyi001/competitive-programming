/*
 *	CodeForces 341E
 *	Created by Ziyi Tang
 *	Matrix Exponentiation
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
typedef vector<ll> vi;
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
const int MOD = (int)1E9+7;

vvi mat;
vi all;
int n,b,k,x;
vvi mul(vvi mat1, vvi mat2){
	vi ttmp(x,0L);
	vvi re(x,ttmp);
	REP(i,0,x) REP(j,0,x) REP(k,0,x){
		re[i][j] += (mat1[i][k]*mat2[k][j]);
		re[i][j] %= MOD;

	}
	return re;
}
vvi expo(vvi mat1, int p){
	if(p == 1) return mat1;
	vvi re;
	if(p%2) return mul(mat1,expo(mat1,p-1));
	else{
		re = expo(mat1,p >> 1);
		return mul(re,re);
	}
}
int main(){
	cin >> n >> b >> k >> x;
	vi ttmp(x,0L);
	mat.assign(x,ttmp);
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		all.push_back(tmp);
	}
	REP(i,0,x){
		REP(j,0,n){
			mat[i][(10*i+all[j])%x]++;
		}
	}
	mat = expo(mat,b);
	// REP(i,0,x){
	// 	REP(j,0,x){
	// 		cout << mat[i][j];
	// 	}
	// 	cout << endl;
	// }
	cout << mat[0][k] << endl;
	return 0;
}
