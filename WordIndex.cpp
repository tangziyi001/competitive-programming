//UVA 417
// Implicit BFS on strings
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <queue>

using namespace std;
map<string, int> dic;
set<char> ap;
queue<string>mark;

void fill(){
	int count = 0;
	int pos = 1;
	while (!mark.empty()){
		string now = mark.front();
		mark.pop();
		if (now == "#"){
			pos = pos+1;
			if (pos == 6){ // Test
				break;
			}	
			now = mark.front();
			mark.pop();
			mark.push("#");
		}

		int sz = now.size();
		char tmp = now[sz - 1];
		count += 1;
		dic[now] = count;
		
		for (int i = tmp + 1; i <= 122; ++i){
			char add = i;
			string cata = now;
			cata.append(1, add);
			mark.push(cata);
		}
	}	
}

int main(){
	for (int i = 97; i <= 122; ++i){
		char add = i;
		string tmp = "";
		tmp.append(1,add);
		mark.push(tmp);
	}
	mark.push("#");
	fill();

	string a;
	while (cin >> a){
		int sz = a.size();
		bool wrong = false;
		for (int i = 0; i < sz - 1; ++i){
			for (int j = i + 1; j < sz; ++j){
				if (a[i] >= a[j]){
					wrong = true;
					break;
				}
			}
			if (wrong == true){
				break;
			}
		}
		if (wrong == true){
			cout << 0 << endl;
		}
		else{
			cout << dic[a] << endl;
		}
	}
	

	return 0;
}