//UVA 11340
#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
typedef map<char,int> mp;

int main(){
	int test;
	cin >> test;
	while (test--){
		mp a;
		int n;
		cin >> n;
		while (n--){
			char k;
			int v;
			cin >> k >> v;
			a[k] = v;
		}
		int m;
		cin >> m;
		getchar();
		int sum = 0;
		string word;
		while (m--){
			getline(cin,word);
			int sz = word.size();
			for (int i = 0; i < sz; i++){
				auto it = a.find(word[i]);
				if (it != a.end()){
					sum += (*it).second;
				}
			}
		}
		printf("%0.2f$\n",(double)sum/100);
	}



	return 0;
}