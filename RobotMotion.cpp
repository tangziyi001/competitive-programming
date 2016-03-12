/*
 *	UVA 10116
 *	Created by Ziyi Tang
 *	Implementation
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
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
#define MAXN 1000

char all[15][15];
int mark[15][15];
int n,m,s;
bool check(int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}
int main(){
	while(cin >> n >> m >> s && (n!=0 || m!=0 || s!=0)){
		FILL(mark,-1);
		getchar();
		string line;
		REP(i,0,n){
			getline(cin, line);
			REP(j,0,m){
				all[i][j] = line[j];
			}
		}
		// REP(i,0,n){
		// 	REP(j,0,m){
		// 		cout << all[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		int x = 0;
		int y = s-1;
		mark[x][y] = 0;
		int cont = 0;
		int flag = -1;
		while(check(x,y) && flag == -1){
			cont++;
			int dd = 0;
			if(all[x][y] == 'N')
				dd = 0;
			if(all[x][y] == 'E')
				dd = 1;
			if(all[x][y] == 'S')
				dd = 2;
			if(all[x][y] == 'W')
				dd = 3;
			int tx = x + dir[dd][0];
			int ty = y + dir[dd][1];
			if(!check(tx,ty)) break;
			if(mark[tx][ty] == -1)
				mark[tx][ty] = mark[x][y]+1;
			else{
				flag = mark[x][y]+1-mark[tx][ty];
				break;
			}
			x = tx; y = ty;
		}
		// REP(i,0,n){
		// 	REP(j,0,m){
		// 		cout << mark[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		if(flag == -1)
			printf("%d step(s) to exit\n",cont);
		else printf("%d step(s) before a loop of %d step(s)\n",cont-flag,flag);
	}
	return 0;
}

