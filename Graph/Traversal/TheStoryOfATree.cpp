/*
 *	HackerRank  University CodeSprint 2 D
 *	Created by Ziyi Tang
 *  Tree Traversal for twice
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
#define MAXN 100005
#define MOD 1000000007

vvi all;
set<pi> ss;
int n;
int g,k;
int re[MAXN];

int dfs1(int now, int p){ 
    int tsz = all[now].size();
    int tot = 0;
    REP(i,0,tsz){
        int nxt = all[now][i];
        if(nxt == p) continue;
        if(ss.find(make_pair(now,nxt)) != ss.end()){
            tot += 1;
        }
        tot += dfs1(nxt, now);
    }
    return tot;
}

void dfs2(int now, int p, int val){
    re[now] = val;
    int tsz = all[now].size();
    REP(i,0,tsz){
        int nxt = all[now][i];
        int tval = val;
        if(nxt == p) continue;
        if(ss.find(make_pair(now,nxt)) != ss.end()){
            tval--;
        }
        if(ss.find(make_pair(nxt,now)) != ss.end()){
            tval++;
        }
        dfs2(nxt,now,tval);
    }
}

// GCD
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	int q;
    cin >> q;
    while(q--){
        cin >> n;
        all.clear();
        ss.clear();
        FILL(re,0);
        all.assign(n,vi(0,0));
        REP(i,0,n-1){
            int a,b;
            cin >> a >> b;
            all[a-1].push_back(b-1);
            all[b-1].push_back(a-1);
        }
        cin >> g >> k;
        REP(i,0,g){
            int a, b;
            cin >> a >> b;
            ss.insert(make_pair(a-1,b-1));
        }
        int first = dfs1(0,-1);
        dfs2(0,-1,first);
        int cont = 0;
        REP(i,0,n){
            if(re[i] >= k) cont++;
        }
        if(cont == 0){
            cout << cont << "/" << 1 << endl;
        }
        else{
            int gcdp = gcd(cont,n);
            cout << cont/gcdp << "/" << n/gcdp << endl;
        }
    }
	return 0;
}