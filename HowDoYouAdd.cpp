// UVA 10943
// n+k-1 choose k-1

#include <iostream>
#include <vector>

using namespace std;
long main(){
	long long c;
	long long k;
	while (cin >> c >> k && c != 0 && k != 0){
		
			int nom = 0;
			int s =  c + k - 1;
			nom = s;
			int count = 1;
			while (count < k){
				nom = nom * (s-1);
				s -= 1;
				count += 1;

			}
			int dno = 0;
			int m = k - 1;
			while (m > 1){
				dno = dno * (m-1);
				m -= 1;
			}

			cout << (nom/dno)%1000000 << endl;
		
	}




}

