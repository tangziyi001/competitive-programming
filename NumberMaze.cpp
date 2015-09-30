//UVA 929
// First try of Dijkstra Algorithm
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
int maze[1001][1001];
int dp[1001][1001];
set<PP> in;
set<PP> compare;
// Initiate variables above in main method

int check(int f, int s, int gf, int gs){
		if (f == gf && s == gs){
			return dp[f][s];
		}
	
		if (f+1 <= gf && in.find(make_pair(f+1,s)) == in.end()){
			if (dp[f+1][s] == -1 || dp[f][s] + maze[f+1][s] < dp[f+1][s]){
				dp[f+1][s] = dp[f][s] + maze[f+1][s];
				compare.insert(make_pair(f+1,s));
			}
		}
		if (f-1 >= 1 && in.find(make_pair(f-1,s)) == in.end()){
			if (dp[f-1][s] == -1 || dp[f][s] + maze[f-1][s] < dp[f-1][s]){
				dp[f-1][s] = dp[f][s] + maze[f-1][s];
				compare.insert(make_pair(f-1,s));
			}
		}
		if (s+1 <= gs && in.find(make_pair(f,s+1)) == in.end()){
			if (dp[f][s+1] == -1 || dp[f][s] + maze[f][s+1] < dp[f][s+1]){
				dp[f][s+1] = dp[f][s] + maze[f][s+1];
				compare.insert(make_pair(f,s+1));
			}
		}
		if (s-1 >= 1 && in.find(make_pair(f,s-1)) == in.end()){
			if (dp[f][s-1] == -1 || dp[f][s] + maze[f][s-1] < dp[f][s-1]){
				dp[f][s-1] = dp[f][s] + maze[f][s-1];
				compare.insert(make_pair(f,s-1));
			}
		}
		
		int tmp = 100000;
		set<PP> :: iterator min = compare.end();
		for (auto it = compare.begin(); it != compare.end(); it++){
			if (dp[(*it).first][(*it).second] < tmp){
				tmp = dp[(*it).first][(*it).second];
				min = it;
			}
		}
		
		in.insert(*min);
		compare.erase(*min);
		return check((*min).first, (*min).second, gf, gs);
	
	
}

int main(){
	int test;
	scanf("%d", &test);
	while(test--){
		memset(dp, -1, sizeof(dp));
		memset(maze, -1, sizeof(maze));
		in.clear();
		in.insert(make_pair(1,1));
		compare.clear();
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
		int re = check(1,1,r,c);
		printf("%d\n",re);

	}



	return 0;
}