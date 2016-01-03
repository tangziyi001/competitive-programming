/*
 *	UVA 10487
 *	Created by Ziyi Tang
 *	Prefix Trie
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


// Prefix
struct TrieNode{
	bool is_end;
	int prefix_count;
	struct TrieNode *child[26]; // Array of pointers
} *head;

void init(){
	head = new TrieNode();
	head -> prefix_count = 0;
	head -> is_end = false;
}

void insert(string word){
	TrieNode *cur = head;
	cur -> prefix_count++;
	for(int i = 0; i < word.size(); i++){
		int letter = (int)word[i] - (int)'a';
		if(cur -> child[letter] == NULL)
			cur -> child[letter] = new TrieNode();
		cur -> child[letter] -> prefix_count++;
		cur = cur -> child[letter];
	}
	cur -> is_end = true;
}

bool search(string word){
	TrieNode *cur = head;
	for(int i = 0; i < word.size(); i++){
		int letter = (int)word[i]-(int)'a';
		if(cur -> child[letter] == NULL)
			return false;
		cur = cur -> child[letter];
	}
	return cur -> is_end;
}

int countWordsWithPrefix(string prefix){
	TrieNode *cur = head;
	for(int i = 0; i < prefix.size(); i++){
		int letter = (int)prefix[i] - (int)'a';
		if(cur -> child[letter] == NULL)
			return 0;
		cur = cur -> child[letter];
	}
	return cur -> prefix_count;
}

int main(){

	return 0;
}