/*
 *	
 *	Created by Ziyi Tang
 *
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

int M, S;
int dp[310][310];
int con[45], info[45];

int cc(int cp, int ip){
	if ( sqrt(cp*cp + ip*ip) > S){
		return INF;
	}
	if ( sqrt(cp*cp + ip*ip) == S){
		return 0;
	}
	if (dp[cp][ip] != -1)
		return dp[cp][ip];
	else{
		int mincc = INF;
		for (int k = 0; k < M; k++){
			//cout << mincc << endl;
			mincc = min(mincc, cc(cp + con[k], ip + info[k]));
		}
		return dp[cp][ip] = 1 + mincc;
	}

}
int main(){
	int n;
	scanf("%d", &n);
	while (n--){
		memset(dp, -1, sizeof(dp));
		scanf("%d %d", &M, &S);
		for (int i = 0; i < M; i++){
			scanf("%d %d", &(con[i]), &(info[i]));
		}
		int re = cc(0, 0);
		if (re >= INF)
			printf("not possible\n");
		else
			printf("%d\n", re);
		
	}





	return 0;
}
