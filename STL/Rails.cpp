// UVA 514
// Stack
#include <iostream>
#include <stack>
#include <vector>
#define REP(i,s,t) for(int i = s; i < t; i++)
using namespace std;
stack<int> ss;
vector<int> all;
int main(){
	int n;
	while(cin >> n && n != 0){
		int tmp;
		while(cin >> tmp){
			all.clear();
			if(tmp == 0) break;
			while(!ss.empty()) ss.pop();
			all.push_back(tmp);
			REP(i,0,n-1){
				cin >> tmp;
				all.push_back(tmp);
			}
			// REP(i,0,n){
			// 	cout << all[i] << endl;
			// }
			int flag = 1;
			int idx = 0;
			int now = 1;
			while(now <= n){
				if(all[idx] == now){
					now++;
					idx++;
					continue;
				}
				if(!ss.empty() && ss.top() == all[idx]){
					idx++;
					ss.pop();
					continue;
				}
				ss.push(now);
				now++;
			}
			while(!ss.empty() && ss.top() == all[idx]) {
				ss.pop(); idx++;
			}
			if(!ss.empty()) flag = 0;
			if(flag) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		cout << endl;
	}
}