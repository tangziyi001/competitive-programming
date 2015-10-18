/*
 *	UVA 357
 *	Created by Ziyi Tang
 *	Basic Coin Change (Counting Ways)
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

ll all[10][30050];

const int money[] = {1,5,10,25,50};
// Counting The number of coins
// int cc(int rem){
// 	if (rem < 0){
// 		return INF;
// 	}
// 	if (rem == 0){
// 		return all[rem] = 0;

// 	}
// 	if (all[rem] != -1){
// 		return all[rem];
// 	}
// 	else{
// 		int mincc = INF;
// 		for (int i = 0; i < 5; i++){
// 			mincc = min(mincc, cc(rem - money[i]));
// 		}
// 		return all[rem] = 1 + mincc;
// 	}
// }


// Counting the number of combinations
ll ccw(int i, int rem){
	if (rem == 0)
		return 1;
	if (rem < 0)
		return 0;
	if (i >= 5)
		return 0;
	if (all[i][rem] != -1)
		return all[i][rem];
	else
		return all[i][rem] = ccw(i+1, rem) + ccw(i, rem - money[i]);
}

int main(){
	int value;
	memset(all, -1, sizeof(all));
	while(scanf("%d",&value) != EOF){
		
		ll re = ccw(0, value);
		if(re == 1)
			printf("There is only 1 way to produce %d cents change.\n", value);
		else
			printf("There are %lld ways to produce %d cents change.\n", re, value);

	}



	return 0;
}
