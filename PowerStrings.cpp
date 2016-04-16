/*
 *
 *	Created by Ziyi Tang
 *
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;
int re;
bool check(string a, string tmp, int asz, int tsz){

	if (asz % tsz != 0){
		return false;
	}
	else{
		int num = asz/tsz;
		for (int i = 0; i < num; i++){
			if (a.substr(i*tsz, tsz) != tmp){
				return false;
			}
		}
		re = num;
		return true;
	}

}
int main(){
	string a;
	while (cin >>a &&  a != "."){
		int count = 0;
		int sz = a.size();
		string tmp = "";
		for (int i = 0; i < sz; ++i){
			tmp.append(1, a[i]);
			if (sz % (i+1) != 0){
				continue;
			}
			re = 0;
			bool ch = check(a, tmp, sz, i+1);
			if (ch == true){
				if (re > count){
					count = re;
				}
			}
		}
		printf("%d\n" ,count);
	}

	return 0;
}