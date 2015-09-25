//UVA 108
// Sub-Matrix Maximum
// Cumulative Matrix Method

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int matrix[105][105];
int cul[105][105];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int k = 0; k < n; k++){
			cin >> matrix[i][k];
		}
	}
	for (int i = 0; i < n; i++){
		int sum = 0;
		for (int k = 0; k < n; k++){
			sum = sum + matrix[i][k];
			cul[i][k] = sum;
		}
	}

	int big = 0;
	for (int k = 0; k < n; k++){
		for (int t = -1; t < k; t++){
			for (int i = 0; i < n; i++){
				int sum = 0;
				for (int j = i; j < n; j++){
					if (k == -1){
						sum += cul[j][k];
					}else{
						sum += cul[j][k] - cul[j][t];
					}
					if (sum > big){
						big = sum;
					}
				}
			
			}
		}
		
	}
	cout << big << endl;
	return 0;
}