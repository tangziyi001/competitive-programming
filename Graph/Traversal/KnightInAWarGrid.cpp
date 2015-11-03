/*
 *	UVA 11906
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
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const long INFL = (long)1E18;
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

int grid[110][110];
int mark[110][110];
queue<pi> que;


int r,c,m,n;
int check(int x, int y){
	if (x >= 0 && x < r && y >= 0 && y < c && grid[x][y] != -1)
		return true;
	return false;
}
int main(){
	int test;
	cin >> test;
	REP(t,0,test){
		int even = 0;
		int odd  = 0;
		FILL(grid,0);
		FILL(mark,0);
		while(!que.empty())
			que.pop();
		cin >> r >> c >> m >> n;
		const int dir[8][2] = {{m,n},{-m,n},{m,-n},{-m,-n},{n,m},{-n,m},{n,-m},{-n,-m}};

		int num;
		cin >> num;
		REP(k,0,num){
			int x,y;
			cin >> x >> y;
			grid[x][y] = -1;
		}
		que.push(make_pair(0,0));
		mark[0][0] = 1;
		while(!que.empty()){
			//cout << even << " " << odd << endl;
			pi a = que.front(); que.pop();
			int x = a.first;
			int y = a.second;
			int count = 0;
			if (m == 0 || n == 0 ){
				int non = (m == 0) ? n : m;
				int dir[4][2] = {{non, 0}, {-non, 0}, {0, non}, {0, -non}};
				REP(i,0,4){
					int tx = x+dir[i][0];
					int ty = y+dir[i][1];
					if (check(tx,ty)){
						count++;
						if (grid[tx][ty] == 0 && mark[tx][ty] == 0){
							mark[tx][ty] = 1;
							que.push(make_pair(tx,ty));
						}
					}
				}
			}
			else{
				REP(i,0,8){
					if (m == n && i == 4)
						break;
					int tx = x+dir[i][0];
					int ty = y+dir[i][1];
					if (check(tx,ty)){
						count++;
						if (grid[tx][ty] == 0 && mark[tx][ty] == 0){
							mark[tx][ty] = 1;
							que.push(make_pair(tx,ty));
						}
					}
				}
			}
			
			if (count > 0 && count % 2 == 0){
				even+=1;
			}
			else if (count > 0 && count % 2 == 1){
				odd+=1;
			}
			grid[x][y] = count;
			//cout << count << endl;
		}
		
		// Show the count of each cell
		// REP(i,0,r){
		// 	REP(j,0,c){
		// 		cout << grid[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		if (even == 0 && odd == 0){
			printf("Case %d: %d %d\n", t+1, 1, 0);
		}
		else
			printf("Case %d: %d %d\n", t+1, even, odd);
		


	}




	return 0;
}
