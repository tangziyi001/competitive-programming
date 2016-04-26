/*
 *	UVA 11107
 *	Coded by Ziyi Tang, CS480 S16 New York University
 *	Binary search the max len. Check if there exists a consecutive LCP >= len
 *	such that the suffix belongs to > n/2 strings.
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
#define MAXN 200010
#define MOD 1000000007

string Ti;
vi T;
int sz;
int RA[MAXN], tempRA[MAXN]; 
int SA[MAXN], tempSA[MAXN]; 
int c[MAXN];
int Phi[MAXN];                      // for computing longest common prefix
int PLCP[MAXN];
int LCP[MAXN];  // LCP[i] stores the LCP between previous suffix T+SA[i-1]
                                              // and current suffix T+SA[i]
vi owner;
int n;
void countingSort(int k) { 
	int i, sum, maxi = max(300, sz);
	memset(c, 0, sizeof c);
	for (i = 0; i < sz; i++)
		c[i + k < sz ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++){
		int t = c[i];
		c[i] = sum;
		sum+=t;
	}
	for(int i = 0; i < sz; i++)
		tempSA[c[SA[i]+k < sz ? RA[SA[i]+k] : 0]++] = SA[i];
	for(int i = 0; i < sz; i++)
		SA[i] = tempSA[i];
}

void constructSA(){
	int i,k,r;
	for(i = 0; i < sz; i++) RA[i] = T[i];
	for(i = 0; i < sz; i++) SA[i] = i;
	for(k = 1; k < sz; k <<= 1){
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for(i = 1; i < sz; i++)
			tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		for(i = 0; i < sz; i++)
			RA[i] = tempRA[i];
		if (RA[SA[sz-1]] == sz-1) break;
	} 
}

void computeLCP() {
	int i, L;
	Phi[SA[0]] = -1;
	for (i = 1; i < sz; i++)
		Phi[SA[i]] = SA[i-1];
	for (i = L = 0; i < sz; i++) {
		if (Phi[i] == -1) { 
			PLCP[i] = 0; 
			continue; 
		} 
		while (T[i + L] == T[Phi[i] + L]) 
			L++; 
		PLCP[i] = L;
		L = max(L-1, 0);
	}
	for (i = 0; i < sz; i++)
		LCP[i] = PLCP[SA[i]];
}

int main(){
	int tt = 0;
	while(cin >> n && n != 0){
		if(tt)
			printf("\n");
		else
			tt = 1;
		Ti = "";
		T.clear(); // All chars are turned into integers
		owner.clear();
		REP(idx,0,n){
			string tmp;
			cin >> tmp;
			Ti += tmp;
			Ti += '#';
			int tsz = tmp.size();
			REP(i,0,tsz){
				T.push_back((int)tmp[i]);
			}
			T.push_back(idx+200);
			owner.push_back(T.size());
		}
		//cout << T << endl;
		sz = T.size();
		constructSA();
		computeLCP();
		// for (int i = 0; i < sz; i++) 
		// 	printf("%2d\t%c\t%d\n", SA[i], T[SA[i]],LCP[i] );
		int sta = 0, ter = 1005;
		vector<pi> re;
		while(sta <= ter){
			int mid = (sta+ter)/2;
			//cout << "mid" << mid << endl;
			vector<pi> interval; // Inclusive
			int idx = 0;
			REP(i,1,sz+1){
				if(LCP[i] < mid || i == sz){
					interval.push_back(make_pair(idx,i-1));
					idx = i;
				}
			}
			int tsz = interval.size();
			int flag = 0;
			REP(i,0,tsz){
				int left = interval[i].first;
				int right = interval[i].second;
				set<int> mark;
				//cout << left << " " << right << endl;
				REP(j,left,right+1){
					int len = SA[j];
					//cout << "len " << len << endl;
					//cout << *upper_bound(owner.begin(),owner.end(),len) << endl;
					mark.insert(*upper_bound(owner.begin(),owner.end(),len));
				}
				if(mark.size() > n/2){
					re.push_back(make_pair(right,mid));
					flag = 1;
				}
			}
			if(flag) sta = mid+1;
			else ter = mid-1;
		}
		//cout << ter << endl;
		if(n == 1){
			cout << Ti.substr(0,Ti.size()-1) << endl;
		}
		else if(ter == 0)
			printf("?\n");
		else{
			int rsz = re.size();
			REP(i,0,rsz) if(re[i].second == ter){
				string result = Ti.substr(SA[re[i].first],ter);
				cout << result << endl;
			}
		}

	}
	return 0;
}