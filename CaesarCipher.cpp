/*
 *	Aizu 0017
 *	Created by Ziyi Tang
 *	Ascii Code for Letters
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


int main(){
	string line;
	while (getline(cin,line) && line != ""){
		int sz = line.size();
		while(true){
			for (int i = 0; i < sz; i++){
				if (line[i] !=  ' ' && line[i] != '.' && line[i] != EOF){
					int tmp = (int)line[i] + 1;
					while (tmp > 122){
						tmp -= 26;
					}
					line[i] = (char)tmp;
				}
			
			}
			
			stringstream ss(line);
			string ts;
			int flag = 0;
			while(ss >> ts){
				if (ts == "this" || ts == "the" || ts == "that"){
					flag = 1;
					break;
				}
			}
			if (flag == 1){
				break;
			}
		}
		cout << line << endl;
		
	}
	return 0;
}
