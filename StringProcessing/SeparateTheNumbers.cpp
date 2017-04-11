/*
 *  HackerRank University CodeSprint 2 B
 *  Created by Ziyi Tang
 *  String Manipulation
 */
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void process(string now){
    long long re = -1;
    for(int i = 0; i < (now.size())/2; i++){
        string tmp = now.substr(0,i+1);
        string first = tmp;
        if(tmp != "0" && tmp[0] == '0')
            break;
        int flag = 1;
        int sta = 0;
        while(1){
           // cout << sta << " " << tmp << endl;
            if(sta == now.size()) break ;
            if(sta+tmp.size()-1 >= now.size() || tmp != now.substr(sta, tmp.size())){
                flag = 0; break ;
            }
           // cout << tmp << endl;
            long long num = stoll(tmp);
            long long nxttmp = num+1;
            string nxt = to_string(nxttmp);
            sta += tmp.size();
            tmp = nxt;
        }
        if(flag){
            re = stoll(first);
            break;
        }
    }
    if(re == -1){
        cout << "NO" << endl;
    } else {
        cout << "YES " << re << endl;  
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    string line;
    for(int i = 0; i < n; i++){
        cin >> line;
        process(line);
    }
    return 0;
}
