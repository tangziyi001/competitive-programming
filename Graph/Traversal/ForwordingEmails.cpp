/*
 *	UVA 12442
 *	Created by Ziyi Tang
 *	DFS with cache
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
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

int mark[50100];
int sta[50100];
int all[50100];

int dfs(int i){ 
	if (mark[i] == 1){
		return 0;
	}
	int count = 1;
	mark[i] = 1;
	count += dfs(all[i]);
	mark[i] = 0;
	return sta[i] = count;      
}
int main(){
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++){
		FILL(sta,-1);
		int num;
		scanf("%d", &num);
		int source, det;
		for (int i = 0; i < num; i++){
			mark[i+1] = 0;
			scanf("%d %d", &source, &det);
			all[source] = det;
		}
		int count = 0;
		int maxp = 0;
		int re;
		REP(i,1,num+1){

			if (sta[i] == -1){	
				count = dfs(i);
				//cout << "Count " << count << endl;
			}
			if (sta[i] > maxp){
				maxp = count;
				re = i;
			}
			
		}
		printf("Case %d: %d\n", t, re);
	}





	return 0;
}
