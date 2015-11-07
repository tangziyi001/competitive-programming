/*
 *	uva 10189
 *	Created by Ziyi Tang
 *	
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cstdlib>
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
const int dir[8][2] = {{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

char grid[110][110];
int m,n;
bool check(int r, int c){
	if (r >= 0 && r < m && c >= 0 && c < n)
		return true;
	return false;
}
int main(){
	string line;
	int yy = 0;
	while (cin >> m >> n && m != 0 && n != 0){
		if (yy != 0){
			cout << endl;
			yy++;
		}
		else{
			yy++;
		}
		getchar();
		REP(i,0,m){
			getline(cin, line);
			REP(j,0,n){
				grid[i][j] = line[j];
			}
		}
		REP(i,0,m){
			REP(j,0,n){
				if (grid[i][j] == '.'){
					int count = 0;
					REP(k,0,8){
						int tx = i + dir[k][0];
						int ty = j + dir[k][1];
						if (check(tx,ty) && grid[tx][ty] == '*')
							count++;

					}
					string a;
					a = to_string(count);
					grid[i][j] = a[0];
				}
				
			}
		}
		cout <<"Field #" << yy << ":" << endl;
		REP(i,0,m){
			REP(j,0,n){
				cout << grid[i][j];
			}
			cout << endl;
		}
	}





	return 0;
}
