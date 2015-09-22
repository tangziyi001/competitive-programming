//CodeForces 544A
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	int num = 0;
	cin >> num;
	string str;
	cin >> str;
	int sz = str.size();
	if (sz >= num){
		vector<int> idx;
		set<char> head;
		string tmp;
		bool repeathead = false;
		int count = 0;
		for (int i = 0; i < sz; ++i){
			if(head.find(str[i]) != head.end()){
				continue;
			}
			else{
				count += 1;
				head.insert(str[i]);
				idx.push_back(i);
			}
			if (count == num){
				break;
			}
		}
		if (count >= num){
			cout << "YES" << endl;
			auto it2 = idx.begin();
			for (auto it = idx.begin(); it != idx.end(); ++it){
				it2 = next(it);
				if (it2 != idx.end()){
					cout << str.substr(*it, *it2 - *it) << endl;
				}
				else{
					cout << str.substr(*it) << endl;
				}
				
			}
		}
		else{
			cout << "NO"  << endl;	
		}
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}