/*
 *  HackerRank University CodeSprint 2 C
 *  Created by Ziyi Tang
 *  Prefix Sum and Binary Search
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> a;
vector<ll> b;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int g;
    cin >> g;
    while(g--){
        a.clear();
        b.clear();
        int al,bl; ll m;
        cin >> al >> bl >> m;
        a.push_back(0);
        b.push_back(0);
        for(int i = 1; i <= al; i++){
            ll tmp;
            scanf("%lld", &tmp);
            a.push_back(tmp);
            a[i] += a[i-1];
        }
        for(int i = 1; i <= bl; i++){
            ll tmp;
            scanf("%lld", &tmp);
            b.push_back(tmp);
            b[i] += b[i-1];
        }
        int maxp = 0;
        for(int i = 0; i <= al; i++){
            if(a[i] > m) break;
            int rem = m-a[i];
            auto bb = upper_bound(b.begin(), b.end(), rem);
            int bi  = distance(b.begin(), bb);
            bi--;
            maxp = max(maxp, i+bi);
        }
        cout << maxp << endl;
    }
    return 0;
}
