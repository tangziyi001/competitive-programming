/*
 *	UVA 11690
 *	Created by Ziyi Tang
 *	Union Find
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;
#define INF (int)1E9
#define INFL (long)1E18
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

ll pt[10050];
ll money[10050];
map<int,ll> all;
ll findRep(ll t){
	if (pt[t] == t){
		return t;
	}
	else
		return pt[t] = findRep(pt[t]);
}

void unionSet(ll i, ll j){
	ll fi=findRep(i);
	ll fj=findRep(j);
	pt[fi] = fj;
}

int main(){
	int test;
	cin >> test;
	while (test--){
		all.clear();
		ll n,m;
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			pt[i] = i;
			ll tmp;
			cin >> tmp;
			money[i] = tmp;
		}
		for (int i = 0; i < m; i++){
			ll a,b;
			cin >> a >> b;
			unionSet(a,b);
		}
		for (int i = 0; i < n; i++){
			all[findRep(i)] += money[i];
		}
		bool yes = true;
		for (int i = 0; i < n; i++){
			if (pt[i] == i && all[i] != 0){
				yes = false;
				break;
			}
		}
		if (yes == true){
			cout << "POSSIBLE" << endl;
		}
		else{
			cout << "IMPOSSIBLE" << endl;
		}
	}




	return 0;
}
