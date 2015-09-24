#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int [105][105] matrix;

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int k = 0; k < n; k++){
			cin >> matrix[i][k];
		}
	}
	int big = 0;
	

	for (int i = 0; i < n; i++){
		
		int tmp = matrix[i];
		int sum = tmp;
		if (tmp > big){
			big = tmp;
		}
		for (int j = i + 1; j < n; j++){
			sum = sum + matrix[j];
			
		}
	}





	return 0;
}