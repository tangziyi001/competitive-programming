//UVA 929
// First try of Dijkstra Algorithm
// Implement Dijkstra by Priority_Queue
#include <cstdio>
#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef pair<int,int> PP;
typedef pair<int,PP> PPP;
int maze[1001][1001];
int dp[1001][1001];

priority_queue<PPP> compare;

int check(int gf, int gs){
	compare.push(make_pair(-dp[1][1], make_pair(1,1)));
	while (!compare.empty()){

		PPP tmp = compare.top();compare.pop();
		PP ttmp = tmp.second;
		int f = ttmp.first;
		int s = ttmp.second;
		if(f == gf && s == gs){
			return -tmp.first;
		}
	
		if (f+1 <= gf){
			if (dp[f+1][s] == -1 || dp[f][s] + maze[f+1][s] < dp[f+1][s]){
				dp[f+1][s] = dp[f][s] + maze[f+1][s];
				compare.push(make_pair(-dp[f+1][s], make_pair(f+1,s)));
			}
		}
		if (f-1 >= 1){
			if (dp[f-1][s] == -1 || dp[f][s] + maze[f-1][s] < dp[f-1][s]){
				dp[f-1][s] = dp[f][s] + maze[f-1][s];
				compare.push(make_pair(-dp[f-1][s], make_pair(f-1,s)));
			}
		}
		if (s+1 <= gs){
			if (dp[f][s+1] == -1 || dp[f][s] + maze[f][s+1] < dp[f][s+1]){
				dp[f][s+1] = dp[f][s] + maze[f][s+1];
				compare.push(make_pair(-dp[f][s+1], make_pair(f,s+1)));
			}
		}
		if (s-1 >= 1){
			if (dp[f][s-1] == -1 || dp[f][s] + maze[f][s-1] < dp[f][s-1]){
				dp[f][s-1] = dp[f][s] + maze[f][s-1];
				compare.push(make_pair(-dp[f][s-1], make_pair(f,s-1)));
			}
		}
		
	}
	return -1;	
}

int main(){
	int test;
	scanf("%d", &test);
	for(int k = 0; k < test; k++){
		memset(dp, -1, sizeof(dp));
		memset(maze, -1, sizeof(maze));
		while(!compare.empty()){
			compare.pop();
		}
		int r,c;
		scanf("%d %d",&r,&c);
		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= c; j++){
				int tmp;
				cin >> tmp;
				maze[i][j] = tmp;
			}
			
		}
		// Make sure that the first r,c grid has initial value
		dp[1][1] = maze[1][1];
		int re = check(r,c);
		printf("%d\n",re);

	}



	return 0;
}