/*
 *	UVA 11831
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
#define INFL (long)1E18
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

int grid[110][110];
bool bound(int tx, int ty, int gx, int gy){
	if (tx >= 0 && tx < gx && ty >= 0 && ty < gy)
		return true;
	else
		return false;
}
int main(){
	int n,m,s;
	while(scanf("%d %d %d",&n,&m,&s) && n != 0 && m != 0 && s != 0){
		getchar();
		pi start;
		char ini;
		FILL(grid,-1);
		REP(i,0,n){
			string line;
			getline(cin, line);
			REP(j,0,m){
				grid[i][j] = line[j];
				if (line[j] == 'N' || line[j] == 'S' || line[j] == 'L' || line[j] == 'O'){
					start = make_pair(i,j);
					ini = line[j];
				}
			}
		}
		int drct;
		if (ini == 'N')
			drct = 0;
		if (ini == 'S')
			drct = 2;
		if (ini == 'L')
			drct = 3;
		if (ini == 'O')
			drct = 1;
		string ins;
		getline(cin, ins);
		int sz = ins.size();
		int x = start.first;
		int y = start.second;
		int count = 0;
		REP(i,0,sz){
			if (ins[i] == 'F'){
				int tx = x+dir[drct][0];
				int ty = y+dir[drct][1];
				if (!bound(tx,ty,n,m) || grid[tx][ty] == '#'){
					continue;
				}
				else{
					if (grid[tx][ty] == '*'){
						count++;
						grid[tx][ty] = '.';
					}
					x = tx;
					y = ty;
				}
			}
			else if(ins[i] == 'E'){
				drct += 1;
				drct %= 4; 
			}
			else{
				drct += 4;
				drct -= 1;
				drct %= 4;
			}
			
		}

		cout << count << endl;
	}
	return 0;
}
