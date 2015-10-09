//UVA 10855
// 2D Square Rotation
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define con 100
typedef vector<vector<int> > vv;


int big[con][con];
int small0[con][con];
int small1[con][con];
int small2[con][con];
int small3[con][con];

bool check(int bi[][con], int sm[][con], int a, int b, int sr, int sc){
	for (int k = sr; k < b+sr; k++){
		for (int t = sc; t < b+sc; t++){
			if (sm[k-sr][t-sc] != bi[k][t]){
				return false;
			}
		}
	}
	return true;
}
int main(){
	int a, b;
	
	while (cin >> a >> b && a != 0 && a != 0){
		
		
		for (int i = 0; i < a; i++){
			for (int j = 0; j < a; j++){
				char tmp;
				cin >> tmp;
				big[i][j] = tmp;
			}
		}
		for (int i = 0; i < b; i++){
			for (int j = 0; j < b; j++){
				char tmp;
				cin >> tmp;
				small0[i][j] = tmp;
				small1[j][b-i-1] = tmp;
				small2[b-i-1][b-j-1] = tmp;
				small3[b-j-1][i] = tmp;
			}
		}


		int flag0, flag1, flag2, flag3;
		flag0 = 0;
		flag1 = 0;
		flag2 = 0;
		flag3 = 0;
		if (a >= b){
			for (int i = 0; i < a-b+1; i++){

				for (int j = 0; j < a-b+1; j++){
					if (check(big, small0, a, b, i, j)){
						flag0++;
					}
					if (check(big, small1, a, b, i, j)){
						flag1++;
					}
					if (check(big, small2, a, b, i, j)){
						flag2++;
					}
					if (check(big, small3, a, b, i, j)){
						flag3++;
					}
				}
			}
		}
		cout << flag0 << " " << flag1 << " " << flag2 << " " << flag3 << endl;

	}




	return 0;
}