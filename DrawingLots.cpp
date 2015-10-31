/*
 *	Aizu 0011
 *	Created by Ziyi Tang
 *	Basic Array Operation
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

int all[35];
int main(){
	int v,h;
	cin >> v >> h;
	for (int i = 1; i <= v; i++){
		all[i] = i;
	}
	int a,b;
	for (int i = 0; i < h; i++){
		scanf("%d,%d",&a,&b);
		int tmp = all[a];
		all[a] = all[b];
		all[b] = tmp;
	}
	for (int i = 1; i <= v; i++){
		cout << all[i] << endl;
	}






	return 0;
}
