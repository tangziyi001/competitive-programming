/*
 *	Codeforces 706D
 *	Created by Ziyi Tang
 *	Binary Trie
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
const ll INFL = (ll)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 1000
#define MOD 1000000007

struct Node{
	int cnt0;
	int cnt1;
	Node* zero;
	Node* one;
	Node() : cnt0(0), cnt1(0), zero(NULL), one(NULL) {}
};
int main(){
	Node* root = new Node();
	int q;
	cin >> q;
	Node* hh = root;
	REP(i,0,32){
		hh->cnt0 += 1;
		hh->zero = new Node();
		hh = hh->zero;
	}
	REP(i,0,q){
		char cc;
		int vv;
		cin >> cc >> vv;
		vector<int> bit(32,0);
		int idx = 31;
		while(vv != 0){
			bit[idx--] = vv&1;
			vv/=2;
		}
		hh = root;
		if(cc == '+'){
			REP(j,0,32){
				if(bit[j] == 0){
					hh->cnt0 += 1;
					if(hh->zero){
						hh = hh->zero;
					} else {
						hh->zero = new Node();
						hh = hh->zero;
					}
				} else {
					hh->cnt1 += 1;
					if(hh->one){
						hh = hh->one;
					} else {
						hh->one = new Node();
						hh = hh->one;
					}
				}
			}
		}
		if(cc == '-'){
			REP(j,0,32){
				if(bit[j] == 0){
					hh->cnt0 -= 1;
					hh = hh->zero;
				} else {
					hh->cnt1 -= 1;
					hh = hh->one;
				}
			}
		}
		int re = 0;
		if(cc == '?'){
			REP(j,0,32){
				int want = 1 - bit[j];
				if(want == 1){
					if(hh->cnt1 > 0){
						re |= (1 << (31-j));
						hh = hh->one;
					} else {
						hh = hh->zero;
					}
				} else {
					if(hh->cnt0 > 0){
						re |= (1 << (31-j));
						hh = hh->zero;
					} else {
						hh = hh->one;
					}
				}
				if(!hh) break;
			}
			cout << re << endl;
		}
	}
	return 0;
}