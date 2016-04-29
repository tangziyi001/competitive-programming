/*
 *	CodeForces 667C - Reberland Linguistics
 *	Coded by Ziyi Tang
 *	DP: check if a substring is not equal to the previous substring of same length,
 *	and if the previous substring of length 2 or 3 is valid
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

string line;
int sz;
set<string> re;
int mark[10010][2];
// Power Computation
ll power(ll base, ll n){
	if(n == 0LL) return 1LL;
	//if(n == 1LL) return base;
	ll tmp = power(base,n/2);
	ll now = tmp*tmp;
	if(n&1){
		now = base*now;
	}
	return now;
}

int main(){
	cin >> line;
	FILL(mark,0);
	if(line.size() < 5){
		cout << "0" << endl;
		return 0;
	}
	line = line.substr(5, line.size()-5);
	reverse(line.begin(), line.end());
	sz = line.size();
	if(sz == 0 || sz == 1)
		cout << "0" << endl;
	else if(sz == 2){
		cout << "1" << endl;
		reverse(line.begin(), line.end());
		cout << line << endl;
	}
	else if(sz == 3){
		cout << "2" << endl;
		reverse(line.begin(), line.end());
		vector<string> tmp;
		tmp.push_back(line);
		tmp.push_back(line.substr(1,2));
		sort(tmp.begin(), tmp.end());
		cout << tmp[0] << endl;
		cout << tmp[1] << endl;
	}
	else{
			re.insert(line.substr(0,2));
			mark[0][0] = 1;

			re.insert(line.substr(0,3));
			mark[0][1] = 1;

		//cout << line << endl;
		// vector<int> idxs;
		// for(int i = 0; power(2, i) < sz; i++){
		// 	//cout << power(2, i) << endl;
		// 	for(int j = 0; power(2, i) + power(3, j) < sz; j++){
		// 		int idx =  power(2, i) + power(3, j);
		// 		idxs.push_back(idx);
		// 	}
		// }
		// sort(idxs.begin(),idxs.end());
		// int tsz = idxs.size();
		REP(k,1,sz){
				int idx = k;
				//cout << idx << endl;
				if(idx >= sz-1) break;
				string two = line.substr(idx, 2);
				int flag = false;
				if(idx >= 3 && mark[idx-3][1] == 1)
					flag = true;
				if(idx >= 2 && two != line.substr(idx-2, 2) && mark[idx-2][0] == 1){
					flag = true;
				}
				if(flag){
					re.insert(two);
					mark[idx][0] = 1;
				}
				if(idx < sz-2){
					string three = line.substr(idx, 3);
					flag = false;
					if(idx >= 3 && three != line.substr(idx-3, 3) && mark[idx-3][1] == 1){
						flag = true;
					}
					if(idx >= 2 && mark[idx-2][0] == 1)
						flag = true;
					if(flag){
						//cout << idx << " " <<  three << endl;
						re.insert(three);
						mark[idx][1] = 1;
					}
				}
		}
		cout << re.size() << endl;
		vector<string> rr;
		for(auto it = re.begin(); it != re.end(); it++){
			string tmp = *it;
			reverse(tmp.begin(), tmp.end());
			rr.push_back(tmp);
		}
		sort(rr.begin(), rr.end());
		int ssz = rr.size();
		REP(i,0,ssz){
			cout << rr[i] << endl;
		}
	}
	return 0;
}