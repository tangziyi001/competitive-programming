// Codechef BINTREE
// Created by Ziyi Tang
// Find common parent

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>

using namespace std;

map<int,int> mm;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		mm.clear();
		int a,b;
		cin >> a >> b;
		int l = 0;
		while(a != 0){
			mm[a] = l;
			l++;
			a/=2;
		}
		l = 0;
		while(b != 0){
			if(mm.find(b) != mm.end()){
				cout << mm[b] + l << endl;
				break;
			}
			l++;
			b/=2;
		}
	}

	return 0;
}