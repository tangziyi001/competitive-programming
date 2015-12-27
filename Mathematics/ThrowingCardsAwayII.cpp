/*
 *	UVA 10940
 *	Created by Ziyi Tang
 *	Use brute force to find pattern. Create lookup table.
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
#define MAXN 500010

vector<int> all;
int look[MAXN];
int mark[MAXN];
int main(){
	int num;
	int sn = 0;
	FILL(mark,0);
	for(int i = 2; i <= MAXN; i*=2){
		mark[i] = 1;
	}
	for(int i = 2; i <= MAXN; i++){
		sn+=2;
		look[i] = sn;
		if(mark[i] == 1){
			sn = 0;
		}
	}
	// REP(i,2,30){
	// 	cout << look[i] << " "<<mark[i]<<endl;
	// }
	while(cin >> num && num != 0){

		if(num == 1)
			cout << 1 << endl;
		else
			cout << look[num] << endl;
		// //Brute Force to find pattern
		// all.clear();
		// REP(i,1,num+1){
		// 	all.push_back(i);
		// }
		// int flag = 1;
		// while(all.size() > 1){
		// 	REP(i,0,all.size()){
		// 		cout << all[i] << " ";
		// 	}
		// 	cout << endl;
		// 	if(flag){
		// 		all.erase(all.begin());
		// 		flag = 0;
		// 	}
		// 	else{
		// 		int tmp = *all.begin();
		// 		all.erase(all.begin());
		// 		all.push_back(tmp);
		// 		flag = 1;
		// 	}
		// }
		// cout << all[0] << endl;



		
	}
	return 0;
}
