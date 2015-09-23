//UVA 11988
// The usage of list (its iterator) and cstdio
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <list>
using namespace std;

int main(){
	char a[100000];
	
	while (gets(a)){
		list<char> buf;
		list<char> :: iterator it = buf.begin();
		int len = strlen(a);
		for (int i = 0; i < len; ++i){
			if (a[i] == '['){
				it = buf.begin();
			}
			else if(a[i] == ']'){
				it = buf.end();
			}
			else{
				buf.insert(it, a[i]);
				
			}
		}

		for (it = buf.begin(); it != buf.end(); ++it){
			printf("%c", *it);
		}
		puts("");

	}
	return 0;
}