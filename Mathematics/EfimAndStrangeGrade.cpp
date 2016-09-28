/*
 *	Codeforces 719C - Efim and Strange Grade
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

string line;
int main(){
	int n,t;
	cin >> n >> t;
	cin >> line;
	int point = -1;
	REP(i,0,n){
		if(line[i] == '.')
			point = i;
	}
	if(point == -1 || t == 0){
		cout << line << endl;
		return 0;
	}
	// Int
	if(line[point+1] >= '5'){
		string re = line.substr(0, point);
		int carry = 1;
		int idx = re.size()-1;
		while(idx != -1){
			if(carry == 1){
				if(re[idx] == '9')
					re[idx] = '0';
				else{
					re[idx] += 1;
					carry = 0;
				}
			}
			idx--;
		}
		if(carry){
			re = "1" + re;
		}
		cout << re << endl;
		return 0;
	}
	string dec = line.substr(point+1, n-point);
	int sz = dec.size();
	int start4 = -2;
	if(dec[0] == '4') start4 = -1;
	REP(i,0,sz-1){
		if(dec[i+1] == '4' && start4 == -2) start4 = i;
		if(dec[i+1] >= '5'){
			if(dec[i] == '4'){
				if(i+1-start4 <= t){
					if(start4 == -1){
						string re = line.substr(0, point);
						int carry = 1;
						int idx = re.size()-1;
						while(idx != -1){
							if(carry == 1){
								if(re[idx] == '9')
									re[idx] = '0';
								else{
									re[idx] += 1;
									carry = 0;
								}
							}
							idx--;
						}
						if(carry){
							re = "1" + re;
						}
						cout << re << endl;
						return 0;
					} else {
						dec[start4] += 1;
						dec = dec.substr(0,start4+1); 
						break;
					}
				} else {
					int five = i+1-t;
					dec = dec.substr(0, five);
					dec += '5';
					break;
				}
			} else {
				dec[i] += 1;
				dec = dec.substr(0, i+1);
				break;
			}
		}
		if(dec[i+1] != '4') start4 = -2;
	}
	line = line.substr(0, point) + '.' + dec;

	// Int
	cout << line << endl;

	return 0;
}