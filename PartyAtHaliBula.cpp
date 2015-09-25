//UVA 1220
// Similar to BFS method
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
	int test;
	while (cin >> test && test != 0){
		string boss;
		cin >> boss;
		map<string, vector<string> > re;
		vector<string> name;
		vector<string> ini;
		re[boss] = ini;
		name.push_back(boss);
		for (int i = 0; i < test - 1; i++){
			string ee, er;
			cin >> ee >> er;
			name.push_back(ee);
			if (re.find(er) != re.end()){
				re[er].push_back(ee);
			}
			else{
				vector<string> tmp;
				tmp.push_back(ee);
				re[er] = tmp;
			}
		}

		queue<string> que;
		que.push(boss);
		que.push("#");
		set<string> go;
		set<string> dontgo;
		int sig = 0;
		while (!que.empty()){
			string tmp = que.front();
			que.pop();
			if (tmp == "#"){
				if (que.empty()){
					break;
				}
				else {
					tmp = que.front();
					que.pop();
					que.push("#");
					if (sig == 0){
						sig = 1;
					}
					else{
						sig = 0;
					}
				}
			}
			if (sig == 0){
				go.insert(tmp);
			}
			else{
				dontgo.insert(tmp);
			}
			for (auto it = re[tmp].begin(); it != re[tmp].end(); it++){
				que.push(*it);
			}
		}

		if (go.size() > dontgo.size()){
			cout << go.size() << " " << "Yes" << endl;
		}
		else if (go.size() < dontgo.size()){
			cout << dontgo.size() << " " << "Yes" << endl;
		}
		else{
			cout << go.size() << " " << "No" << endl;
		}
		


	}





	return 0;
}
