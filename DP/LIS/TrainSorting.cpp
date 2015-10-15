/*
 *	UVA 11456
 *	Created by Ziyi Tang
 *	Reversely calculating LIS and LDS to determine the longest sequence
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
	
	int test;
	cin >> test;
	while(test--){
		vi all(2005,0);
		vi lis(2005,0);
		vi lds(2005,0);
		int num;
		cin >> num;
		int tmp;
		int maxld = 0;
		
		for (int i = 0; i < num; i++){
			cin >> tmp;
			all[i] = tmp;
		}
		reverse(all.begin(),all.begin()+num);
		int sz = num;
		
		for (int i = 0; i < sz; i++){
			//cout << all[i] << "i" << endl;
			if (i == 0){
				lis[0] = 1;
				lds[0] = 1;
			}
			else{
				// LIS LDS
				int idx = i-1;
				int len_lis = 0;
				int len_lds = 0;
				while (idx >= 0){
					if (all[i] > all[idx]){
						//cout << "+" << endl;
						len_lis = max(lis[idx], len_lis);
						
					}
					if (all[i] < all[idx]){
						//cout << "-" << endl;
						len_lds = max(lds[idx],len_lds);
					}
					idx--;
				}
				lis[i] = 1 + len_lis;
				lds[i] = 1 + len_lds;
			}
			maxld = max(maxld,lis[i]+lds[i]);
		}
		
		if (num == 0){
			cout << 0 << endl;
		}
		else{
			cout << maxld - 1 << endl;
		}	
		
	}




	return 0;
}
