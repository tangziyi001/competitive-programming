//UVA 10038
// 1D Array Mark

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int mark[3050];
int main(){
	int len;
	while (cin >> len){
		memset(mark,0,sizeof(mark));
		if (len == 0){
			continue;
		}
		if (len == 1){
			int num;
			cin >> num;
			cout << "Jolly" << endl;
			continue;
		}
		else{
			int num;
			int pre = 0;
			int clen = len;
			cin >> pre;
			len -= 1;
			while (len--){
				cin >> num;
				int tmp = (num - pre) >= 0 ? (num-pre) : (pre-num);
				mark[tmp] = 1;
				pre = num;
			}
			int flag = true;
			for (int i = 1; i < clen; i++){
				if (mark[i] != 1){
					flag = false;
					break;
				}
			}
			if (flag == true){
				cout << "Jolly" << endl;
			}
			else{
				cout << "Not jolly" << endl;
			}
		}
	}



	return 0;
}