/*
 *	UVA 272
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
#define INF 1E18
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main(){
	string line;
	bool start = true;

	while (getline(cin, line)){
		string newline;
		int sz = line.size();
		for (int i = 0; i < sz; i++){
			if (line[i] == '\"'){
				if (start == true){
					newline+="``";
					start = false;
				}
				else{
					newline+="\'\'";
					start = true;
				}
			}
			else{
				newline+=line[i];
			}

		}
		cout << newline << endl;
	}





	return 0;
}
