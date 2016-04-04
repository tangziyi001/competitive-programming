/*
 *	UVA 897
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
#define REP(i,s,t) for(ll i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define MAXN 10000005

int primes[MAXN];
int anap[MAXN];
vi pp;
int main(){
	FILL(anap,0);
	REP(i,0,MAXN) primes[i] = 1;
	primes[0] = primes[1] = 0;
	REP(i,2,MAXN) if(primes[i]){
			pp.push_back(i);
			for(ll j = i*i; j < MAXN; j+=i)
				primes[j] = 0;
	}
	//cout << pp.size() << endl;
	int sz = pp.size();
	REP(i,0,sz){
		//cout << "pp" << pp[i] << endl;
			int flag = 1;
			string now = to_string(pp[i]);
			sort(now.begin(),now.end());
			if(now[0] == '0') continue;
			if(!anap[stoi(now)]){
				do{
					//cout << now << endl;
					int tmp = stoi(now);
					if(!primes[tmp] || now[0] == '0'){
						flag = 0; break;
					}
				}while(next_permutation(now.begin(), now.end()));
			}
			if(flag){
				//cout << "pp" << pp[i] << endl;
				anap[pp[i]] = 1;
			}
	}
	int n;
	while(cin >> n && n != 0){
		if(n > 1000){
			cout << 0 << endl;
			continue;
		}
		int re = 0;
		string now = to_string(n);
		int ssz = pow(10, (now.size()));
		//cout << ssz << endl;
		for(int i = n+1; i < ssz && !re; i++){
			string tmp = to_string(i);
			if(tmp[0] != '0' && anap[stoi(tmp)]){
				re = stoi(tmp);
				break;
			}
		}
		cout << re << endl;
	}

	return 0;
}