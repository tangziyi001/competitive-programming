/*	
 *	UVA 10755
 *	Created by Ziyi Tang
 *	Modular Arithmetic, Big Integer
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
#define INF 1E9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};


int main(){
	ll a, b, n;
	while(cin >> n && n != 0){
		cin >> a >> b;
		map<ll,int> all;
		ll count = n;
		ll cur = 0;
		while (1){
			all[cur] += 1;
			if (all[cur] == 2){
				count--;
			}
			else if(all[cur] == 3){
				break;
			}
			ll square = ((cur%n) * (cur%n))%n;
			ll mul = ((a%n) * (square%n))%n;
			ll next = (mul%n + b%n + n)%n;
			cur = next;
		}
		cout << count << endl;
		
	}



	return 0;
}
