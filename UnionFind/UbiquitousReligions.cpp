/*
 *	POJ 2524
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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int all[50010];
int p[50010];
int depth[50010];

// Union Find
int findRep(int i){
	if (p[i] == i){
		return i;
	}
	else{
		return p[i] = findRep(p[i]);
	}
}
int isSameSet(int i, int j){
	return findRep(i) == findRep(j);
}
void unionSet(int i, int j){
	i = findRep(i);
	j = findRep(j);
	if (depth[i] < depth[j]){
		p[i] = j;
	}
	else if (depth[i] > depth[j]){
		p[j] = i;
	}
	else{
		p[j] = i;
		depth[i]++;
	}
}
int main(){
	int num, lines;
	int test = 0;
	while (scanf("%d %d",&num, &lines) && num != 0 && lines != 0){
		test++;
		for (int i = 1; i <= num; i++){
			all[i] = i;
			p[i] = i;
			depth[i] = 0;
		}
		int count = 0;
		for (int i = 0; i < lines; i++){
			int a,b;
			scanf("%d %d",&a, &b);
			unionSet(a,b);
		}
		for (int i = 1; i <= num; i++){
			if (findRep(i) == i){
				count++;
			}
		}
		printf("Case %d: %d\n", test, count);
	}




	return 0;
}
