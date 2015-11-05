/*
 *	UVA 1103
 *	Created by Ziyi Tang
 *	Advanced DFS
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

int grid[250][250];
int mark[250][250];
int color, black;
set<int> neighbor;
int h,w;
vi all;
string htob(char a){
	if (a == '0')	return "0000";
	if (a == '1') 	return "0001";
	if (a == '2')  	return "0010";
	if (a == '3')	return "0011";
	if (a == '4')	return "0100";
	if (a == '5')	return "0101";
	if (a == '6')	return "0110";
	if (a == '7')	return "0111";
	if (a == '8')	return "1000";
	if (a == '9')	return "1001";
	if (a == 'a')	return "1010";
	if (a == 'b')	return "1011";
	if (a == 'c')	return "1100";
	if (a == 'd')	return "1101";
	if (a == 'e')	return "1110";
	if (a == 'f')	return "1111";
	else 
		return "-1-1-1-1";
}

bool check(int x, int y){
	if (x >= 0 && x <= h+1 && y >=0 && y <= 4*w+1)
		return true;
	return false;
}
void dfs_w(int x, int y, int color){
	mark[x][y] = color;
	for (int i = 0; i < 4; i++){
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (mark[tx][ty] == -1 && grid[tx][ty] == 0 && check(tx,ty)){
			dfs_w(tx,ty,color);
		}
	}
}
void dfs_b(int x, int y, int black){
	mark[x][y] = black;
	int count = 0;
	for (int i = 0; i < 4; i++){
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (mark[tx][ty] == -1 && grid[tx][ty] == 1 && check(tx,ty)){
			dfs_b(tx,ty,black);
		}
		else if (grid[tx][ty] == 0 && check(tx,ty)){
			neighbor.insert(mark[tx][ty]);
		}
	}
}
int main(){
	int test = 1;

	while (cin >> h >> w && h != 0 && w != 0){
		getchar();
		FILL(grid,0);
		FILL(mark,-1);
		all.clear();
		string line;
		for (int i = 1; i <= h; i++){
			getline(cin, line);
			for (int j = 1; j <= w; j++){
				string tmp = htob(line[j-1]);
				for (int k = 0; k < 4; k++){
					grid[i][(j-1)*4+1+k] = stoi(tmp.substr(k,1));
				}
			}
		}
		color = 0;
		black = 0;
		for (int i = 0; i <= h+1; i++){
			for (int j = 0; j <= 4*w+1; j++){
				if (mark[i][j] == -1 && grid[i][j] == 0){
					dfs_w(i,j,color);
					color++;
				}
			}
		}
		for (int i = 0; i <= h+1; i++){
			for (int j = 0; j <= 4*w+1; j++){
				if (mark[i][j] == -1 && grid[i][j] == 1){
					neighbor.clear();
					int num = 0;
					dfs_b(i,j,black);
					num = neighbor.size();
					all.push_back(num);
					black++;
				}
			}
		}

		vector<char> re;

		int sz = all.size();
		for (int i = 0; i < sz; i++){
			int amount = all[i];
			if (amount == 1) re.push_back('W');
			if (amount == 2) re.push_back('A');
			if (amount == 3) re.push_back('K');
			if (amount == 4) re.push_back('J');
			if (amount == 5) re.push_back('S');
			if (amount == 6) re.push_back('D');
		}

		sort(re.begin(),re.end());
		sz = re.size();
		cout << "Case " << test << ": ";
		for (int i = 0; i < sz; i++){
			cout << re[i];
		}
		test++;
		cout << endl;
		// Test
		// cout << endl;
		// for (int i = 0; i <= h+1; i++){
		// 	for (int j = 0; j <= 4*w+1; j++){
		// 		cout << grid[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		// cout << endl;
		// for (int i = 0; i <= h+1; i++){
		// 	for (int j = 0; j <= 4*w+1; j++){
		// 		cout << mark[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		


	}




	return 0;
}
