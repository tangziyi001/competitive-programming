/*
 *	UVA 334
 *	Created by Ziyi Tang
 *	
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
#define MAXN 300

map<string,int> strint;
vector<string> intstr;
vpi rec;
int all[MAXN][MAXN];

int main(){
	int test = 0;
	string sta,ter;
	int n;
	while(cin >> n && n != 0){
		strint.clear();
		intstr.clear();
		rec.clear();
		test++;
		int item = 0;
		FILL(all,0);
		int idx = 0;
		int cas;
		string tmp;
		REP(i,0,n){
			cin >> cas;
			int flag = 0;
			REP(j,0,cas){
				item+=1;
				cin >> tmp;
				strint[tmp] = idx;
				intstr.push_back(tmp);
				if(flag != 0)
					all[idx-1][idx] = 1;
				else
					flag = 1;
				idx++;
			}
		}
		cin >> cas;
		REP(i,0,cas){
			cin >> sta >> ter;
			all[strint[sta]][strint[ter]] = 1;
		}


		REP(k,0,item) REP(i,0,item) REP(j,0,item){
			all[i][j] |= (all[i][k] & all[k][j]);
			if(i == j) all[i][j] = 1;
		}

		int re = 0;
		REP(i,0,item){
			REP(j,i,item){
				all[i][j] |= all[j][i];
				if(all[i][j] == 0){
					re++;
					rec.push_back(make_pair(i,j));
				}
			}
		}
		//test
		// REP(i,0,item){
		// 	REP(j,0,item){
		// 		cout << all[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		
		if(re == 0)
			printf("Case %d, no concurrent events.\n",test);
		else{
			printf("Case %d, %d concurrent events:\n",test,re);
			if(re == 1)
				cout << "(" << intstr[rec[0].first] << "," << intstr[rec[0].second] << ")" << " " << endl;
			else if(re > 1)
				cout << "(" << intstr[rec[0].first] << "," << intstr[rec[0].second] << ")" << " " <<
						"(" << intstr[rec[1].first] << "," << intstr[rec[1].second] << ")" << " " <<endl;
		}
	}

	return 0;
}
