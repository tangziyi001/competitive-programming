/*
 *	POJ 1129
 *	Created by Ziyi Tang
 *	Graph Coloring with Brute Force
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
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

map<char,int> str;
vvi all;
int color[30];
int mark[30];
int maxp = 0;

void coloring(int i){
		memset(mark, 0, sizeof(mark));
		int sz = (all[i]).size();
		for (int j = 0; j < sz; j++){
			if (color[all[i][j]] != -1){
				mark[color[all[i][j]]] = 1;
			}
		}
		for (int k = 0; k < 30; k++){
			if (mark[k] == 0){
				color[i] = k;
				maxp = max(maxp, k+1);
				break;
			}
		}

}
int main(){
	string nums;
	for (int i = 65; i <= 90; i++){
		char le = (char)i;
		str.insert(make_pair(le, i-65));
	}

	while (getline(cin, nums) && nums != "0"){
		maxp = 0;
		stringstream ss(nums);
		int num;
		ss >> num;
		memset(color, -1, sizeof(color));
		all.clear();
		for (int i = 0; i < num; i++){
			vector<int> tm;
			all.push_back(tm);
			string line;
			getline(cin,line);
			int sz = line.size();
			int source = str[line[0]];
			for (int j = 0; j < sz; j++){
				if (j == 0 || j == 1) continue;
				int tmp = str[line[j]];
				all[source].push_back(tmp);
			}
		}
		for (int i = 0; i < num; i++){

			coloring(i);
		}


		if (maxp == 1)
			cout << maxp << " channel needed." << endl;
		else
			cout << maxp << " channels needed." << endl;
	
		
	}





	return 0;
}
