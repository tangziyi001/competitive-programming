//UVA 429
// BFS, blank line handling getline(), and index selection
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;
bool check(string a, string b){
    
        if(a.size()==b.size()){
            int count = 0;
            int sz = (int)a.size();
            for (int i = 0; i < sz; ++i){
                if (a[i] != b[i]){
                    count += 1;
                }
                if (count >= 2){
                    return false;
                }
            }
            return true;
        }
        return false;
        
    
}
int Distance(map<string, vector<string> > all, string str1, string str2){
    queue<string> que;
    que.push(str1);
    que.push("#");
    int count = 0;
    set<string>mark;
    mark.clear();
    mark.insert(str1);
    while (!que.empty()){
        string str = que.front();
        que.pop();
        if (str == "#"){
            str = que.front();
            que.pop();
            count += 1;
            que.push("#");
        }
        if (str == str2){
            return count;
        }
        vector<string> vec = all[str];
        
        if (!vec.empty()){
            for (auto it = vec.begin(); it != vec.end(); ++it){
                if(mark.find(*it)==mark.end())
                {
                    mark.insert(*it);
                    que.push(*it);
                }
            }
        }
        
    }
    return -1;
}

int main(){
    int test;
    string testnum;
    string blank;
    
    while (getline(cin, testnum)){
        getline(cin, blank);
        test = stoi(testnum);
        map<string, vector<string> > all;
        bool first=true;
        for (int t = 0; t < test; ++t){
            if(first)first=false;
            else cout<<endl;
            all.clear();
            vector<string> words;
            string str;
            while (getline(cin, str) && str != "*"){
                vector<string> tmp;
                all[str] = tmp;
            }
            
            for (auto it = all.begin(); it != prev(all.end()); ++it){
                string fir = (*it).first;
                for (auto it2 = all.begin(); it2 != all.end(); ++it2){
                    string sec = (*it2).first;
                    if (check(fir, sec) == true){
                        (*it).second.push_back(sec);
                        (*it2).second.push_back(fir);
                    }
                    
                }
            }
            string line;
            string one;
            string two;
            while (getline(cin, line)){
                if (line == ""){
                    break;
                }
                int idx = (int)line.find(' ');
                one = line.substr(0, idx);
                two = line.substr(idx+1, line.size() - idx - 1);
                int dis = Distance(all, one, two);
                cout << one << " " << two << " " << dis << endl;
            }
        }
        break;
        
        
    }
    
    
    return 0;
}