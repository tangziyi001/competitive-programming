/*
 *	UVA 00104
 *	Created by Ziyi Tang
 *	A 3D DP with Floyd Warshall. Use DP to record the biggest product value 
 *	for each round of exchange. Terminate the loop after n round.
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
#define MAXN 25


double all[MAXN][MAXN][MAXN];
int path[MAXN][MAXN][MAXN];
double tmp;

void printPath(int sta, int ter, int lev){
	if(lev == 0)
		cout << sta+1;
	else{
		printPath(sta,path[sta][ter][lev], lev-1);
		cout << " " << path[sta][ter][lev]+1;
	}

}
int main(){
	int n;
	while(cin >> n){
		FILL(all,0);
		FILL(path,0);
		REP(i,0,n){
			REP(j,0,n){
				if(i == j){
					all[i][j][0] = 1.0;
				}
				else{
					cin >> tmp;
					all[i][j][0] = tmp;
				}
				path[i][j][0]=j;
			}
		}
		// REP(i,0,n){
		// 	REP(j,0,n){
		// 		cout << all[i][j][0] << " ";
		// 	}
		// 	cout<< endl;
		// }
		bool flag = false;
		int val, lev;
		REP(t,1,n+1){
			REP(k,0,n){
				REP(i,0,n){
					REP(j,0,n){
						if(all[i][k][t-1]*all[k][j][0] > all[i][j][t]){
							all[i][j][t] = (double)all[i][k][t-1]*all[k][j][0];
							path[i][j][t] = k;
						}
					}
				}
			}
				// // Test
				// REP(i,0,n){
				// 	REP(j,0,n){
				// 		cout << all[i][j][t] << " ";
				// 	}
				// 	cout<< endl;
				// }
				// REP(i,0,n){
				// 	REP(j,0,n){
				// 		cout << path[i][j][t] << " ";
				// 	}
				// 	cout<< endl;
				// }

				REP(i,0,n){
					if(all[i][i][t] >= 1.01){
						val = i; lev = t;
						flag=true;
						break;
					}
				}
			
			if(flag == true)
				break;

		}
		if(flag == false)
			cout <<"no arbitrage sequence exists" << endl;
		else{
			printPath(val,val,lev);
			cout << " " << val+1 << endl;
		}


	}

	return 0;
}
