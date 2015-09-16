//UVA 514
#include <iostream>
using namespace std;

int main(){
	int num;
	while (cin >> num && num != 0){
		int tmp1, tmp2;
		int tmp2x;
		while (cin >> tmp1 && tmp1 != 0){
			tmp2x = tmp1;
			int judge = 1;
			for (int i = 2; i <= num ; ++i){
			cin >> tmp2;
				if (tmp2 < tmp2x){
					tmp2x = tmp2;
					continue;
				}
				else{
					if (tmp2 < tmp1){
						judge = 0;
						
					}
					else{
						tmp1 = tmp2;
						tmp2x = tmp1;
						continue;
					}
				}
			}
			if (judge == 1){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}
		cout << endl;
	}


	return 0;
}