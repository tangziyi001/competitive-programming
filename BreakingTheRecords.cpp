/*
 *	HackerRank University CodeSprint 2 A
 *	Created by Ziyi Tang
 *	
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> all;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        all.push_back(tmp);
    }
    int maxp = all[0], minp = all[0];
    int contmax = 0, contmin = 0;
    for(int i = 1; i < n; i++){
        if(all[i] > maxp){
            maxp = all[i]; contmax++;
        }
        if(all[i] < minp){
            minp = all[i]; contmin++;
        }
    }
    cout << contmax << " " << contmin << endl;
    return 0;
}
