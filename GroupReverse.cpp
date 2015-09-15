#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int a;
    char b[101];
    while (cin >> a >> b){
        int n = strlen(b) / a;
        for (int i = 0; i < a; ++i){
        	reverse(&b[i * n], &b[i * n + n]);
        }
        cout << b << endl;
    }


return 0;
}