/*
 *	Aizu 0025
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
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int A[4];
int B[4];
int main(){
	string line;
	while(getline(cin, line) && line != ""){
		stringstream ss(line);
	int hit = 0;
	int blow = 0;
	set<int> all;
	int tmp;
	for (int i = 0; i < 4; i++){
		ss >> tmp;
		A[i]= tmp;
		all.insert(tmp);
	}
	getline(cin,line);
	stringstream se(line);
	for (int i = 0; i < 4; i++){
		se >> tmp;
		B[i]= tmp;
	}
	for (int i = 0; i < 4; i++){
		if (A[i] == B[i]){
			hit++;
		}
		else{
			if (all.find(B[i]) != all.end()){
				blow++;
			}
		}
	}
	cout << hit << " " << blow << endl;
	}




	return 0;
}
