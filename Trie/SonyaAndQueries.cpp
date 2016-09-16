/*
 *	Codeforces 714C - Sonya and Queries
 *	Created by Ziyi Tang
 *	Trie of even and odd
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
	ll count;
	Node* odd;
	Node* even;
	Node() : count(0LL), odd(NULL), even(NULL) {}
};
struct Trie{
	Node* root;
	Trie() : root(new Node) {}
	void insert(ll val){
		Node* cur = root;
		while(val != 0){
			ll dig = val%10; val /= 10;
			if(dig&1){
				if(cur->odd == NULL)
					cur->odd = new Node();
				cur = cur->odd;
			} else {
				if(cur->even == NULL)
					cur->even = new Node();
				cur = cur->even;
			}
		}
		cur->count++;
	}
	void remove(ll val){
		Node* cur = root;
		while(val != 0){
			ll dig = val%10; val/=10;
			if(dig&1){
				cur = cur->odd;
			} else {
				cur = cur->even;
			}
		}
		cur->count--;
	}
	ll check(string line){
		Node* cur = root;
		ll sum = 0;
		// Remove trailing 0s
		ll val = stoll(line);
		while(val != 0) {
			int dig = val%10; val/=10;
			if(!dig && cur->even != NULL){
				cur = cur->even;
			} else if(dig && cur->odd != NULL){
				cur = cur->odd;
			} else {
				return 0;
			}
		}
		while(cur != NULL){
			sum += cur->count;
			cur = cur->even;
		}
		return sum;
	}
};
int main(){
	int t;
	cin >> t;
	Trie trie = Trie();
	REP(i,0,t){
		char c;
		cin >> c;
		if(c == '+'){
			ll tmp; cin >> tmp;
			trie.insert(tmp);
		} else if(c == '-'){
			ll tmp; cin >> tmp;
			trie.remove(tmp);
		} else {
			string tmp; cin >> tmp;
			cout << trie.check(tmp) << endl;
		}
	}
	return 0;
}