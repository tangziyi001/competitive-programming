#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <map>

using namespace std;
int main(){
	map<int,int> a;
	string tmp;
	while (getline(cin,tmp) && tmp != ""){
		int b = stoi(tmp);
		a[b] +=1;
	}
	int sz = a.size();
	int ma = 0;
	int flag = 0;
	while (flag == 0){
		int tmp = 0;
		int nu = 0;
		for (auto it = a.begin(); it != a.end(); it ++){
			if((*it).second > tmp){
				tmp = (*it).second;
				nu = (*it).first;
			}
		}
		if (tmp >= ma){
			cout << nu << endl;
			a[nu] = 0;
			ma = tmp;
		}else{
			flag = 1;
		}
		

	}
		
		


	return 0;
}