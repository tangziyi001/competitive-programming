/*
 *	CodeForces 122A
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

int all[1005];

int main(){
	memset(all,0,sizeof(all));
	int num;
	cin >> num;
	vi di;
	all[4] = 1;
	di.push_back(4);
	all[7] = 1;
	di.push_back(7);
	all[44] = 1;
	di.push_back(44);
	all[47] = 1;
	di.push_back(47);
	all[74] = 1;
	di.push_back(74);
	all[77] = 1;
	di.push_back(77);
	all[444] = 1;
	di.push_back(444);
	all[447] = 1;
	di.push_back(447);
	all[474] = 1;
	di.push_back(474);
	all[477] = 1;
	di.push_back(477);
	all[744] = 1;
	di.push_back(744);
	all[747] = 1;
	di.push_back(747);
	all[774] = 1;
	di.push_back(774);
	all[777] = 1;
	di.push_back(777);
	int sz = di.size();
	bool yes = false;
	for (int i = 0; i < sz; i++){
		if(num % di[i] == 0){
			yes = true;
		}
	}
	if (yes == true){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}





	return 0;
}
