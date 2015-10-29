/*
 *	UVA 10337
 *	Created by Ziyi Tang
 *	Combinatorial Special DP
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

int all[10][1100];
int dp[10][1100];
int x;

bool check(int i){
	return (i >= 0 && i <= 9);
}

int recurse(int al, int mi){
	if (al == 0 && mi == x)
		return 0;
	else if(mi == x)
		return INF;
	if (dp[al][mi] != -1)
		return dp[al][mi];
	else{
		int minp = INF;
		minp = min(minp, 30-all[al][mi] + recurse(al, mi+1));
		if (check(al+1))
			minp = min(minp, 60-all[al][mi] + recurse(al+1, mi+1));
		if (check(al-1))
			minp = min(minp, 20-all[al][mi] + recurse(al-1, mi+1));
		return dp[al][mi] = minp;
	}

}
int main(){
	int test;
	scanf("%d",&test);
	for (int k = 0; k < test; k++){
		memset(dp,-1,sizeof(dp));
		scanf("%d", &x);
		x /= 100;
		int tmp;
		for (int i = 9; i >= 0; i--){
			for (int j = 0; j < x; j++){
			scanf("%d", &tmp);
			all[i][j] = tmp;
			}
		}
		// for (int i = 0; i <= 9; i++){
		// 	for (int j = 0 ; j < x; j++){
		// 		cout << all[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		int re = recurse(0, 0);

		printf("%d\n",re);
		printf("\n");
	}





	return 0;
}
