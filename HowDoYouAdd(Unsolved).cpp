// UVA 10943
// n+k-1 choose k-1

#include <iostream>
#include <vector>

using namespace std;
int main(){
	long long c;
	long long k;
	while (cin >> c >> k && (c != 0 || k != 0)){
		
			long long nom = 1;
			long long s =  c + k - 1;
			
			for (int i = 1; i <= k-1; ++i){
				nom = nom * s;
				s -= 1;
			}
			cout << nom << endl;
			long long m = k - 1;
			long long dno = 1;
			if (k == 0){
				cout << 1 << endl;
			}
			else{
				for (int i = 1; i <= k-1; i++){
					dno = dno * m;
					m -= 1;
				}
				cout << dno << endl;

				cout << (nom/dno)%1000000 << endl;
			}
			
		
	}




}

