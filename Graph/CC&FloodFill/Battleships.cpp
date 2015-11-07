/*
 *	UVA 11593
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

int N;
char grid[110][110];
int mark[110][110];
int check(int r, int c){
	if (r >= 0 && r < N && c >= 0 && c < N)
		return true;
	return false;
}
void dfs(int r, int c){
	mark[r][c] = 1;
	for (int i = 0; i < 4; i++){
		int tx = r + dir[i][0];
		int ty = c + dir[i][1];
		if (check(tx,ty) && mark[tx][ty] == 0 && grid[tx][ty] == 'x'){
			dfs(tx,ty);
		}
	}
}
int main(){
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++){
		FILL(mark,0);
		cin >> N;
		string line;
		REP(i,0,N){
			getline(cin,line);
			REP(j,0,N){
				grid[i][j] = line[j];
			}
		}
		REP(i,0,N){
			REP(j,0,N){
				if (grid[i][j] == '@'){
					grid[i][j] = '.';
					for (int k = 0; k < 4; k++){
						int tx = i + dir[k][0];
						int ty = j + dir[k][1];
						if (check(tx,ty) && grid[tx][ty] == 'x')
							grid[i][j] = 'x';
					}
				}
			}
		}

		int count = 0;
		REP(i,0,N){
			REP(j,0,N){
				if (grid[i][j] == 'x' && mark[i][j] == 0){
					dfs(i,j);
					count++;
				}
			}
		}

		printf("Case %d: %d", t, count);
	}

	return 0;
}
