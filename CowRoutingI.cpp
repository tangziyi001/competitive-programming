/*
 *  USACO 2015 January Contest, Bronze 1
 *  Coded by Ziyi Tang
 *
 */
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

vector<pair<int,vector<int> > >all;
int main(){
    freopen("cowroute.in","r",stdin);
    freopen("cowroute.out","w",stdout);
    int a,b,n;
    cin >> a >> b >> n;
    for(int i = 0; i < n; i++){
        int w,d;
        cin >> w >> d;
        all.push_back(make_pair(w,vector<int>(0,0)));
        for(int j = 0; j < d; j++){
            int tmp;
            cin >> tmp;
            all[i].second.push_back(tmp);
        }
    }
    sort(all.begin(),all.end());
    int flag = -1;
    for(int i = 0; i < n; i++){
       int sz = all[i].second.size();
       int idx1 = -1, idx2 = -1;
       for(int j = 0; j < sz; j++){
            if((all[i].second)[j] == a){
                idx1 = j;
            }
            if((all[i].second)[j] == b){
                idx2 = j;
            }
       }
       if(idx1 != -1 && idx2 != -1 && idx1 < idx2){
            flag = all[i].first; break;
       }
    }
    cout << flag << endl;
}

