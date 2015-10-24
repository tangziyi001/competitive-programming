/*
 *	Aizu 0019
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

ll re(int a){
	if (a == 1){
		return 1;
	}
	else{
		return a*re(a-1);
	}
}
int main(){

	ll a;
	cin >> a;
	ll b = re(a);
	cout << b << endl;


	return 0;
}
