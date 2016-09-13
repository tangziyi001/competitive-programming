/*
 *	ACM Amritapuri 2009
 *	Created by Ziyi Tang
 *	Binary Trie & XOR Prefix
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

vi all;
vi sum;
vector<ll> pows;
struct Node{
	bool end;
	Node* zero;
	Node* one;
	int count;
	Node() : end(false), zero(NULL), one(NULL), count(0) {}
};
struct Trie{
	Node* root;
	Trie() : root(new Node()) {}
	void insert(int num){
		Node* cur = root;
		REP(i,0,32){
			if(num & (1 << (31-i))){
				if(cur->one == NULL){
					cur->one = new Node();
				}
				cur->one->count++;
				cur = cur->one;
			} else {
				if(cur->zero == NULL){
					cur->zero = new Node();
				}
				cur->zero->count++;
				cur = cur->zero;
			}
		}
	}
	int queryMax(int now){
		int ans = 0;
		Node* cur = root;
		REP(i,0,32){
			int tmp = (now & (1 << (31-i))) == 0 ? 0 : 1;
			if(tmp == 0 && cur->one != NULL){
				ans += pows[31-i];
				cur = cur->one;
			} else if(tmp == 1 && cur->zero != NULL){
				ans += pows[31-i];
				cur = cur->zero;
			} else {
				cur = cur->zero != NULL ? cur->zero : cur->one;
			}
		}
		return ans;
	}
};

int main(){
	int test;

	// Record Pow 2
	ll now = 1;
	pows.push_back(now);
	REP(i,1,32){
		now *= 2;
		pows.push_back(now);
	}
	cin >> test;
	while(test--){
		Trie trie;
		trie.insert(0);
		all.clear();
		int n;
		cin >> n;
		REP(i,0,n){
			int tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		sum.clear();
		sum.push_back(0);
		int ans = 0;
		REP(i,0,n) {
			sum.push_back(sum[i]^all[i]);
		}
		REP(i,1,n+1){
			ans = max(ans, trie.queryMax(sum[i]));
			trie.insert(sum[i]);
		}
		cout << ans << endl;
	}
	return 0;
}