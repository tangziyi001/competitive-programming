/*
 *	Codeforces 716B - Complete the Word
 *	Created by Ziyi Tang
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
#include <unordered_set>
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

int main(){
	string line;
	cin >> line;
	int sz = line.size();
	if(sz < 26){
		cout << -1 << endl;
	} else {
		REP(i,0,sz-26+1){
			string now = line.substr(i,26);
			//cout << now << endl;
			unordered_set<char> tmp;
			int cont = 0;
			int flag = 0;
			REP(j,0,26){
				if(now[j] == '?')
					cont++;
				else if(tmp.count(now[j]) == 0){
					tmp.insert(now[j]);
				} else {
					flag = 1;
					break;
				}
			}
			if(flag == 1) continue;
			if(tmp.size() + cont == 26){
				string re = "";
				REP(t,0,i){
					if(line[t] == '?')
						re += 'A';
					else
						re += line[t];
				}
				REP(j,0,26){
					if(now[j] == '?'){
						REP(k,0,26){
							if(tmp.count((char)('A'+k)) == 0){
								re += (char)('A'+k);
								tmp.insert((char)('A'+k));
								break;
							}
						}
					} else {
						re += now[j];
					}
				}
				REP(t, i+26,sz){
					if(line[t] == '?')
						re += 'A';
					else
						re += line[t];
				}
				cout << re << endl;
				return 0;
			}
		}
		cout << -1 << endl;
	}
	return 0;
}