/*
 *	POJ 1046
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

int grid[16][3];
int main(){
	REP(i,0,16){
		REP(j,0,3){
			int tmp;
			cin >> tmp;
			grid[i][j] = tmp;
		}
	}
	int r,g,b;
	while (cin >> r >> g >> b && r != -1 && g != -1 && b != -1){
		double minp = 1E9;
		int tr, tg, tb;
		REP(i,0,16){
			double D = sqrt(double((r-grid[i][0])*(r-grid[i][0]) + (g-grid[i][1])*(g-grid[i][1]) + (b-grid[i][2])*(b-grid[i][2])));
			if (D < minp){
				minp = D;
				tr = grid[i][0]; tg = grid[i][1]; tb = grid[i][2];
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",r,g,b,tr,tg,tb);

	}





	return 0;
}
