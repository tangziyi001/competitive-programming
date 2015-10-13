//UVA10755
// 2D Max and Kadane's Algorithm, Prefix Sum, Big Number

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

ll sum[25][25][25];
int main(){
	int test;
	cin >> test;
	int a,b,c;
	while (test--){
		memset(sum,0,sizeof(sum));
		cin >> a >> b >> c;
		for (int i = 1; i <= a; i++){
			for (int j = 1; j <= b; j++){
				for (int k = 1; k <= c; k++){
					ll newtmp;
					cin >> newtmp;
					sum[i][j][k] = newtmp;
					if (k == 1 && j == 1){
						sum[i][j][k] = sum[i][j][k];
					}
					else if(k == 1){
						sum[i][j][k] += sum[i][j-1][k];
					}
					else if(j == 1){
						sum[i][j][k] += sum[i][j][k-1];
					}
					else{
						sum[i][j][k] += (sum[i][j-1][k] + sum[i][j][k-1] - sum[i][j-1][k-1]);
					}
					
				}
			}
		}
		ll total = -INF;
		
		
		for (int k = 1; k <= c; k++){
			for (int j = 1; j <= b; j++){
				for (int tk = k; tk <= c; tk++){
					for (int tj = j; tj <= b; tj++){
						ll tmpsum = -INF;
						ll tmp = 0;
						for (int i = 1; i <= a; i++){
							tmp += (sum[i][tj][tk] - sum[i][j-1][tk] - sum[i][tj][k-1] + sum[i][j-1][k-1]);
							if (tmp > tmpsum){
								tmpsum = tmp;
							}
							if (tmp < 0){
								tmp = 0;
							}
						}
						if (tmpsum > total){
							total = tmpsum;
						}
					}
				}
				
			}
		}
		cout << total << endl;

		// test
		// for (int i = 1; i <= a; i++){
		// 	for (int j = 1; j <= b; j++){
		// 		for (int k = 1; k <= c; k++){
		// 			cout << sum[i][j][k];
		// 		}
		// 		cout << endl;
		// 	}
		// 	cout << endl;
		// 	cout << endl;
		// }
		if (test != 0){
			cout << endl;
		}
	}





	return 0;
}
