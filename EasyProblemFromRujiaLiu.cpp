//UVA 11991
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int main (){
	int ele, qu;


	while (cin >> ele >> qu){
		map<int, vector<int> > m;
		for (int i = 1; i <= ele; i++){
			int num;
			cin >> num;
			if (m.find(num) == m.end()){
				vector<int> def;
				def.push_back(i);
				m.insert(pair<int, vector<int> > (num, def));

			}else{
				m[num].push_back(i);
			}

		}
		for (int i = 0; i < qu; i++){
			int oc, in;
			cin >> oc >> in;
			auto it = m.find(in);
			if (it != m.end()){
				if (oc <= (*it).second.size()){
					cout << ((*it).second)[oc-1] << endl;
				}
				else{
					cout << 0 << endl;
				}
			}
			else{
				cout << 0 << endl;
			}


		}


	}



	return 0 ;
}